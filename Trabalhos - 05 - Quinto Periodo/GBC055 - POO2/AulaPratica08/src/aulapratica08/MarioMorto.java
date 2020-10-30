package aulapratica08;

public class MarioMorto extends EstadoMario
{
    public MarioMorto(ContextoMario contextoMario)
    {
        super(contextoMario);
        this.setNomeEstado("Mario Morto");
    }
    
    public void pegarItem(String item)
    {
        System.out.println("-> O Mario nao conseguiu pegar o item " + item + " porque ele esta MORTO");
    }
    
    public void levarDano()
    {
        System.out.println("-> O Mario ja esta MORTO e mutilacao de cadaver eh crime");
    }
}
