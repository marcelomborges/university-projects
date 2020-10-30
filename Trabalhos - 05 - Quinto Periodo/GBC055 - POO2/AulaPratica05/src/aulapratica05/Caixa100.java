package aulapratica05;

public class Caixa100 extends CaixaChain
{
    public Caixa100(int q)
    {
        super(IDCaixa.C100,q);
    }
    
    protected int efetuaPagamento(int valor)
    {
        if((qntnotas > 0) && (valor/100 < qntnotas))
        {
            qntnotas -= valor/100;
            System.out.println("Notas de 100 : " + valor/100);
            return (valor % 100);
        }
        else
        {
            if(qntnotas > 0)
            {
                System.out.println("Notas de 100 : " + qntnotas);
                valor = valor - 100*qntnotas;
                qntnotas = 0;       
                return valor;
            }
        }
        
        System.out.println("Nenhuma nota de 100 disponivel");
        return (valor);
    }
    
}
