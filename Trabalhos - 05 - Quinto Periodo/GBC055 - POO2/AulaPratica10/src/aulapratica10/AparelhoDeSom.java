
package aulapratica10;

public class AparelhoDeSom
{
    /*RECEIVER*/
    public String estado;
    public int volume;
    
    public AparelhoDeSom()
    {
        this.estado = "desligado";
        this.volume = 0;
    }
    
    public void ligar()
    {
        System.out.println("-> Ligando Aparelho de Som");
        this.estado = "ligado";
    }
    
    public void desligar()
    {
        System.out.println("-> Desligando Aparelho de Som");
        this.estado = "desligado";
    }
    
    public void setarVolume(int novoVolume)
    {
        if((novoVolume >= 0)&&(novoVolume <= 100))
        {
            System.out.println("-> Setando volume do Aparelho de Som para " + novoVolume);
            this.volume = novoVolume;
        }
        else
        {
            System.out.println("-> Valor do novo volume eh invalido");
        }
    }
    
    public MementoAparelhoDeSom criarMemento()
    {
        return (new MementoAparelhoDeSom(this.estado,this.volume));
    }
    
    public void recuperarMemento(MementoAparelhoDeSom memento)
    {
        this.estado = memento.getEstado();
        this.volume = memento.getVolume();
    }
}
