/* 1) Faça uma breve descrição do funcionamento do tipo de ordenação e
implemente em C uma função que receba (no mínimo) um vetor e realize a
ordenação solicitada para os itens abaixo:
  a. Seleção
  b. Bolha
  c. Intercalação (merge sort)
  d. Quick Sort */

#include <stdio.h>

// Na ordenação por seleção, o vetor é dividido em duas partes (ordenada e não ordenada), o código encontra o menor elemento da lista e troca com o primeiro elemento e segue para o segundo elemento até chegar ao último, realizando as trocas.

void ordenarSelecao(int vetor[], int n) { 
  for (int i = 0; i < n - 1; i++) { //percorre o vetor
    int comparador = vetor[i]; //seleciona um elemento para comparar e encontrar o menor
    int menor = vetor[i + 1];
    int pos = i + 1;

    for (int j = i + 1; j < n; j++) { //percorre os demais elementos para encontrar o menor
      if (vetor[j] < menor) {
        menor = vetor[j];
        pos = j;
      }
    } 

    if (menor < comparador) { //troca o elemento de comparação com o menor
      vetor[i] = vetor[pos];
      vetor[pos] = comparador;
    }
  }
}

// Na ordenação por bubble sort, o vetor é dividido em duas partes (ordenada e não ordenada), o elemento atual é comparado com o próximo e caso ele for maior, a troca é realizada.

void ordenarBolha(int vetor[], int n) {
  for (int i = 0; i < n - 1; i++) { //percorre o vetor
    for (int j = 0; j < n - i - 1; j++) { //percorre até o penúltimo elemento
      if (vetor[j] > vetor[j + 1]) { //troca os elementos de posição caso o atual seja maior que o próximo
        int comparador = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = comparador;
      }
    }
  }
}

// Na ordenação por merge sort é utilizada a técnica de divisão e conquista, busca dividir o vetor em dois até que cada sub-vetor contenha um único elemento. Em seguida, os elementos são comparados e ordenados em listas cada vez maiores, até chegar ao tamanho original do vetor.

void merge(int vetor[], int inicio, int meio, int fim) { //compara os sub-vetores e ordena
  int n = fim - inicio + 1;
  int vetor2[n];
  int i = inicio, j = meio + 1, posicao = 0;

  while (i <= meio && j <= fim) {
    if (vetor[i] < vetor[j]) {
      vetor2[posicao++] = vetor[i++];
    } else {
      vetor2[posicao++] = vetor[j++];
    }
  }

  while (i <= meio) {
    vetor2[posicao++] = vetor[i++];
  }
  while (j <= fim) {
    vetor2[posicao++] = vetor[j++];
  }

  for (i = inicio, posicao = 0; i <= fim; i++, posicao++) {
    vetor[i] = vetor2[posicao];
  }
}

void mergeSort(int vetor[], int inicio, int fim) { //divide o vetor em dois até que cada sub-vetor contenha um único elemento
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergeSort(vetor, inicio, meio); //chama a função para a parte esquerda
    mergeSort(vetor, meio + 1, fim); //chama a função para a parte direita
    merge(vetor, inicio, meio, fim); //chama a função merge para ordenar e juntar os sub-vetores
  }
}

void ordenarIntercalacao(int vetor[], int n) { //organiza os parâmetros recebidos e chama a função mergeSort
  mergeSort(vetor, 0, n - 1);
}

// Na ordenação por quick sort (particionamento) é escolhido qualquer número do vetor (chamado de pivô) e o coloca em uma posição tal que todos os elementos à esquerda são menores e todos os elementos à direita são maiores.

int particionar(int vetor[], int inicio, int fim) {
  int esquerda, direita, pivo, comparador;
  esquerda = inicio;
  direita = fim;
  pivo = vetor[inicio];
  
  while (esquerda < direita) {
    while (vetor[esquerda] <= pivo) { //percorre o lado esquerdo do pivô
      esquerda++;
    }
    
    while (vetor[direita] > pivo) { //percorre o lado direito do pivô
      direita--;
    }
    
    if (esquerda < direita) { //se a parte esquerda for menor que a direita, troca a parte esquerda com a direita
      comparador = vetor[esquerda];
      vetor[esquerda] = vetor[direita];
      vetor[direita] = comparador;
    }
  }
  
  vetor[inicio] = vetor[direita];
  vetor[direita] = pivo;
  return direita;
}

void quickSort(int vetor[], int inicio, int fim) {
  int pivo;
  if (inicio < fim) {
    pivo = particionar(vetor, inicio, fim); //particiona em 2 partes
    quickSort(vetor, inicio, pivo - 1); //chama a função para a parte esquerda
    quickSort(vetor, pivo + 1, fim); //chama a função para a parte direita
  }
}

void ordenarQuickSort(int vetor[], int n) { //organiza os parâmetros recebido e chama a função quickSort
  quickSort(vetor, 0, n - 1);
}

void imprimirVetor(int vetor[], int n) { //função para imprimir o vetor
  for (int i = 0; i < n; i++) {
    printf(" %d ", vetor[i]);
  }
  printf("\n");
}

int main(void) {
  int a[] = {4, 9, -5, 7, 2, 8, 14, 11, 0};

  printf("Antes da ordenação:");
  imprimirVetor(a, 9);
  ordenarSelecao(a, 9);
  printf("Ordenação por seleção:");
  imprimirVetor(a, 9);

  int b[] = {2, 9, 5, 7, 1, 8, -14, 11, 10};

  printf("\nAntes da ordenação:");
  imprimirVetor(b, 9);
  ordenarBolha(b, 9);
  printf("Ordenação por bolha:");
  imprimirVetor(b, 9);

  int c[] = {1, 8, -3, 2, 2, 6, 13, 11, 0};

  printf("\nAntes da ordenação:");
  imprimirVetor(c, 9);
  ordenarIntercalacao(c, 9);
  printf("Ordenação por intercalação:");
  imprimirVetor(c, 9);

  int d[] = {4, 7, -5, 1, 2, 8, 10, 11, 9};

  printf("\nAntes da ordenação:");
  imprimirVetor(d, 9);
  ordenarQuickSort(d, 9);
  printf("Ordenação por quick sort:");
  imprimirVetor(d, 9);

  return 0;
}
