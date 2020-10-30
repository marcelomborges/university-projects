package aulapratica01;

public class ContaCorrente extends Conta
{
    public ContaCorrente(String sen, String cli, int nro, int sal)
    {
        super(sen, cli, nro, sal);
        super.setRent(new R_baixa());
        super.setMens(new M_normal());
        super.setMov(new M_completa());
        super.setLim(new Ch_liberado());
    }
}
