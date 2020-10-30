package aulapratica01;

public class ContaPoupanca extends Conta
{
    public ContaPoupanca(String sen, String cli, int nro, int sal)
    {
        super(sen, cli, nro, sal);
        super.setRent(new R_normal());
        super.setMens(new M_baixa());
        super.setMov(new M_simplificada());
        super.setLim(new Ch_bloqueado());
    }
}
