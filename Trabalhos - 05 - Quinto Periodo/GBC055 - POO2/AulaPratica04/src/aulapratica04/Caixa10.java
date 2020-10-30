package aulapratica04;

public class Caixa10 extends CaixaChain
{
    public Caixa10()
    {
        super(IDCaixa.C10);
    }
    
    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 10 : " + valor/10);
        return (valor % 10);
    }
}
