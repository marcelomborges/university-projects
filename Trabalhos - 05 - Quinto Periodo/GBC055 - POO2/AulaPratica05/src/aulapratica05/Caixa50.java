package aulapratica05;

public class Caixa50 extends CaixaChain
{
    public Caixa50(int q)
    {
        super(IDCaixa.C50,q);
    }
    
    protected int efetuaPagamento(int valor){
        
        if((qntnotas > 0) && (valor/50 < qntnotas))
        {
            qntnotas -= valor/50;
            System.out.println("Notas de 50 : " + valor/50);
            return (valor % 50);
        }
        else
        {
            if(qntnotas > 0)
            {
                System.out.println("Notas de 50 : " + qntnotas);
                valor = valor - 50*qntnotas;
                qntnotas = 0;
                return valor;
            }
        }
        
        System.out.println("Nenhuma nota de 50 disponivel");
        return (valor);
    }
    
}
