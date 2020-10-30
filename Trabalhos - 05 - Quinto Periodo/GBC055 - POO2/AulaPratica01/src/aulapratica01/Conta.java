package aulapratica01;

public abstract class Conta
{
    private String senha;
    private String cliente;
    private int nroconta;
    private int saldo;
    private Rentabilidade rent;
    private Mensalidade mens;
    private Movimentacao mov;
    private Limite lim;

    public Conta(String sen,String cli,int nro,int sal)
    {
        senha = sen;
        cliente = cli;
        nroconta = nro;
        saldo = sal;   
    }
    
    public void setRent(Rentabilidade r)
    {
        this.rent = r;
    }

    public void setMens(Mensalidade m)
    {
        this.mens = m;
    }

    public void setMov(Movimentacao m)
    {
        this.mov = m;
    }

    public void setLim(Limite l)
    {
       this.lim = l;
    }
    
    public void imprimeDadosConta()
    {
        this.rent.tipoRentabilidade();
        this.mens.tipoMensalidade();
        this.mov.tipoMovimentacao();
        this.lim.tipoLimite();
    }
}