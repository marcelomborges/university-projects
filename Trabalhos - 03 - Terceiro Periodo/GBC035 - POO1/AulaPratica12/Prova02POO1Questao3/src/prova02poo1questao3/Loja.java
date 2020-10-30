
package prova02poo1questao3;

public class Loja
{
    int quantidadeAtual;
    int quantidadeMaxima;
    Cliente[] clientes;
    
    public Loja(int quantidade)
    {
        this.clientes = new Cliente[quantidade];
        this.quantidadeMaxima = quantidade;
        this.quantidadeAtual = 0;
    }
    
    public void cadastraClienteVIP(String nome, String endereco)
    {
        if(this.quantidadeAtual == this.quantidadeMaxima)
        {
            System.out.println("=> A Loja chegou ao maximo de clientes. ");
            return;
        }
        
        ClienteVIP novoClienteVIP;
        novoClienteVIP = new ClienteVIP(nome,endereco);
        
        clientes[quantidadeAtual] = novoClienteVIP;
        quantidadeAtual++;
    }
    
    public void cadastraClienteVVIP(String nome, String endereco, String gerente)
    {
        if(this.quantidadeAtual == this.quantidadeMaxima)
        {
            System.out.println("=> A Loja chegou ao maximo de clientes. ");
            return;
        }
        
        ClienteVVIP novoClienteVVIP;
        novoClienteVVIP = new ClienteVVIP(nome,endereco,gerente);
        
        clientes[quantidadeAtual] = novoClienteVVIP;
        quantidadeAtual++;
    }
    
    public void malaDiretaClientes()
    {
        int i;
        
        System.out.println("Mala Direta para cada Cliente da Loja:----------------------------\n");
        for(i = 0; i < quantidadeAtual; i++)
        {
            System.out.println(clientes[i].malaDireta());
            System.out.println("------------------------------------------------------------------");
        }
    }
}
