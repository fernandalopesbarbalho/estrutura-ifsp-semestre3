/* 1. Dada a seguinte estrutura Aluno com os campos: Matrícula (número inteiro), Nome (60 caracteres), I.R.A - Índice de Rendimento Acadêmico (número com ponto flutuante).

  1. Implemente um programa em C ou C++ que receba os dados de 10 alunos e os armazene em um vetor.

  2. O programa deverá exibir os alunos por ordem de matrícula - implemente a ordenação utilizando o método da seleção ou inserção.

  3. Ordene e mostre o vetor ordenado pelo IRA - implemente a ordenação pelo método da bolha.

É importante comentar o código e explicar as etapas de implementação. */

#include <stdio.h>

struct Aluno {
  int matricula;
  char nome[60];
  float ira;
};

//função para receber os dados
struct Aluno receberDados() {
  struct Aluno aluno;

  //recebe os dados do aluno
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &aluno.matricula);

  printf("Digite o nome do aluno: ");
  scanf("%s", aluno.nome);

  printf("Digite o IRA do aluno: ");
  scanf("%f", &aluno.ira);

  return aluno;
};

//função para ordenar por seleção
void ordenarMatricula(struct Aluno aluno[], int tam) {
  for (int i = 0; i < tam - 1; i++) {
    int menor = i;
    for (int j = i + 1; j < tam; j++) {
      if (aluno[j].matricula < aluno[menor].matricula) {
        menor = j;
      }
    }
    //troca de posição
    struct Aluno aux = aluno[i];
    aluno[i] = aluno[menor];
    aluno[menor] = aux;
  }
}

//função para ordenar por bolha
void ordenarIra(struct Aluno aluno[], int tam) {
  for (int i = 0; i < tam - 1; i++) {
    for (int j = 0; j < tam - i - 1; j++) {
      if (aluno[j].ira > aluno[j + 1].ira) {
        //troca de posição
        struct Aluno aux = aluno[j];
        aluno[j] = aluno[j + 1];
        aluno[j + 1] = aux;
      }
    }
  }
}

//função para exibir os dados
void exibirDados(struct Aluno aluno[], int tam) {
  for (int i = 0; i < tam; i++){
    printf("Matrícula: %d, Nome: %s, IRA: %.2f\n", aluno[i].matricula, aluno[i].nome, aluno[i].ira);
  }
}

int main(void) {
  struct Aluno aluno[10];

  //loop para receber os dados dos alunos
  for (int i = 0; i < 10; i++) {
    aluno[i] = receberDados();
    printf("\n");
  }

  //chama a função para ordenar por matrícula
  ordenarMatricula(aluno, 10);
  printf("Alunos ordenados por matrícula:\n");
  exibirDados(aluno, 10);
  
  //chama a função para ordenar por IRA
  ordenarIra(aluno, 10);
  printf("\nAlunos ordenados por IRA:\n");
  exibirDados(aluno, 10);
  
  return 0;
}
