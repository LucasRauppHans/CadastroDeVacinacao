#ifndef __VACINACAO__H__
#define __VACINACAO__H__

#include <stdio.h>
#include <stdlib.h>
#include "../cidadao/cidadao.h"
#include "../queue/queue.h"

typedef queue_t fila_vacina;

fila_vacina* nova_fila_vacina();

void destroi_fila_vacina(fila_vacina *f);

void cadastra_cidadao(fila_vacina *f, cidadao_t *c);

void cadastra_lista_csv(fila_vacina *f, const char *nome_arquivo); // implementar

void vacina_cidadao(fila_vacina *f);

void busca_ordem_cidadao(fila_vacina *f, const char *nome_cidadao); // implementar 

void imprime_fila_vacinacao(fila_vacina *f);

void lista_grupo_risco(fila_vacina *f); // implementar

// outros:
// lista por faixa etaria (30-49, 50-69, ...)
// 

#endif  //!__VACINACAO__H__