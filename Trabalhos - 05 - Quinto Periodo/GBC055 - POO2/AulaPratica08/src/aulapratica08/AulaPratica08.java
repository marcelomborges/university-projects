/*
Programa: Aula Pratica 08 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 17/05/2018
*/

package aulapratica08;

public class AulaPratica08
{
    public static void main(String[] args)
    {
        ContextoMario mario = new ContextoMario();
        
        mario.pegarItem("cogumelo");
        mario.pegarItem("pena");
        mario.levarDano();
        mario.pegarItem("flor");
        mario.pegarItem("flor");
        mario.pegarItem("flor");
        mario.pegarItem("pena");
        mario.pegarItem("cogumelo");
        mario.levarDano();
        mario.levarDano();
        mario.levarDano();
        mario.pegarItem("pena");
        mario.levarDano();
    }
}
