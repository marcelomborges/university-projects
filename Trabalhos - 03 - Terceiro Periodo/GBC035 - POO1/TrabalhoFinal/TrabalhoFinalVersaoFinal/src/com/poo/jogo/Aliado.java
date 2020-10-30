
package com.poo.jogo;

public class Aliado extends Jogador
{
    private int indiceInsercaoProximoBarco;
    
    public Aliado(String nome)
    {
        super(nome);
        this.indiceInsercaoProximoBarco = 0;
    }
    
    public int getIndiceInsercaoProximoBarco()
    {
        return this.indiceInsercaoProximoBarco;
    }
    
    public Boolean restamInserirBarcos()
    {
        return (this.indiceInsercaoProximoBarco < 5);
    }
    
    public int inserirBarcoAliado(int linha, int coluna, int direcao, int indice)
    {
        int controle;
        
        controle = super.getFrota()[indice].inserirEmbarcacao(super.getMatrizNumeros(), linha, coluna, direcao);
        
        if(controle == 1)
        {
            this.indiceInsercaoProximoBarco++;
        }
        
        return controle;
    }
    
    public int ataqueAliado(int[][] matrizNumerosInimiga, int linha, int coluna)
    {
        if(matrizNumerosInimiga[linha][coluna] != 0)
        {
            super.incrementaResultados();
        }
        
        return (matrizNumerosInimiga[linha][coluna]);
    }
    
    /*Metodos realcionados a subclasse Adversario------------------------------------------------*/
    public void inserirFrotaInimiga() {}
    
    public int[] ataqueInimigoAleatorio(int[][] matrizInteiros) {return null;}
    
    public int[] ataqueInimigoEstrategico(int[][] matrizInteiros, int linha, int coluna, int direcao) {return null;}
    /*-------------------------------------------------------------------------------------------*/
}
