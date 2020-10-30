package controleacademico;

import java.util.*;

public class Disciplina
{
    String nome;
    ArrayList<Disciplina> prerequisitos;

    Disciplina(String nome)
    {
        this.nome = nome;
        prerequisitos = new ArrayList<Disciplina>();
    }

    void criaPrerequisito(Disciplina d)
    {
        prerequisitos.add(d);
    }

    String getNome()
    {
        return nome;
    }
}
