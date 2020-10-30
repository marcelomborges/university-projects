package controleacademico;

import java.util.*;

public class Historico
{
    ArrayList<MatriculaAluno> disciplinasMatriculadas;
    Aluno aluno;

    Historico(Aluno a)
    {
        aluno = a;
        disciplinasMatriculadas = new ArrayList<MatriculaAluno>();
    }

    void matriculaDisciplina(OfertaTurma oferta)
    {
        if (oferta.validaOferta(aluno, oferta.disciplina))
        {
            MatriculaAluno m = new MatriculaAluno(aluno, oferta);
            this.disciplinasMatriculadas.add(m);
            oferta.matriculaAluno(m);
            System.out.println("O aluno foi matriculado na disciplina " + oferta.disciplina.nome);
        }
        else
        {
            System.out.println("O aluno nao cumpriu os prerequisitos para a disciplina " + oferta.disciplina.nome);
        }
    }

    boolean constaAprovacao(Disciplina d)
    {
        for (MatriculaAluno m : disciplinasMatriculadas)
        {
            if (m.aprovado(d))
            {
                return true;
            }
        }
        return false;
    }

    void registraResultado(Disciplina d, int nota)
    {
        for (MatriculaAluno m : disciplinasMatriculadas)
        {
            if (m.oferta.nomeDisciplina().equals(d.nome) && m.status == StatusMatriculaDisciplina.CURSANDO)
            {
                m.registraNota(nota);
            }
        }
        System.out.println("Resultado da disciplina " + d.nome + " registrado");
    }
}
