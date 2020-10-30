package aulapratica08;

public class MarioFogo extends EstadoMario
{
    public MarioFogo(ContextoMario contextoMario)
    {
        super(contextoMario);
        this.setNomeEstado("Mario Fogo");
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
            System.out.println("-> Mario recebe 1000 pontos por pegar flor");
            this.getContextoMario().adicionaPontuacao(1000);
        }
    }
    
    public void levarDano()
    {
        this.getContextoMario().setEstadoMario(new MarioGrande(this.getContextoMario()));
    }
}
