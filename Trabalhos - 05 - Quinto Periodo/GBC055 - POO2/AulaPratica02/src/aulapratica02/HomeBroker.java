package aulapratica02;

public class HomeBroker implements Observador
{
    String nome;
    Sujeito servidor;
    
    public HomeBroker (String name, Sujeito server)
    {
        this.nome = name;
        this.servidor = server;
        servidor.registrarObservador(this);
    }
    
    public void atualizar(String valores)
    {
        System.out.println("HomeBroker" + nome + " :");
        System.out.println(valores);
    }
}
