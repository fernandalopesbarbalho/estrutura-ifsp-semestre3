/* A busca binária encontra uma chave x em um conjunto de dados ordenado. A ideia básica da busca binária é dividir o conjunto de dados ao meio repetidamente até encontrar o valor desejado, muito eficientee para encontrar valores em grandes conjuntos de dados, pois reduz pela metade o conjunto de dados a cada iteração.

O processo começa comparando o valor que se procura com o valor central do conjunto de dados. Se o valor procurado for menor que o valor central, a busca é repetida na metade esquerda do conjunto de dados. Se for maior, a busca é repetida na metade direita do conjunto de dados. Esse processo é repetido até que o valor procurado seja encontrado ou até que o conjunto de dados seja reduzido a um único elemento, o que significa que o valor procurado não está presente no conjunto.

Explicação: https://ruddabeltrao.medium.com/como-implementar-busca-bin%C3%A1ria-teoria-parte-1-c0733040d84b */

#include <stdio.h>

int buscaBinaria(int a[], int inicio, int fim, int x){
  int meio;

  if(inicio <= fim){
    meio = (fim + inicio)/2;
    if(x == a[meio]){
      return meio;
    }else{
      if(a[meio] < x){
        return buscaBinaria(a, meio + 1, fim, x);
      }else{
        return buscaBinaria(a, inicio, meio - 1, x);
      }
    }
  }else{
    return -1; //se não encontrar retorna -1
  }
}

int main(void) {
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("%d",buscaBinaria(a, 0, 9, 5)); //no vetor a, que inicia no 0 e termina no 9, o valor procurado é 5.
  
  return 0;
}