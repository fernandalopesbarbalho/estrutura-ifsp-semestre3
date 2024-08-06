/* Você deverá criar uma classe para representar um aluno com os seguintes atributos: matrícula (int), nome (String), idade (int), IRA (int). A classe deve ter os métodos get e set e ao menos um construtor explícito.

Faça o código (no main) para utilizar uma Fila e uma Pilha adicionando no mínimo 3 objetos do tipo Aluno em cada e mostrando o comportamento das estruturas ao inserir e remover objetos - comente o seu código principalmente nas chamadas dos métodos que manipulam a pilha/fila. */

import java.util.*;

public class Main {
  public static void main(String[] args) {

    // Criando os Alunos
    Aluno aluno1 = new Aluno(123, "Fernanda", 19, 9);
    Aluno aluno2 = new Aluno(321, "Igor", 27, 8);
    Aluno aluno3 = new Aluno(345, "Eduarda", 20, 7);
    Aluno aluno4 = new Aluno(543, "Valentina", 21, 10);

    // Criando a Fila
    Queue<Aluno> fila = new LinkedList<Aluno>();

    // Adicionando os alunos no final da fila (primeiro a entrar é o primeiro a sair)
    fila.add(aluno1);
    fila.add(aluno2);
    fila.add(aluno3);
    fila.add(aluno4);

    System.out.println("- Ordem dos alunos na fila:");
    while (!fila.isEmpty()) { // Enquanto a fila não estiver vazia, imprime os alunos
        System.out.println(fila.remove()); // Remove o primeiro aluno adicionado na fila e imprime
    }

    // Criando a Pilha
    Stack<Aluno> pilha = new Stack<Aluno>();

    // Adicionando os alunos no topo da pilha (o último a entrar é o primeiro a sair)
    pilha.push(aluno1);
    pilha.push(aluno2);
    pilha.push(aluno3);
    pilha.push(aluno4);

    System.out.println("- Ordem dos alunos na pilha:");
    while (!pilha.isEmpty()) { // Enquanto a pilha não estiver vazia, imprime os alunos
        System.out.println(pilha.pop()); // Remove o último aluno adicionado na pilha e imprime
    }
  }
}
