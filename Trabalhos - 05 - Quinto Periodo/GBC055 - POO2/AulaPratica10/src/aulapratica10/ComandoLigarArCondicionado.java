
package aulapratica10;

public class ComandoLigarArCondicionado implements Comando
{
    /*CONCRETE_COMMAND*/
    private ArCondicionado arCondicionado;
    
    public ComandoLigarArCondicionado(ArCondicionado receiver)
    {
        this.arCondicionado = receiver;
    }
    
    public void executar()
    {
        this.arCondicionado.ligar();
    }      
    
    public void desfazer()
    {
        
    }
}
