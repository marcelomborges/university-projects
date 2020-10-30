/*
Programa: Aula Pratica 07 - POO2
Alunos : Adriano Araujo Martins de Resende 11611BCC015
         Marcelo Mendonca Borges           11611BCC020
Data: 10/05/2018
*/

package aulapratica07;

public class AulaPratica07
{
    public static void main(String[] args)
    {
        Amplificador amplificador = new Amplificador();
        CDPlayer cdPlayer = new CDPlayer();
        DVDPlayer dvdPlayer = new DVDPlayer();
        LuzAmbiente luzAmbiente = new LuzAmbiente();
        Pipoqueira pipoqueira = new Pipoqueira();
        Projetor projetor = new Projetor();
        Sintonizador sintonizador = new Sintonizador();
        Tela tela = new Tela();
        HomeTheaterFacade htf = new HomeTheaterFacade(amplificador,cdPlayer,dvdPlayer,luzAmbiente,pipoqueira,projetor,sintonizador,tela);
        
        CD cd = new CD("Tranquility Base Hotel & Casino", "Arctic Monkeys", 41, 11);
        DVD dvd = new DVD("Vingadores: Guerra Infinita", "Irmaos Russo", 14, 160);
        
        htf.assistirDVD(dvd);
        htf.pararDVD();
        
        htf.ouvirCD(cd);
        htf.pararCD();
    }
}
