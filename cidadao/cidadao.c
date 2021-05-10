#include "cidadao.h"

bool tem_risco(cidadao_t *c) {
    return (c->grupo_de_risco != 'N');
}

void imprime_cidadao(cidadao_t *c) {
    printf(" %s, %d anos", c->nome, c->idade);
    if ( tem_risco(c) ) {
        printf(", grupo de risco %c", c->grupo_de_risco);
    }
    printf("\n");        
}

void imprime_node_cidadao(sl_node_t *node, size_t pos) {
    cidadao_t *c = get_data(node);
    printf("\t#%li\t", pos);
    imprime_cidadao(c);
}