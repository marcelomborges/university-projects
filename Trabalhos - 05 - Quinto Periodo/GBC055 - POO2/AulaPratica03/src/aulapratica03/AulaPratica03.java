/*
Programa: Aula Pratica 03 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 05/04/2018
*/

package aulapratica03;

public class AulaPratica03
{
    public static void main(String[] args)
    {
        Sanduiche pedido1 = new SmokinSickSandwich();
        pedido1 = new Bacon(pedido1);
        pedido1 = new Cebola(pedido1);
        pedido1 = new Hamburguer(pedido1);
        pedido1 = new Linguica(pedido1);
        pedido1 = new Milho(pedido1);
        pedido1 = new Ovo(pedido1);
        pedido1 = new Presunto(pedido1);
        pedido1 = new Queijo(pedido1);
        
        Sanduiche pedido2 = new PraiseTheSandwich();
        pedido2 = new Bacon(pedido2);
        pedido2 = new Cebola(pedido2);
        pedido2 = new Linguica(pedido2);
        pedido2 = new Milho(pedido2);
        
        Sanduiche pedido3 = new GalactusSandwich();
        pedido3 = new Hamburguer(pedido3);
        pedido3 = new Bacon(pedido3);
        pedido3 = new Cebola(pedido3);
        pedido3 = new Linguica(pedido3);
        pedido3 = new Queijo(pedido3);
        
        System.out.println("Pedidos: --------------------------------------------------\n");
        
        System.out.println("Pedido 01:");
        System.out.println("-> Sanduiche: " + pedido1.getDescricao());
        System.out.println("-> Total: R$ " + pedido1.calculoPreco() + "\n");
        
        System.out.println("Pedido 02:");
        System.out.println("-> Sanduiche: " + pedido2.getDescricao());
        System.out.println("-> Total: R$ " + pedido2.calculoPreco() + "\n");
        
        System.out.println("Pedido 03:");
        System.out.println("-> Sanduiche: " + pedido3.getDescricao());
        System.out.println("-> Total: R$ " + pedido3.calculoPreco() + "\n");
    }    
}
