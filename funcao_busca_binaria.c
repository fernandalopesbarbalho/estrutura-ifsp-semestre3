/* 3) Crie uma função recursiva para realizar uma busca binária para encontrar
uma chave x em um vetor de inteiros. */

#include <stdio.h>

int buscaBinaria(int vetor[], int inicio, int fim, int chaveX) {
  if (inicio <= fim) {
    int meio = (inicio + fim) / 2;
    
    if (chaveX == vetor[meio]) { //se a chave for igual ao número da posição do meio, ela já foi encontrada
      return meio;
      
    } else if (vetor[meio] < chaveX) {
        return buscaBinaria(vetor, meio + 1, fim, chaveX); //se a chave for maior que o número da posição do meio, a busca será do lado direito do vetor
        
      } else {
        return buscaBinaria(vetor, inicio, meio-1, chaveX); //se a chave for menor que o número da posição do meio, a busca será do lado esquerdo do vetor
      }
    
  } else {
    return -1; //se a chave não for encontrada, retorna -1
  }
}

void imprimirVetor(int vetor[], int n) { //função para imprimir o vetor
  for (int i = 0; i < n; i++) {
    printf(" %d ", vetor[i]);
  }
  printf("\n");
}

int main(void) {
  int vetor[] = {1, 3, 4, 5, 6, 7, 9, 10, 13};
  
  printf("O vetor é:");
  imprimirVetor(vetor, 9);

  printf("\nA chave X procurada é o número: %d\n", 9);
  printf("\nA chave X está na posição: %d\n", buscaBinaria(vetor, 1, 13, 9));
  
  printf("\nA chave X procurada é o número: %d\n", 0);
  printf("\nA chave X está na posição: %d", buscaBinaria(vetor, 1, 13, 0));

  return 0;
}
