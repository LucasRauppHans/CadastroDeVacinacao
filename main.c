#include <stdio.h>
#include "vacinacao/vacinacao.h"

void busca_opcao(char *op);
void print_menu();
int  encerra(const char op);

int main(void) {
    
    system("cls||clear");

    char opcao = '\0';

    fila_vacina *f = nova_fila_vacina();
    
    do {
        //print_menu(); - implementar

        busca_opcao(&opcao);

        switch (opcao) {
            case 'p':
            case 'P': {
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
            case 'C': {
                // montar um cidadao a partir
                // de entradas do usuario

                // testes:
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
                break;
            }
            case 'v':
            case 'V': {
                vacina_cidadao(f);
                break;
            }                
            case 'l':
            case 'L': {
                imprime_fila_vacinacao(f);
                break;
            }
            case 'q':
            case 'Q': {
                printf("Saindo.\n");
                break;
            }
            default: printf("Opcao invalida. ");
        }

    } while ( !encerra(opcao) );

    destroi_fila_vacina(f);

    exit(0);
}

void busca_opcao(char *op) {
    printf("Informe sua opcao: ");
    scanf (" %c%*c", op);
}

int encerra(const char op) {
    return (op == 'q' || op == 'Q');
}