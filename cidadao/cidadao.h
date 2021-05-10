#ifndef __CIDADAO__H__
#define __CIDADAO__H__

#include <stdlib.h>
#include <stdbool.h>
#include "../node/node.h"

#define MAX_NOME 64

typedef struct cidadao_s {
    char  nome[MAX_NOME];
    short idade;
    char  grupo_de_risco;
} cidadao_t;

bool tem_risco(cidadao_t *c);

void imprime_cidadao(cidadao_t *c);

void imprime_node_cidadao(sl_node_t *node, size_t pos);

#endif  //!__CIDADAO__H__