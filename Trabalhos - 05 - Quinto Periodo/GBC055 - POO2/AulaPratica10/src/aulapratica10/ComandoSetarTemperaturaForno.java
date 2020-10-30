
package aulapratica10;

public class ComandoSetarTemperaturaForno implements Comando
{
    /*CONCRETE_COMMAND*/
    private Forno forno;
    int temperatura;
    
    public ComandoSetarTemperaturaForno(Forno receiver, int temperaturaInicial)
    {
        this.forno = receiver;
        this.temperatura = temperaturaInicial;
    }
    
    public void setTemperatura(int novaTemperatura)
    {
        System.out.println("-> Setando nova temperatura do comando para " + novaTemperatura + "°C");
        this.temperatura = novaTemperatura;
    }
    
    public void executar()
    {
        this.forno.setarTemperatura(temperatura);
    }
    
    public void desfazer()
    {
        
    }
}
