package aulapratica01;

public class ContaSalario extends Conta
{
    public ContaSalario(String sen, String cli, int nro, int sal)
    {
        super(sen, cli, nro, sal);
        super.setRent(new R_baixa());
        super.setMens(new M_normal());
        super.setMov(new M_simplificada());
        super.setLim(new Ch_bloqueado());
    }
}
