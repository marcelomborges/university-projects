package academico.dominio.pessoas;

import academico.dominio.matriculas.OfertaTurma;
import java.util.*;

public class Professor
{
    private String nome;
    private String departamento;
    private ArrayList<OfertaTurma> turmasOfertadas;

    public Professor(String nome, String d)
    {
        this.nome = nome;
        departamento = d;
    }

    public void ficaAlocadoTurma(OfertaTurma o)
    {
        turmasOfertadas.add(o);
        o.vinculaProfessor(this);
    }
}
