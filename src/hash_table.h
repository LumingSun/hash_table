//
// Created by luming on 2019/10/28.
//

#ifndef HASH_HASH_TABLE_H
#define HASH_HASH_TABLE_H

static int HT_PRIME_1 = 163;
static int HT_PRIME_2 = 144;
static int HT_INITIAL_BASE_SIZE = 50;

typedef struct {
    char* key;
    char* value;
}ht_item;

typedef struct {
    int size;
    int count;
    int base_size;
    ht_item** items;
}ht_hash_table;

void ht_insert(ht_hash_table* ht,const char* key, const char* value);
char* ht_search(ht_hash_table* ht,const char * key);
void ht_delete(ht_hash_table* ht,const char* key);
ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);
#endif //HASH_HASH_TABLE_H
