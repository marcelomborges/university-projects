package aulapratica03;

public class Bacon extends Adicional
{
    Sanduiche sanduiche;
    
    public Bacon(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Bacon");
    }
    
    public float calculoPreco()
    {
        return ((float) (7.00 + sanduiche.calculoPreco()));
    }
}
