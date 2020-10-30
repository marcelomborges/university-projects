/*
Programa: Aula Pratica 02 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 29/03/2018
*/
package aulapratica02;

public class AulaPratica02
{
    public static void main(String[] args)
    {
        Servidor servidor = new Servidor(" Capcom: 0.0 \n Konami: 0.0 \n CD Projekt Red: 0.0 \n Warner Bros: 0.0\n");
        HomeBroker homebroker1 = new HomeBroker("HomeBroker1",servidor);
        HomeBroker homebroker2 = new HomeBroker("HomeBroker2",servidor);
        HomeBroker homebroker3 = new HomeBroker("HomeBroker3",servidor);
        
        System.out.println("Aula Pratica 02 - POO2:\n");
        
        System.out.println("Primeira Atualizacao:----------------------------------------------------\n");
        servidor.setValor(" Capcom: 10.0 \n Konami: 20.1 \n CD Projekt Red: 30.2 \n Warner Bros: 40.3\n");
        
        System.out.println("Segunda Atualizacao:----------------------------------------------------\n");
        servidor.setValor(" Capcom: 20.0 \n Konami: 30.1 \n CD Projekt Red: 40.2 \n Warner Bros: 50.3\n");
        
        System.out.println("Terceira Atualizacao:----------------------------------------------------\n");
        servidor.setValor(" Capcom: 30.0 \n Konami: 40.1 \n CD Projekt Red: 50.2 \n Warner Bros: 60.3\n");
    }
}
