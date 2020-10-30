/*
Programa: Aula Pratica 11 - POO1
Aluno: Marcelo Mendonca Borges
Data: 06/07/2017
*/

package aulapratica11parte2eparte3;

public class AulaPratica11Parte2eParte3
{
    public static void main(String[] args) throws StackEmptyException, StackFullException
    {
        int i;
        int elemento;
        Stack pilha, pilha1, pilha2, pilha3;
        
        pilha = new Stack(10);
        pilha1 = new Stack(10);
        pilha2 = new Stack(10);
        pilha3 = new Stack(10);
        
        /*Codigo pra excecao de pilha cheia nao tratada------------------------------------------*/
        
        /*
        for(i = 0; i < 11; i++)
        {
            pilha.push(i);
        }
        pilha.printStack("pilha");
        */
        
        /*---------------------------------------------------------------------------------------*/
        
        /*Codigo pra excecao de pilha vazia nao tratada------------------------------------------*/
        
        /*
        for(i = 0; i < 10; i++)
        {
            pilha.push(i);
        }
        for(i = 0; i < 11; i++)
        {
            elemento = pilha.pop();
            System.out.print(elemento + " - ");
        }
        pilha.printStack("pilha");
        */
        
        /*---------------------------------------------------------------------------------------*/
        
        /*Codigo pra excecao de pilha cheia tratada----------------------------------------------*/
        System.out.println("(3)b)---------------------------------------------------------------");
        try
        {
            for(i = 0; i < 11; i++)
            {
                pilha1.push(i);
            }
            pilha1.printStack("pilhaNaoImpressa1");
        }
        catch (StackFullException pilhaCheia)
        {
            System.out.println(pilhaCheia.getErrorMessage());
            pilha1.printStack("pilhaImpressa1");
        }
        System.out.println("--------------------------------------------------------------------\n");
        /*---------------------------------------------------------------------------------------*/
        
        /*Codigo pra excecao de pilha cheia e vazia tratada--------------------------------------*/
        System.out.println("(3)c)Parte1:--------------------------------------------------------");
        try
        {
            for(i = 0; i < 11; i++)
            {
                pilha2.push(i);
            }
            pilha2.printStack("pilhaNaoImpressa2.1");
            for(i = 0; i < 10; i++)
            {
                elemento = pilha2.pop();
                System.out.print(elemento + " - ");
            }
            pilha2.printStack("pilhaNaoImpressa2.2");
        }
        catch (StackEmptyException pilhaVazia)
        {
            System.out.println(pilhaVazia.getErrorMessage());
            pilha2.printStack("pilhaNaoImpressa2.3");
        }
        catch (StackFullException pilhaCheia)
        {
            System.out.println(pilhaCheia.getErrorMessage());
            pilha2.printStack("pilhaImpressa2.1");
        }
        System.out.println("--------------------------------------------------------------------\n");
        
        System.out.println("(3)c)Parte2:--------------------------------------------------------");
        try
        {
            for(i = 0; i < 10; i++)
            {
                pilha3.push(i);
            }
            pilha3.printStack("pilhaImpressa3.1");
            for(i = 0; i < 11; i++)
            {
                elemento = pilha3.pop();
                System.out.println("Stack Pop => Elemento: " + elemento);
            }
            pilha3.printStack("pilhaNaoImpressa3.1");
        }
        catch (StackEmptyException pilhaVazia)
        {
            System.out.println(pilhaVazia.getErrorMessage());
            pilha3.printStack("pilhaImpressa3.2");
        }
        catch (StackFullException pilhaCheia)
        {
            System.out.println(pilhaCheia.getErrorMessage());
            pilha3.printStack("pilhaNaoImpressa3.2");
        }
        System.out.println("--------------------------------------------------------------------\n");
        /*---------------------------------------------------------------------------------------*/
    }
}
