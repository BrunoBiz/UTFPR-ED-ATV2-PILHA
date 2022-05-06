typedef struct{
    int valor;
}Campo;

typedef struct{
    Campo campo;
    struct nodo* proximo;
}Nodo;

typedef struct{
    struct Nodo* topo;
}Pilha;

Pilha* criarPilha();
void destruirPilha(Pilha** pilha);
int push(Pilha* pilha, Campo campo);
void pop(Pilha* pilha);
