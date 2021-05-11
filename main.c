#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacinacao/vacinacao.h"

void busca_opcao(char *op);
void print_menu();
int encerra(const char op);

int main(void)
{

    system("cls||clear");

    fila_vacina *f = nova_fila_vacina();

    char nome_arq[256];

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 256, stdin);             //fgets com stdin le do teclado
    nome_arq[strcspn(nome_arq, "\r\n")] = 0; //elimina o \n deixado pelo fgets

    if (le_arquivo(f, nome_arq) == 0)
    {
        printf("Lista nao foi preenchida a partir do arquivo. Iniciando com lista vazia...\n");
    }

    char opcao = '\0';

    do
    {
        //print_menu(); - implementar

        busca_opcao(&opcao);

        switch (opcao)
        {
        case 'p':
        case 'P':
        {
            /* listar riscos e prioridades:

                Ordem de Risco: 
                    A > B > C
                Lista de Prioridades:
                    - Risco maior e é até cinco anos mais novo;
                    - Risco igual/menor e é suficientemente mais velho.
                */
            break;
        }
        case 'c':
        case 'C':
        {
            cidadao_t c1 = {"Felipe", 24, 'N'};
            cadastra_cidadao(f, &c1);
            break;
        }
        case 'v':
        case 'V':
        {
            vacina_cidadao(f);
            break;
        }
        case 'l':
        case 'L':
        {
            imprime_fila_vacinacao(f);
            break;
        }
        case 'q':
        case 'Q':
        {
            printf("Saindo.\n");
            break;
        }
        default:
            printf("Opcao invalida. ");
        }

    } while (!encerra(opcao));

    destroi_fila_vacina(f);

    exit(0);
}

void busca_opcao(char *op)
{
    printf("Informe sua opcao: ");
    scanf(" %c%*c", op);
}

int encerra(const char op)
{
    return (op == 'q' || op == 'Q');
}