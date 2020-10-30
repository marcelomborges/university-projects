/*
Programa: Aula Pratica 08 - POO1
Aluno: Marcelo Mendonca Borges
Data: 08/06/2017
*/

package aulapratica08;

import java.util.*;
import javax.swing.*;

public class AulaPratica08
{
    public static void main(String[] args)
    {
        int i, quantidadePessoas, quantidadePFisicas, quantidadePJuridicas;
        Vector<Pessoa> vetorDePessoas;
        vetorDePessoas = new Vector<Pessoa>();
        Pessoa pessoa;
        String nome, cpf, cnpj, resultado = "";
        float ra, fa, ci;
        double imposto;
        
        do
        {
            quantidadePFisicas = Integer.parseInt(JOptionPane.showInputDialog("Quantidade de pessoas fisicas:"));
            if (quantidadePFisicas <= 0)
            {
                JOptionPane.showMessageDialog(null, "-Valor Invalido");
            }
        }
        while (quantidadePFisicas <= 0);
        
        for (i = 0; i < quantidadePFisicas; i++)
        {
            nome = JOptionPane.showInputDialog("Pessoa Fisica " + (i + 1) + " :\n" + "Digite o nome da pessoa fisica:");
            cpf = JOptionPane.showInputDialog("Pessoa Fisica " + (i + 1) + " :\n" + "Digite o CPF da pessoa fisica:");
            ra = Float.parseFloat(JOptionPane.showInputDialog("Pessoa Fisica " + (i + 1) + " :\n" + "Digite o rendimento anual da pessoa fisica:"));
            pessoa = new PessoaFisica(nome, cpf, ra);
            vetorDePessoas.add(pessoa);
        }
        
        do
        {
            quantidadePJuridicas = Integer.parseInt(JOptionPane.showInputDialog("Quantidade de pessoas juridicas:"));
            if (quantidadePJuridicas <= 0)
            {
                JOptionPane.showMessageDialog(null, "-Valor Invalido");
            }
        }
        while (quantidadePJuridicas <= 0);
        
        for (i = 0; i < quantidadePJuridicas; i++)
        {
            nome = JOptionPane.showInputDialog("Pessoa Juridica " + (i + 1) + " :\n" + "Digite o nome da pessoa juridica:");
            cnpj = JOptionPane.showInputDialog("Pessoa Juridica " + (i + 1) + " :\n" + "Digite o CNPJ da pessoa juridica:");
            fa = Float.parseFloat(JOptionPane.showInputDialog("Pessoa Juridica " + (i + 1) + " :\n" + "Digite o valor do faturamento anual da pessoa juridica:"));
            ci = Float.parseFloat(JOptionPane.showInputDialog("Pessoa Juridica " + (i + 1) + " :\n" + "Digite o valor de contribuicoes isentas da pessoa juridica:"));
            pessoa = new PessoaJuridica(nome, cnpj, fa, ci);
            vetorDePessoas.add(pessoa);
        }
        
        quantidadePessoas = quantidadePFisicas + quantidadePJuridicas;
        
        resultado += "Pessoas Fisicas:-------------------------------------------------------\n\n";
        for (i = 0; i < quantidadePFisicas; i++)
        {
            pessoa = vetorDePessoas.get(i);
            nome = pessoa.getNome();
            cpf = pessoa.getCPF();
            imposto = pessoa.calculoImposto();
            resultado += "Nome: " + nome + "\nCPF: " + cpf + "\nValor do Imposto: " + imposto + "\n\n";
        }
        
        resultado += "Pessoas Juridicas:-----------------------------------------------------\n\n";
        for (i = quantidadePFisicas; i < quantidadePessoas; i++)
        {
            pessoa = vetorDePessoas.get(i);
            nome = pessoa.getNome();
            cnpj = pessoa.getCNPJ();
            imposto = pessoa.calculoImposto();
            resultado += "Nome: " + nome + "\nCNPJ: " + cnpj + "\nValor do Imposto: " + imposto + "\n\n";
        }
        
        JOptionPane.showMessageDialog(null, resultado);
    }

}
