
package trabalhofinal;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public abstract class Embarcacoes
{
    private int identificadorBarco;
    private String nomeBarco;
    private int numQuadrados;
    private int tirosTomados;
    
    private int linhaPrincipal;
    private int colunaPrincipal;
    private int direcaoBarco;
    
    public Embarcacoes (int identificador, int quadrados, String nome)
    {
        this.identificadorBarco = identificador;
        this.numQuadrados = quadrados;
        this.nomeBarco = nome;
        this.tirosTomados = 0;
    }
    
    public void inserirPosicao(int linha, int coluna, int direcao)
    {
        this.linhaPrincipal = linha;
        this.colunaPrincipal = coluna;
        this.direcaoBarco = direcao;
    }
    
    public int getIdentificadorBarco()
    {
        return this.identificadorBarco;
    }
    
    public String getNomeBarco()
    {
        return this.nomeBarco;
    }
    
    public int getNumQuadrados()
    {
        return this.numQuadrados;
    }
    
    public int getLinhaPrincipal()
    {
        return this.linhaPrincipal;
    }
    
    public int getColunaPrincipal()
    {
        return this.colunaPrincipal;
    }
    
    public int getDirecaoBarco()
    {
        return this.direcaoBarco;
    }
    
    public void levouTiro()
    {
        this.tirosTomados++;
    }
    
    public Boolean afundou()
    {
        return (this.tirosTomados == this.numQuadrados);
    }
    
    public abstract String[] getImagensHorizontal();
    
    public abstract String[] getImagensVertical();
    
    public abstract int inserirEmbarcacao(int[][] matrizInteiros, int linha, int coluna, int direcao);
}
