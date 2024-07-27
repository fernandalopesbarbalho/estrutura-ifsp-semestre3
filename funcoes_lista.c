/*Faça um programa com as seguintes funções para uma lista simplesmente encadeada:

  a. Inserir no início
  b. Inserir no final
  c. Remover no início
  d. Remover no final
  e. Contar a quantidade de elementos da lista
  f. Buscar um elemento da lista
  g. Exibir todos os elementos da lista

No main faça um menu para que o usuário possa escolher as funções.*/

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

void inserirInicio(No** primeiro, int valor) { //função que insere um novo nó no início da lista
  No* novoNo = criarNo(valor);
  novoNo->proximo = *primeiro; //passa o antingo primeiro para o proximo do novo nó
  *primeiro = novoNo; //passa o novo valor para o primeiro
}

void inserirFim(No** primeiro, int valor) { //função que insere um novo nó no final da lista
  No* novoNo = criarNo(valor);
  if (*primeiro == NULL) { //verifica se a lista está vazia
    *primeiro = novoNo; //passa o novo valor para o primeiro
  } else {
    No* no = *primeiro;
    while (no->proximo != NULL) { //verifica o valor vazio para encontrar o último nó
      no = no->proximo;
    }
    no->proximo = novoNo; //atualiza o valor da lista com o novo elemento no fim da lista
  }
}

void removerInicio(No** primeiro) { //função que remove o primeiro nó da lista
  if (*primeiro != NULL) {
    No* temp = *primeiro;
    *primeiro = (*primeiro)->proximo; //atualiza o primeiro valor passando o valor do próximo
    printf("Número %d removido do início\n", temp->valor);
    free(temp);
  } else {
    printf("A lista está vazia\n");
  }
}

void removerFinal(No** primeiro) { //função que remove o último nó da lista
  if (*primeiro == NULL) {
    printf("A lista está vazia\n");
    return;
  }
  
  No* no = *primeiro;
  if (no->proximo == NULL) { //verifica o valor vazio para encontrar o último
    printf("Número %d removido no final\n", no->valor);
    free(no);
    *primeiro = NULL; 
    return;
  }
  
  No* penul = NULL; 
  while (no->proximo != NULL) { //encontra o penúltimo nó para transformar em último
    penul = no;
    no = no->proximo;
  }
  printf("Número %d removido no final\n", no->valor);
  free(no);
  penul->proximo = NULL;
}

int contarElementos(No* primeiro) { //função que conta a quantidade de elementos da lista
  int contador = 0;
  No* no = primeiro;
  while (no != NULL) { //enquanto o nó não for vazio é contabilizado no contador
    contador++;
    no = no->proximo;
  }
  return contador;
}

void buscarValor(No* primeiro, int valor) { //função para buscar um valor na lista
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

void exibirElementos(No* primeiro) { //imprime os valores dos nós
  if (primeiro == NULL) {
    printf("A lista está vazia\n");
    return;
  }
  
  No* no = primeiro;
  printf("Valores da lista encadeada: ");
  while (no != NULL) {
    printf("%d ", no->valor);
    no = no->proximo;
  }
  printf("\n");
}

int main(void) {
  No* primeiro = NULL;
  int opcao, valor;

  do {
    printf("\nMenu:\n");
    printf("Digite '1' | Inserir no início\n");
    printf("Digite '2' | Inserir no final\n");
    printf("Digite '3' | Remover no início\n");
    printf("Digite '4' | Remover no final\n");
    printf("Digite '5' | Contar a quantidade de elementos da lista\n");
    printf("Digite '6' | Buscar um elemento da lista\n");
    printf("Digite '7' | Exibir todos os elementos da lista\n");
    printf("Digite '0' | Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        printf("Digite o valor a ser inserido no início: ");
        scanf("%d", &valor);
        inserirInicio(&primeiro, valor);
        break;
      
      case 2:
        printf("Digite o valor a ser inserido no final: ");
        scanf("%d", &valor);
        inserirFim(&primeiro, valor);
        break;
      
      case 3:
        removerInicio(&primeiro);
        break;
      
      case 4:
        removerFinal(&primeiro);
        break;

      case 5:
        printf("A quantidade de elementos na lista é: %d\n", contarElementos(primeiro));
        break;

      case 6:
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &valor);
        buscarValor(primeiro, valor); 
        break;

      case 7:
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