
package testeminicalculadora;

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MiniCalculadora
{
    public MiniCalculadora ()
    {
        JFrame janela = new JFrame ("Mini Calculadora");
        janela.setSize(500,150);
        janela.setLocationRelativeTo(null);
        janela.setResizable(false);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        JTextField campoDeTextoMultiplicacao1 = new JTextField(10);
        JTextField campoDeTextoMultiplicacao2 = new JTextField(10);
        JTextField campoDeTextoAdicao1 = new JTextField(10);
        JTextField campoDeTextoAdicao2 = new JTextField(10);
        
        JLabel simboloMultiplicacao = new JLabel("*");
        JLabel simboloAdicao = new JLabel("+");
        
        JTextField campoResultadoMultiplicacao = new JTextField(10);
        JTextField campoResultadoAdicao = new JTextField(10);
        
        JButton operacaoMultiplicacao = new JButton("=");
        JButton operacaoAdicao = new JButton("=");
        
        JPanel painel = new JPanel();
        painel.setLayout(new GridLayout(2,1));
        
        JPanel painelMultiplicacao = new JPanel();
        JPanel painelAdicao = new JPanel();
        
        ActionListener multiplicacao = new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                int operando1, operando2, resultado;
                
                try
                {
                    operando1 = Integer.parseInt(campoDeTextoMultiplicacao1.getText());
                    operando2 = Integer.parseInt(campoDeTextoMultiplicacao2.getText());
                    resultado = operando1 * operando2;
                    campoResultadoMultiplicacao.setText(Integer.toString(resultado));
                }
                catch(NumberFormatException exception)
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Algum operando eh invalido.");
                    campoDeTextoMultiplicacao1.setText("");
                    campoDeTextoMultiplicacao2.setText("");
                    campoResultadoMultiplicacao.setText("ERRO");
                }
            }
        };
        
        ActionListener adicao = new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                int operando1, operando2, resultado;
                
                try
                {
                    operando1 = Integer.parseInt(campoDeTextoAdicao1.getText());
                    operando2 = Integer.parseInt(campoDeTextoAdicao2.getText());
                    resultado = operando1 + operando2;
                    campoResultadoAdicao.setText(Integer.toString(resultado));
                }
                catch(NumberFormatException exception)
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Algum operando eh invalido.");
                    campoDeTextoAdicao1.setText("");
                    campoDeTextoAdicao2.setText("");
                    campoResultadoAdicao.setText("ERRO");
                }
            }
        };
        
        operacaoMultiplicacao.addActionListener(multiplicacao);
        operacaoAdicao.addActionListener(adicao);
        
        painelMultiplicacao.add(campoDeTextoMultiplicacao1);
        painelMultiplicacao.add(simboloMultiplicacao);
        painelMultiplicacao.add(campoDeTextoMultiplicacao2);
        painelMultiplicacao.add(operacaoMultiplicacao);
        painelMultiplicacao.add(campoResultadoMultiplicacao);
        painelAdicao.add(campoDeTextoAdicao1);
        painelAdicao.add(simboloAdicao);
        painelAdicao.add(campoDeTextoAdicao2);
        painelAdicao.add(operacaoAdicao);
        painelAdicao.add(campoResultadoAdicao);
        painel.add(painelMultiplicacao);
        painel.add(painelAdicao);
        janela.getContentPane().add(painel);
        
        janela.setVisible(true);
    }
}
