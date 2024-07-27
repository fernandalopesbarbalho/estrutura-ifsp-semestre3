/*Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No { //cria a estrutura do nó em uma lista simplesmente encadeada
    int valor;
    struct No* proximo;
} No;

No* criarNo(int valor) { //função que cria um novo nó
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void imprimir(No* primeiro) { //imprime os valores dos nós
    No *no = primeiro;
    while (no != NULL) {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n");
}

void verificarOrdenacao(No* primeiro) { //função que ve se a lista está em ordem crescente
    if (primeiro != NULL) { //verifica se não está vazio
        No* no = primeiro;
        while (no->proximo != NULL) { //enquanto o valor não for vazio ocorre o loop
            if (no->valor > no->proximo->valor) { //verifica se o valor do nó atual é maior que o próximo
                printf("A lista não está ordenada\n");
                return;
            }
            no = no->proximo;
        }
    }
    printf("A lista está ordenada\n");
}

int main(void) {
    //criação da lista encadeada chamando a função criarNo
    No* primeiro = criarNo(1);
    No* segundo = criarNo(2);
    No* terceiro = criarNo(3);
    No* quarto = criarNo(4);
    No* quinto = criarNo(5);

    //conectando os nós
    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = quarto;
    quarto->proximo = quinto;
    quinto->proximo = NULL;
    
    printf("Valores da lista encadeada: "); //chama a função para imprimir os valores dos nós
    imprimir(primeiro);

    verificarOrdenacao(primeiro); //chama a função para verificar se a lista está ordenada
    
    return 0;
}
