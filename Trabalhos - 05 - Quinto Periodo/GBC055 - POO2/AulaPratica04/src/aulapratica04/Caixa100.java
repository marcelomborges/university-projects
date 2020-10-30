package aulapratica04;

public class Caixa100 extends CaixaChain
{
    public Caixa100()
    {
        super(IDCaixa.C100);
    }
    
    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 100 : " + valor/100);
        return (valor % 100);
    }
}
