package academico.dominio.matriculas;

import academico.dominio.cursos.Disciplina;
import academico.dominio.pessoas.Aluno;

public class MatriculaAluno
{
    private Aluno aluno;
    private OfertaTurma oferta;
    private StatusMatriculaDisciplina status;
    private float nota;

    public MatriculaAluno(Aluno a, OfertaTurma o)
    {
        aluno = a;
        oferta = o;
        status = StatusMatriculaDisciplina.CURSANDO;
    }

    public Aluno alunoMatriculado()
    {
        return aluno;
    }

    public OfertaTurma turmaMatriculada()
    {
        return oferta;
    }

    public void registraNota(float n)
    {
        this.nota = n;
        if (this.nota >= 60)
        {
            status = StatusMatriculaDisciplina.APROVADA;
        }
        else
        {
            status = StatusMatriculaDisciplina.REPROVADA;
        }
    }

    public void trancaMatricula()
    {
        this.status = StatusMatriculaDisciplina.TRANCADA;
    }

    public boolean aprovado(Disciplina d)
    {
        return d.getNome().equals(oferta.nomeDisciplina()) && status == StatusMatriculaDisciplina.APROVADA;
    }

    public boolean verificaDisciplina(Disciplina d)
    {
        if (d.getNome().equals(oferta.nomeDisciplina()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public StatusMatriculaDisciplina getStatus()
    {
        return status;
    }
}
