/*
Programa: Aula Pratica 06 - POO1
Aluno: Marcelo Mendonca Borges
Data: 18/05/2017
*/

package prova01poo1;

import java.util.*;
import javax.swing.*;

public class Prova01POO1
{
    public static void main(String[] args)
    {
        int quantidade;
        String resultado;
        Jogo jogo;
        Jogador jogador;
        Vector<Jogador> vencedores;
        
        quantidade = Integer.parseInt(JOptionPane.showInputDialog("Quantidade de Jogadores"));
        jogo = new Jogo(quantidade);
        resultado = "Vencedores:\n\n";
        
        jogo.executarJogo();
        vencedores = jogo.jogadoresVencedores();
        
        for (int i = 0; i < vencedores.size(); i++)
        {
            jogador = vencedores.get(i);
            resultado += "Jogador: " + jogador.getNome() + "\n" + "Pontos: " + jogador.getPontos() + "\n\n";
        }
        
        JOptionPane.showMessageDialog(null, resultado);
    }
}
