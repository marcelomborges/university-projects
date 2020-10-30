package aulapratica07;

public class DVDPlayer
{
    private DVD dvd;
    
    public DVDPlayer()
    {
        
    }
    
    void ligar()
    {
        System.out.println("-> DVD Player: Ligando");
    }
    
    void desligar()
    {
        System.out.println("-> DVD Player: Desligando");
    }
    
    void play(DVD dvdNovo)
    {
        if(dvdNovo != null)
        {
            dvd = dvdNovo;
            System.out.println("-> DVD Player: Reproduzindo " + dvd.getNome());
        }
        else
        {
            if(dvd != null)
            {
                System.out.println("-> DVD Player: Reproduzindo " + dvd.getNome());
            }
            else
            {
                System.out.println("-> DVD Player: Insira DVD para reproducao");
            }
        }
    }
    
    void pause()
    {
        System.out.println("-> DVD Player: Pausando");
    }
    
    void stop()
    {
        System.out.println("-> DVD Player: Parando");
    }
    
    void eject()
    {
        System.out.println("-> DVD Player: Ejetando");
    }
}
