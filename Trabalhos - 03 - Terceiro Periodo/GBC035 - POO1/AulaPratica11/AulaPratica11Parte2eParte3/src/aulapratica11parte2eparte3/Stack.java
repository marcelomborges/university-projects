
package aulapratica11parte2eparte3;

public class Stack
{
    private int[] vetor;
    private int indice;
    
    public Stack (int tamanho)
    {
        this.vetor = new int[tamanho];
        this.indice = -1;
    }
    
    public int isEmpty ()
    {
        if(this.indice == (-1))
        {
            return 1;
        }
        
        return 0;
    }
    
    public int isFull ()
    {
        if(this.indice >= (this.vetor.length - 1))
        {
            return 1;
        }
        
        return 0;
    }
    
    public int pop () throws StackEmptyException
    {
        int elemento;
        
        if(this.isEmpty() == 1)
        {
            throw new StackEmptyException("-> Erro: Falha no pop, pilha vazia.");
        }
        
        elemento = this.vetor[indice];
        this.indice--;
        
        return elemento;
    }
    
    public void push (int elemento) throws StackFullException
    {
        if(this.isFull() == 1)
        {
            throw new StackFullException("-> Erro: Falha no push, pilha cheia.");
        }
        
        this.indice++;
        this.vetor[indice] = elemento;
    }
    
    public void printStack (String nome)
    {
        int i;
        
        System.out.println("Stack " + nome + ":");
        for(i = 0; i < this.indice; i++)
        {
            System.out.print(vetor[i] + " ");
        }
        System.out.println("");
    }
}
