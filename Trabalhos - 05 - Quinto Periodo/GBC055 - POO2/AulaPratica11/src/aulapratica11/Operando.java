
package aulapratica11;

public class Operando implements ExpressaoLogica
{
    private Boolean conteudo;
    
    public Operando(Boolean booleano)
    {
        this.conteudo = booleano;
    }
    
    public Boolean operacao()
    {
        return this.conteudo;
    }
}
