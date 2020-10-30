package aulapratica03;

import java.util.*;

public class ControleAcademico
{
    Vector<Aluno> listaAlunos;

    public ControleAcademico()
    {
        listaAlunos = new Vector<Aluno>();
    }

    void adicionaAluno(Aluno a)
    {
        listaAlunos.add(a);
    }

    void removeAluno(Aluno a)
    {
        listaAlunos.remove(a);
    }

    void imprime()
    {
        System.out.println("");
        System.out.println("|--------CONTROLE-ACADEMICO---------|");
        for (Aluno a : listaAlunos)
        {
            a.imprime();
        }
    }
}
