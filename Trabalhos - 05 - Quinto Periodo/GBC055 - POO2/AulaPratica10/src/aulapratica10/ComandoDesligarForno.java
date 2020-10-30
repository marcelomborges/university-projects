
package aulapratica10;

public class ComandoDesligarForno implements Comando
{
    /*CONCRETE_COMMAND*/
    private Forno forno;
    
    public ComandoDesligarForno(Forno receiver)
    {
        this.forno = receiver;
    }
    
    public void executar()
    {
        this.forno.desligar();
    }
    
    public void desfazer()
    {
        
    }
}
