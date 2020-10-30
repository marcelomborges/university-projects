package aulapratica03;

import java.util.*;

public class Aluno
{
    String nome;
    int matricula;
    int ingresso;
    Historico h = new Historico();

    public Aluno(String nome, int matricula, int ingresso)
    {
        this.nome = nome;
        this.matricula = matricula;
        this.ingresso = ingresso;
    }

    void imprime()
    {
        System.out.println("|---------------ALUNO---------------|");
        System.out.println("Nome: " + nome);
        System.out.println("Matricula: " + matricula);
        System.out.println("Ano de Ingresso:" + ingresso);
        h.imprime();
        System.out.println("|-----------------------------------|");
    }
}
