
package testeexcecao1;

public class TabajaraException extends Exception
{
    String mensagem;
    TabajaraException (String msg)
    {
        mensagem = msg;
    }
}
