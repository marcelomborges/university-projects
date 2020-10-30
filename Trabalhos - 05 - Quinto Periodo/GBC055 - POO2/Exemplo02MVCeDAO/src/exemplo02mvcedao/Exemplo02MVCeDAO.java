/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exemplo02mvcedao;

import control.ClienteControl;
import model.beam.Cliente;
import view.TelaCadstroCliente;

/**
 *
 * @author Carrefuor
 */
public class Exemplo02MVCeDAO {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        TelaCadstroCliente theView = new TelaCadstroCliente();
        Cliente theModel = new Cliente();
        ClienteControl theController = new ClienteControl(theView,theModel);
        
        theView.setVisible(true);
    }
    
}
