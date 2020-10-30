
package aulapratica08;

public class PessoaJuridica extends Pessoa
{
    private String cnpj;
    private float faturamentoAnual;
    private float contribuicoesIsentas;

    public PessoaJuridica(String n, String c, float fa, float ci)
    {
        super(n);
        cnpj = c;
        faturamentoAnual = fa;
        contribuicoesIsentas = ci;
    }

    public double calculoImposto()
    {
        return (0.20 * (faturamentoAnual - contribuicoesIsentas));
    }

    public String getCNPJ()
    {
        return cnpj;
    }
}
