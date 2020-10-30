package aulapratica03;

public class Presunto extends Adicional
{
    Sanduiche sanduiche;
    
    public Presunto(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Presunto");
    }
    
    public float calculoPreco()
    {
        return ((float) (3.50 + sanduiche.calculoPreco()));
    }
}
