package aulapratica08;

public class MarioPequeno extends EstadoMario
{
    public MarioPequeno(ContextoMario contextoMario)
    {
        super(contextoMario);
        this.setNomeEstado("Mario Pequeno");
    }
    
    public void pegarItem(String item)
    {
        if(item.equals("cogumelo"))
        {
            this.getContextoMario().setEstadoMario(new MarioGrande(this.getContextoMario()));
        }
        else if(item.equals("pena"))
        {
            this.getContextoMario().setEstadoMario(new MarioCapa(this.getContextoMario()));
        }
        else if(item.equals("flor"))
        {
            this.getContextoMario().setEstadoMario(new MarioFogo(this.getContextoMario()));
        }
    }
    
    public void levarDano()
    {
        this.getContextoMario().setEstadoMario(new MarioMorto(this.getContextoMario()));
    }
}
