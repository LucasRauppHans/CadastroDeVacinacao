#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
            // montar um cidadao a partir
            // de entradas do usuario

            /* testes:
            cidadao_t c1 = {"Felipe",  24, 'N'};
            cidadao_t c2 = {"Matheus", 24, 'C'};
            cidadao_t c6 = {"Lucas",   24, 'B'};
            cidadao_t c3 = {"Bianca",  18, 'B'};
            cidadao_t c4 = {"João",    30, 'C'};
            cidadao_t c5 = {"Paulo",   82, 'N'};
            cadastra_cidadao(f, &c1);
            cadastra_cidadao(f, &c2);
            cadastra_cidadao(f, &c3);
            cadastra_cidadao(f, &c4);
            cadastra_cidadao(f, &c5);
            cadastra_cidadao(f, &c6);
            */

            cidadao_t c;
            char input;
            
            do {
                printf("Deseja adicionar um novo cidadão ao banco? [y/n] ");
                scanf(" %c%*c", &input);

                if (input == 'y') {
                    printf("Informe o nome do cidadao : ");
                    scanf("%s", c.nome);
                    printf("Informe a idade : ");
                    scanf("%hu", &c.idade);
                    printf("Selecione o grupo de Risco: (a) Tipo A (b) Tipo B (c) Tipo C (n) Nenhum : ");
                    fflush(stdin);
                    do {
                        scanf(" %c%*c", &input);
                    } while ( input != 'a' && input != 'b' && input != 'c' && input != 'n' );
                    c.grupo_de_risco = toupper(input);
                    cadastra_cidadao(f, &c);
                }
            } while (input != 'n');   
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

void busca_opcao(char *op) {
    printf("Informe sua opcao : ");
    scanf (" %c%*c", op);
}

int encerra(const char op)
{
    return (op == 'q' || op == 'Q');
}