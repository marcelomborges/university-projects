package exemplo03singleton;

public class Configuracao2 {

    //Variavel estatica: unica instacia do objeto
	private static Configuracao2 instancia = new Configuracao2();

    private String ip;
    private int porta;
    private String usuario;
    private String senha;

    //Construtor privado
    private Configuracao2(){
    }

    //Metodo da classe que retorna a unica instacian do objeto
    public static Configuracao2 getInstancia(){
        
        return instancia;
    }
    
    

    //Outros metodos
    public void autenticar(){
    }

    /*
     * getters e setters e outros metodos
     */

}