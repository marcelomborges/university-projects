package aulapratica05;

public abstract class CaixaChain
{
    private CaixaChain next;
    private IDCaixa id;
    public int qntnotas;
    public static int totalSaque;
    
    public CaixaChain(IDCaixa i,int q)
    {
        next = null;
        id = i;
        qntnotas = q;
    }
    
    static public CaixaChain ChainFactory(int v[])
    {
        CaixaChain base = null;
        int i = 0;
        int valorTotal = 0;
        
        while((i < 5) && (v[i] == 0))
        {
            i += 1;
        }
        
        if(i < 5)
        {
            switch(i)
            {
                case 0 : 
                    base = new Caixa100(v[i]);
                    valorTotal = valorTotal + (v[i]*100);
                    break;
                case 1 :
                    base = new Caixa50(v[i]);
                    valorTotal = valorTotal + (v[i]*50);
                    break;
                case 2 : 
                    base = new Caixa20(v[i]);
                    valorTotal = valorTotal + (v[i]*20);
                    break;
                case 3 : 
                    base = new Caixa10(v[i]);
                    valorTotal = valorTotal + (v[i]*10);
                    break;
                case 4 : 
                    base = new Caixa5(v[i]);
                    valorTotal = valorTotal + (v[i]*5);
                    break;
            }
            
            i++;
            
            for(; i < 5; i++)
            {
                if(v[i] > 0)
                {
                    switch(i)
                    {
                        case 0 : 
                            base.setNext(new Caixa100(v[i]));
                            valorTotal = valorTotal + (v[i]*100);
                            break;
                        case 1 : 
                            base.setNext(new Caixa50(v[i]));
                            valorTotal = valorTotal + (v[i]*50);
                            break;
                        case 2 : 
                            base.setNext(new Caixa20(v[i]));
                            valorTotal = valorTotal + (v[i]*10);
                            break;
                        case 3 : 
                            base.setNext(new Caixa10(v[i]));
                            valorTotal = valorTotal + (v[i]*10);
                            break;
                        case 4 : 
                            base.setNext(new Caixa5(v[i]));
                            valorTotal = valorTotal + (v[i]*5);
                            break;
                    }
                }
            }
        }
        
        totalSaque = valorTotal;
                
        return base;
    }
    
    public void setNext(CaixaChain cn)
    {
        if(next == null)
        {
            next = cn;
        }
        else
        {
            next.setNext(cn);
        }
    }
    
    public void retornaNotas(int valor)
    {
        if(valor > this.totalSaque)
        {
            System.out.println("-> Erro: Saldo do Caixa Eletronico Insuficiente");
            return;
        } 
        int resto = this.efetuaPagamento(valor);
        if(resto > 0 && next != null)
        {
            next.retornaNotas(resto);
        }
    }
    
    protected abstract int efetuaPagamento(int valor); 
}
