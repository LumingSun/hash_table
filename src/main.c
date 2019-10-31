//
// Created by luming on 2019/10/28.
//
#include "hash_table.h"
#include "prime.h"
#include <string.h>
#include <stdio.h>
int main() {
    ht_hash_table* ht = ht_new();
    ht_insert(ht,"a","aa");
    ht_insert(ht,"b","bb");
//    ht_search(ht,"bb");
    ht_del_hash_table(ht);
}