#include "atividade2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MenuPrincipal();
void EmpilharValor(Pilha* Pilha);
void DesempilharValor(Pilha* Pilha);
void LimparTela();
void ImpressaoPilha(Pilha* pilha);

int main()
{
    int Menu;
    Pilha* pilha = criarPilha();

    do {
        LimparTela();
        MenuPrincipal();
        Menu = 0;
        scanf("%d", &Menu);

        switch (Menu)
        {
            /* SAI DO MENU */
                case 9:
                break;

            /* EMPILHAR */
                case 1:
                    EmpilharValor(pilha);
                    break;

            /* DESEMPILHAR */
                case 2:
                    DesempilharValor(pilha);
                    break;

            /* IMPRESSÃO */
                case 3:
                    ImpressaoPilha(pilha);
                    break;

            /* OPCAO INVALIDA */
                default:
                    printf("Opcao Invalida\n");
                    fflush(stdin);
                    break;
        }

    }while (Menu != 9);

    return 0;
}


void MenuPrincipal(){
    printf("X-- Atividade 2 ------------X\n");
    printf("| 1 - Empilhar valor        |\n");
    printf("| 2 - Desempilhar valor     |\n");
    printf("| 3 - Impressao             |\n");
    printf("|                           |\n");
    printf("| 9 - Sair                  |\n");
    printf("X---------------------------X\n");
}


void EmpilharValor(Pilha* pilha){
    Campo NovoCampo;

    LimparTela();
    printf("X-----------------------X\n");
    printf("| Valor a ser empilhado |\n");
    printf("X-----------------------X\n");
    scanf("%d", &NovoCampo.valor);
    fflush(stdin);

    push(pilha, NovoCampo);

    printf("\nPressione ENTER para continuar...\n");
    getch();
    fflush(stdin);
}

void DesempilharValor(Pilha* pilha){
    Campo CampoDesempilhado;

    LimparTela();

    printf("X-------------X\n");
    printf("| Desempilhar |\n");
    printf("X-------------X\n");

    pop(pilha);

    printf("\nPressione ENTER para continuar...\n");
    getch();
    fflush(stdin);
}


void ImpressaoPilha(Pilha* pilha){
    if(pilha != NULL){

        Nodo* nodo;
		nodo = pilha->topo;

        while(nodo != NULL){
			printf("%d\n", nodo->campo.valor);
			nodo = nodo->proximo;
/*
			nodo = (*pilha)->topo;
            (*pilha)->topo = nodo->proximo;
            free(nodo);
*/
		}
    }else{
        printf("Pilha vazia.\n");
    }

    printf("\nPressione ENTER para continuar...\n");
    getch();
    fflush(stdin);
}


void LimparTela(){
    #ifdef _WIN32
    system("cls");

    #elif __linux__
    system("clear");

    #endif
}
