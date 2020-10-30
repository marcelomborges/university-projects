package controleeventos;

public class Palestrante extends Apresentador
{
    public Palestrante(String n, Evento e, String t)
    {
        super(n, e, t);
    }

    public String certificado()
    {
        return "Declaramos que " + getNome() + " apresentou a palestra " + getTitulo() + " no " + getEvento().getNome();
    }

    public String listaDePresenca()
    {
        return "";
    }
}
