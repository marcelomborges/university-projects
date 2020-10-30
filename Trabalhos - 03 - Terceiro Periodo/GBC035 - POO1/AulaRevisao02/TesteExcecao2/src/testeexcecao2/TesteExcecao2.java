
package testeexcecao2;

public class TesteExcecao2 { // Arquivo TesteExcecao2.java

    public static void main(String args[]) throws Exception
    {
        try
        {
            new A().f(2);
            System.out.println("Depois do f no main");
        }
        catch (TabajaraException e)
        {
            System.out.println(e.mensagem);
        }
        finally
        {
            System.out.println("Antes do fim do main");
        }
        System.out.println("Fim");
    }
}
