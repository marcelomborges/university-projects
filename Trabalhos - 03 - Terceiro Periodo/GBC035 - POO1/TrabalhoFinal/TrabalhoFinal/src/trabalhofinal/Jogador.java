
package trabalhofinal;

public abstract class Jogador
{
    private String nome;
    private int resultados;
    private Embarcacoes[] frota;
    private int[][] matrizNumeros;
    
    public Jogador(String nome)
    {
        this.nome = nome;
        this.resultados = 0;
        
        
        this.frota = new Embarcacoes[5];
        frota[0] = new Submarino(1,1,"Submarino");
        frota[1] = new Cruzador(2,2,"Cruzador");
        frota[2] = new Fragata(3,3,"Fragata");
        frota[3] = new Encouracado(4,4,"Encouracado");
        frota[4] = new PortaAvioes(5,5,"Porta Avioes");
        
        this.matrizNumeros = new int[10][10];
        for(int i = 0; i < matrizNumeros.length; i++)
        {
            for(int j = 0; j < matrizNumeros[i].length; j++)
            {
                matrizNumeros[i][j] = 0;
            }
        }
    }
    
    public String getNome()
    {
        return this.nome;
    }
    
    public int getResultados()
    {
        return this.resultados;
    }
    
    public void incrementaResultados()
    {
        this.resultados++;
    }
    
    public Embarcacoes getEmbarcacao(int indice)
    {
        return this.frota[indice];
    }
    
    public Embarcacoes[] getFrota()
    {
        return this.frota;
    }
    
    public int[][] getMatrizNumeros()
    {
        return this.matrizNumeros;
    }
    
    public void tomarTiro(int linha, int coluna)
    {
        this.matrizNumeros[linha][coluna] = (-1);
    }
    
    public Boolean venceuJogo()
    {
        return (this.resultados == 15);
    }
    
    /*Metodos realcionados a subclasse Aliado----------------------------------------------------*/
    public abstract int getIndiceInsercaoProximoBarco();
    
    public abstract Boolean restamInserirBarcos();
    
    public abstract int inserirBarcoAliado(int linha, int coluna, int direcao, int indice);
    
    public abstract int ataqueAliado(int[][] matrizNumerosInimiga, int linha, int coluna);
    /*-------------------------------------------------------------------------------------------*/
    
    /*Metodos realcionados a subclasse Adversario------------------------------------------------*/
    public abstract void inserirFrotaInimiga();
    
    public abstract int[] ataqueInimigoAleatorio(int[][] matrizInteiros);
    
    public abstract int[] ataqueInimigoEstrategico(int[][] matrizInteiros, int linha, int coluna, int direcao);
    /*-------------------------------------------------------------------------------------------*/
}
