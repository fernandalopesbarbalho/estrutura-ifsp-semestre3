/* O insertion sort divide a lista em duas partes, uma ordenada e a outra desordenada. Assim, ele vai pegando sempre o primeiro elemento da lista desordenada e colocando em sua posição correta na lista ordenada. Esse processo ocorre até que a lista esteja completamente ordenada. 

Explicação: https://www.estrategiaconcursos.com.br/blog/algoritmo-ordenacao-insercao/ */

#include <stdio.h>

void ordenarPorInsercao(int a[], int n){
  if(n >= 0){
    ordenarPorInsercao(a, n - 1);
    int i = n;
    while(i >= 1 && a[i] < a[i-1]){
      int aux = a[i];
      a[i] = a[i-1];
      a[i-1] = aux;
      i--;
    }
  }
}

int main(void) {
  int a[] = {4, 0, -1, 3, 2};

  ordenarPorInsercao(a, 5);

  for(int i = 0; i < 5; i++){
    printf(" %d ", a[i]);
  }

  return 0;
}