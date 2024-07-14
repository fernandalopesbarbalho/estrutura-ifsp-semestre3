/* Uma função que realiza uma busca para encontrar uma chave x em um vetor de inteiros. Caso não encontre, retorna -1.

Um programa recursivo é um programa que chama a si mesmo. */

#include <stdio.h>

int buscaLinear(int a[], int n, int x){
  if(n == 0){
    return -1; //se não encontrar retorna -1
  }else{
    if(x == a[n-1]){
      return n-1;
    }else{
      return buscaLinear(a, n-1, x);
    }
  }
}

int main(void) {
  int a[] = {3, 0, 7, -1, 2, 10};

  printf("%d", buscaLinear(a, 6, 7)); //no vetor a, de tamanho 6(-1), busca o valor 7.

  return 0;
}
