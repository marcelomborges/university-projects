package aulapratica06;

import java.util.Calendar;
import java.util.Date;

public class BalanceAdapter implements BalanceResolver
{
    BalanceCalculator bc;
    
    public BalanceAdapter(BalanceCalculator bbc){
        bc = bbc;
    }
    
    public double balanceFor(Account account,Date date){
        Calendar cald = Calendar.getInstance();
        cald.setTime(date);
        
        return bc.calculateBalance(account.nro, cald);
    }
}
