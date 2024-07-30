/*Exemplo fornecido pelo professor de como inserir, remover, imprimir e limpar pilhas

Pilhas:
- Estrutura do tipo FILO (first in last out)
- Possui um ponteiro denominado TOPO
- As operações acontecem sempre na mesma
extremidade da estrutura*/

#include <stdio.h>
#include <stdlib.h>

struct Pilha {
  int dado;
  struct Pilha *proximo;
};

void push(struct Pilha *&topo, int dado) {//função para inserir elementos na pilha

  struct Pilha *novo = (struct Pilha *)calloc(1, sizeof(struct Pilha));

  novo->dado = dado;
  novo->proximo = topo;
  topo = novo;
  printf("\nValor inserido na pilha");
}

int pop(struct Pilha *&topo) {//função para remover elementos da pilha
  struct Pilha *aux;
  int vlr = 0;
  aux = topo;
  vlr = aux->dado;
  topo = topo->proximo;
  free(aux);
  return vlr;
}

void consultar(struct Pilha *&topo) {//função para consultar elementos da pilha
  if (topo == NULL) {
    printf("\nPilha vazia");
  } else {
    printf("\nExibir pilha");
    struct Pilha *aux = topo;
    while (aux != NULL) {
      printf("\n%d", aux->dado);
      aux = aux->proximo;
    }
  }
}

void limparPilha(struct Pilha *&topo) {//função para limpar a pilha
  struct Pilha *aux = topo;
  while (aux != NULL) {
    topo = topo->proximo;
    free(aux);
    aux = topo;
  }
}

int main() {

  struct Pilha *topo = NULL;

  push(topo, 10);
  push(topo, 20);
  push(topo, 30);
  push(topo, 40);

  consultar(topo);

  // printf("\npop - %d\n",pop(topo));
  // printf("pop - %d\n",pop(topo));

  limparPilha(topo);
  consultar(topo);
  push(topo, 10);
  consultar(topo);
}
/*Outras operações
- peek: Consiste na leitura do valor
armazenado no topo da pilha, sem no entanto
removê-lo.
- isFull: Função utilizada para verificar se uma
pilha está cheia (ou seja, se não é mais
possível armazenar itens).
- isEmpty: Função que verifica se uma pilha
está vazia - ou seja, se não é possível
continuar a remover itens.*/
