#include "cache.h"
#include <string.h>

typedef struct {
    unsigned int tag;
    unsigned char valid;
    unsigned char data[32];
} cache_line_t;

typedef struct {
    cache_line_t *lines;
    unsigned int num_lines;
    int initialized;
} cache_t;


static void init_cache(cache_t *cache) {
    cache->num_lines = c_info.F_size / sizeof(cache_line_t);
    cache->lines = (cache_line_t *)(((char *)cache) + sizeof(cache_t));
    cache->initialized = 1;
    memset(cache->lines, 0, cache->num_lines * sizeof(cache_line_t));
}

static cache_line_t *find_line(cache_t *cache, unsigned int tag) {
    for (unsigned int i = 0; i < cache->num_lines; i++) {
        if (cache->lines[i].valid && cache->lines[i].tag == tag) {
            return &cache->lines[i];
        }
    }

    return NULL;
}

static cache_line_t *find_victim(cache_t *cache) {
    for (unsigned int i = 0; i < cache->num_lines; i++) {
        if (!cache->lines[i].valid) {
            return &cache->lines[i];
        }
    }

    return &cache->lines[0];
}


int cache_get(unsigned long address, unsigned long *value) {
    cache_t *cache = (cache_t *)c_info.F_memory;

    if (cache->initialized == 0) {
        init_cache(cache);
    }

    unsigned int tag = (address >> 5);
    unsigned int block_offset = address & 0xFF;

    // Searching for the line in the cache
    cache_line_t *line = find_line(cache, tag);

    if (line != NULL) {
        // Cache hit
        memcpy(value, line->data + block_offset, sizeof(unsigned long));
        return 1;
    }

    // Cache miss
    line = find_victim(cache);
    line->tag = tag;
    line->valid = 1;

    unsigned long mask = address & ~0x1F;
    if (!memget(mask, line->data, 32)) {
        return 0;
    }

    memcpy(value, line->data + block_offset, sizeof(unsigned long));
    return 1;
}