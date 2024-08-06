public class Aluno {
    private int matricula;
    private String nome;
    private int idade;
    private int ira;

    // Construtor para inicializar os objetos
    public Aluno(int matricula, String nome, int idade, int ira) {
        this.matricula = matricula;
        this.nome = nome;
        this.idade = idade;
        this.ira = ira;
    }

    // Get e Set
    public int getMatricula() {
        return matricula;
    }
    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getIra() {
        return ira;
    }
    public void setIra(int ira) {
        this.ira = ira;
    }

    @Override // Sobrescrita de um método
    public String toString() {
        return "Nome do aluno: " + nome + "\nMatrícula: " + matricula + "\nIdade: " + idade + "\nIRA: " + ira + "\n";
    }
}
