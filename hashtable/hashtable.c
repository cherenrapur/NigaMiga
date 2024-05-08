

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <libc.h>
#include "hashtable.h"

#define INIT_CAPACITY 4

Hashtable* ht_init()
{
    Hashtable* table = (Hashtable*)malloc(sizeof(Hashtable));
    // Check if memory for table is allocated
    if(table == NULL )
    {
        fprintf(stderr, "Failed to allocate memory for hash table\n");
        return NULL;
    }
    table->length = 0;
    table->capacity = INIT_CAPACITY;
    table->entries = calloc(table->capacity, sizeof(Entry));
    if(table->entries == NULL)
    {
        free(table); // Error allocating entries
        return NULL;
    }

    return table;
}

void ht_free(Hashtable* table){
    for(size_t i = 0; i < table->capacity; ++i)
        free((void*)table->entries[i].key);

    free(table->entries);
    free(table);
}

/**
 * @brief 'djb2' algorithm for hashing string
 *
 **/
unsigned int hash_key(unsigned char* str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

/**
 * @brief Retrieve value associated with a given key from the hash table
 *
 * */
void* ht_get(Hashtable* table, const char* key)
{
    uint32_t hash = hash_key(key);
    uint32_t index = hash & (uint32_t)(table->capacity - 1);

    // Parameters used for quadratic probing
    uint32_t initial_index = index;
    uint32_t h = 1;

    while(table->entries[index].key != NULL)
    {
        if(strcmp(table->entries[index].key, key) == 0)
            return table->entries[index].value;

        index = (initial_index + (h * h)) % table->capacity;
        h++;
    }
    // Key not found in table
    return NULL;
}

const char* ht_set_entry(Entry* entry, const char* key, void* value, size_t capacity, size_t* plength)
{
    uint32_t hash = hash_key(key);
    uint32_t index = hash & (uint32_t)(capacity - 1);

    // Parameters used for quadratic probing
    uint32_t initial_index = index;
    uint32_t h = 1;

    while(entry[index].key != NULL)
    {
        if(strcmp(entry[index].key, key) == 0)
        {
            entry[index].value = value;
            return entry[index].key;
        }
        index = (initial_index + (h * h)) % capacity;
        h++;
    }
    if (plength != NULL) {
        key = strdup(key);
        if (key == NULL) {
            return NULL;
        }
        (*plength)++;
    }
    entry[index].key = (char*)key;
    entry[index].value = value;
    return key;
}


int ht_expand(Hashtable* table)
{
    size_t new_capacity = table->capacity * 2;
    if(new_capacity < table->capacity)
    {
        return 0; // Overflow has occurred
    }
    Entry* new_entries = calloc(new_capacity, sizeof(Entry));
    if(new_entries == NULL)
    {
        return 0; // Allocation failed
    }
    for(size_t i = 0; i < table->capacity; ++i)
    {
        //new_entries[i] = table->entries[i];
        Entry entry = table->entries[i];
        if(entry.key != NULL)
        {
            ht_set_entry(new_entries, entry.key, entry.value, new_capacity, NULL);
        }
    }

    free(table->entries);
    table->capacity = new_capacity;
    table->entries = new_entries; //0 0 0 0 0 0 0 0 0 0 0
    //free(table->entries);
    return 1;
}

const char* ht_set(Hashtable* table, const char* key, void* value)
{
    if(value == NULL)
        return NULL;

    if(table->length >= table->capacity / 2)
    {
        if(!ht_expand(table))
            return NULL;
    }

    return ht_set_entry(table->entries, key, value, table->capacity, &table->length);
}



