
package aulapratica10;

public class ComandoDesligarAparelhoDeSom implements Comando
{
    /*CONCRETE_COMMAND*/
    private AparelhoDeSom aparelhoDeSom;
    private MementoAparelhoDeSom memento;
    
    public ComandoDesligarAparelhoDeSom(AparelhoDeSom receiver)
    {
        this.aparelhoDeSom = receiver;
    }
    
    public void executar()
    {
        this.memento = this.aparelhoDeSom.criarMemento();
        this.aparelhoDeSom.desligar();
    }
    
    public void desfazer()
    {
        aparelhoDeSom.recuperarMemento(memento);
        System.out.println("-> Aparelho de Som voltou para a seguinte situacao:");
        System.out.println("   (Estado: " + aparelhoDeSom.estado + ")");
        System.out.println("   (Volume: " + aparelhoDeSom.volume + ")");
    }
}
