/*
Programa: Aula Pratica 09 - Teste da Janela Simples - POO1
Aluno: Marcelo Mendonca Borges
Data: 22/06/2017
*/

package janelasimples;

import java.awt.event.*;
import javax.swing.*;

public class JanelaSimples
{
    public JanelaSimples()
    {    
        final JButton botaoLimpa = new JButton("Limpa"); //botão
        
        final JTextField campoTexto = new JTextField(10); //texto
        campoTexto.setText("Java");
        
        final JFrame janela = new JFrame("Janela Simples"); //janela
        janela.setSize(300, 100);
        
        JPanel painel = new JPanel(); // adiciona componentes
        painel.add(botaoLimpa);
        painel.add(campoTexto);
        janela.getContentPane().add(painel);
        
        //Quando o usuário clicar no botao, limpa o campo de texto
        botaoLimpa.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                campoTexto.setText("");
            }
        });
        
        janela.setVisible(true);
    }

    public static void main(String[] args)
    {
        JanelaSimples janela = new JanelaSimples();
    }
}
