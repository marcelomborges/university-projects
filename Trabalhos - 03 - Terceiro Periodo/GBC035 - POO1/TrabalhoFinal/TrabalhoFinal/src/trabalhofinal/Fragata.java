
package trabalhofinal;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Fragata extends Embarcacoes
{
    String[] imagensFragataHorizontal;
    String[] imagensFragataVertical;
    
    public Fragata(int id, int q, String n)
    {
        super(id,q,n);
        imagensFragataHorizontal = new String[3];
        imagensFragataHorizontal[0] = "/imagens/barco3";
        imagensFragataHorizontal[1] = "/imagens/barco3";
        imagensFragataHorizontal[2] = "/imagens/barco3";
        imagensFragataVertical = new String[3];
        imagensFragataVertical[0] = "/imagens/barco3";
        imagensFragataVertical[1] = "/imagens/barco3";
        imagensFragataVertical[2] = "/imagens/barco3";
    }
    
    public String[] getImagensHorizontal()
    {
        return this.imagensFragataHorizontal;
    }
    
    public String[] getImagensVertical()
    {
        return this.imagensFragataVertical;
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
            if(((c+1) >= 0)&&((c+1) <= 9)&&((c+2) >= 0)&&((c+2) <= 9))
            {
                aux1 = 1;
                if((matrizInteiros[l][c] == 0)&&(matrizInteiros[l][c+1] == 0)&&(matrizInteiros[l][c+2]==0))
                {
                    aux2 = 1;
                }
            }
            if((aux1 == 1)&&(aux2 == 1))
            {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l][c+1] = super.getIdentificadorBarco();
                matrizInteiros[l][c+2] = super.getIdentificadorBarco();
                
                return 1;
            }
        }
        else if(direcao == 2)
        {
            if(((l+1) >= 0)&&((l+1) <= 9)&&((l+2) >= 0)&&((l+2) <= 9))
            {
                aux1 = 1;
                if((matrizInteiros[l][c] == 0)&&(matrizInteiros[l+1][c] == 0)&&(matrizInteiros[l+2][c] == 0))
                {
                    aux2 = 1;
                }
            }
            if((aux1 == 1)&&(aux2 == 1))
            {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l+1][c] = super.getIdentificadorBarco();
                matrizInteiros[l+2][c] = super.getIdentificadorBarco();
                
                return 1;
            }
        }
        
        return 0;
    }
}
