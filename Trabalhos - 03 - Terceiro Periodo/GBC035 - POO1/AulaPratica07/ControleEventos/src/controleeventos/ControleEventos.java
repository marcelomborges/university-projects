/*
Programa: Aula Pratica 07 - POO1
Aluno: Marcelo Mendonca Borges
Data: 01/06/2017
*/

package controleeventos;

import javax.swing.*;

public class ControleEventos {

    public static void main(String args[]) {
        
        String n = JOptionPane.showInputDialog("Entre com o nome do Evento");
        int max = Integer.parseInt(JOptionPane.showInputDialog("Entre com o maximo de participantes"));
        
        Evento e = new Evento(n, max);
        int opcao;
        
        do
        {
            opcao = Integer.parseInt(JOptionPane.showInputDialog("Entre com opcao: 0 - Participantes simples; 1 - Palestrante; 2 - Apres. Poster; 3 - Apres. Artigo; 4 - Sair"));
            String t;
            
            if (opcao != 4)
            {
                n = JOptionPane.showInputDialog("Entre com o nome do participante");
                if (opcao == 0)
                {
                    e.addParticipante(new Participante(n, e));
                }
                else
                {
                    t = JOptionPane.showInputDialog("Entre com o titulo");
                    if (opcao == 1)
                    {
                        e.addParticipante(new Palestrante(n, e, t));
                    }
                    else if (opcao == 2)
                    {
                        e.addParticipante(new ApresentadorPoster(n, e, t));
                    }
                    else if (opcao == 3)
                    {
                        e.addParticipante(new ApresentadorArtigo(n, e, t));
                    }
                }
            }
        }
        while (opcao != 4);
        
        JOptionPane.showMessageDialog(null, e.certificados());
        JOptionPane.showMessageDialog(null, e.listaDePresenca());
    }
}
