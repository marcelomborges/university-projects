
package academico.dominio.pessoas;

import academico.dominio.cursos.Disciplina;
import academico.dominio.cursos.GradeCurricular;
import academico.dominio.matriculas.Historico;
import academico.dominio.matriculas.OfertaTurma;

public class Aluno
{
    private String nome;
    private GradeCurricular grade;
    private Historico historico;

    public Aluno(String n, GradeCurricular g)
    {
        nome = n;
        grade = g;
        historico = new Historico(this);
    }

    public boolean verificaSeFormou()
    {
        // for (int i = 0; i < grade.nroDisciplinas(); i++) {
        for (Disciplina d : grade.acessaVetor())
        {
            if (!historico.constaAprovacao(d))
            {
                return false;
            }
        }
        return true;
    }

    public String getNome()
    {
        return nome;
    }

    public void matriculaAluno(OfertaTurma oferta)
    {
        historico.matriculaDisciplina(oferta);
    }

    public void atualizaResultado(Disciplina d, int nota)
    {
        historico.registraResultado(d, nota);
    }
}
