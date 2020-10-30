package aulapratica07;

public class LuzAmbiente
{
    private int luminosidade;
    
    public LuzAmbiente()
    {
        luminosidade = 1;
    }
    
    void ligar()
    {
        System.out.println("-> Luz Ambiente: Ligando");
    }
    
    void desligar()
    {
        System.out.println("-> Luz Ambiente: Desligando");
    }
    
    void setLuminosidade(int nivel)
    {
        if((nivel >= 1)&&(nivel <= 10))
        {   
            luminosidade = nivel;
            System.out.println("-> Luz Ambiente: Nivel de luminosidade alterado para " + nivel);
        }
        else
        {
            System.out.println("-> Luz Ambiente: Nivel de luminosidade selecionado esta fora dos padroes");
        }
    }
}
