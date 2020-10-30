
package prova02poo1questao3;

public abstract class Cliente
{
    String nome;
    String endereco;
    
    public Cliente (String n, String e)
    {
        this.nome = n;
        this.endereco = e;
    }
    
    public String getNome()
    {
        return this.nome;
    }
    
    public String getEndereco()
    {
        return this.endereco;
    }
    
    public abstract String malaDireta();
}
