//
// Created by luming on 2019/10/28.
//

#ifndef HASH_HASH_TABLE_H
#define HASH_HASH_TABLE_H

typedef struct {
    char* key;
    char* value;
}ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
}ht_hash_table;




#endif //HASH_HASH_TABLE_H
