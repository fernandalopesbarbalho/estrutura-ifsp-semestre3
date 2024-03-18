/* Crie uma estrutura (registro) representando os alunos do curso de Estrutura de Dados. A estrutura deve conter o número de matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.

Construa um menu em linguagem C que atenda os seguintes requisitos:

(a) permita ao usuário entrar com os dados de 5 alunos (vetor).
(b) encontre o aluno com maior nota da primeira prova.
(c) encontre o aluno com maior média geral.
(d) encontre o aluno com menor média geral
(e) para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação. */

#include <stdio.h>

struct Aluno {
  int matricula;
  char nome[50];
  int nota1;
  int nota2;
  int nota3;
};

struct Aluno receberDados() {
  struct Aluno a;

  printf("\n");
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &a.matricula);

  printf("Digite o nome do aluno: ");
  scanf("%s", a.nome);

  printf("Digite a nota da primeira prova: ");
  scanf("%d", &a.nota1);

  printf("Digite a nota da segunda prova: ");
  scanf("%d", &a.nota2);

  printf("Digite a nota da terceira prova: ");
  scanf("%d", &a.nota3);

  return a;
}

void verificarMaiorNota1(struct Aluno grupo[], int tamanho) {
  int maiorNota = -1;
  int aluno = -1;

  for (int i = 0; i < tamanho; i++) {
    if (grupo[i].nota1 > maiorNota) {
      maiorNota = grupo[i].nota1;
      aluno = i;
    }
  }

  printf("\n%s está com a maior nota na primeira prova: %d\n", grupo[aluno].nome, grupo[aluno].nota1);
}

void verificarMaiorMedia(struct Aluno grupo[], int tamanho) {
  float mediaMaior = -1;
  int aluno = -1;

  for (int i = 0; i < tamanho; i++) {
    float media = (grupo[i].nota1 + grupo[i].nota2 + grupo[i].nota3) / 3.0;
    if (media > mediaMaior) {
      mediaMaior = media;
      aluno = i;
    }
  }

  printf("\n%s está com a maior média: %.2f\n", grupo[aluno].nome, mediaMaior);
}

void verificarMenorMedia(struct Aluno grupo[], int tamanho) {
  float mediaMenor = 1000;
  int aluno = -1;

  for (int i = 0; i < tamanho; i++) {
    float media = (grupo[i].nota1 + grupo[i].nota2 + grupo[i].nota3) / 3.0;
    if (media < mediaMenor) {
      mediaMenor = media;
      aluno = i;
    }
  }

  printf("\n%s está com a menor média:  %.2f\n", grupo[aluno].nome, mediaMenor);
}

void verificarAprovados(struct Aluno grupo[], int tamanho) {
  printf("\n");
  for (int i = 0; i < tamanho; i++) {
    float media = (grupo[i].nota1 + grupo[i].nota2 + grupo[i].nota3) / 3.0;
    if (media >= 6) {
      printf("%s está: aprovado(a)\n", grupo[i].nome);
    } else {
      printf("%s está: reprovado(a)\n", grupo[i].nome);
    }
  }
}

int main(void) {
  struct Aluno grupo[5];

  for(int i = 0; i < 5; i++){
    grupo[i] = receberDados();
  }

  verificarMaiorNota1(grupo, 5);
  verificarMaiorMedia(grupo, 5);
  verificarMenorMedia(grupo, 5);
  verificarAprovados(grupo, 5);

  return 0;
}