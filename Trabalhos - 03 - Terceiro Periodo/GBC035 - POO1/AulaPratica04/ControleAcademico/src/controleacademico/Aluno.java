package controleacademico;

public class Aluno
{
    String nome;
    GradeCurricular grade;
    Historico historico;

    Aluno(String n, GradeCurricular g)
    {
        nome = n;
        grade = g;
        historico = new Historico(this);
    }

    boolean verificaSeFormou()
    {
        // for (int i = 0; i < grade.nroDisciplinas(); i++) {
        for (Disciplina d : grade.disciplinas)
        {
            if (!historico.constaAprovacao(d))
            {
                return false;
            }
        }
        return true;
    }

    void disciplinasRestantes() {
        System.out.println("-> Disciplinas que ainda restam para o aluno " + nome + " se formar:");
        {
            for (Disciplina d : grade.disciplinas)
            {
                if (!historico.constaAprovacao(d))
                {
                    System.out.println(d.nome);
                }
            }
        }
    }
}
