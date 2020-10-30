package exemplo03singleton;

public class Configuracao {

    //Variavel estatica: unica instacia do objeto
	private static Configuracao instancia;

    private String ip;
    private int porta;
    private String usuario;
    private String senha;

    //Construtor privado
    private Configuracao(){
    }

    //Metodo da classe que retorna a unica instacian do objeto 
    //como lidar com chamadas simultaneas/intercaladas do getInstancia?
    public synchronized static Configuracao getInstancia(){
        if (instancia==null){
            instancia=new Configuracao();
        }
        return instancia;
    }
    
    

    //Outros metodos
    public void autenticar(){
    }

    /*
     * getters e setters e outros metodos
     */

}