package aulapratica03;

public class Disciplina
{
    String nome;
    SituacaoDisciplina situacao;
    double nota;
    double frequencia;

    public Disciplina(String nome)
    {
        this.nome = nome;
        situacao = SituacaoDisciplina.CURSANDO;
    }

    void atualizaResultado(double nota, double frequencia)
    {
        if ((nota >= 60.0) && (frequencia >= 0.75))
        {
            situacao = SituacaoDisciplina.APROVADO;
        }
        else
        {
            situacao = SituacaoDisciplina.REPROVADO;
        }
        this.nota = nota;
        this.frequencia = frequencia;
    }

    void imprime()
    {
        System.out.println(nome + " - " + nota + " - " + frequencia + ": " + situacao);
    }
}
