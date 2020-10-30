package aulapratica04;

public class Caixa20 extends CaixaChain
{
    public Caixa20()
    {
        super(IDCaixa.C20);
    }
    
    
    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 20 : " + valor/20);
        return (valor % 20);
    }
    
}
