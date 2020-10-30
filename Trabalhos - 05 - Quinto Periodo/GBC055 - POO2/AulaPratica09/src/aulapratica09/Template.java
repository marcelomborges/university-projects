package aulapratica09;

public abstract class Template
{
    String CPF_CNPJ;
    String numeroConta;
    String senhaConta;
    int saldo;
    
    public final void abrirConta(String CPF_CNPJ, String numero, String senha, int valorInicial, Boolean cartao)
    {
        this.CPF_CNPJ = CPF_CNPJ;
        this.numeroConta = numero;
        cadastrar();
        validar();
        depositarValorInicial(valorInicial);
        configurarLimite();
        cadastrarSenha(senha);
        if(cartao)
        {
            solicitarCartaoCredito();
        }
        finalizar();
    }
    
    public abstract void cadastrar();
    public abstract void validar();
    
    public void depositarValorInicial(int valor)
    {
        System.out.println("-> Depositando valor inicial de R$" + valor);
        saldo += valor;
    }
    
    public void cadastrarSenha(String novaSenha)
    {
        System.out.println("-> Cadastrando a senha: " + novaSenha);
        this.senhaConta = novaSenha;
    }
    
    public void finalizar()
    {
        System.out.println("-> Finalizando criacao da conta");
    }
    
    public void configurarLimite(){}
    public void solicitarCartaoCredito(){}
}
