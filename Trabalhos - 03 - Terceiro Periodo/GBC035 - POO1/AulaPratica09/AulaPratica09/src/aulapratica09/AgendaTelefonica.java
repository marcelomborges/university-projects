
package aulapratica09;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class AgendaTelefonica
{
    int quantidadeDeContatos;
    Vector<Contato> agenda;
    
    public AgendaTelefonica()
    {
        quantidadeDeContatos = 0;
        agenda = new Vector<Contato>();
        
        /*Criacao da Janela---------------------------------------------------*/
        final JButton botaoProcurar = new JButton("Procurar");
        final JButton botaoListar = new JButton("Listar");
        final JButton botaoApagar = new JButton("Apagar");
        final JButton botaoCadastrar = new JButton("Cadastrar");

        final JTextField campoNome = new JTextField(20);
        final JTextField campoTelefone = new JTextField(20);
        final JTextField campoEndereco = new JTextField(20);

        JLabel labelTitulo = new JLabel("Insira os Dados:\n");
        JLabel labelNome = new JLabel("Nome:");
        JLabel labelTelefone = new JLabel("Telefone:");
        JLabel labelEndereco = new JLabel("Endereco:");
        
        final JFrame janela = new JFrame("Agenda Telefonica");
        janela.setSize(600, 175);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel painel1 = new JPanel();
        JPanel painel2 = new JPanel();
        JPanel painel3 = new JPanel();
        
        painel2.setLayout(new GridLayout(3,2));
        painel3.setLayout(new GridLayout(1,4));
        
        painel1.add(labelTitulo);
        janela.getContentPane().add(painel1, BorderLayout.NORTH);
        
        painel2.add(labelNome);
        painel2.add(campoNome);
        painel2.add(labelTelefone);
        painel2.add(campoTelefone);
        painel2.add(labelEndereco);
        painel2.add(campoEndereco);
        janela.getContentPane().add(painel2, BorderLayout.CENTER);
        
        painel3.add(botaoProcurar);
        painel3.add(botaoListar);
        painel3.add(botaoApagar);
        painel3.add(botaoCadastrar);
        janela.getContentPane().add(painel3, BorderLayout.SOUTH);
        /*--------------------------------------------------------------------*/
        
        /*Definicao da Acao de cada Botao-------------------------------------*/
        botaoProcurar.addActionListener (new ActionListener() /*Botao Procurar*/
        {
            int controle = 0;
            
            public void actionPerformed(ActionEvent e)
            {
                String nome = campoNome.getText();
                campoNome.setText("");
                campoTelefone.setText("");
                campoEndereco.setText("");
                String resultado = "Contatos:\n--------------------------------------------------\n";
                String separador = "\n--------------------------------------------------\n";
                
                for(int i = 0; i < quantidadeDeContatos; i++)
                {
                    
                    Contato c = agenda.get(i);
                    if(c.getNome().equals(nome))
                    {
                        controle = 1;
                        resultado += "Nome: " + c.getNome() + "\nTelefone: " + c.getTelefone() + "\nEndereco: " + c.getEndereco() + separador;
                    }
                }
                
                if(controle == 0) 
                {
                    JOptionPane.showMessageDialog(null, "=> Falha ao Procurar: Contato Inexistente!");
                }
                else
                {
                    controle = 0;
                    JOptionPane.showMessageDialog(null, resultado);
                }
                
            }
        });
        
        botaoListar.addActionListener(new ActionListener() /*Botao Listar*/
        {
            public void actionPerformed(ActionEvent e)
            {
                campoNome.setText("");
                campoTelefone.setText("");
                campoEndereco.setText("");
                String resultado = "Contatos:\n--------------------------------------------------\n";
                String separador = "\n--------------------------------------------------\n";
                
                if(quantidadeDeContatos == 0)
                {
                    JOptionPane.showMessageDialog(null, "=> Agenda Vazia!");
                }
                else
                {
                    for(int i = 0; i < quantidadeDeContatos; i++)
                    {
                        Contato c = agenda.get(i);
                        resultado += "Nome: " + c.getNome() + "\nTelefone: " + c.getTelefone() + "\nEndereco: " + c.getEndereco() + separador;
                    }
                
                    JOptionPane.showMessageDialog(null, resultado);
                }
            }
        });
        
        botaoApagar.addActionListener(new ActionListener() /*Botao Apagar*/
        {
            int controle = 0;
            
            public void actionPerformed(ActionEvent e)
            {
                String nome = campoNome.getText();
                campoNome.setText("");
                campoTelefone.setText("");
                campoEndereco.setText("");
                
                for(int i = 0; i < quantidadeDeContatos; i++)
                {
                    Contato c = agenda.get(i);
                    if(c.getNome().equals(nome))
                    {
                        controle = 1;
                        agenda.remove(c);
                        quantidadeDeContatos--;
                    }
                }
                
                if(controle == 0)
                {
                    JOptionPane.showMessageDialog(null, "=> Falha ao Apagar: Contato Inexistente!");
                }
                else
                {
                    controle = 0;
                    JOptionPane.showMessageDialog(null, "=> Contato Apagado!");
                } 
            }
        });
        
        botaoCadastrar.addActionListener(new ActionListener() /*Botao Cadastrar*/
        {
            public void actionPerformed(ActionEvent e)
            {
                String nome = campoNome.getText();
                String telefone = campoTelefone.getText();
                String endereco = campoEndereco.getText();
                campoNome.setText("");
                campoTelefone.setText("");
                campoEndereco.setText("");
                
                if(("".equals(nome))||("".equals(telefone))||("".equals(endereco)))
                {
                    JOptionPane.showMessageDialog(null, "=> Falha ao Cadastrar: Faltam Dados!");
                }
                else
                {
                    Contato c = new Contato(nome, telefone, endereco);
                    agenda.add(c);
                    quantidadeDeContatos++;
                
                    JOptionPane.showMessageDialog(null, "=> Contato Cadastrado!");
                }
            }
        });
        /*--------------------------------------------------------------------*/
        
        janela.setVisible(true);
    }
}
