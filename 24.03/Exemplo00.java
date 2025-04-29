import java.util.*;
import javax.print.attribute.standard.MediaSize;
 class Aluno {
	int matricula;
	String nome;
	String email;
	
	public Aluno(){}
	
	public Aluno(int matricula, String nome) {
		this.matricula = matricula;
		this.nome = nome;
		this.gerarEmail();
	}
	
	public void gerarEmail() {
		String vetorNome[] = this.nome.split(" ");
		this.email = vetorNome[0] + "." + vetorNome[vetorNome.length-1] + "@ufn.edu.br";
		this.email = this.email.toLowerCase();
	}

    @Override
    public String toString() {
        return "Aluno [matricula=" + matricula + ", nome=" + nome + "]";
    }

    @Override
    public boolean equals(Object obj) {
        Aluno other = (Aluno) obj;
        if(other.email.equals(this.email)){
            return true;
        }
        return false;
    }

}

public class Exemplo00{
	public static void main(String[] args) {
		List<Aluno> alunos = new ArrayList<Aluno>();
        Scanner scanner = new Scanner(System.in);
        String nome;
        String opcao;
        int matricula = 1;
        Aluno alunoTmp;
        do{
            System.out.println("Digite o nome do aluno: ");
            nome = scanner.nextLine();
            alunoTmp = new Aluno(matricula, nome);
            if(alunos.contains(alunoTmp)){
                System.out.println("Aluno já cadastrado!");
            }else{
                alunos.add(alunoTmp);
                matricula++;
            }
            System.out.println("Deseja adicionar outro aluno? (s/n)");
            opcao = scanner.nextLine();
            if(opcao.equalsIgnoreCase("N")){
                break;
            }
        } while (true);

        alunos.sort((a1, a2) -> a1.nome.compareTo(a2.nome));

        for (Aluno aluno : alunos) {
            System.out.println(aluno);
        }
	}
}