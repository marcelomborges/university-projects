
package aulapratica10;

public class ComandoLigarForno implements Comando
{
    /*CONCRETE_COMMAND*/
    private Forno forno;
    
    public ComandoLigarForno(Forno receiver)
    {
        this.forno = receiver;
    }
    
    public void executar()
    {
        this.forno.ligar();
    }
    
    public void desfazer()
    {
        
    }
}
