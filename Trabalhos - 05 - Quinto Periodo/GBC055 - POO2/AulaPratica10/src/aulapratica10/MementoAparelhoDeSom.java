
package aulapratica10;

public class MementoAparelhoDeSom
{
    /*MEMENTO*/
    private String estado;
    private int volume;
    
    public MementoAparelhoDeSom(String estadoMemento, int volumeMemento)
    {
        this.estado = estadoMemento;
        this.volume = volumeMemento;
    }
    
    public String getEstado()
    {
        return estado;
    }
    
    public int getVolume()
    {
        return volume;
    }
}
