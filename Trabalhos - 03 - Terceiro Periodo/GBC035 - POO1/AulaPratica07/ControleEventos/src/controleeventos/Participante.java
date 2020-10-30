package controleeventos;

public class Participante
{
    private String nome;
    private Evento evento;

    public Participante(String n, Evento e)
    {
        nome = n;
        evento = e;
    }

    public String certificado()
    {
        return "Declaramos que " + nome + " participou do " + evento.getNome();
    }

    public String listaDePresenca()
    {
        return "Participante: " + nome + "\n";
    }

    protected String getNome()
    {
        return nome;
    }

    protected Evento getEvento()
    {
        return evento;
    }
}
