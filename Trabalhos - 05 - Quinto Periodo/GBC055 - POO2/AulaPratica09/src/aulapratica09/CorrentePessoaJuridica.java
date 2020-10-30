package aulapratica09;

public class CorrentePessoaJuridica extends ContaCorrente
{
    public CorrentePessoaJuridica()
    {
        super();
    }

    public void cadastrar()
    {
        System.out.println("-> Cadastrando Pessoa Juridica");
    }

    public void validar()
    {
        System.out.println("-> Validando Pessoa Juridica na Receita Federal");
    }
    
    public void configurarLimite()
    {
        System.out.println("-> Configurando limite da Conta Corrente de Pessoa Juridica");
    }
    
    public void solicitarCartaoCredito()
    {
        System.out.println("-> Solicitando cartao de credito para Conta Corrente de Pessoa Juridica");
    }
}
