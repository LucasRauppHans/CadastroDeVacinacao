#include "vacinacao.h"

fila_vacina* nova_fila_vacina() {
    return new_queue(sizeof(cidadao_t));
}

void destroi_fila_vacina(fila_vacina* f) {
    delete_queue(f);
}

int compara_riscos(cidadao_t *c1, cidadao_t *c2) {
    // risco c1 é menor/igual que c2
    if (c1->grupo_de_risco >= c2->grupo_de_risco) {
        return -1;
    }
    // risco c1 é maior que c2
    if (c1->grupo_de_risco < c2->grupo_de_risco) {
        return 1;
    }
}

bool tem_prioridade(cidadao_t *c1, cidadao_t *c2) {
    return
        (compara_riscos(c1, c2) ==  1 &&
        (c1->idade >= c2->idade - 5 || c1->idade >= c2->idade)) 
         ||
        (compara_riscos(c1, c2) == -1 &&
         c1->idade > c2->idade);
}

/* insere cidadão na fila de prioridade de vacinação */
int insere_cidadao_fila(queue_t *q, cidadao_t *cid) {
    sl_node_t *node = new_node(cid, q->list->size_data);
    if ( node == NULL ) {
        return EXIT_FAILURE;
    };

    if ( size_queue(q) == 0 ) {
        set_first(q->list, node);
        set_last (q->list, node);
    } else {
        sl_node_t *prev_node = NULL, *next_node = NULL,
                  *node_it   = get_first(q->list);
        cidadao_t *cid_it    = NULL;

        while ( node_it != NULL ) {
            cid_it = get_data(node_it);

            if ( tem_prioridade(cid, cid_it) ) {
                sl_node_t *tmp_node = NULL;
                if ( prev_node == NULL ) {
                    tmp_node = get_first(q->list);
                    set_next(node, tmp_node);
                    set_first(q->list, node);
                } else {
                    tmp_node = get_next(prev_node); 
                    set_next(prev_node, node);
                    set_next(node, tmp_node);
                }
                break;
            }

            prev_node = node_it;
            next_node = get_next(node_it);

            if ( next_node == NULL ) {
                set_next(node_it, node);
                set_last(q->list, node);
                break;
            }

            node_it = next_node;
        }
    }

    q->list->length_list++;
    return EXIT_SUCCESS;
}


void cadastra_cidadao(fila_vacina *f, cidadao_t *c) {
    int erro = insere_cidadao_fila(f, c);
    if (erro) {
        fprintf(stderr, "Nao foi possivel cadastrar novo cidadao.\n");
    }
}

void cadastra_lista_csv(fila_vacina *f, const char *nome_arquivo);

void vacina_cidadao(fila_vacina *f) {
    cidadao_t *c = dequeue(f);
    printf("Cidadao vacinado: ");
    imprime_cidadao(c);
}

void imprime_fila_vacinacao(fila_vacina *f) {
    void (*print_cidadao_func)(sl_node_t*, size_t) =
        imprime_node_cidadao;
    print_queue(f, print_cidadao_func);
}