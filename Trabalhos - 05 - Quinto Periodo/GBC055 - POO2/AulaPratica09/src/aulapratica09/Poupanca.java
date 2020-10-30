package aulapratica09;

public class Poupanca extends Template
{
    public Poupanca()
    {       
        saldo = 0;
    }

    public void cadastrar()
    {
        System.out.println("-> Cadastrando pessoa física");
    }

    public void validar()
    {
        System.out.println("-> Validando Pessoa Física no SPC");
    }
}
