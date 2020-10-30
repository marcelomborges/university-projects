package aulapratica03;

public class Queijo extends Adicional
{
    Sanduiche sanduiche;
    
    public Queijo(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Queijo");
    }
    
    public float calculoPreco()
    {
        return ((float) (5.50 + sanduiche.calculoPreco()));
    }
}
