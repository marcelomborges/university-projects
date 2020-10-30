package aulapratica07;

public class DVD
{
    private String nome;
    private String diretor;
    private int classificacaoEtaria;
    private int minutosDuracao;
    private int numeroCapitulos;
    
    public DVD(String name, String director, int classification, int time)
    {
        nome = name;
        diretor = director;
        classificacaoEtaria = classification;
        minutosDuracao = time;
    }
    
    String getNome()
    {
        return nome;
    }
}
