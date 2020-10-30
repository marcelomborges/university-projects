package aulapratica05;

public class Caixa20 extends CaixaChain
{
    public Caixa20(int q)
    {
        super(IDCaixa.C20,q);
    }
    
    protected int efetuaPagamento(int valor)
    {
        if((qntnotas > 0) && (valor/20 < qntnotas))
        {
            qntnotas -= valor/20;
            System.out.println("Notas de 20 : " + valor/20);
            return (valor % 20);
        }
        else
        {
            if(qntnotas > 0)
            {
                System.out.println("Notas de 20 : " + qntnotas);
                valor = valor - 20*qntnotas;
                qntnotas = 0;       
                return valor;
            }
        }
        
        System.out.println("Nenhuma nota de 20 disponivel");
        return (valor);
    }
}
