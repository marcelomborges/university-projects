/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package control;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import model.beam.Cliente;
import model.dao.ClienteDAO;
import view.TelaCadstroCliente;

/**
 *
 * @author Henrique
 */
public class ClienteControl {
    private TelaCadstroCliente theView;
    private Cliente theModel;
    
    public ClienteControl (TelaCadstroCliente theView, Cliente theModel){
        this.theView = theView;
        this.theModel = theModel;
        
        this.theView.addSalvaListener(new SalvaListener());
    }
    
    class SalvaListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            try {
                Cliente obj = new Cliente();
                obj.setNome(theView.getTxtNome());
                obj.setTelefone(theView.getTxtTelefone());
                obj.setEmail(theView.getTxtEmail());
                
                ClienteDAO clienteDAO = new ClienteDAO();
                clienteDAO.cadatrarCliente(obj);
                
                theView.displayMessage("Cadastro efetuado com sucesso.");
            } catch (Exception erro) {
                theView.displayMessage("O cadastro nao pode ser efetuado pois ocorreu um erro: "+erro);
            }
        }
    }
}
