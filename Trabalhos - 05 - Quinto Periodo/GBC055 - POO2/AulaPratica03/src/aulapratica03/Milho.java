package aulapratica03;

public class Milho extends Adicional
{
    Sanduiche sanduiche;
    
    public Milho(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Milho");
    }
    
    public float calculoPreco()
    {
        return ((float) (2.00 + sanduiche.calculoPreco()));
    }
}
