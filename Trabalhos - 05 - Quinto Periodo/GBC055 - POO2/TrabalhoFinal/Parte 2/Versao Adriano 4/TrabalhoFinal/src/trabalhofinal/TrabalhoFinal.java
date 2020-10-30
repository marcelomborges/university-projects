package trabalhofinal;

import controller.ControllerPrincipal;
import controller.ControllerTelaCadastraFuncionario;
import controller.FGerente;
import controller.FRecepcao;
import dao.CommunicateDAO;
import java.util.ArrayList;
import model.Consumiveis;
import model.EnumCargo;
import static model.EnumCargo.Gerente;
import model.Hospede;
import model.Quarto;
import model.Reserva;
import model.template.Quarto_Simples;
import view.Principal;
import view.TelaCadastraFuncionario;
import view.TelaSolicitaLimpeza;

public class TrabalhoFinal {

    public static void main(String[] args) throws ClassNotFoundException {
        ControllerTelaCadastraFuncionario c = new ControllerTelaCadastraFuncionario(new TelaCadastraFuncionario());
        ControllerPrincipal p = new ControllerPrincipal(new Principal());
    }
    
}
