package aulapratica04;

public class Caixa50 extends CaixaChain
{
    public Caixa50()
    {
        super(IDCaixa.C50);
    }

    protected int efetuaPagamento(int valor)
    {
        System.out.println("Notas de 50 : " + valor/50);
        return (valor % 50);
    }
}
