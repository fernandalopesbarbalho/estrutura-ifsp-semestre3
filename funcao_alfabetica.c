/* 2) Faça um programa em C para colocar os nomes dos alunos da turma em
ordem alfabética. Implemente, se possível, mais de uma estratégia de
ordenação se não justifique os motivos que o impediram de implementar. */

#include <stdio.h>
#include <string.h> //biblioteca para manipular strings

void bubbleSort(char nomes[][50], int n) { //ordenação por bubble sort
  char nomes2[50];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(nomes[j], nomes[j + 1]) > 0) {
        strcpy(nomes2, nomes[j]);
        strcpy(nomes[j], nomes[j + 1]);
        strcpy(nomes[j + 1], nomes2);
      }
    }
  }
}

void insercao(char nomes[][50], int n) { //ordenação por inserção
  char nomes2[50];
  for (int i = 1; i < n; i++) {
    strcpy(nomes2, nomes[i]);
    int j = i - 1;
    while (j >= 0 && strcmp(nomes[j], nomes2) > 0) {
      strcpy(nomes[j + 1], nomes[j]);
      j--;
    }
  strcpy(nomes[j + 1], nomes2);
  }
}

void imprimirVetor(char nomes[][50], int n) { //função para imprimir os vetores
  for (int i = 0; i < n; i++) {
    printf("%s\n", nomes[i]);
  }
}

int main(void) {
  char listaNomes1[15][50] = {"João", "Bruno", "Pedro", "Beatriz", "Lucas", "Maria", "Daniel", "Julia", "Denize", "Gabriel", "Ana", "Heitor", "Mariana", "Fernanda", "Raphael"};

  printf("Antes da ordenação: \n");
  imprimirVetor(listaNomes1, 15);
  
  bubbleSort(listaNomes1, 15);
  printf("\nOrdenação por bubble sort: \n");
  imprimirVetor(listaNomes1, 15);

  char listaNomes2[15][50] = {"Amanda", "Isabely", "Pietra", "Zara", "Michele", "Davi", "Felipe", "James", "Xavier", "Guilherme", "Alice", "Livia", "Nicolas", "Vivian", "Vanessa"};

  printf("\nAntes da ordenação: \n");
  imprimirVetor(listaNomes2, 15);
  
  insercao(listaNomes2, 15);
  printf("\nOrdenação por inserção: \n");
  imprimirVetor(listaNomes2, 15);

  return 0;
}
