#pragma once
#include "include/zl_type_hash.h"

zl_hash_t*
zl_hash_init()
{
    zl_hash_t* map = (zl_hash_t*)malloc(sizeof(zl_hash_t));
    if (map == NULL)
    {
#ifdef ZL_DEBUG
        fprintf(stderr, "[x] zl_hash_init : problem allocating memory for hash map");
#endif
        free(map);
        return NULL;
    }
    map->table = (zl_hashkv_t*)calloc(MAX_HASH_TABLE_SIZE, sizeof(zl_hashkv_t));
    if (map->table == NULL)
    {
#ifdef ZL_DEBUG
        fprintf(stderr, "[x] zl_hash_init : problem allocating memory for hash map table");
#endif
        free(map);
        return NULL;
    }

    // clear map & its table
    map->size = MAX_HASH_TABLE_SIZE;
    map->size = 0;

    for (uint i = 0; i < MAX_HASH_TABLE_SIZE; i++)
    {
        map->table[i].key = NULL;
        map->table[i].value = NULL;
    }

    return map;
}

bool
zl_hash_free(zl_hash_t* map)
{
    // clear out array before free
    for (uint i = 0; i < MAX_HASH_TABLE_SIZE; i++)
    {
        map->table[i].key = NULL;
        map->table[i].value = NULL;
    }

    free(map);
    map = NULL;
    if (map != NULL)
        return FALSE;

    return TRUE;
}

bool
zl_hash_append(zl_hash_t* map, char* key, void* data)
{
    if (map == NULL)
        return FALSE;

    uint index = zl_hash_key(key);
    if (map->table[index].key != NULL)
    {
        return FALSE;
    }

    map->table[index].key = key;
    map->table[index].value = data;

    return TRUE;
}

bool
zl_hash_remove(zl_hash_t* map, char* key)
{
    uint index = zl_hash_key(key);
    if (map->table[index].key != NULL)
    {
        if (strncmp(map->table[index].key, key, MAX_HASH_TABLE_SIZE) == 0)
        {
            map->table[index].key = NULL;
            map->table[index].value = NULL;

            return TRUE;
        }
    }

    return FALSE;
}

uint
zl_hash_key(char* key)
{
    uint length = strnlen(key, MAX_HASH_NAME);
    uint hash = 0;

    for (uint i = 0; i < length; i++)
    {
        hash += key[i];
        hash = (hash * key[i]) % MAX_HASH_TABLE_SIZE;
    }

    return hash;
}

zl_hashkv_t*
zl_hash_search_key(zl_hash_t* map, char* key)
{
    uint index = zl_hash_key(key);
    if (map->table[index].key != NULL)
    {
        if (strncmp(map->table[index].key, key, MAX_HASH_TABLE_SIZE) == 0)
        {
            return &map->table[index];
        }
    }

    return NULL;
}

void
zl_hash_print_map(zl_hash_t* hmap)
{
    // prints out available keys with address to (void*) value
    for (uint i = 0; i < MAX_HASH_TABLE_SIZE; i++)
    {
        if (hmap->table[i].key == NULL) continue;

        fprintf(stdout, "%15p %s\n", &hmap->table[i].value, hmap->table[i].key);
    }
}