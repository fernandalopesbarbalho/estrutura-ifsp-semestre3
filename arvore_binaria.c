/*Baseando-se na aula anterior (a aula do sábado letivo) faça um programa para
manipular árvores binárias. Lembrando que a estrutura de um nó deve ser: struct
Noh
{
int dado;
struct Noh *esquerda;
struct Noh *direita;
};

Partindo de um nó que deve ser a raiz da árvore (Noh *raiz;) adicione mais dados
(nós em sua árvore para efetuar os testes)  e implemente:
1. Uma função para cada tipo de percurso: pré ordem, em ordem e pós ordem.
2. Escreva uma função que conte o número de nós de uma árvore binária.
3. Escreva uma função para achar o MAIOR valor em uma árvore binária não
ordenada.
4. Escreva uma função que conte o número de folhas de uma árvore binária.*/

#include <stdio.h>
#include <stdlib.h>

struct Noh { //estrutura do nó da árvore
  int dado;
  struct Noh *esquerda;
  struct Noh *direita;
};

struct Noh *novoNoh(int dado) { //função que cria um novo nó
  struct Noh *noh = (struct Noh *)malloc(sizeof(struct Noh));
  noh->dado = dado;
  noh->esquerda = NULL;
  noh->direita = NULL;
  return noh;
}

struct Noh *adicionarNoh(struct Noh *raiz, int dado) { //função que adiciona um novo nó na árvore
  if (raiz == NULL) { //se a raiz estiver vazia, o nó vira a raiz
    return novoNoh(dado);
  }

  if (dado < raiz->dado) { //se o dado for menor que a raiz, adiciona na esquerda
    raiz->esquerda = adicionarNoh(raiz->esquerda, dado);
  } else { //se o dado for maior que a raiz, adiciona na direita
    raiz->direita = adicionarNoh(raiz->direita, dado);
  }
  return raiz;
}

void percursoPreOrdem(struct Noh *raiz) { //função para percurso pré ordem
  if (raiz != NULL) {
    printf("%d ", raiz->dado); //imprime a raiz
    percursoPreOrdem(raiz->esquerda); //chama a função recursivamente para imprimir a esquerda
    percursoPreOrdem(raiz->direita); //chama a função recursivamente para imprimir a direita
  }
}

void percursoEmOrdem(struct Noh *raiz) { //função para percurso em ordem
  if (raiz != NULL) {
    percursoEmOrdem(raiz->esquerda); //chama a função recursivamente para imprimir a esquerda
    printf("%d ", raiz->dado); //imprime a raiz
    percursoEmOrdem(raiz->direita); //chama a função recursivamente para imprimir a direita
  }
}

void percursoPosOrdem(struct Noh *raiz) { //função para percurso pós ordem
  if (raiz != NULL) {
    percursoPosOrdem(raiz->esquerda); //chama a função recursivamente para imprimir a esquerda
    percursoPosOrdem(raiz->direita); //chama a função recursivamente para imprimir a direita
    printf("%d ", raiz->dado); //imprime a raiz
  }
}

int contarNos(struct Noh* raiz) { //função para contar o número de nós
  if (raiz == NULL) { //se a raiz estiver vazia, retorna 0
    return 0;
    } else {
      return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita); //soma a raiz e os nós da esquerda e direita
    }
}

int encontrarMaior(struct Noh* raiz) { //fução para encontrar o maior valor
  if (raiz == NULL) { //se a raiz estiver vazia, retorna -1
    return -1; 
  }

  int maior = raiz->dado; //inicializa o maior valor com o valor da raiz
  int maiorEsquerda = encontrarMaior(raiz->esquerda);
  int maiorDireita = encontrarMaior(raiz->direita); //mesmo que neste código em específico o maior valor sempre estará na direita, será procurado na esquerda também, pois a função deve funcionar em árvores não ordendas

  if (maiorEsquerda > maior) {
    maior = maiorEsquerda;
    }

  if (maiorDireita > maior) {
    maior = maiorDireita;
  }
  return maior;
}

int contarFolhas(struct Noh* raiz) { //função para contar o número de folhas
  if (raiz == NULL) { //se a raiz estiver vazia, retorna 0
    return 0;
  }
  
  if (raiz->esquerda == NULL && raiz->direita == NULL) { //se a raiz não tiver filhos, ela é uma folha
    return 1;
  }
  return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita); //soma o número de folhas da esquerda e da direita
}

int main(void) { 
  struct Noh *raiz = NULL;

  //inserindo dados na árvore
  raiz = adicionarNoh(raiz, 7);
  raiz = adicionarNoh(raiz, 4);
  raiz = adicionarNoh(raiz, 2);
  raiz = adicionarNoh(raiz, 9);
  raiz = adicionarNoh(raiz, 1);
  raiz = adicionarNoh(raiz, 13);
  raiz = adicionarNoh(raiz, 6);
  raiz = adicionarNoh(raiz, 10);

  printf("Percurso em pré-ordem: ");
  percursoPreOrdem(raiz);
  printf("\n");

  printf("Percurso em ordem: ");
  percursoEmOrdem(raiz);
  printf("\n");

  printf("Percurso em pós-ordem: ");
  percursoPosOrdem(raiz);
  printf("\n");

  printf("Número de nós: %d\n", contarNos(raiz));
  printf("Maior valor: %d\n", encontrarMaior(raiz));
  printf("Número de folhas: %d\n", contarFolhas(raiz));
  
  return 0; 
}