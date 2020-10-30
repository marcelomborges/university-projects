
package aulapratica10;

public class ArCondicionado
{
    /*RECEIVER*/
    public String estado;
    public int temperatura;
    
    public ArCondicionado()
    {
        this.estado = "desligado";
        this.temperatura = 0;
    }
    
    public void ligar()
    {
        System.out.println("-> Ligando Ar Condicionado");
        this.estado = "ligado";
    }
    
    public void desligar()
    {
        System.out.println("-> Desligando Ar Condicionado");
        this.estado = "desligado";
    }
    
    public void setarTemperatura(int novaTemperatura)
    {
        if((novaTemperatura >= (-10))&&(novaTemperatura <= 30))
        {
            System.out.println("-> Setando temperatura do Ar Condicionado para " + novaTemperatura + "°C");
            this.temperatura = novaTemperatura;
        }
        else
        {
            System.out.println("-> Valor da nova temperatura eh invalida");
        }
    }
}
