
#ifndef NIGAMIGA_HASHTABLE_H
#define NIGAMIGA_HASHTABLE_H

/**
 * @brief ht_entry structure for the hash table.
 *        Represents a key-value pair stored in the hash table.
 */
typedef struct {
    char* key;
    void* value;
} Entry;

typedef struct {
    Entry* entries;    // hash slots
    size_t capacity;   // size of hash table, initially 16 [, , ,...]
    size_t length;     // number of items in hash table
} Hashtable;

/**
 * @brief Initialize hash table
 *
 */
Hashtable* ht_init();
void ht_free(Hashtable* table);
unsigned int hash_key(unsigned char* str);
void* ht_get(Hashtable* table, const char* key);
const char* ht_set_entry(Entry* entry, const char* key, void* value, size_t capacity, size_t* plength);
int ht_expand(Hashtable* table);
const char* ht_set(Hashtable* table, const char* key, void* value);

#endif //NIGAMIGA_HASHTABLE_H
