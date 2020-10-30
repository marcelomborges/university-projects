package exemplo03singleton;

public class Configuracao3 {

    //Variavel estatica: unica instacia do objeto
	private volatile static Configuracao3 instancia;

    private String ip;
    private int porta;
    private String usuario;
    private String senha;

    //Construtor privado
    private Configuracao3(){
    }

    //Metodo da classe que retorna a unica instacian do objeto
    public static Configuracao3 getInstancia(){
        if (instancia==null){
        	synchronized (Configuracao3.class){
        		if (instancia==null){
        			instancia=new Configuracao3();
        		}
        	}
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