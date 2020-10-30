package prova01poo1;

public class Jogador
{
    private String nome;
    private int pontos;

    public Jogador(String str)
    {
        this.nome = str;
        pontos = 0;
    }

    public String getNome()
    {
        return nome;
    }

    public int getPontos()
    {
        return pontos;
    }

    public void addPontuacao(int n)
    {
        pontos = pontos + n;
    }
}
