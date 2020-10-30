/*
Programa: Aula Pratica 05 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 12/04/2018
*/

package aulapratica05;

public class AulaPratica05
{
    public static void main(String[] args)
    {
        CaixaChain base;
        int vetorQuantidades[] = new int[5];
        
        vetorQuantidades[0] = 10; //Quantidade de notas de 100
        vetorQuantidades[1] = 10; //Quantidade de notas de 50
        vetorQuantidades[2] = 10;  //Quantidade de notas de 20
        vetorQuantidades[3] = 10; //Quantidade de notas de 10
        vetorQuantidades[4] = 0; //Quantidade de notas de 5
        
        base = CaixaChain.ChainFactory(vetorQuantidades); //Factory Method
        
        System.out.println("Teste 01:");
        System.out.println("Quantidade de notas emitidas pelo Caixa Eletronico:");
        base.retornaNotas(1650);
        
        System.out.println("\nTeste 02:");
        System.out.println("Quantidade de notas emitidas pelo Caixa Eletronico:");
        base.retornaNotas(2000);
    }
}
