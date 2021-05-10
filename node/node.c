#include "node.h"

sl_node_t* new_node(void* data, size_t size_data) {
    sl_node_t *node = malloc(sizeof *node);   
    if ( node == NULL ) return NULL;

    node->data = malloc(size_data);
    if ( node->data == NULL ) return NULL;
    memcpy(node->data, data, size_data);
        
    node->next = NULL;
    return node;
}

void delete_node(sl_node_t *node) { free(node->data); free(node); }

void* get_data(sl_node_t *node)   { return node->data; }

void       set_next(sl_node_t *node, sl_node_t *next) { node->next = next; }
sl_node_t* get_next(sl_node_t *node)                  { return node->next; }
