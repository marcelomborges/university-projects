/*
Programa: Aula Pratica 01 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 22/03/2018
*/
package aulapratica01;

public class AulaPratica01
{
    public static void main(String[] args)
    {
        Conta conta1 = new ContaCorrente("1","cliente1",1,1);
        Conta conta2 = new ContaSalario("2","cliente2",2,2);
        Conta conta3 = new ContaPoupanca("3","cliente3",3,3);
        Conta conta4 = new ContaInvestimento("4","cliente4",4,4);
        Conta conta5 = new ContaUniversitaria("5","cliente5",5,5);
        
        System.out.println("Aula Pratica 01 - POO2:");
        
        System.out.println("\nConta Corrente:");
        conta1.imprimeDadosConta();
           
        System.out.println("\nConta Salario:");
        conta2.imprimeDadosConta();
           
        System.out.println("\nConta Poupanca:");
        conta3.imprimeDadosConta();
        
        System.out.println("\nConta Investimento:");
        conta4.imprimeDadosConta();
        
        System.out.println("\nConta Universitaria:");
        conta5.imprimeDadosConta();
    }
}
