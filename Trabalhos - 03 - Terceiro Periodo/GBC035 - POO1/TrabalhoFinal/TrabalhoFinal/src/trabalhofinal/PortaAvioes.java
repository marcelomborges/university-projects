
package trabalhofinal;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class PortaAvioes extends Embarcacoes
{
    String[] imagensPortaAvioesHorizontal;
    String[] imagensPortaAvioesVertical;
    
    public PortaAvioes(int id, int q, String n)
    {
        super(id,q,n);
        imagensPortaAvioesHorizontal = new String[5];
        imagensPortaAvioesHorizontal[0] = "/imagens/barco5";
        imagensPortaAvioesHorizontal[1] = "/imagens/barco5";
        imagensPortaAvioesHorizontal[2] = "/imagens/barco5";
        imagensPortaAvioesHorizontal[3] = "/imagens/barco5";
        imagensPortaAvioesHorizontal[4] = "/imagens/barco5";
        imagensPortaAvioesVertical = new String[5];
        imagensPortaAvioesVertical[0] = "/imagens/barco5";
        imagensPortaAvioesVertical[1] = "/imagens/barco5";
        imagensPortaAvioesVertical[2] = "/imagens/barco5";
        imagensPortaAvioesVertical[3] = "/imagens/barco5";
        imagensPortaAvioesVertical[4] = "/imagens/barco5";
    }
    
    public String[] getImagensHorizontal()
    {
        return this.imagensPortaAvioesHorizontal;
    }
    
    public String[] getImagensVertical()
    {
        return this.imagensPortaAvioesVertical;
    }
    
    public int inserirEmbarcacao(int[][] matrizInteiros, int linha, int coluna, int direcao)
    {
        int l,c;
        int aux1 = 0, aux2 = 0;
        int verificaArredores = 0;
        l = linha;
        c = coluna;
        
        super.inserirPosicao(linha, coluna, direcao);
        
        if(direcao == 1)
        {
            if(((c+1) >= 0)&&((c+1) <= 9)&&((c+2) >= 0)&&((c+2) <= 9)&&((c+3) >= 0)&&((c+3) <= 9)&&((c+4) >= 0)&&((c+4) <= 9))
            {
                aux1 = 1;
                if((matrizInteiros[l][c] == 0)&&(matrizInteiros[l][c+1] == 0)&&(matrizInteiros[l][c+2]==0)&&(matrizInteiros[l][c+3] == 0)&&(matrizInteiros[l][c+4]==0))
                {
                    aux2 = 1;
                }
            }
            if((aux1 == 1)&&(aux2 == 1))
            {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l][c+1] = super.getIdentificadorBarco();
                matrizInteiros[l][c+2] = super.getIdentificadorBarco();
                matrizInteiros[l][c+3] = super.getIdentificadorBarco();
                matrizInteiros[l][c+4] = super.getIdentificadorBarco();
                
                return 1;
            }
        }
        else if(direcao == 2)
        {
            if(((l+1) >= 0)&&((l+1) <= 9)&&((l+2) >= 0)&&((l+2) <= 9)&&((l+3) >= 0)&&((l+3) <= 9)&&((l+4) >= 0)&&((l+4) <= 9))
            {
                aux1 = 1;
                if((matrizInteiros[l][c] == 0)&&(matrizInteiros[l+1][c] == 0)&&(matrizInteiros[l+2][c]==0)&&(matrizInteiros[l+3][c] == 0)&&(matrizInteiros[l+4][c]==0))
                {
                    aux2 = 1;
                }
            }
            if((aux1 == 1)&&(aux2 == 1))
            {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l+1][c] = super.getIdentificadorBarco();
                matrizInteiros[l+2][c] = super.getIdentificadorBarco();
                matrizInteiros[l+3][c] = super.getIdentificadorBarco();
                matrizInteiros[l+4][c] = super.getIdentificadorBarco();
                
                return 1;
            }
        }
        
        return 0;
    }
}
