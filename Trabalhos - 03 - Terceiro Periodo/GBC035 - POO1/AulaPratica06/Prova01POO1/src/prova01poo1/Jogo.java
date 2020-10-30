
package prova01poo1;

import java.util.*;
import javax.swing.*;

public class Jogo
{
    int quantidadeJogadores, maxPontos;
    Vector<Jogador> jogadores;
    Vector<Jogador> vencedores;

    public Jogo(int n)
    {
        maxPontos = 15;
        quantidadeJogadores = n;
        jogadores = new Vector<Jogador>();
        vencedores = new Vector<Jogador>();
        
        String nome;
        Jogador j;
        
        for (int i = 0; i < n; i++)
        {
            nome = JOptionPane.showInputDialog("Nome do jogador " + i + ": ");
            j = new Jogador(nome);
            jogadores.add(j);
        }
    }

    public boolean existeVencedor()
    {
        Jogador j;
        
        for (int i = 0; i < quantidadeJogadores; i++)
        {
            j = jogadores.get(i);
            if (j.getPontos() >= maxPontos)
            {
                return true;
            }
        }
        
        return false;
    }

    public Vector<Jogador> jogadoresVencedores()
    {
        int maiorPontuacao = 0;
        Jogador j;
        
        for (int i = 0; i < quantidadeJogadores; i++)
        {
            j = jogadores.get(i);
            if ((j.getPontos() >= maxPontos) && (j.getPontos() > maiorPontuacao))
            {
                maiorPontuacao = j.getPontos();
            }
        }
        
        for (int i = 0; i < quantidadeJogadores; i++)
        {
            j = jogadores.get(i);
            if (j.getPontos() >= maiorPontuacao)
            {
                vencedores.add(j);
            }
        }
        
        return vencedores;
    }

    public void executarJogo()
    {
        int resultado;
        String resultados;
        Jogador jogador;
        
        do
        {
            for (int i = 0; i < quantidadeJogadores; i++)
            {
                resultado = ((int) (Math.random() * 6) + 1);
                jogador = jogadores.get(i);
                jogador.addPontuacao(resultado);
            }
        }
        while (this.existeVencedor() == false);
        
        resultados = "Jogadores:\n\n";
        
        for (int i = 0; i < quantidadeJogadores; i++)
        {
             
            jogador = jogadores.get(i);
            resultados += "Jogador: " + jogador.getNome() + "\n" + "Pontos: " + jogador.getPontos() + "\n\n";
        }
        
        JOptionPane.showMessageDialog(null, resultados);
    }
}
