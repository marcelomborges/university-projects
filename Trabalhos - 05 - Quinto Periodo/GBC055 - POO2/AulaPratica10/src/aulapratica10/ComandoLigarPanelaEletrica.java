
package aulapratica10;

public class ComandoLigarPanelaEletrica implements Comando
{
    /*CONCRETE_COMMAND*/
    private PanelaEletrica panelaEletrica;
    
    public ComandoLigarPanelaEletrica(PanelaEletrica receiver)
    {
        this.panelaEletrica = receiver;
    }
    
    public void executar()
    {
        this.panelaEletrica.ligar();
    }
    
    public void desfazer()
    {
        
    }
}
