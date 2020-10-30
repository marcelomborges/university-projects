
package aulapratica07;

public class Amplificador
{
    private int volume;
    private CDPlayer cdAmp;
    private DVDPlayer dvdAmp;
    private Sintonizador sintAmp;
    
    public Amplificador()
    {
        
    }
    
    void ligar()
    {
        System.out.println("-> Amplificador: Ligando");
    }
    
    void desligar()
    {
        System.out.println("-> Amplificador: Desligando");
    }
    
    void setSurroundAudio()
    {
        System.out.println("-> Amplificador: Selecionando modo de audio Surround");
    }
    
    void setStereoAudio()
    {
        System.out.println("-> Amplificador: Selecionando modo de audio Stereo");
    }
    
    void setVolume(int nivel)
    {
        if((nivel >= 1)&&(nivel <= 10))
        {   
            volume = nivel;
            System.out.println("-> Amplificador: Volume alterado para " + nivel);
        }
        else
        {
            System.out.println("-> Amplificador: Volume selecionado esta fora dos padroes");
        }
    }
    
    void setCD(CDPlayer novoCDPlayer)
    {
        cdAmp = novoCDPlayer;
    }
    
    void setDVD(DVDPlayer novoDVDPlayer)
    {
        dvdAmp = novoDVDPlayer;
    }
    
    void setTuner(Sintonizador novoSintonizador)
    {
        sintAmp = novoSintonizador;
    }
}
