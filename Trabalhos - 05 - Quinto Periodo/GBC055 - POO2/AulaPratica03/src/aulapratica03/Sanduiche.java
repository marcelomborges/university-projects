package aulapratica03;

public abstract class Sanduiche
{
    String descricao;
    
    public String getDescricao()
    {
        return this.descricao;
    }
    
    public void setDescricao(String novaDescricao)
    {
        this.descricao = novaDescricao;
    }
    
    public abstract float calculoPreco();
}
