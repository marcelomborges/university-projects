package aulapratica05;

public class Caixa10 extends CaixaChain
{
    public Caixa10(int q)
    {
        super(IDCaixa.C10,q);
    }
    
    protected int efetuaPagamento(int valor)
    {
        if((qntnotas > 0) && (valor/10 < qntnotas))
        {
            qntnotas -= valor/10;
            System.out.println("Notas de 10 : " + valor/10);
            return (valor % 10);
        }
        else
        {
            if(qntnotas > 0)
            {
                System.out.println("Notas de 10 : " + qntnotas);
                valor = valor - 10*qntnotas;
                qntnotas = 0;       
                return valor;
            }
        }
        
        System.out.println("Nenhuma nota de 10 disponivel");
        return (valor);
    }
}
