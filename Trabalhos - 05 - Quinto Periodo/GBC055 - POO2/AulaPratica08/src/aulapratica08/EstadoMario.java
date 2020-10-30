package aulapratica08;

public abstract class EstadoMario
{
    private String nomeEstado;
    private ContextoMario mario;
    
    public EstadoMario(ContextoMario contextoMario)
    {
        this.mario = contextoMario;
    }
    
    public String getNomeEstado()
    {
        return nomeEstado;
    }
    
    public void setNomeEstado(String nome)
    {
        nomeEstado = nome;
    }
    
    public ContextoMario getContextoMario()
    {
        return mario;
    }
    
    public void setContextoMario(ContextoMario contexto)
    {
        mario = contexto;
    }
    
    public abstract void pegarItem(String item);
    
    public abstract void levarDano();
}
