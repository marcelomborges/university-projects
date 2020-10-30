package aulapratica07;

public class CD
{
    private String nome;
    private String artista;
    private int minutosDuracao;
    private int numeroMusicas;
    
    public CD(String name, String artist, int time, int numberMusics)
    {
        nome = name;
        artista = artist;
        minutosDuracao = time;
        numeroMusicas = numberMusics;
    }
    
    String getNome()
    {
        return nome;
    }
}
