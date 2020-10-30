
package aulapratica10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calculadora
{
    float valor = 0;
    int controle = 0;
    int token_operacao = 0;
    
    public Calculadora ()
    {
        /*Janela--------------------------------------------------------------*/
        final JFrame janela = new JFrame("Calculadora");
        janela.setSize(250, 300);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        /*Parte Superior: Visor-----------------------------------------------*/
        JPanel painelSuperior = new JPanel();
        painelSuperior.setLayout(new BorderLayout());
        painelSuperior.setBackground(Color.white);
        
        final JSeparator separadorCima = new JSeparator();
        separadorCima.setForeground(Color.black);
        
        final JLabel visor = new JLabel(" ");
        visor.setHorizontalAlignment(JLabel.RIGHT);
        
        final JSeparator separadorBaixo = new JSeparator();
        separadorBaixo.setForeground(Color.black);
        
        painelSuperior.add(separadorCima, BorderLayout.NORTH);
        painelSuperior.add(visor, BorderLayout.CENTER);
        painelSuperior.add(separadorBaixo, BorderLayout.SOUTH);
        janela.getContentPane().add(painelSuperior, BorderLayout.NORTH);
        
        /*Parte Central: Numeros e operacoes----------------------------------*/
        
        /*Botoes Numericos----------------------------------------------------*/
        JPanel numeros = new JPanel();
        numeros.setLayout(new GridLayout(4,3));
        
        final JButton[] botoesNumeros = new JButton[12];
        
        String[] numbers = {"1","2","3","4","5","6","7","8","9","","0",""};
        
        for(int i = 0; i < botoesNumeros.length; i++)
        {           
            botoesNumeros[i] = new JButton(numbers[i]);
            if((i == 9)||(i == 11))
            {
                botoesNumeros[i].setVisible(false);
            }
        }
        for(int i = 0; i < botoesNumeros.length; i++)
        {
            numeros.add(botoesNumeros[i]);
        }
        
        ActionListener trataTecla = new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                JButton botaoClicado = (JButton)e.getSource();
                visor.setText(visor.getText()+botaoClicado.getText());
            }
        };
        
        for(int i = 0; i < botoesNumeros.length; i++)
        {
            botoesNumeros[i].addActionListener(trataTecla);
        }
        
        /*Botoes de Operacoes-------------------------------------------------*/
        JPanel operacoes = new JPanel();
        operacoes.setLayout(new GridLayout(5,1));
        
        JButton[] botoesOperacoes = new JButton[5];
        
        String[] operations = {"+","-","*","/","="};
        
        for(int i = 0; i < botoesOperacoes.length; i++)
        {
            botoesOperacoes[i] = new JButton(operations[i]);
            operacoes.add(botoesOperacoes[i]);
        }
        
        botoesOperacoes[0].addActionListener(new ActionListener ()
        {
            float leitura;
            
            public void actionPerformed(ActionEvent e)
            {
                if(!(visor.getText().equals(" ")))
                {
                    leitura = Float.parseFloat(visor.getText());
                }
                else
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Dado de entrada vazio.");
                }
                
                if((controle == 0)&&(!(visor.getText().equals(" "))))
                {
                    valor = leitura;
                    controle = 1;
                    token_operacao = 1;
                }
                else
                {
                    valor = valor + leitura;
                    token_operacao = 1;
                }
                
                visor.setText(" ");
            }
        });
        
        botoesOperacoes[1].addActionListener(new ActionListener ()
        {
            float leitura;
            
            public void actionPerformed(ActionEvent e)
            {
                if(!(visor.getText().equals(" ")))
                {
                    leitura = Float.parseFloat(visor.getText());
                }
                else
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Dado de entrada vazio.");
                }
                
                if((controle == 0)&&(!(visor.getText().equals(" "))))
                {
                    valor = leitura;
                    controle = 1;
                    token_operacao = 2;
                }
                else
                {
                    valor = valor - leitura;
                    token_operacao = 2;
                }
                
                visor.setText(" ");
            }
        });
        
        botoesOperacoes[2].addActionListener(new ActionListener ()
        {
            float leitura;
            
            public void actionPerformed(ActionEvent e)
            {
                if(!(visor.getText().equals(" ")))
                {
                    leitura = Float.parseFloat(visor.getText());
                }
                else
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Dado de entrada vazio.");
                }
                
                if((controle == 0)&&(!(visor.getText().equals(" "))))
                {
                    valor = leitura;
                    controle = 1;
                    token_operacao = 3;
                }
                else
                {
                    valor = valor * leitura;
                    token_operacao = 3;
                }
                
                visor.setText(" ");
            }
        });
        
        botoesOperacoes[3].addActionListener(new ActionListener ()
        {
            float leitura;
            
            public void actionPerformed(ActionEvent e)
            {
                if(!(visor.getText().equals(" ")))
                {
                    leitura = Float.parseFloat(visor.getText());
                }
                else
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Dado de entrada vazio.");
                }
                
                if((controle == 0)&&(!(visor.getText().equals(" "))))
                {
                    valor = leitura;
                    controle = 1;
                    token_operacao = 4;
                }
                else
                {
                    valor = valor / leitura;
                    token_operacao = 4;
                }
                
                visor.setText(" ");
            }
        });
        
        botoesOperacoes[4].addActionListener(new ActionListener ()
        {
            float leitura;
            String resultado;
            
            public void actionPerformed(ActionEvent e)
            {
                if(!(visor.getText().equals(" ")))
                {
                    leitura = Float.parseFloat(visor.getText());
                }
                else
                {
                    JOptionPane.showMessageDialog(null, "=> Erro: Dado de entrada vazio.");
                }
                
                if((controle == 0)&&(!(visor.getText().equals(" "))))
                {
                    resultado = Float.toString(leitura);
                    visor.setText(resultado);
                }
                else if(token_operacao == 1)
                {
                    valor = valor + leitura;
                    resultado = Float.toString(valor);
                    visor.setText(resultado);
                    valor = 0;
                    controle = 0;
                    token_operacao = 0;
                }
                else if(token_operacao == 2)
                {
                    valor = valor - leitura;
                    resultado = Float.toString(valor);
                    visor.setText(resultado);
                    valor = 0;
                    controle = 0;
                    token_operacao = 0;
                }
                else if(token_operacao == 3)
                {
                    valor = valor * leitura;
                    resultado = Float.toString(valor);
                    visor.setText(resultado);
                    valor = 0;
                    controle = 0;
                    token_operacao = 0;
                }
                else if(token_operacao == 4)
                {
                    valor = valor / leitura;
                    resultado = Float.toString(valor);
                    visor.setText(resultado);
                    valor = 0;
                    controle = 0;
                    token_operacao = 0;
                }
            }
        });
        
        janela.getContentPane().add(numeros, BorderLayout.CENTER);
        janela.getContentPane().add(operacoes, BorderLayout.EAST);
        
        /*Parte Inferior: Botao Clear-----------------------------------------*/
        JPanel painelInferior = new JPanel();
        painelInferior.setLayout(new BorderLayout());
        
        JPanel painelInferiorAux = new JPanel();
        
        final JButton clear = new JButton("Clear");
        painelInferiorAux.add(clear);
        
        final JSeparator separadorInferior = new JSeparator();
        separadorInferior.setForeground(Color.gray);
        
        clear.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                    visor.setText(" ");
                    valor = 0;
                    controle = 0;
                    token_operacao = 0;
            }
        });
        
        painelInferior.add(separadorInferior, BorderLayout.NORTH);
        painelInferior.add(painelInferiorAux, BorderLayout.SOUTH);
        janela.getContentPane().add(painelInferior, BorderLayout.SOUTH);
        /*--------------------------------------------------------------------*/
        
        janela.setVisible(true);
    }
}
