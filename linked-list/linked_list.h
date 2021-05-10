#ifndef __LINKED_LIST__H__
#define __LINKED_LIST__H__

#include <stdio.h>
#include <stdlib.h>

#include "../node/node.h"

// singly-linked list
typedef struct linked_list_s {
    size_t length_list;
    size_t size_data;
    sl_node_t *first, *last;
} linked_list_t;

linked_list_t* new_list(size_t size_data);

void delete_list(linked_list_t *l);

size_t size_list(linked_list_t *l);

void* lookup(linked_list_t *l, int pos);

int insert(linked_list_t *l, void* data, int pos);

void* extract(linked_list_t *l, int pos);

void* look_front(linked_list_t *l);

void* look_back(linked_list_t *l);

int push_front(linked_list_t *l, void* data); 

int push_back(linked_list_t *l, void* data);

void* pop_front(linked_list_t *l);

void* pop_back(linked_list_t *l);

void print_list(linked_list_t *l, void (*print_data)(sl_node_t*, size_t));

void set_first(linked_list_t *l, sl_node_t *node); 
void set_last (linked_list_t *l, sl_node_t *node); 
sl_node_t* get_first(linked_list_t *l);                 
sl_node_t* get_last (linked_list_t *l);       

#endif  //!__LINKED_LIST__H__
