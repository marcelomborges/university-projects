package aulapratica03;

public class Cebola extends Adicional
{
    Sanduiche sanduiche;
    
    public Cebola(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Cebola");
    }
    
    public float calculoPreco()
    {
        return ((float) (1.50 + sanduiche.calculoPreco()));
    }
}
