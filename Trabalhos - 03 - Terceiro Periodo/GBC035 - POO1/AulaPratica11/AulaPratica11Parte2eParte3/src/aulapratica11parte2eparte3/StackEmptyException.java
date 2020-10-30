
package aulapratica11parte2eparte3;

public class StackEmptyException extends Exception
{
    private String mensagemDeErro;
    
    public StackEmptyException (String mensagem)
    {
        this.mensagemDeErro = mensagem;
    }
    
    public String getErrorMessage()
    {
        return this.mensagemDeErro;
    }
}
