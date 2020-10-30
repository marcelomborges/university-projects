package controller;

import dao.CommunicateDAO;
import java.util.ArrayList;
import model.Endereco;
import model.Hospede;
import model.Quarto;
import model.Reserva;

public class FRecepcao {

    CommunicateDAO dao = new CommunicateDAO();
    
// working (looks like)
    public void cadastraHospede(String nome,String cpf,String telefone,String cep,String rua,String numerocasa,String bairro,String cidade){
        Hospede h;
        Endereco e;
        
        e = new Endereco(Integer.parseInt(numerocasa),rua,bairro,cidade,Integer.parseInt(cep),Integer.parseInt(telefone));
        h = new Hospede(nome,Integer.parseInt(cpf),0,e,null);
        
        dao.registraHospede(h);
    }

// esta inserindo    
    public void abrirReserva(String cpf,String numeroquarto,String dataentrada,String datasaida,String codigoreserva,String cpf1,String cpf2,String cpf3,String cpf4){
        Reserva r;
        Hospede h;
        ArrayList<Hospede> a = new ArrayList<Hospede>();
        Quarto q = dao.retornaQuarto(Integer.parseInt(numeroquarto));
        
        if(cpf1 != null){
            h = dao.retornaHospede(Integer.parseInt(cpf1));
            a.add(h);
        }
        if(cpf2 != null){
            h = dao.retornaHospede(Integer.parseInt(cpf2));
            a.add(h);
        }
        if(cpf3 != null){
            h = dao.retornaHospede(Integer.parseInt(cpf3));
            a.add(h);
        }
        if(cpf4 != null){
            h = dao.retornaHospede(Integer.parseInt(cpf4));
            a.add(h);
        }
        
        h = dao.retornaHospede(Integer.parseInt(cpf));
        r = new Reserva(Integer.parseInt(codigoreserva),h,null,dataentrada,datasaida,a,(float) 0.00,null);

        String entrada[] = r.getData_entrada().split("/");
        String saida[]   = r.getData_saida().split("/");

        int dia_entrada = Integer.parseInt(entrada[0]);
        int dia_saida = Integer.parseInt(saida[0]);

        int mes_entrada = Integer.parseInt(entrada[1]);
        int mes_saida = Integer.parseInt(saida[1]);        

        if(mes_entrada == mes_saida){
            r.setPreco_total(q.getValor_diaria()*(dia_saida - dia_entrada));
        } else {
            r.setPreco_total(q.getValor_diaria()*(30 - dia_entrada + 30*(mes_saida - mes_entrada - 1) + dia_saida));
        }

        dao.registraReserva(r);
    }
    
//funciona    
    public void editaReserva(String codigo,String dataentrada,String datasaida){
        Reserva reserva;
            
        reserva = dao.retornaReserva(Integer.parseInt(codigo));
            
        if(dataentrada != null){
            reserva.setData_entrada(dataentrada);
        }
        
        if(datasaida != null){
            reserva.setData_saida(datasaida);
        }

        dao.deletaReserva(Integer.parseInt(codigo));
        dao.registraReserva(reserva);
    }
    
    
//banco funciona    
    public void fechaReserva(String codigo){
        Reserva reserva;
        
        reserva = dao.retornaReserva(Integer.parseInt(codigo));
        reserva.getPreco_total();// Faz o que com isso
        dao.deletaReserva(Integer.parseInt(codigo));
    }

}