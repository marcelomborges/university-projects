package aulapratica10;

public class ComandoSetarTemperaturaArCondicionado implements Comando
{
    /*CONCRETE_COMMAND*/
    private ArCondicionado arCondicionado;
    int temperatura;
    
    public ComandoSetarTemperaturaArCondicionado(ArCondicionado receiver, int temperaturaInicial)
    {
        this.arCondicionado = receiver;
        this.temperatura = temperaturaInicial;
    }
    
    public void setTemperatura(int novaTemperatura)
    {
        System.out.println("-> Setando nova temperatura do comando para " + novaTemperatura + "°C");
        this.temperatura = novaTemperatura;
    }
    
    public void executar()
    {
        this.arCondicionado.setarTemperatura(temperatura);
    }
    
    public void desfazer()
    {
        
    }
}
