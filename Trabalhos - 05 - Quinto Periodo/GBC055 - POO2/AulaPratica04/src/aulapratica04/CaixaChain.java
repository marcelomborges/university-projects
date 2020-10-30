package aulapratica04;

public abstract class CaixaChain
{    
    private CaixaChain next;
    private IDCaixa id;
    
    public CaixaChain(IDCaixa i)
    {
        next = null;
        id = i;
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
        int resto = this.efetuaPagamento(valor);
        if(resto > 0)
        {
            next.retornaNotas(resto);
        }
        
    }
    
    protected abstract int efetuaPagamento(int valor); 
}
