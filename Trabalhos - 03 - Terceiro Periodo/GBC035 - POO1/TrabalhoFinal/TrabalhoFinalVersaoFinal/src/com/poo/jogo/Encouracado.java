package com.poo.jogo;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Encouracado extends Embarcacoes {

    String[] imagensEncouracadoHorizontal;
    String[] imagensEncouracadoVertical;

    public Encouracado(int id, int q, String n) {
        super(id, q, n);
        imagensEncouracadoHorizontal = new String[4];
        imagensEncouracadoHorizontal[0] = "EncouracadoHpt1";
        imagensEncouracadoHorizontal[1] = "EncouracadoHpt2";
        imagensEncouracadoHorizontal[2] = "EncouracadoHpt3";
        imagensEncouracadoHorizontal[3] = "EncouracadoHpt4";
        imagensEncouracadoVertical = new String[4];
        imagensEncouracadoVertical[0] = "EncouracadoVpt1";
        imagensEncouracadoVertical[1] = "EncouracadoVpt2";
        imagensEncouracadoVertical[2] = "EncouracadoVpt3";
        imagensEncouracadoVertical[3] = "EncouracadoVpt4";
    }

    public String[] getImagensHorizontal() {
        return this.imagensEncouracadoHorizontal;
    }

    public String[] getImagensVertical() {
        return this.imagensEncouracadoVertical;
    }

    public int inserirEmbarcacao(int[][] matrizInteiros, int linha, int coluna, int direcao) {
        int l, c;
        int aux1 = 0, aux2 = 0;
        int verificaArredores = 0;
        l = linha;
        c = coluna;

        super.inserirPosicao(linha, coluna, direcao);

        if (direcao == 1) {
            if (((c + 1) >= 0) && ((c + 1) <= 9) && ((c + 2) >= 0) && ((c + 2) <= 9) && ((c + 3) >= 0) && ((c + 3) <= 9)) {
                aux1 = 1;
                if ((matrizInteiros[l][c] == 0) && (matrizInteiros[l][c + 1] == 0) && (matrizInteiros[l][c + 2] == 0) && (matrizInteiros[l][c + 3] == 0)) {
                    aux2 = 1;
                }
            }
            if ((aux1 == 1) && (aux2 == 1)) {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l][c + 1] = super.getIdentificadorBarco();
                matrizInteiros[l][c + 2] = super.getIdentificadorBarco();
                matrizInteiros[l][c + 3] = super.getIdentificadorBarco();

                return 1;
            }
        } else if (direcao == 2) {
            if (((l + 1) >= 0) && ((l + 1) <= 9) && ((l + 2) >= 0) && ((l + 2) <= 9) && ((l + 3) >= 0) && ((l + 3) <= 9)) {
                aux1 = 1;
                if ((matrizInteiros[l][c] == 0) && (matrizInteiros[l + 1][c] == 0) && (matrizInteiros[l + 2][c] == 0) && (matrizInteiros[l + 3][c] == 0)) {
                    aux2 = 1;
                }
            }
            if ((aux1 == 1) && (aux2 == 1)) {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l + 1][c] = super.getIdentificadorBarco();
                matrizInteiros[l + 2][c] = super.getIdentificadorBarco();
                matrizInteiros[l + 3][c] = super.getIdentificadorBarco();

                return 1;
            }
        }

        return 0;
    }
}
