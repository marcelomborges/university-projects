/*
Programa: Aula Pratica 05 - POO1
Aluno: Marcelo Mendonca Borges
Data: 04/05/2017
*/

package academico.ui;

import academico.dominio.cursos.*;
import academico.dominio.pessoas.*;
import academico.dominio.matriculas.*;
import javax.swing.*;

public class ControleAcademico
{
    public static void main(String[] args)
    {
        String nome;
        nome = JOptionPane.showInputDialog("Entre com o nome:");
        
        Disciplina pp = new Disciplina("PP");
        Disciplina aed1 = new Disciplina("AED1");
        Disciplina poo1 = new Disciplina("POO1");
        GradeCurricular grade = new GradeCurricular();
        
        grade.incluiDisciplina(pp);
        grade.incluiDisciplina(aed1);
        grade.incluiDisciplina(poo1);
        
        Professor profMarcelo = new Professor("Marcelo", "FACOM");
        Aluno alunoSeverino = new Aluno(nome, grade);
        
        JOptionPane.showMessageDialog(null, "O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        OfertaTurma ofertaPP = new OfertaTurma(2015, Semestre.SEGUNDO, pp);
        alunoSeverino.matriculaAluno(ofertaPP);
        JOptionPane.showMessageDialog(null, "O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        
        OfertaTurma ofertaAED1 = new OfertaTurma(2016, Semestre.PRIMEIRO, aed1);
        alunoSeverino.matriculaAluno(ofertaAED1);
        OfertaTurma ofertaPOO1 = new OfertaTurma(2016, Semestre.PRIMEIRO, poo1);
        alunoSeverino.matriculaAluno(ofertaPOO1);
        
        JOptionPane.showMessageDialog(null, "O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.atualizaResultado(pp, 60);
        JOptionPane.showMessageDialog(null, "O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.atualizaResultado(aed1, 60);
        JOptionPane.showMessageDialog(null, "O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
        alunoSeverino.atualizaResultado(poo1, 60);
        JOptionPane.showMessageDialog(null, "O aluno " + alunoSeverino.getNome() + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!" : "ainda cursando"));
    }

}
