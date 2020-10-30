
package prova02poo1questao3;

public class ClienteVVIP extends Cliente
{
    String gerente;
    
    public ClienteVVIP (String n, String e, String g)
    {
        super(n,e);
        this.gerente = g;
    }

    public String malaDireta()
    {
        String string;
        
        string = (super.getNome() + "\n" + super.getEndereco() + "\n\n" + super.getNome() + ",\n" + 
                "   Quanta alegria em te convidar a tomar um cafézinho com o nosso gerente " + this.gerente + ".\n"
                + " Estaremos em promoção no dia 23/07 e convidamos você a aproveitar 50% de desconto em toda nossa loja.");
        
        return string;
    }
}
