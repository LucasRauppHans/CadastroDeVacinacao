#include "vacinacao.h"

fila_vacina *nova_fila_vacina()
{
    return new_queue(sizeof(cidadao_t));
}

void destroi_fila_vacina(fila_vacina *f)
{
    delete_queue(f);
}

int compara_riscos(cidadao_t *c1, cidadao_t *c2)
{
    // risco c1 é menor/igual que c2
    if (c1->grupo_de_risco >= c2->grupo_de_risco)
    {
        return -1;
    }
    // risco c1 é maior que c2
    if (c1->grupo_de_risco < c2->grupo_de_risco)
    {
        return 1;
    }
}

bool tem_prioridade(cidadao_t *c1, cidadao_t *c2)
{
    return (compara_riscos(c1, c2) == 1 &&
            c1->idade >= c2->idade - 5) ||
           (compara_riscos(c1, c2) == -1 &&
            c1->idade > c2->idade);
}

/* insere cidadão na fila de prioridade de vacinação */
int insere_cidadao_fila(fila_vacina *f, cidadao_t *cid)
{
    sl_node_t *node = new_node(cid, f->list->size_data);
    if (node == NULL)
    {
        return EXIT_FAILURE;
    };

    if (size_queue(f) == 0)
    {
        set_first(f->list, node);
        set_last(f->list, node);
    }
    else
    {
        sl_node_t *prev_node = NULL, *next_node = NULL,
                  *node_it = get_first(f->list);
        cidadao_t *cid_it = NULL;

        while (node_it != NULL)
        {
            cid_it = get_data(node_it);

            if (tem_prioridade(cid, cid_it))
            {
                sl_node_t *tmp_node = NULL;
                if (prev_node == NULL)
                {
                    tmp_node = get_first(f->list);
                    set_next(node, tmp_node);
                    set_first(f->list, node);
                }
                else
                {
                    tmp_node = get_next(prev_node);
                    set_next(prev_node, node);
                    set_next(node, tmp_node);
                }
                break;
            }

            prev_node = node_it;
            next_node = get_next(node_it);

            if (next_node == NULL)
            {
                set_next(node_it, node);
                set_last(f->list, node);
                break;
            }

            node_it = next_node;
        }
    }

    f->list->length_list++;
    return EXIT_SUCCESS;
}

void cadastra_cidadao(fila_vacina *f, cidadao_t *c)
{
    int erro = insere_cidadao_fila(f, c);
    if (erro)
    {
        fprintf(stderr, "Nao foi possivel cadastrar novo cidadao.\n");
    }
    escreve_arquivo(c);
}

void vacina_cidadao(fila_vacina *f)
{
    cidadao_t *c = dequeue(f);
    printf("Cidadao vacinado: ");
    imprime_cidadao(c);
    free(c);
}

void imprime_fila_vacinacao(fila_vacina *f)
{
    void (*print_cidadao_func)(sl_node_t *, size_t) =
        imprime_node_cidadao;
    print_queue(f, print_cidadao_func);
}

void escreve_arquivo(cidadao_t *c)
{
    FILE *arq;
    arq = fopen("fila_de_vacinacao.txt", "a");
    int r;

    if (!arq)
    {
        printf("Erro ao abrir arquivo '%s'!\n", "fila_de_vacinacao.txt");
    }

    char idade[5];
    itoa(c->idade, idade, 10);

    char grupo_de_risco[2];
    grupo_de_risco[0] = c->grupo_de_risco;
    grupo_de_risco[1] = '\0';

    fputs(c->nome, arq);
    fputs(", ", arq);
    fputs(idade, arq);
    fputs(", ", arq);
    fputs(grupo_de_risco, arq);
    fputs("\n", arq);

    if (r == EOF)
    {
        printf("Erro ao tentar gravar os dados! \n");
    }

    fclose(arq);
}

int le_arquivo(fila_vacina *l, char *nome_arq)
{
    FILE *arq;
    arq = fopen(nome_arq, "r");

    if (!arq)
    {
        printf("Erro ao abrir arquivo '%s'!\n", nome_arq);
        return 0;
    }

    char linha[300]; // linha atual lida do arquivo
    char *token;     // trecho atual da linha
    cidadao_t atual; //tera' os dados de 1 estudante lido

    while (fgets(linha, 300, arq) != NULL)
    {

        //primeiro valor eh o nome
        token = strtok(linha, ",");
        strcpy(atual.nome, token);

        //segundo valor eh a idade
        token = strtok(NULL, ",");
        atual.idade = atoi(token);

        //terceiro valor eh a grupo de risco
        token = strtok(NULL, ",");
        char grupo_de_risco[10];
        strcpy(grupo_de_risco, token);
        atual.grupo_de_risco = grupo_de_risco[0];

        insere_cidadao_fila(l, &atual);
    }
    return 1; //tudo ok
}