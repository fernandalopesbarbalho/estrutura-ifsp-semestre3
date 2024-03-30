/* 1) Implemente em linguagem C um dos algoritmos de ordenação apresentados na aula. 

2) O vetor V abaixo deve ser colocado em ordem crescente escolha um dos métodos apresentados em sala para isso.

a) Preencha a tabela com todos os resultados intermediários da operação.

Vetor original V: 40, 30, 15, 5, 100, 25, 65, 145

b) Apresente os passos necessários utilizando a busca binária para localizar as chaves: 65 e 300. */

#include <stdio.h>

int main(void) {

  int v[8] = {40, 30, 15, 5, 100, 25, 65, 145};

  //ordenação bubblesort
  int i, aux, contador = 0;

  for (contador = 1; contador < 8; contador++) {
    for (i = 0; i < 8 - 1; i++){
      if (v[i] > v[i + 1]) {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }
  
  printf("Vetor em ordem crescente:\n");
  for (i = 0; i < 8; i++) {
    printf("%d ", v[i]);
  }

  //busca binária
  int ini = 0, fim = 8 - 1, meio, chave = 65;

  do {
    meio = (ini + fim) / 2;
    if (chave < v[meio]) {
      fim = meio - 1;
    } else if (chave > v[meio]) {
      ini = meio + 1;
    }
  } while (chave != v[meio] && ini <= fim);
  
  if (chave == v[meio]) {
    printf("\nA chave %d está na posição %d do vetor.", chave, meio);
  } else {
    printf("\nA chave %d não foi encontrada.", chave);
  }

  
  ini = 0;
  fim = 8 - 1;
  chave = 300;
  do {
    meio = (ini + fim) / 2;
    if (chave < v[meio]) {
      fim = meio - 1;
    } else if (chave > v[meio]) {
      ini = meio + 1;
    }
  } while (chave != v[meio] && ini <= fim);

  if (chave == v[meio]) {
    printf("\nA chave %d está na posição %d do vetor.", chave, meio);
  } else {
    printf("\nA chave %d não foi encontrada.", chave);
  }

  return 0;
}