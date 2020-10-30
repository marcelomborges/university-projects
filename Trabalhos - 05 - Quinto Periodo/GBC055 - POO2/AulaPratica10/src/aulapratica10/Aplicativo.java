
package aulapratica10;

import java.util.ArrayList;

public class Aplicativo
{
    /*INVOKER*/
    public ArrayList<Comando> listaComandos;
    public ArrayList<Comando> listaComandosMacro;
    
    public Aplicativo()
    {
        listaComandos = new ArrayList<Comando>();
        listaComandosMacro = new ArrayList<Comando>();
    }
    
    public void enviarComando(int slot)
    {
        listaComandos.get(slot).executar();
    }
    
    public void enviarComandoDesfazer(int slot)
    {
        listaComandos.get(slot).desfazer();
    }
    
    public void inserirComando(int slot, Comando novoComando)
    {
        listaComandos.add(slot,novoComando);
    }
    
    public void inserirComandoMacro(Comando novoComando)
    {
        listaComandosMacro.add(novoComando);
    }
    
    public void saindoTrabalho()
    {
        for(Comando comando : listaComandosMacro)
        {
            comando.executar();
        }
    }
}
