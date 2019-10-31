//
// Created by 任真如 on 2019/10/31.
//

#include "prime.h"
#include <math.h>

int is_prime(const int x){
    if(x<2) return -1;
    if(x<4) return 1;
    if(x%2==0) return 0;
    for(int i=3;i<floor(sqrt((double)x));i=i+2){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

int next_prime(int x){
    while(is_prime(x)!=1){
        x++;
    }
    return x;
}