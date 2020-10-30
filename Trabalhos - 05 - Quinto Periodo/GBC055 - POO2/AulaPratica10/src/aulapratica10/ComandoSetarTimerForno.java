
package aulapratica10;

public class ComandoSetarTimerForno implements Comando
{
    /*CONCRETE_COMMAND*/
    private Forno forno;
    int timer;
    
    public ComandoSetarTimerForno(Forno receiver, int tempoInicial)
    {
        this.forno = receiver;
        this.timer = tempoInicial;
    }
    
    public void setTempoTimer(int novoTempo)
    {
        System.out.println("-> Setando novo tempo do comando para " + novoTempo + " minutos");
        this.timer = novoTempo;
    }
    
    public void executar()
    {
        this.forno.setarTemperatura(timer);
    }
    
    public void desfazer()
    {
        
    }
}
