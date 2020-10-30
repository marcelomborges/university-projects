package academico.dominio.matriculas;

import academico.dominio.matriculas.MatriculaAluno;
import academico.dominio.cursos.Disciplina;
import academico.dominio.pessoas.Professor;
import academico.dominio.pessoas.Aluno;
import java.util.*;

public class OfertaTurma
{
    private int ano;
    private Semestre semestre;
    private Disciplina disciplina;
    private Vector<MatriculaAluno> alunosMatriculados;
    private Professor professor;

    public OfertaTurma(int ano, Semestre s, Disciplina d)
    {
        this.ano = ano;
        this.semestre = s;
        this.disciplina = d;
        alunosMatriculados = new Vector<MatriculaAluno>();
    }

    public void matriculaAluno(MatriculaAluno m)
    {
        alunosMatriculados.add(m);
    }

    public void cancelaMatricula(Aluno a)
    {
        alunosMatriculados.remove(a);
    }

    public void vinculaProfessor(Professor p)
    {
        professor = p;
        professor.ficaAlocadoTurma(this);
    }

    public String nomeDisciplina()
    {
        return this.disciplina.getNome();
    }
}
