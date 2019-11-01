//
// Created by 任真如 on 2019/11/1.
//

#ifndef HASH_XMALLOC_H
#define HASH_XMALLOC_H

#include <stddef.h>
void *xmalloc (size_t size);
void *xcalloc (size_t nmemb, size_t size);
void *xrealloc (void *ptr, size_t size);
char *xstrdup (const char *s);
#endif //HASH_XMALLOC_H
