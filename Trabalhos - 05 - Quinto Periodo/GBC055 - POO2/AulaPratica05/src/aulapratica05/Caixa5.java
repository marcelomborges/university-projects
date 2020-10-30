package aulapratica05;

public class Caixa5 extends CaixaChain
{
    public Caixa5(int q)
    {
        super(IDCaixa.C5,q);
    }
    
    
    protected int efetuaPagamento(int valor)
    {
        if((qntnotas > 0) && (valor/5 < qntnotas))
        {
            qntnotas -= valor/5;
            System.out.println("Notas de 5 : " + valor/5);
            return (valor % 5);
        }
        else
        {
            if(qntnotas > 0)
            {
                System.out.println("Notas de 5 : " + qntnotas);
                valor = valor - 5*qntnotas;
                qntnotas = 0;
                return valor;
            }
        }
        
        System.out.println("Nenhuma nota de 5 disponivel");
        return (valor);
    }
}
