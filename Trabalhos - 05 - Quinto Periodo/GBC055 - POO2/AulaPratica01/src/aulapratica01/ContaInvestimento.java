package aulapratica01;

public class ContaInvestimento extends Conta
{
    public ContaInvestimento(String sen, String cli, int nro, int sal)
    {
        super(sen, cli, nro, sal);
        super.setRent(new R_normal());
        super.setMens(new M_baixa());
        super.setMov(new M_completa());
        super.setLim(new Ch_liberado());
    }
}
