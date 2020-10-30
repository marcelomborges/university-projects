package model;

public class Limpeza extends Servicos {
	
    public Limpeza()
    {
        super.setId(1);
        super.setOferecido(EnumCargo.Gerente_Restaurante);
    }
	
    public final void solicitarLimpeza(Reserva reserva){
        solicitarLimpezaNormal(reserva);
        solicitarLimpezaBanheira(reserva);
        solicitarLimpezaPiscina(reserva);
    }	
	
    public void solicitarLimpezaNormal(Reserva reserva){}
    public void solicitarLimpezaBanheira(Reserva reserva){}
    public void solicitarLimpezaPiscina(Reserva reserva){}
    
}
