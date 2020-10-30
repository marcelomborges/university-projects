
package trabalhofinal;

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Adversario extends Jogador
{
    public Adversario(String nome)
    {
        super(nome);
    }
    
    public void inserirFrotaInimiga()
    {
        int linha, coluna, direcao, controle;
        int barcoInimigo = 0;
        Random gerador = new Random();
        
        do
        {
            linha = gerador.nextInt(10);
            coluna = gerador.nextInt(10);
            direcao = (gerador.nextInt(2)) + 1;
            controle = super.getFrota()[barcoInimigo].inserirEmbarcacao(super.getMatrizNumeros(), linha, coluna, direcao);
            if(controle == 1) barcoInimigo++;
        }
        while(barcoInimigo < 5);
    }
    
    public int[] ataqueInimigoAleatorio(int[][] matrizInteiros)
    {
        int linha, coluna, direcao;
        Random gerador = new Random();
        
        /*Retorno da funcao----------------------------------------------------------------------*/
        /*
        A funcao retornara um vetor de 3 elementos:
        retorno[0] = identificador do barco
        retorno[1] = linha do tiro
        retorno[2] = coluna do tiro
        retorno[3] = direcao para seguir se acertar um barco, inicia aleatoriamente
        */
        int[] retorno = new int[4];
        /*---------------------------------------------------------------------------------------*/
        
        /*Gerando posicao aleatoria valida-------------------------------------------------------*/
        do
        {
            linha = gerador.nextInt(10);
            coluna = gerador.nextInt(10);
            direcao = gerador.nextInt(4);
        }
        while(matrizInteiros[linha][coluna] == (-1));
        
        if(matrizInteiros[linha][coluna] != 0)
        {
            super.incrementaResultados();
            JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
        }
        
        retorno[0] = matrizInteiros[linha][coluna];
        retorno[1] = linha;
        retorno[2] = coluna;
        retorno[3] = direcao;
        
        return retorno;
    }
    
    public int[] ataqueInimigoEstrategico(int[][] matrizInteiros, int linha, int coluna, int direcao)
    {
        int l, c, d;
        
        l = linha;
        c = coluna;
        d = direcao;
        
        /*Retorno da funcao----------------------------------------------------------------------*/
        /*
        A funcao retornara um vetor de 3 elementos:
        retorno[0] = identificador do barco
        retorno[1] = linha do tiro
        retorno[2] = coluna do tiro
        retorno[3] = direcao para seguir se acertar um barco
        */
        int[] retorno = new int[4];
        /*---------------------------------------------------------------------------------------*/
        
        if(d == 0)
        {
            if(((l-1) >= 0)&&((l-1) <= 9))/*Tentando marcar na linha de cima*/
            {
                if(matrizInteiros[l-1][c] != (-1))
                {
                    if(matrizInteiros[l-1][c] != 0)
                    {
                        super.incrementaResultados();
                        JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                    }
                    retorno[0] = matrizInteiros[l-1][c];
                    retorno[1] = l-1;
                    retorno[2] = c;
                    retorno[3] = 0;
                    return retorno;
                }
            }
        }
        else if(d == 1)
        {
            if(((l+1) >= 0)&&((l+1) <= 9))/*Tentando marcar na linha de baixo*/
            {
                if(matrizInteiros[l+1][c] != (-1))
                {
                    if(matrizInteiros[l+1][c] != 0)
                    {
                        super.incrementaResultados();
                        JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                    }
                    retorno[0] = matrizInteiros[l+1][c];
                    retorno[1] = l+1;
                    retorno[2] = c;
                    retorno[3] = 1;
                    return retorno;
                }
            }
        }
        else if(d == 2)
        {
            if(((c-1) >= 0)&&((c-1) <= 9))/*Tentando marcar na coluna da esquerda*/
            {
                if(matrizInteiros[l][c-1] != (-1))
                {
                    if(matrizInteiros[l][c-1] != 0)
                    {
                        super.incrementaResultados();
                        JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                    }

                    retorno[0] = matrizInteiros[l][c-1];
                    retorno[1] = l;
                    retorno[2] = c-1;
                    retorno[3] = 2;
                    return retorno;
                }
            }
        }
        else if(d == 3)
        {
            if(((c+1) >= 0)&&((c+1) <= 9))/*Tentando marcar na coluna da direita*/
            {
                if(matrizInteiros[l][c+1] != (-1))
                {
                    if(matrizInteiros[l][c+1] != 0)
                    {
                        super.incrementaResultados();
                        JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                    }

                    retorno[0] = matrizInteiros[l][c+1];
                    retorno[1] = l;
                    retorno[2] = c+1;
                    retorno[3] = 3;
                    return retorno;
                }
            }
        }
        
        if(((l-1) >= 0)&&((l-1) <= 9))/*Tentando marcar na linha de cima*/
        {
            if(matrizInteiros[l-1][c] != (-1))
            {
                if(matrizInteiros[l-1][c] != 0)
                {
                    super.incrementaResultados();
                    JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                }
                retorno[0] = matrizInteiros[l-1][c];
                retorno[1] = l-1;
                retorno[2] = c;
                retorno[3] = 0;
                return retorno;
            }
        }
        if(((l+1) >= 0)&&((l+1) <= 9))/*Tentando marcar na linha de baixo*/
        {
            if(matrizInteiros[l+1][c] != (-1))
            {
                if(matrizInteiros[l+1][c] != 0)
                {
                    super.incrementaResultados();
                    JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                }
                retorno[0] = matrizInteiros[l+1][c];
                retorno[1] = l+1;
                retorno[2] = c;
                retorno[3] = 1;
                return retorno;
            }
        }
        if(((c-1) >= 0)&&((c-1) <= 9))/*Tentando marcar na coluna da esquerda*/
        {
            if(matrizInteiros[l][c-1] != (-1))
            {
                if(matrizInteiros[l][c-1] != 0)
                {
                    super.incrementaResultados();
                    JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                }
                
                retorno[0] = matrizInteiros[l][c-1];
                retorno[1] = l;
                retorno[2] = c-1;
                retorno[3] = 2;
                return retorno;
            }
        }
        if(((c+1) >= 0)&&((c+1) <= 9))/*Tentando marcar na coluna da direita*/
        {
            if(matrizInteiros[l][c+1] != (-1))
            {
                if(matrizInteiros[l][c+1] != 0)
                {
                    super.incrementaResultados();
                    JOptionPane.showMessageDialog(null, "Sua embarcacao levou um tiro.");
                }
                
                retorno[0] = matrizInteiros[l][c+1];
                retorno[1] = l;
                retorno[2] = c+1;
                retorno[3] = 3;
                return retorno;
            }
        }
        
        retorno = this.ataqueInimigoAleatorio(matrizInteiros);
        
        return retorno;
    }
    
    /*Metodos realcionados a subclasse Aliado----------------------------------------------------*/
    public int getIndiceInsercaoProximoBarco() {return 0;}
    
    public Boolean restamInserirBarcos() {return false;}
    
    public int inserirBarcoAliado(int linha, int coluna, int direcao, int indice) {return 0;}
    
    public int ataqueAliado(int[][] matrizNumerosInimiga, int linha, int coluna) {return 0;}
    /*-------------------------------------------------------------------------------------------*/
}

