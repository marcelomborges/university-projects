
package controleeventos;

public class Evento {

    private static final String SEPARADOR = "\n=================================\n";
    private static final String SEPARADOR2 = "=================================\n";
    private static final String TITULO = "\n=Lista de Presenca===============\n";
    
    private String nome;
    private Participante participantes[];
    private int nroParticipantes;

    public Evento(String n, int maxParticipantes)
    {
        nome = n;
        participantes = new Participante[maxParticipantes];
    }
    
    // Metodo que adiciona um participante no arranjo
    // Convencao: se o arranjo nao estiver cheio, adiciona e
    // retorna o proprio participante. Se o arranjo estiver
    // cheio retorna null.

    public Participante addParticipante(Participante p)
    {
        if (nroParticipantes == participantes.length)
        {
            return null;
        }
        
        return participantes[nroParticipantes++] = p; // insere e depois incrementa nroParticipantes
    }

    public String getNome()
    {
        return nome;
    }

    public String certificados()
    {
        String resultado = "";
        
        for (int i = 0; i < participantes.length && participantes[i] != null; i++)
        {
            resultado += SEPARADOR + participantes[i].certificado() + SEPARADOR;
        }
        
        return resultado;
    }

    public String listaDePresenca()
    {
        String resultado = "";
        resultado += TITULO;
        
        for (int i = 0; i < participantes.length && participantes[i] != null; i++)
        {
            resultado += participantes[i].listaDePresenca();
        }
        resultado += SEPARADOR2;
        
        return resultado;
    }
}
