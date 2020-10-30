package aulapratica07;

public class CDPlayer
{
    private CD cd;
    
    public CDPlayer()
    {
        
    }
    
    void ligar()
    {
        System.out.println("-> CD Player: Ligando");
    }
    
    void desligar()
    {
        System.out.println("-> CD Player: Desligando");
    }
    
    void play(CD cdNovo)
    {
        if(cdNovo != null)
        {
            cd = cdNovo;
            System.out.println("-> CD Player: Reproduzindo " + cd.getNome());
        }
        else
        {
            if(cd != null)
            {
                System.out.println("-> CD Player: Reproduzindo " + cd.getNome());
            }
            else
            {
                System.out.println("-> CD Player: Insira CD para reproducao");
            }
        }
    }
    
    void pause()
    {
        System.out.println("-> CD Player: Pausando");
    }
    
    void stop()
    {
        System.out.println("-> CD Player: Parando");
    }
    
    void eject()
    {
        System.out.println("-> CD Player: Ejetando");
    }
}
