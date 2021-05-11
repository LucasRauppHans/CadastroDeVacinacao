#ifndef __VACINACAO__H__
#define __VACINACAO__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cidadao/cidadao.h"
#include "../queue/queue.h"

typedef queue_t fila_vacina;

fila_vacina *nova_fila_vacina();

void destroi_fila_vacina(fila_vacina *f);

void cadastra_cidadao(fila_vacina *f, cidadao_t *c);

void vacina_cidadao(fila_vacina *f);

void busca_ordem_cidadao(fila_vacina *f, const char *nome_cidadao); // implementar

void imprime_fila_vacinacao(fila_vacina *f);

void lista_grupo_risco(fila_vacina *f); // implementar

void escreve_arquivo(cidadao_t *c);

int le_arquivo(fila_vacina *l, char *nome_arq);

// outros:
// lista por faixa etaria (30-49, 50-69, ...)
//

#endif //!__VACINACAO__H__