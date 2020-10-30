package aulapratica09;

public class CorrentePessoaFisica extends ContaCorrente
{
    public CorrentePessoaFisica()
    {
        super();
    }

    public void cadastrar()
    {
        System.out.println("-> Cadastrando Pessoa Física");
    }

    public void validar()
    {
        System.out.println("-> Validando Pessoa Física no SPC");
    }
    
    public void configurarLimite()
    {
        System.out.println("-> Configurando limite da Conta Corrente de Pessoa Física");
    }
    
    public void solicitarCartaoCredito()
    {
        System.out.println("-> Solicitando cartao de credito para Conta Corrente de Pessoa Física");
    }
}
