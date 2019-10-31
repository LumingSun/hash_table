//
// Created by luming on 2019/10/28.
//

#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "prime.h"

static ht_item HT_DELETED_ITEM = {NULL, NULL};
static ht_item* ht_new_item(const char* key,const char * v){
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(key);
    i->value = strdup(v);
    return i;
}

ht_hash_table* ht_new_sized(const int base_size){
    ht_hash_table * ht = malloc(sizeof(ht_hash_table));
    ht->base_size = base_size;
    ht->size = next_prime(ht->base_size);
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

ht_hash_table* ht_new(){
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

static void ht_del_item(ht_item* i){
    free(i->key);
    free(i->value);
}

void ht_del_hash_table(ht_hash_table* ht){
    for (int i=0;i<ht->size;i++){
        ht_item* item = ht->items[i];
        if(item!=NULL)
            ht_del_item(item);
    }
    free(ht->items);
    free(ht);
}

static int ht_hash(const char* s, const int a, const int size){
    long hash = 0;
    const int length = strlen(s);
    for (int i=0;i<length;i++){
        hash += (long)(pow(a,length-(i+1)) * s[i]);
        hash = hash % size;
    }
    return (int)hash;
}

static int ht_get_hash(const char *s, const int size, const int attempt){
    const int hash_a = ht_hash(s,HT_PRIME_1,size);
    const int hash_b = ht_hash(s,HT_PRIME_2,size);
    const int hash = (hash_a + (attempt * (hash_b + 1)))%size;
    return hash;
}


static void ht_resize(ht_hash_table * ht,const int base_size){
    ht_hash_table * ht_new = ht_new_sized(base_size);
    for(int i = 0;i<ht->size;i++){
        ht_item* item = ht->items[i];
        if(item!=NULL && item!=&HT_DELETED_ITEM){
            ht_insert(ht_new,item->key,item->value);
        }
    }
    ht->base_size = ht_new->base_size;
    ht->count = ht_new->count;

    const int tmp_size = ht->size;
    ht->size = ht_new->size;
    ht_new->size = tmp_size;

    ht_item ** tmp_items = ht->items;
    ht->items = ht_new->items;
    ht_new->items = tmp_items;

    ht_del_hash_table(ht_new);

}

static void ht_resize_up(ht_hash_table * ht){
    const int new_size = ht->base_size * 2;
    ht_resize(ht,new_size);
}
static void ht_resize_down(ht_hash_table * ht){
    const int new_size = ht->base_size / 2;
    ht_resize(ht,new_size);
}

void ht_insert(ht_hash_table* ht,const char* key, const char* value){
    const int load = ht->count*100/ht->size;
    if(load>70){
        ht_resize_up(ht);
    }
    ht_item* item = ht_new_item(key,value);
    int index = ht_get_hash(item->key,ht->size,0);
    ht_item* curr_item = ht->items[index];
    int i = 1;
    while(curr_item!=NULL && curr_item != &HT_DELETED_ITEM){
        if(strcmp(curr_item->key,key)==0){
            ht_del_item(curr_item);
            ht->items[index] = item;
            return;
        }
        index = ht_get_hash(item->key,ht->size,i);
        i++;
        curr_item = ht->items[index];
    }
    ht->items[index] = curr_item;
    ht->count ++;
}

char* ht_search(ht_hash_table* ht,const char * key){
    int index = ht_get_hash(key,ht->size,0);
    ht_item * curr_item = ht->items[index];
    int i = 1;
    while(curr_item->key != NULL){
        if(strcmp(curr_item->key,key)==0){
            return curr_item->value;
        }
        else{
            index = ht_get_hash(key,ht->size,i);
            curr_item = ht->items[index];
            i++;
        }
    }
    return NULL;
}

void ht_delete(ht_hash_table* ht,const char* key){
    const int load = ht->count * 100 / ht->size;
    if(load<10){
        ht_resize_down(ht);
    }
    int index = ht_get_hash(key,ht->size,0);
    ht_item* curr_item = ht->items[index];
    int i = 1;
    while(curr_item->key!=NULL){
        if(curr_item->key != &HT_DELETED_ITEM){
            if(strcmp(curr_item->key,key)==0){
                ht_del_item(curr_item);
                ht->items[index]=&HT_DELETED_ITEM;
            } else{
                index = ht_get_hash(key,ht->size,i);
                curr_item = ht->items[index];
                i++;
            }
        }
    }
    ht->count --;
}

