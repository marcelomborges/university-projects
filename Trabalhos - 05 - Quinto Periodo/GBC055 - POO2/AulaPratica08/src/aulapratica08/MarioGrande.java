package aulapratica08;

public class MarioGrande extends EstadoMario
{
    public MarioGrande(ContextoMario contextoMario)
    {
        super(contextoMario);
        this.setNomeEstado("Mario Grande");
    }
    
    public void pegarItem(String item)
    {
        if(item.equals("cogumelo"))
        {
            System.out.println("-> Mario recebe 1000 pontos por pegar cogumelo");
            this.getContextoMario().adicionaPontuacao(1000);
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
        this.getContextoMario().setEstadoMario(new MarioPequeno(this.getContextoMario()));
    }
}
