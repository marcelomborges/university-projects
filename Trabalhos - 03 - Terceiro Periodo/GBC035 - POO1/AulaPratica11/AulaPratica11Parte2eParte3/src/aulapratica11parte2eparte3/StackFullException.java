
package aulapratica11parte2eparte3;

public class StackFullException extends Exception
{
    private String mensagemDeErro;
    
    public StackFullException (String mensagem)
    {
        this.mensagemDeErro = mensagem;
    }
    
    public String getErrorMessage()
    {
        return this.mensagemDeErro;
    }
}
