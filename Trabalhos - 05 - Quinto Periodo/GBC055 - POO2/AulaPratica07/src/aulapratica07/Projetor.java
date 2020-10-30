package aulapratica07;

public class Projetor
{
    private DVDPlayer input;
    
    public Projetor()
    {
        
    }
    
    void ligar()
    {
        System.out.println("-> Projetor: Ligando");
    }
    
    void desligar()
    {
        System.out.println("-> Projetor: Desligando");
    }
    
    void modoTV()
    {
        System.out.println("-> Projetor: Selecionando o modo de projecao TV");
    }
    
    void modoWidescreen()
    {
        System.out.println("-> Projetor: Selecionando o modo de projecao Widescreen");
    }
    
    void setInput(DVDPlayer dvdPlayer)
    {
        input = dvdPlayer;
    }
    
}
