
package aulapratica10;

public class ComandoDesligarArCondicionado implements Comando
{
    /*CONCRETE_COMMAND*/
    private ArCondicionado arCondicionado;
    
    public ComandoDesligarArCondicionado(ArCondicionado receiver)
    {
        this.arCondicionado = receiver;
    }
    
    public void executar()
    {
        this.arCondicionado.desligar();
    }
    
    public void desfazer()
    {
        
    }
}
