package com.poo.jogo;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Cruzador extends Embarcacoes {

    String[] imagensCruzadorHorizontal;
    String[] imagensCruzadorVertical;

    public Cruzador(int id, int q, String n) {
        super(id, q, n);
        imagensCruzadorHorizontal = new String[2];
        imagensCruzadorHorizontal[0] = "CruzadorHpt1";
        imagensCruzadorHorizontal[1] = "CruzadorHpt2";
        imagensCruzadorVertical = new String[2];
        imagensCruzadorVertical[0] = "CruzadorVpt1";
        imagensCruzadorVertical[1] = "CruzadorVpt2";
    }

    public String[] getImagensHorizontal() {
        return this.imagensCruzadorHorizontal;
    }

    public String[] getImagensVertical() {
        return this.imagensCruzadorVertical;
    }

    public int inserirEmbarcacao(int[][] matrizInteiros, int linha, int coluna, int direcao) {
        int l, c;
        l = linha;
        c = coluna;

        super.inserirPosicao(linha, coluna, direcao);

        if (direcao == 1) {
            if (((c + 1) >= 0) && ((c + 1) <= 9) && (matrizInteiros[l][c] == 0) && (matrizInteiros[l][c + 1] == 0)) {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l][c + 1] = super.getIdentificadorBarco();

                return 1;
            }
        } else if (direcao == 2) {
            if (((l + 1) >= 0) && ((l + 1) <= 9) && (matrizInteiros[l][c] == 0) && (matrizInteiros[l + 1][c] == 0)) {
                matrizInteiros[l][c] = super.getIdentificadorBarco();
                matrizInteiros[l + 1][c] = super.getIdentificadorBarco();

                return 1;
            }
        }

        return 0;
    }
}
