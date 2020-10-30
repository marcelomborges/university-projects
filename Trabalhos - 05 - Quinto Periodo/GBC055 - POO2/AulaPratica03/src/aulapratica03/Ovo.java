package aulapratica03;

public class Ovo extends Adicional
{
    Sanduiche sanduiche;
    
    public Ovo(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Ovo");
    }
    
    public float calculoPreco()
    {
        return ((float) (5.00 + sanduiche.calculoPreco()));
    }
}
