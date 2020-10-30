/*
Programa: Aula Pratica 04 - POO1
Aluno: Marcelo Mendonca Borges
Data: 27/04/2017
*/

package controleacademico;

public class ControleAcademico
{
    public static void main(String[] args)
    {
        Disciplina pp = new Disciplina("PP");
        Disciplina aed1 = new Disciplina("AED1");
        Disciplina poo1 = new Disciplina("POO1");
        GradeCurricular grade = new GradeCurricular();
        
        grade.incluiDisciplina(pp);
        grade.incluiDisciplina(aed1);
        grade.incluiDisciplina(poo1);
        
        Professor profMarcelo = new Professor("Marcelo", "FACOM");
        Aluno alunoSeverino = new Aluno("Severino", grade);
        
        aed1.criaPrerequisito(pp);
        System.out.println("CONTROLE ACADEMICO");
        System.out.println("");
        
        alunoSeverino.disciplinasRestantes();
        System.out.println("(O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!)" : "ainda cursando)"));
        System.out.println("");
        
        System.out.println("-> Tentativa de Matricula nas Disciplinas:");
        OfertaTurma ofertaPP = new OfertaTurma(2015, Semestre.SEGUNDO, pp);
        alunoSeverino.historico.matriculaDisciplina(ofertaPP);
        OfertaTurma ofertaAED1 = new OfertaTurma(2016, Semestre.PRIMEIRO, aed1);
        alunoSeverino.historico.matriculaDisciplina(ofertaAED1);
        OfertaTurma ofertaPOO1 = new OfertaTurma(2016, Semestre.PRIMEIRO, poo1);
        alunoSeverino.historico.matriculaDisciplina(ofertaPOO1);
        System.out.println("");
        
        System.out.println("(O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!)" : "ainda cursando)"));
        System.out.println("");
        
        System.out.println("-> Registrando os Resultados das Disciplinas Matriculadas:");
        alunoSeverino.historico.registraResultado(pp, 60);
        alunoSeverino.historico.registraResultado(poo1, 60);
        System.out.println("");
        
        alunoSeverino.disciplinasRestantes();
        System.out.println("(O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!)" : "ainda cursando)"));
        System.out.println("");
        
        System.out.println("-> Tentativa de Matricula nas Disciplinas Restantes:");
        OfertaTurma novaOfertaAED1 = new OfertaTurma(2016, Semestre.SEGUNDO, aed1);
        alunoSeverino.historico.matriculaDisciplina(novaOfertaAED1);
        System.out.println("");
        
        System.out.println("-> Registrando os Resultados das Disciplinas Restantes Matriculadas:");
        alunoSeverino.historico.registraResultado(aed1, 60);
        System.out.println("");
        
        alunoSeverino.disciplinasRestantes();
        System.out.println("(O aluno " + alunoSeverino.nome + " esta' " + (alunoSeverino.verificaSeFormou() ? "formado!)" : "ainda cursando)"));
        System.out.println("");
    }
}
