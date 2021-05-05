#include "product.h"

void print_product(product_t *product) {
    printf("=== Product:\t%s\t%s\t%.2lf\n", 
        product->code, product->name, product->price);
}

void print_node_product(sl_node_t *node, size_t pos) {
    product_t *product = get_data(node);
        
    printf("=== Product %zi:\t%s\t%s\t%.2lf\n", 
        pos,
        product->code, product->name, product->price);
}