
package aulapratica11;

public abstract class OperadorUnario implements ExpressaoLogica
{
    private ExpressaoLogica expressao;
    
    public OperadorUnario(ExpressaoLogica expressaoLogica)
    {
        this.expressao = expressaoLogica;
    }
    
    public ExpressaoLogica getExpressao()
    {
        return this.expressao;
    }

    public abstract Boolean operacao();
}
