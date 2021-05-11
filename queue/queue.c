#include "queue.h"
#include "../cidadao/cidadao.h"

queue_t *new_queue(size_t size_data)
{
    queue_t *q = malloc(sizeof(queue_t));
    q->list = new_list(size_data);
}

void delete_queue(queue_t *q)
{
    delete_list(q->list);
    free(q);
}

size_t size_queue(queue_t *q)
{
    return size_list(q->list);
}

int empty_queue(queue_t *q)
{
    return (size_queue(q) == 0);
}

int enqueue(queue_t *q, void *data)
{
    return push_back(q->list, data);
}

void *dequeue(queue_t *q)
{
    return pop_front(q->list);
}

void print_queue(queue_t *q, void (*print_data)(sl_node_t *, size_t))
{
    print_list(q->list, print_data);
}
