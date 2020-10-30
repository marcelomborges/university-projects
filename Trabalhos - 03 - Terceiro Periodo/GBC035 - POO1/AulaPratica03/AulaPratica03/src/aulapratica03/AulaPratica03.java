/*
Programa: Aula Pratica 03 - POO1
Aluno: Marcelo Mendonca Borges
Data: 20/04/2017
*/

package aulapratica03;

public class AulaPratica03 {

    public static void main(String[] args) {
        ControleAcademico ca1 = new ControleAcademico();
        
        Aluno a1 = new Aluno("Marcelo", 11611020, 2016);
        Aluno a2 = new Aluno("Alexandre", 11211036, 2012);
        Aluno a3 = new Aluno("Leticia", 11711079, 2017);
        
        Disciplina d1 = new Disciplina("POO1");
        Disciplina d2 = new Disciplina("AED1");
        Disciplina d3 = new Disciplina("AOC1");
        Disciplina d4 = new Disciplina("AED2");
        Disciplina d5 = new Disciplina("POO2");
        
        a1.h.adicionaDisciplina(d1);
        a1.h.adicionaDisciplina(d2);
        a2.h.adicionaDisciplina(d3);
        a2.h.adicionaDisciplina(d4);
        a3.h.adicionaDisciplina(d5);
        
        a1.h.atualizaResultado(d1, 90, 0.95);
        a1.h.atualizaResultado(d2, 100, 1);
        a2.h.atualizaResultado(d3, 55, 0.8);
        a2.h.atualizaResultado(d4, 70, 0.65);
        
        ca1.adicionaAluno(a1);
        ca1.adicionaAluno(a2);
        ca1.adicionaAluno(a3);
        
        ca1.imprime();
        
        a1.h.removeDisciplina(d1);
        ca1.removeAluno(a2);
        
        System.out.println("");
        System.out.println("");
        
        ca1.imprime();
    }
}
