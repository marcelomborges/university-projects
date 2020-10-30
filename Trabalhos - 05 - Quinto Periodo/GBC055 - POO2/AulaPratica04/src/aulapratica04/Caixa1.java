package aulapratica04;

public class Caixa1 extends CaixaChain
{
    public Caixa1()
    {
        super(IDCaixa.C1);
    }
    
    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 1 : " + valor/1);
        return (valor % 1);
    }
}
