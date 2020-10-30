package controller;

import dao.CommunicateDAO;
import model.Reserva;

public class FGerenteRestaurante {
    
    CommunicateDAO dao = new CommunicateDAO();
    
    public void cobraPedido(String quarto,String consumido){        
        int numeroquarto = Integer.parseInt(quarto);
        
        Reserva reserva = dao.retornaReserva_2(numeroquarto);
        reserva.setPreco_total(reserva.getPreco_total() + (float) Double.parseDouble(consumido));
    }
}
