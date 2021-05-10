#ifndef __NODE__H__
#define __NODE__H__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct sl_node_s {
    void* data;
    struct sl_node_s *next;
} sl_node_t;

sl_node_t* new_node(void* data, size_t size_data);

void delete_node(sl_node_t *node);

void* get_data(sl_node_t *node);

sl_node_t* get_next(sl_node_t *node);
void       set_next(sl_node_t *node, sl_node_t *next);

#endif  //!__NODE__H__