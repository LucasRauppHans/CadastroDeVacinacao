#include <stdio.h>
#include "queue/queue.h"
#include "product/product.h"

void testa_lista() {
    linked_list_t *l = new_list(sizeof(product_t));

    product_t p1 = {"2406887", "Camaro",          34.00};
    product_t p2 = {"5839421", "Ferrari",         16.50};
    product_t p3 = {"8562834", "Sabre",           249.99};
    product_t p4 = {"8562834", "Arroz branco",    99999.00};

    push_back(l, &p2);
    push_back(l, &p1);
    push_back(l, &p3);
    push_back(l, &p1);
    push_back(l, &p4);
    push_back(l, &p1);
    push_back(l, &p2);
    push_back(l, &p4);
    push_back(l, &p3);
    push_back(l, &p2);
    push_back(l, &p3);
    push_back(l, &p1);
    push_back(l, &p4);
    push_back(l, &p3);
    push_back(l, &p3);
    push_back(l, &p2);
    push_back(l, &p4);
    push_back(l, &p1);
    push_back(l, &p3);
    push_back(l, &p2);
    push_back(l, &p2);

    product_t* p = extract(l, 5);
    print_product(p);
    free(p);

    void (*print_product_func)(sl_node_t*, size_t) =
        print_node_product;
    print_list(l, print_product_func); 

    delete_list(l);
}

void testa_fila() {
    queue_t *q = new_queue(sizeof(product_t));
    product_t* p = NULL;

    product_t p1 = {"2406887", "Camaro",          34.00};
    product_t p2 = {"5839421", "Ferrari",         16.50};
    product_t p3 = {"8562834", "Sabre",           249.99};
    product_t p4 = {"8562834", "Fusca",    99999.00};

    enqueue(q, &p1);
    enqueue(q, &p2);
    enqueue(q, &p3);
    enqueue(q, &p4);
    p = dequeue(q); print_product(p); free(p); 
    p = dequeue(q); print_product(p); free(p);
    enqueue(q, &p1);
    enqueue(q, &p2);

    void (*print_product_func)(sl_node_t*, size_t) =
        print_node_product;
    print_queue(q, print_product_func); 

    delete_queue(q);    
}

int main(void) {
    
    //testa_lista();

    testa_fila();

    return 0;
}