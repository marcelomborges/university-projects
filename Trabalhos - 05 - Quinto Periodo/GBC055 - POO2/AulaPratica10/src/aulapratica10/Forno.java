
package aulapratica10;

public class Forno
{
    /*RECEIVER*/
    public String estado;
    public int temperatura;
    public int timer;
    
    public Forno()
    {
        this.estado = "desligado";
        this.temperatura = 0;
        this.timer = 0;
    }
    
    public void ligar()
    {
        System.out.println("-> Ligando Forno");
        this.estado = "ligado";
    }
    
    public void desligar()
    {
        System.out.println("-> Desligando Forno");
        this.estado = "desligado";
    }
    
    public void setarTemperatura(int novaTemperatura)
    {
        if((novaTemperatura >= 0)&&(novaTemperatura <= 200))
        {
            System.out.println("-> Setando temperatura do Forno para " + novaTemperatura + "°C");
            this.temperatura = novaTemperatura;
        }
        else
        {
            System.out.println("-> Valor da nova temperatura eh invalida");
        }
    }
    
    public void setarTimer(int novoTempo)
    {
        if((novoTempo >= 0)&&(novoTempo <= 1000))
        {
            System.out.println("-> Setando timer do Forno para " + novoTempo + " minutos");
            this.temperatura = novoTempo;
        }
        else
        {
            System.out.println("-> Valor do novo tempo do timer eh invalido");
        }
    }
}
