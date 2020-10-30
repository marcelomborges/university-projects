package aulapratica03;

public class Hamburguer extends Adicional
{
    Sanduiche sanduiche;
    
    public Hamburguer(Sanduiche sandwich)
    {
        this.sanduiche = sandwich;
    }
    
    public String getDescricao()
    {
        return (sanduiche.getDescricao() + ", Hamburguer");
    }
    
    public float calculoPreco()
    {
        return ((float) (6.00 + sanduiche.calculoPreco()));
    }
}
