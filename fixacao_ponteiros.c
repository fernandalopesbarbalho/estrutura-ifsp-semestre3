/* 1) Como seriam, em linguagem C, as declarações de ponteiros para as seguintes estruturas de dados:

a) uma variável do tipo int
b) uma variável do tipo double
c) uma variável do tipo char
d) uma variável do tipo struct Hora { int hora; int minuto; int segundo; }
e) uma variável do tipo double * (um ponteiro para double) 

2) Utilizando apenas operações primitivas, escreva o pseudocódigo de um programa que recebe uma cadeia de caracteres pelo teclado e exibe na tela a cadeia invertida. Por exemplo, se a cadeia informada é “ABCD”, será mostrada na tela a cadeia “DCBA”. */

#include <stdio.h>

int main(void) {
  int * xPrt;

  double * yPrt;

  char * zPrt;

  struct Hora {
    int hora; 
    int minuto; 
    int segundo;
  };
  
  struct Hora * hPtr;

  double ** wPrt;

  /*
  2)
  Função InverterVetor(string):
    Declare um inteiro comprimento = tamanho(string)
    Para cada índice de i = comprimento - 1 até 0, decrementando:
      Imprima string[i]

  Função Principal:
    Declare uma string de caracteres

    Imprima "Digite uma cadeia de caracteres: "
      Receba string

    Imprima "A cadeia invertida é: "
      Chame a função InverterVetor(string)
  */

  return 0;
}