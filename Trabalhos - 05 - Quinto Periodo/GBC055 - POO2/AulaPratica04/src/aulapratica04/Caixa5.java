package aulapratica04;

public class Caixa5 extends CaixaChain
{
    public Caixa5()
    {
        super(IDCaixa.C5);
    }
    
    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 5 : " + valor/5);
        return (valor % 5);
    }
}
