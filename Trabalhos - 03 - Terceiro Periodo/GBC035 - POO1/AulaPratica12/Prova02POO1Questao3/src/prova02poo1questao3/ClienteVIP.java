
package prova02poo1questao3;

public class ClienteVIP extends Cliente
{
    public ClienteVIP (String n, String e)
    {
        super(n,e);
    }

    public String malaDireta()
    {
        String string;
        
        string = (super.getNome() + "\n" + super.getEndereco() + "\n\n" + "Prezado(a) " + super.getNome() + ",\n" + 
                "   estaremos em promoção no dia 23/07 e convidamos você a aproveitar 30% de desconto em toda nossa loja.");
        
        return string;
    }
    
    
}
