
package aulapratica11parte1;

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
    
    public int pop ()
    {
        int elemento;
        
        elemento = this.vetor[indice];
        this.indice--;
        
        return elemento;
    }
    
    public void push (int elemento)
    {
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
