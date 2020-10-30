/*
Programa: Aula Pratica 12 - POO1
Aluno: Marcelo Mendonca Borges
Data: 17/07/2017
*/

package prova02poo1questao3;

public class Prova02POO1Questao3
{
    public static void main(String[] args)
    {
        Loja loja = new Loja(3);
        
        loja.cadastraClienteVIP("João da Silva", "Rua Sapucaí, 10. Uberlândia – MG");
        loja.cadastraClienteVVIP("Michael Jackson", "Wonderland St., 100. Los Angeles – CA", "Edgar Fidalgo");
        loja.cadastraClienteVVIP("Zeca Pagodinho", "Rua de Trás, 30. Xerém - RJ", "Rui Cevada");
        
        loja.malaDiretaClientes();
    }
}
