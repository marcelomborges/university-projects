package aulapratica02;

import java.util.ArrayList;

public class Servidor implements Sujeito
{
    private String valor;
    private ArrayList<Observador> observadores;
    
    public Servidor (String valor)
    {
        this.valor = valor;
        observadores = new ArrayList<Observador>(); 
    }

    public void registrarObservador(Observador beholder)
    {
        observadores.add(beholder);
    }
    
    public void removerObservador(Observador beholder)
    {
        observadores.remove(beholder);

    }
    
    public void notificarObservadores(String valores)
    {
        for(Observador auxiliar : observadores)
        {
            auxiliar.atualizar(valores);
        }
    }
    
    public String getValor()
    {
        return valor;
    }
    
    public void setValor(String valores)
    {
        this.valor = valores;
        this.notificarObservadores(valores);
    }
}
