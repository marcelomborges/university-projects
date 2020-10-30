package academico.dominio.cursos;

import java.util.*;

public class GradeCurricular
{
    private Vector<Disciplina> disciplinas = new Vector<Disciplina>();

    public void incluiDisciplina(Disciplina d)
    {
        disciplinas.add(d);
    }

    public void removeDisciplina(Disciplina d)
    {
        disciplinas.remove(d);
    }

    public int nroDisciplinas()
    {
        return disciplinas.size();
    }

    public Vector<Disciplina> acessaVetor()
    {
        return disciplinas;
    }
}
