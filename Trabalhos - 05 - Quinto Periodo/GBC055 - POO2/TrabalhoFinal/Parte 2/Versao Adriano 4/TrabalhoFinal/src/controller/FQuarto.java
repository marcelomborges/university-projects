package controller;

import dao.CommunicateDAO;
import java.util.ArrayList;
import model.Consumiveis;
import model.Reserva;
import model.decorator.Calda;
import model.decorator.Chantily;
import model.decorator.Chocolate;
import model.decorator.Sorvete;
import model.decorator.SorveteChocolate;
import model.decorator.SorveteCreme;
import model.decorator.SorveteMorango;

public class FQuarto {
    
CommunicateDAO dao = new CommunicateDAO();
       
    public void solicitarLimpeza(String nroquarto){
        int quarto = Integer.parseInt(nroquarto);
        
        Reserva reserva = dao.retornaReserva_2(quarto);
        reserva.getQuarto().solicitarLimpeza(reserva);
        dao.updateValorReserva(reserva.getSerial(),reserva.getPreco_total());
    }
    
    public void solicitarItemCardapio(String nroquarto,String codigo){
        int quarto = Integer.parseInt(nroquarto);
        int consumivel = Integer.parseInt(codigo);
        
        Reserva reserva = dao.retornaReserva_2(quarto);
        ArrayList<Consumiveis> frigobar = dao.retornaConsumiveis(0);
    
        for(Consumiveis item:frigobar){
            if(consumivel == item.getId()){
                dao.updateValorReserva(reserva.getSerial(),reserva.getPreco_total() + item.getPreco_uni());
            }
        }
    }
    
    public void sorvete(String sorvete,String quarto){
        int nroquarto = Integer.parseInt(quarto);
        String me[] = sorvete.split("+");
        
        Sorvete copo = null;
        
        switch(me[0]){
            case "Sorvete Morango" : copo = new SorveteMorango();
            case "Sorvete Chocolate" : copo = new SorveteChocolate();
            case "Sorvete Creme" : copo = new SorveteCreme();
        }
        
        for(int i = 1;i < me.length;i++){
            switch(me[i]){
                case "Calda" : copo = new Calda(copo);
                case "Chantily" : copo = new Chantily(copo);
                case "Confete" : copo = new Chocolate(copo);
            }
        }
        
        Reserva reserva = dao.retornaReserva_2(nroquarto);
        reserva.setPreco_total(reserva.getPreco_total() + copo.custo());
        dao.updateValorReserva(reserva.getSerial(),reserva.getPreco_total());
    }
}
