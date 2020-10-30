/*
Programa: Aula Pratica 02 - POO1
Aluno: Marcelo Mendonca Borges
Data: 13/04/2017
*/

package aulapratica02;

public class AulaPratica02 {

    public static void main(String[] args)
    {
        Historico h = new Historico();
        
        Disciplina d1 = new Disciplina("POO1");
        Disciplina d2 = new Disciplina("AED1");
        Disciplina d3 = new Disciplina("AOC1");
        
        d1.atualizaResultado(50);
        d2.atualizaResultado(100);
        
        h.matriculaDisciplina(d1);
        h.matriculaDisciplina(d2);
        h.matriculaDisciplina(d3);
        
        h.imprime();
    }
}
