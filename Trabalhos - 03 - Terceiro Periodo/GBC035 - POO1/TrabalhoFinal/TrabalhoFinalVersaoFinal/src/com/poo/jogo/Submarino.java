package com.poo.jogo;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Submarino extends Embarcacoes {

    String[] imagensSubmarinoHorizontal;
    String[] imagensSubmarinoVertical;

    public Submarino(int id, int q, String n) {
        super(id, q, n);
        this.imagensSubmarinoHorizontal = new String[1];
        imagensSubmarinoHorizontal[0] = "SubmarinoH";
        this.imagensSubmarinoVertical = new String[1];
        imagensSubmarinoVertical[0] = "SubmarinoV";
    }

    public String[] getImagensHorizontal() {
        return this.imagensSubmarinoHorizontal;
    }

    public String[] getImagensVertical() {
        return this.imagensSubmarinoVertical;
    }

    public int inserirEmbarcacao(int[][] matrizInteiros, int linha, int coluna, int direcao) {
        int l, c;
        l = linha;
        c = coluna;

        super.inserirPosicao(linha, coluna, direcao);

        if (matrizInteiros[l][c] == 0) {
            matrizInteiros[l][c] = super.getIdentificadorBarco();
            return 1;
        }

        return 0;
    }
}
