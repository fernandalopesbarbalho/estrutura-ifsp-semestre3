import java.util.*;

public class Main {
  public static void main(String[] args) {
    
    Aluno a1 = new Aluno(1, "Igor");
    Aluno a2 = new Aluno(5, "Maria");
    Aluno a3 = new Aluno(3, "Ana");

    List<Aluno> alunos = new ArrayList<Aluno>();

    alunos.add(a1);
    alunos.add(a2);
    alunos.add(a3);

    System.out.println(alunos);

    Collections.sort(alunos);

    System.out.println(alunos);
  }
}
