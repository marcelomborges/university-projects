package aulapratica08;

public class ContextoMario
{
    private int pontuacao;
    private EstadoMario estadoMario;
    
    public ContextoMario()
    {
        this.pontuacao = 0;
        this.estadoMario = new MarioPequeno(this);
    }
    
    public int getPontuacao()
    {
        return pontuacao;
    }
    
    public void setPontuacao(int pontos)
    {
        pontuacao = pontos;
    }
    
    public void adicionaPontuacao(int pontos)
    {
        pontuacao = pontuacao + pontos;
    }
    
    public EstadoMario getEstadoMario()
    {
        return estadoMario;
    }
    
    public void setEstadoMario(EstadoMario estado)
    {
        estadoMario = estado;
    }
    
    public void pegarItem(String item)
    {
        System.out.println("Mario pega o item " + item + ": --------------------------------------------------");
        System.out.println("-> Estava no estado " + estadoMario.getNomeEstado());
        estadoMario.pegarItem(item);
        System.out.println("-> Mario esta agora com " + pontuacao + " pontos");
        System.out.println("-> Mario esta agora no estado " + estadoMario.getNomeEstado());
    }
    
    public void levarDano()
    {
        System.out.println("Mario leva dano: --------------------------------------------------");
        System.out.println("-> Estava no estado " + estadoMario.getNomeEstado());
        estadoMario.levarDano();
        System.out.println("-> Mario esta agora no estado " + estadoMario.getNomeEstado());
    }   
}
