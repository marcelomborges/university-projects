/*
Programa: Aula Pratica 06 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 10/05/2018
*/

package aulapratica06;

import java.sql.Date;

public class AulaPratica06
{
    public static void main(String[] args)
    {
        Account ac = new Account(0);
        BalanceCalculator ba = new BalanceCalculatorA();
        BalanceAdapter ad = new BalanceAdapter(ba);
        BalanceResolver br = ad;
        Date date = Date.valueOf("2018-05-10");
        
        ad.balanceFor(ac, date);
    }
    
}
