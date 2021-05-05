#ifndef __PRODUCT__H__
#define __PRODUCT__H__

#include "../node/node.h"

typedef struct product_s {
    char code[8];
    char name[96];
    double price;
} product_t;

void print_product(product_t *product);

void print_node_product(sl_node_t *node, size_t pos);

#endif  //!__PRODUCT__H__