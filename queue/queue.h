#ifndef __QUEUE__H__
#define __QUEUE__H__

#include "../linked-list/linked_list.h"

typedef struct queue_s {
    linked_list_t* list;
} queue_t;

queue_t* new_queue(size_t size_data);

void delete_queue(queue_t *q);

size_t size_queue(queue_t* q);

int empty_queue(queue_t* q);

int enqueue(queue_t* q, void* data);

void* dequeue(queue_t* q);
        
void print_queue(queue_t *q, void (*print_data)(sl_node_t*, size_t));

#endif  //!__QUEUE__H__