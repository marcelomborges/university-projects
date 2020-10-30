/*
Programa: Aula Pratica 09 - POO2
Alunos: Adriano Araujo Martins de Resende 11611BCC015
        Marcelo Mendonca Borges           11611BCC020
Data: 07/06/2018
*/

package aulapratica09;

public class AulaPratica09
{
    public static void main(String[] args)
    {
        Template contaPoupanca = new Poupanca();
        Template contaPessoaFisica = new CorrentePessoaFisica();
        Template contaPessoaJuridica = new CorrentePessoaJuridica();
        System.out.println("Abrindo Conta Poupanca:------------------------------------------------------------------");
        contaPoupanca.abrirConta("111.111.111-11", "conta1", "senha1", 100, Boolean.TRUE);
        System.out.println("\nAbrindo Conta Corrente Pessoa Fisica:----------------------------------------------------");
        contaPessoaFisica.abrirConta("222.222.222-22", "conta2", "senha2", 200, Boolean.FALSE);
        System.out.println("\nAbrindo Conta Corrente Pessoa Juridica:--------------------------------------------------");
        contaPessoaJuridica.abrirConta("333.333.333-33", "conta3", "senha3", 300, Boolean.TRUE);
    }
}
