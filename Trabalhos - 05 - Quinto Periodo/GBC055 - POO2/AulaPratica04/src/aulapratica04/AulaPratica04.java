/*
Programa: Aula Pratica 04 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 05/04/2018
*/

package aulapratica04;

public class AulaPratica04
{
    public static void main(String[] args)
    {
        CaixaChain caixa = new Caixa100();
        caixa.setNext(new Caixa50());
        caixa.setNext(new Caixa20());
        caixa.setNext(new Caixa10());
        caixa.setNext(new Caixa5());
        caixa.setNext(new Caixa2());
        caixa.setNext(new Caixa1());
        
        System.out.println("Quantidade de notas emitidas pelo Caixa Eletronico:\n");
        caixa.retornaNotas(187);
    }
}
