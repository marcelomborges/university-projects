
package aulapratica09;

public class Contato
{
    private String nome;
    private String telefone;
    private String endereco;
    
    public Contato (String name, String phone, String adress)
    {
        this.nome = name;
        this.telefone = phone;
        this.endereco = adress;
    }
    
    public String getNome()
    {
        return nome;
    }
    
    public String getTelefone()
    {
        return telefone;
    }
    
    public String getEndereco()
    {
        return endereco;
    }
}
