/* Escreva uma função que faça uma busca em uma lista duplamente encadeada.*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct No { //cria a estrutura do nó em uma lista duplamente encadeada
  int valor;
  struct No* proximo;
  struct No* anterior;
} No;

No* criarNo(int valor) { //função que cria um novo nó
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->valor = valor;
  novoNo->proximo = NULL;
  novoNo->anterior = NULL;
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

void buscarValor(No* primeiro, int valor) { //função para buscar um valor na lista duplamente encadeada
  No* no = primeiro;
  while (no != NULL) {
    if (no->valor == valor) { //verifica se o valor do nó é igual ao valor procurado
      printf("Valor %d encontrado na lista\n", valor);
      return;
    }
    no = no->proximo;
  }
  printf("Valor %d não encontrado na lista\n", valor);
}

int main(void) {
  //criação da lista duplamente encadeada chamando a função criarNo
  No* primeiro = criarNo(1);
  No* segundo = criarNo(2);
  No* terceiro = criarNo(3);
  No* quarto = criarNo(4);
  No* quinto = criarNo(5);

  //conectando os nós
  primeiro->proximo = segundo;
  segundo->anterior = primeiro;
  segundo->proximo = terceiro;
  terceiro->anterior = segundo;
  terceiro->proximo = quarto;
  quarto->anterior = terceiro;
  quarto->proximo = quinto;
  quinto->anterior = quarto;

  printf("Valores da lista duplamente encadeada: "); //chama a função para imprimir os valores dos nós
  imprimir(primeiro);

  buscarValor(primeiro, 4); //chama a função para buscar o valor na lista
  buscarValor(primeiro, 0);
  
  return 0;
}