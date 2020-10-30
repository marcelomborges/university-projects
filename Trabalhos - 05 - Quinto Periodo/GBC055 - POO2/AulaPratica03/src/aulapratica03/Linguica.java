package aulapratica03;

public class Linguica extends Adicional
{
    Sanduiche sanduiche;
    
    public Linguica(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Linguica");
    }
    
    public float calculoPreco()
    {
        return ((float) (4.00 + sanduiche.calculoPreco()));
    }
}
