package aulapratica01;

public class ContaUniversitaria extends Conta
{
    public ContaUniversitaria(String sen, String cli, int nro, int sal)
    {
        super(sen, cli, nro, sal);
        super.setRent(new R_baixa());
        super.setMens(new M_baixa());
        super.setMov(new M_simplificada());
        super.setLim(new Ch_bloqueado());
    }
}
