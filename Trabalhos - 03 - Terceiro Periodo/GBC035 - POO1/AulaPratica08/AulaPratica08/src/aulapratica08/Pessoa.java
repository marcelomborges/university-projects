
package aulapratica08;

public abstract class Pessoa implements Contribuinte
{
    private final String nome;

    public Pessoa(String n)
    {
        nome = n;
    }

    public abstract double calculoImposto();

    public String getNome()
    {
        return nome;
    }

    public String getCPF()
    {
        return "";
    }

    public String getCNPJ()
    {
        return "";
    }
}
