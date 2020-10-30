/*
Programa: Aula Pratica 01 - POO1
Aluno: Marcelo Mendonca Borges
Data: 06/04/2017
*/

package aulapratica01;

import javax.swing.*;

public class AulaPratica01
{
    public static void main(String[] args)
    {
        Pessoa p = new Pessoa();
        p.nome = JOptionPane.showInputDialog("Entre com seu nome");
        p.altura = Double.parseDouble(JOptionPane.showInputDialog("Entre com sua altura"));
        p.peso = Double.parseDouble(JOptionPane.showInputDialog("Entre com seu peso"));
        JOptionPane.showMessageDialog(null, "" + p.nome + " seu IMC = " + p.calculaIMC());
        JOptionPane.showMessageDialog(null, "Isto significa que voce estah " + p.avaliaIMC());
    }
}
