#include "linked_list.h"

sl_node_t* get_node(linked_list_t *l, size_t pos) {
    if (size_list(l) == 0 || pos < 0 || pos >= size_list(l)) {
        fprintf(stderr, "invalid position %zi\n", pos);
        return NULL;
    }

    if (pos == 0)         return l->first; /* O(1) - first node  */
    if (pos == size_list(l)-1) return l->last;  /* O(1) - last node   */

    sl_node_t *node = l->first;
    for (size_t i = 0; i < pos; ++i) {     /* O(n) - other nodes */
        node = get_next(node); 
    }
    return node;
}

linked_list_t* new_list(size_t size_data) {
    linked_list_t *l = malloc(sizeof *l);
    l->first = NULL;
    l->last = NULL;
    l->length_list = 0;
    l->size_data = size_data;
    return l;
}

void delete_list(linked_list_t *l) {
    sl_node_t *node = l->first;
    sl_node_t *next_node = NULL;

    while ( node != NULL ) {
        next_node = node->next;
        delete_node(node);
        node = next_node;
    }

    free(l);
}

size_t size_list(linked_list_t *l) {
    return l->length_list;
}

void* lookup(linked_list_t *l, int pos) {
    sl_node_t* node = NULL;
    node = get_node(l, pos);

    return node->data;
}

int insert(linked_list_t *l, void* data, int pos) {

    if (pos < 0 || pos > size_list(l)) {
        fprintf(stderr, "unable to reach list in position %i\n", pos);
        return EXIT_FAILURE;
    }
    
    sl_node_t *node = new_node(data, l->size_data);
    sl_node_t *curr_node = NULL;

    if (node == NULL) {
        fprintf(stderr, "could not allocate a new list node");
        return EXIT_FAILURE;
    };

    /* O(1) Insert in beginning */
    if (pos == 0) {
        // empty list
        if (size_list(l) == 0) {
            l->first = node;
            l->last = node;

        // not empty list
        } else {
            curr_node = l->first;
            node->next = curr_node;
            l->first = node;
        }

    /* O(1) Insert in the end */
    } else if (pos == size_list(l)) {
        curr_node = l->last;
        curr_node->next = node;
        l->last = curr_node->next;

    // O(n) Insert arbitrarily
    } else {
        sl_node_t *prev_node = get_node(l, pos-1);

        if (prev_node) {
            curr_node = prev_node->next;
            node->next = curr_node;
            prev_node->next = node;
        }
    }

    l->length_list++;
    return EXIT_SUCCESS;
}

void* extract(linked_list_t *l, int pos) {
    sl_node_t *prev_node = NULL, *next_node = NULL,
              *node = NULL;

    if ( pos == 0 ) {
        node = l->first;
        next_node = node->next;
        l->first = next_node;
    } else {
        prev_node = get_node(l, pos-1);
        
        if (pos == size_list(l) - 1) {
            l->last = prev_node;
        }

        node = prev_node->next;
        next_node = node->next;
        prev_node->next = next_node;
    }
    
    void* data = node->data;
    free(node);
    l->length_list--;
    return data;
}

void* look_front(linked_list_t *l) {
    return l->first->data;
}

void* look_back(linked_list_t *l) {
    return l->last->data;
}

int push_front(linked_list_t *l, void* data) {
    return insert(l, data, 0);
}

int push_back(linked_list_t *l, void* data) {
    return insert(l, data, size_list(l));
}

void* pop_front(linked_list_t *l) {
    return extract(l, 0);
}

void* pop_back(linked_list_t *l) {
    return extract(l, size_list(l)-1);
}

void print_list(linked_list_t *l,
                void (*print_data)(sl_node_t*, size_t)) {
    sl_node_t *node = l->first;
    size_t i = 0;

    do {
        print_data(node, ++i);
        
    } while ( (node = node->next) != NULL );

    //printf("=== List size: %zi\n", size_list(l));
}

void       set_first(linked_list_t *l, sl_node_t *node) { l->first = node; }
void       set_last (linked_list_t *l, sl_node_t *node) { l->last  = node; }
sl_node_t* get_first(linked_list_t *l)                  { return l->first; } 
sl_node_t* get_last (linked_list_t *l)                  { return l->last;  }