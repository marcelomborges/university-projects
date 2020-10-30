
package aulapratica10;

public class ComandoLigarAparelhoDeSom implements Comando
{
    /*CONCRETE_COMMAND*/
    private AparelhoDeSom aparelhoDeSom;
    private MementoAparelhoDeSom memento;
    
    public ComandoLigarAparelhoDeSom(AparelhoDeSom receiver)
    {
        this.aparelhoDeSom = receiver;
    }
    
    public void executar()
    {
        this.memento = this.aparelhoDeSom.criarMemento();
        this.aparelhoDeSom.ligar();
    }
    
    public void desfazer()
    {
        aparelhoDeSom.recuperarMemento(memento);
        System.out.println("-> Aparelho de Som voltou para a seguinte situacao:");
        System.out.println("   (Estado: " + aparelhoDeSom.estado + ")");
        System.out.println("   (Volume: " + aparelhoDeSom.volume + ")");
    }
}
