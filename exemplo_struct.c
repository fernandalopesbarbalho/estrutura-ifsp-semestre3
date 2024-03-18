/* Declarar uma estrutura para armazenar o nome e idade de uma pessoa:
- Construa uma função que solicite os dados da
pessoa ao usuário. A função deverá retornar um
tipo pessoa.
- Escreva um procedimento para exibir os dados de
uma pessoa (receba um parâmetro do tipo
pessoa) */

#include <stdio.h>

struct Pessoa {
  char nome[50];
  int idade;
};

struct Pessoa receberDados() {

  struct Pessoa p;

  // receber o nome da pessoa
  printf("Digite o nome da pessoa: ");
  scanf("%s", p.nome);
  // receber a idade da pessoa
  printf("Digite a idade da pessoa: ");
  scanf("%d", &p.idade);

  return p;
}

void mostrarDados(struct Pessoa p) {
  printf("Nome: %s - Idade: %d\n", p.nome, p.idade);
}

int main(void) {

  struct Pessoa pes = receberDados();

  mostrarDados(pes);

/* Modificar o exercício anterior adicionando:
- Um vetor de pessoas com 5 posições
- Criar uma nova função para receber os dados das
pessoas do vetor (utilize a função criada
anteriormente)
- Criar um novo procedimento para exibir todas as
pessoas do vetor. */

  struct Pessoa grupo[5];

  for(int i = 0; i < 5; i++){
      grupo[i] = receberDados();
  }
  
  for(int i = 0; i < 5; i++){
    mostrarDados(grupo[i]);
  }
  
  return 0;
}
