/* Crie, baseando-se nas aulas de listas até o momento, um programa que implemente uma fila (utilize C ou C++).
Deve existir um menu com as opções para adicionar um novo elemento e remover.
Você também deverá implementar o tamanho da fila (recebendo ou não esse valor do usuário) e a cada inclusão verificar se a lista já está cheia.

Filas
- Estrutura do tipo FIFO (first in first out)
Possui os ponteiros:
- Início: remoções
- Fim: inserções*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No { //cria a estrutura do nó
  int valor;
  struct No *proximo;
} No;

No *criarNo(int valor) { //função que cria um novo nó
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->valor = valor;
  novoNo->proximo = NULL;
  return novoNo;
}

void inserirFim(No **primeiro, int valor, int *tamanhoAtual, int tamanhoMaximo) { //operação Enqueue (inserir)
  if (*tamanhoAtual >= tamanhoMaximo) {
    printf("Não foi possível adicionar, pois a fila está cheia.\n");
    return;
  }
  No *novoNo = criarNo(valor); //cria um novo nó
  if (*primeiro == NULL) {
    *primeiro = novoNo; //caso a fila esteja vazia, o novo nó é o primeiro
  } else {
    No *no = *primeiro;
    while (no->proximo != NULL) { //percorre a fila até o último nó
      no = no->proximo;
    }
    no->proximo = novoNo; //o último nó aponta para o novo nó que foi inserido
  }
  (*tamanhoAtual)++; //atualiza o tamanho da fila usando ponteiro
}

void removerInicio(No **primeiro, int *tamanhoAtual) { //operação Dequeue (remover)
  if (*primeiro == NULL) {
    printf("Não foi possível remover, pois a fila está vazia.\n");
    return;
  }
  No *temp = *primeiro; //armazena o nó que vai ser removido
  *primeiro = (*primeiro)->proximo; //o próximo nó vira o primeiro
  printf("Número %d removido do início.\n", temp->valor);
  free(temp); //libera a memória do nó removido
  (*tamanhoAtual)--; //atualiza o tamanho da fila usando ponteiro
}

void exibirElementos(No *primeiro) { //imprimir a fila
  if (primeiro == NULL) {
    printf("A fila está vazia.\n");
    return;
  }
  No *no = primeiro;
  printf("Valores da fila: ");
  while (no != NULL) {
    printf("%d ", no->valor); //imprime o valor do nó atual
    no = no->proximo; //avança para o próximo nó
  }
  printf("\n");
}

void exibirTamanho(int tamanhoAtual, int tamanhoMaximo) {
  printf("A fila possui %d elementos e seu tamanho máximo é %d.\n", tamanhoAtual, tamanhoMaximo);
}

int main(void) {
  No *primeiro = NULL;
  int opcao, valor, tamanhoMaximo, tamanhoAtual;

  printf("Digite o tamanho máximo da fila: ");
  scanf("%d", &tamanhoMaximo);
  tamanhoAtual = 0;

  do {
    printf("\nMenu:\n");
    printf("Digite '1' | Inserir no final\n");
    printf("Digite '2' | Remover no início\n");
    printf("Digite '3' | Exibir todos os elementos da fila\n");
    printf("Digite '0' | Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Digite o valor a ser inserido no final: ");
      scanf("%d", &valor);
      inserirFim(&primeiro, valor, &tamanhoAtual, tamanhoMaximo);
      exibirTamanho(tamanhoAtual, tamanhoMaximo);
      break;

    case 2:
      removerInicio(&primeiro, &tamanhoAtual);
      exibirTamanho(tamanhoAtual, tamanhoMaximo);
      break;

    case 3:
      exibirElementos(primeiro);
      break;

    case 0:
      printf("Fim da operação.\n");
      break;

    default:
      printf("Erro. Insira apenas os números listados acima.\n");
    }
  } while (opcao != 0);

  return 0;
}