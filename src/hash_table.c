//
// Created by luming on 2019/10/28.
//

#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
static ht_item* ht_new_item(const char* key,const char * v){
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(key);
    i->value = strdup(v);
    return i;
}

ht_hash_table* ht_new(){
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));
    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size,sizeof(ht_item*));
    return ht;
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
    for (int i=0;i<lenth;i++){
        hash += (long)(pow(a,length-(i+1)) * s[i]);
        hash = hash % size;
    }
    return (int)hash;
}
