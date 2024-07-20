import java.lang.*;

public class Aluno implements Comparable<Aluno> {
    
    private String nome;
    private int matricula;

    public Aluno(int matricula, String nome) {
        this.matricula = matricula;
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMatricula() {
        return this.matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String toString() {
        return this.matricula + " - " + this.nome;
    }

    public int compareTo(Aluno outro){
        /*if(this.matricula > outro.matricula){
            return 1;
        }else if(this.matricula < outro.matricula){
            return -1;
        }else{
            return 0;
        }*/
        
        return this.nome.compareTo(outro.nome);
    }
}
