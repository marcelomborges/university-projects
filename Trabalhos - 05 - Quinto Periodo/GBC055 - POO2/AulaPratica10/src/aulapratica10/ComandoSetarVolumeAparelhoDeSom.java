
package aulapratica10;

public class ComandoSetarVolumeAparelhoDeSom implements Comando
{
    /*CONCRETE_COMMAND*/
    private AparelhoDeSom aparelhoDeSom;
    int volume;
    private MementoAparelhoDeSom memento;
    
    public ComandoSetarVolumeAparelhoDeSom(AparelhoDeSom receiver, int volumeInicial)
    {
        this.aparelhoDeSom = receiver;
        this.volume = volumeInicial;
    }
    
    public void setVolume(int novoVolume)
    {
        System.out.println("-> Setando novo volume do comando para " + novoVolume);
        this.volume = novoVolume;
    }
    
    public void executar()
    {
        this.memento = this.aparelhoDeSom.criarMemento();
        this.aparelhoDeSom.setarVolume(volume);
    }
    
    public void desfazer()
    {
        aparelhoDeSom.recuperarMemento(memento);
        System.out.println("-> Aparelho de Som voltou para a seguinte situacao:");
        System.out.println("   (Estado: " + aparelhoDeSom.estado + ")");
        System.out.println("   (Volume: " + aparelhoDeSom.volume + ")");
    }
}
