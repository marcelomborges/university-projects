
package aulapratica08;

public class PessoaFisica extends Pessoa {

    private String cpf;
    private float rendimentoAnual;

    public PessoaFisica(String n, String c, float ra)
    {
        super(n);
        cpf = c;
        rendimentoAnual = ra;
    }

    public double calculoImposto()
    {
        return (rendimentoAnual * 0.15);
    }

    public String getCPF()
    {
        return cpf;
    }
}
