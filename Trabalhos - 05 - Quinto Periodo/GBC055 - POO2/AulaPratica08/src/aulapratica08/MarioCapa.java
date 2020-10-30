package aulapratica08;

public class MarioCapa extends EstadoMario
{   
    public MarioCapa(ContextoMario contextoMario)
    {
        super(contextoMario);
        this.setNomeEstado("Mario Capa");
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
            System.out.println("-> Mario recebe 1000 pontos por pegar pena");
            this.getContextoMario().adicionaPontuacao(1000);
        }
        else if(item.equals("flor"))
        {
            this.getContextoMario().setEstadoMario(new MarioFogo(this.getContextoMario()));
        }
    }
    
    public void levarDano()
    {
        this.getContextoMario().setEstadoMario(new MarioGrande(this.getContextoMario()));
    }
}
