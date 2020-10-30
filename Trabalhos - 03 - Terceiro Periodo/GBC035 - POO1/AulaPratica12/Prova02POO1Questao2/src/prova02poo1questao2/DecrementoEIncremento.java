
package prova02poo1questao2;

import javax.swing.*;
import java.awt.event.*;

public class DecrementoEIncremento
{
    public DecrementoEIncremento()
    {
        JFrame janela = new JFrame();
        janela.setSize(300,75);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setResizable(false);
        janela.setLocationRelativeTo(null);
        
        JPanel painel = new JPanel();
        
        JTextField display = new JTextField(10);
        display.setText("0");
        display.setHorizontalAlignment(JTextField.CENTER);
        
        final JButton botaoDecrementa = new JButton("--");
        final JButton botaoIncrementa = new JButton("++");
        
        botaoDecrementa.addActionListener(new ActionListener()
        {
            int valor;
            public void actionPerformed(ActionEvent e)
            {
                valor = Integer.parseInt(display.getText());
                
                valor--;
                
                display.setText(Integer.toString(valor));
            }
        });
        
        botaoIncrementa.addActionListener(new ActionListener()
        {
            int valor;
            public void actionPerformed(ActionEvent e)
            {
                valor = Integer.parseInt(display.getText());
                
                valor++;
                
                display.setText(Integer.toString(valor));
            }
        });
        
        painel.add(botaoDecrementa);
        painel.add(display);
        painel.add(botaoIncrementa);
        janela.getContentPane().add(painel);
        
        janela.setVisible(true);
   }
}
