/*
Programa: Aula Pratica 11 - POO1
Aluno: Marcelo Mendonca Borges
Data: 06/07/2017
*/

package aulapratica11parte1;

public class AulaPratica11Parte1
{
    public static void main(String[] args)
    {
        int i, elemento;
        Stack pilha;
        pilha = new Stack(10);
        
        /*Codigo para tentar empilhar 11 elementos em uma pilha de tamanho 10--------------------*/
        
        /*
        for(i = 0; i < 11; i++)
        {
            pilha.push(i);
        }
        pilha.printStack("pilha");
        */
        
        /*---------------------------------------------------------------------------------------*/
        /*Codigo para tentar empilhar 11 elementos em uma pilha de tamanho 10--------------------*/
        
        /*
        for(i = 0; i < 10; i++)
        {
            pilha.push(i);
        }
        for(i = 0; i < 11; i++)
        {
            elemento = pilha.pop();
            System.out.print("(" + elemento + ") - ");
        }
        pilha.printStack("pilha");
        */
        
        /*---------------------------------------------------------------------------------------*/
    }
}
