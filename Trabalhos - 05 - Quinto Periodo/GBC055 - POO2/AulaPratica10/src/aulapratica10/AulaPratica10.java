/*
Programa: Aula Pratica 10 - POO2
Alunos: Adriano Araujo Martins de Resende 11611BCC015
        Marcelo Mendonca Borges           11611BCC020
Data: 14/06/2018
*/

package aulapratica10;

public class AulaPratica10
{
    public static void main(String[] args)
    {
        /*Invoker*/
        Aplicativo aplicativo = new Aplicativo();
        
        /*Receivers*/
        AparelhoDeSom aparelhoDeSom = new AparelhoDeSom();
        ArCondicionado arCondicionado = new ArCondicionado();
        Forno forno = new Forno();
        PanelaEletrica panelaEletrica = new PanelaEletrica();
        
        /*Comandos Aparelho de Som*/
        ComandoLigarAparelhoDeSom comando0 = new ComandoLigarAparelhoDeSom(aparelhoDeSom);
        ComandoDesligarAparelhoDeSom comando1 = new ComandoDesligarAparelhoDeSom(aparelhoDeSom);
        ComandoSetarVolumeAparelhoDeSom comando2 = new ComandoSetarVolumeAparelhoDeSom(aparelhoDeSom, 0);
        
        /*Comandos Ar Condicionado*/
        ComandoLigarArCondicionado comando3 = new ComandoLigarArCondicionado(arCondicionado);
        ComandoDesligarArCondicionado comando4 = new ComandoDesligarArCondicionado(arCondicionado);
        ComandoSetarTemperaturaArCondicionado comando5 = new ComandoSetarTemperaturaArCondicionado(arCondicionado, 0);
        
        /*Comandos Forno*/
        ComandoLigarForno comando6 = new ComandoLigarForno(forno);
        ComandoDesligarForno comando7 = new ComandoDesligarForno(forno);
        ComandoSetarTemperaturaForno comando8 = new ComandoSetarTemperaturaForno(forno, 0);
        ComandoSetarTimerForno comando9 = new ComandoSetarTimerForno(forno, 0);
        
        /*Comandos Panela Eletrica*/
        ComandoLigarPanelaEletrica comando10 = new ComandoLigarPanelaEletrica(panelaEletrica);
        
        /*Inserindo comandos no Invoker*/
        aplicativo.inserirComando(0, comando0); /*Ligar aparelho de som*/
        aplicativo.inserirComando(1, comando1); /*Desligar aparelho de som*/
        aplicativo.inserirComando(2, comando2); /*Setar volume aparelho de som*/
        aplicativo.inserirComando(3, comando3); /*Ligar ar condicionado*/
        aplicativo.inserirComando(4, comando4); /*Desigar ar condicionado*/
        aplicativo.inserirComando(5, comando5); /*Setar temperatura ar condicionado/*/
        aplicativo.inserirComando(6, comando6); /*Ligar forno*/
        aplicativo.inserirComando(7, comando7); /*Desligar forno*/
        aplicativo.inserirComando(8, comando8); /*Setar temperatura forno*/
        aplicativo.inserirComando(9, comando9); /*Setar timer forno*/
        aplicativo.inserirComando(10, comando10); /*Ligar panela eletrica*/
        
        /*Definindo Macro para Saindo do Trabalho*/
        aplicativo.inserirComandoMacro(comando3);
        aplicativo.inserirComandoMacro(comando5);
        aplicativo.inserirComandoMacro(comando6);
        aplicativo.inserirComandoMacro(comando8);
        aplicativo.inserirComandoMacro(comando9);
        aplicativo.inserirComandoMacro(comando10);
        aplicativo.inserirComandoMacro(comando0);
        aplicativo.inserirComandoMacro(comando2);
        
        /*Testando comando*/
        System.out.println("Teste dos comandos:---------------------------------------------------");
        aplicativo.enviarComando(0);
        aplicativo.enviarComando(1);
        aplicativo.enviarComandoDesfazer(1);
        aplicativo.enviarComando(3);
        aplicativo.enviarComando(4);
        aplicativo.enviarComando(6);
        aplicativo.enviarComando(7);
        aplicativo.enviarComando(10);
        
        /*Dados da Macro Saindo do Trabalho*/
        System.out.println("\nDefinindo Dados da Macro:-------------------------------------------");
        comando5.setTemperatura(22);
        comando8.setTemperatura(200);
        comando9.setTempoTimer(30);
        comando2.setVolume(20);
        
        /*Execucao da Macro*/
        System.out.println("\nExecucao da Macro:--------------------------------------------------");
        aplicativo.saindoTrabalho();
        System.out.println();
    }
}
