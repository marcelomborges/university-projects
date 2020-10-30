
package aulapratica07;

public class Sintonizador
{
    private double frequencia;
    
    public Sintonizador()
    {
        frequencia = (0.1);
    }
    
    void ligar()
    {
        System.out.println("-> Sintonizador: Ligando");
    }
    
    void desligar()
    {
        System.out.println("-> Sintonizador: Desligando");
    }
    
    void setAM()
    {
        System.out.println("-> Sintonizador: Selecionando faixa AM");
    }
    
    void setFM()
    {
        System.out.println("-> Sintonizador: Selecionando faixa FM");
    }
    
    void setFrequencia(double novaFreq)
    {
        if(novaFreq > 0.0)
        {
            frequencia = novaFreq;
            System.out.println("-> Sintonizador: Frequencia alterada para " + novaFreq);
        }
        else
        {
            System.out.println("-> Sintonizador: Frequencia selecionada esta fora dos padroes");
        }
    }
}
