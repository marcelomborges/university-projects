package aulapratica10;

public class PanelaEletrica
{
    /*RECEIVER*/
    public String estado;
    
    public PanelaEletrica()
    {
        this.estado = "desligado";
    }
    
    public void ligar()
    {
        System.out.println("-> Ligando Panela Eletrica");
        this.estado = "ligado";
        System.out.println("-> Funcionando...");
        System.out.println("-> Desligando Panela Eletrica");
        this.estado = "desligado";
    }
}
