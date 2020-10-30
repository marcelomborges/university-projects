
package aulapratica11;

public abstract class OperadorBinario implements ExpressaoLogica
{
    private ExpressaoLogica expressao1;
    private ExpressaoLogica expressao2;
    
    public OperadorBinario(ExpressaoLogica expressaoLogica1, ExpressaoLogica expressaoLogica2)
    {
        this.expressao1 = expressaoLogica1;
        this.expressao2 = expressaoLogica2;
    }
    
    public ExpressaoLogica getExpressao1()
    {
        return this.expressao1;
    }
    
    public ExpressaoLogica getExpressao2()
    {
        return this.expressao2;
    }

    public abstract Boolean operacao();
}
