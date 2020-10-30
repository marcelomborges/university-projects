package aulapratica04;

public class Caixa2 extends CaixaChain
{
    public Caixa2()
    {
        super(IDCaixa.C2);
    }
    
    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 2 : " + valor/2);
        return (valor % 2);
    }
}
