#include <stdio.h>
#include <stdlib.h>
#include "atividade2.h"

Pilha* criarPilha(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha != NULL){
        pilha->topo = NULL;
        return pilha;
    }
    else{
        printf("Erro ao criar a pilha.\n");
        return NULL;
    }
}

int push(Pilha* pilha, Campo campo){
    if(pilha != NULL){
        Nodo* novoNodo = (Nodo*) malloc(sizeof(Nodo));
        if(novoNodo != NULL){
            novoNodo->campo = campo;
            novoNodo->proximo = pilha->topo;
            pilha->topo = novoNodo;
            printf("Valor empilhado: %d \n", campo.valor);
            return 1;
        }
        else{
            printf("Erro ao empilhar.\n");
        }
    }
    else{
        printf("Erro ao empilhar. Pilha nula.\n");
    }
    return 0;
}

void pop(Pilha* pilha){
    Campo CampoDesempilhado;

    if(pilha != NULL){
        if(pilha->topo == NULL){
            printf("Erro ao desempilhar. Pilha vazia.\n");
        }
        Nodo* nodoAuxiliar = pilha->topo;
        pilha->topo=nodoAuxiliar->proximo;

        printf("Valor desempilhado: %d\n", nodoAuxiliar->campo.valor);

        CampoDesempilhado = nodoAuxiliar->campo;
        free(nodoAuxiliar);
    }
    else{
        printf("Erro ao desempilhar. Pilha nula.\n");
    }
}
