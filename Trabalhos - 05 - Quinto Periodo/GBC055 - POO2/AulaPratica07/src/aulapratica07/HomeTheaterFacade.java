package aulapratica07;

public class HomeTheaterFacade
{
    private Amplificador amplificador;
    private CDPlayer cdPlayer;
    private DVDPlayer dvdPlayer;
    private LuzAmbiente luzAmbiente;
    private Pipoqueira pipoqueira;
    private Projetor projetor;
    private Sintonizador sintonizador;
    private Tela tela;
    
    public HomeTheaterFacade(Amplificador amp, CDPlayer cdp, DVDPlayer dvdp, LuzAmbiente luz, Pipoqueira pip, Projetor proj, Sintonizador sint, Tela t)
    {
        amplificador = amp;
        cdPlayer = cdp;
        dvdPlayer = dvdp;
        luzAmbiente = luz;
        pipoqueira = pip;
        projetor = proj;
        sintonizador = sint;
        tela = t;
    }
    
    void assistirDVD(DVD dvd)
    {
        System.out.println("\nPreparacao para assistir DVD:--------------------------------------------------\n");
        
        pipoqueira.ligar();
        pipoqueira.cozinhar();
        
        luzAmbiente.ligar();
        luzAmbiente.setLuminosidade(1);
        
        tela.descer();
        
        projetor.ligar();
        projetor.setInput(dvdPlayer);
        projetor.modoWidescreen();
        
        amplificador.ligar();
        amplificador.setDVD(dvdPlayer);
        amplificador.setSurroundAudio();
        amplificador.setVolume(5);
        
        dvdPlayer.ligar();
        dvdPlayer.play(dvd);
    }
    
    void pararDVD()
    {
        System.out.println("\nParando a reproducao do DVD:--------------------------------------------------\n");
        
        pipoqueira.desligar();
        
        luzAmbiente.setLuminosidade(10);
        
        tela.subir();
        
        projetor.desligar();
        
        amplificador.desligar();
        
        dvdPlayer.stop();
        dvdPlayer.eject();
        dvdPlayer.desligar();
    }
    
    void ouvirCD(CD cd)
    {
        System.out.println("\nPreparacao para ouvir DVD:--------------------------------------------------\n");
        
        luzAmbiente.ligar();
        luzAmbiente.setLuminosidade(5);
        
        amplificador.ligar();
        amplificador.setCD(cdPlayer);
        amplificador.setStereoAudio();
        amplificador.setVolume(7);
        
        cdPlayer.ligar();
        cdPlayer.play(cd);
    }
    
    void pararCD()
    {
        System.out.println("\nParando a reproducao do CD:--------------------------------------------------\n");
        
        luzAmbiente.setLuminosidade(10);
        
        amplificador.desligar();
        
        cdPlayer.stop();
        cdPlayer.eject();
        cdPlayer.desligar();
    }
}

