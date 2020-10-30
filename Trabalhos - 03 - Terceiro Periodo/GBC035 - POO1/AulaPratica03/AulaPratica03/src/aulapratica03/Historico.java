package aulapratica03;

import java.util.*;

public class Historico
{
    Vector<Disciplina> listaDisciplinas;

    public Historico()
    {
        listaDisciplinas = new Vector<Disciplina>();
    }

    void adicionaDisciplina(Disciplina d)
    {
        listaDisciplinas.add(d);
    }

    void removeDisciplina(Disciplina d)
    {
        listaDisciplinas.remove(d);
    }

    void atualizaResultado(Disciplina d, double nota, double frequencia)
    {
        d.atualizaResultado(nota, frequencia);
    }

    void imprime()
    {
        System.out.println("");
        System.out.println("Historico do Aluno (Nome - Nota - Frequencia: Situacao):");
        for (Disciplina d : listaDisciplinas)
        {
            d.imprime();
        }
    }
}
