/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model.dao;

import JDBC.ConnectionFactory;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import model.beam.Cliente;

/**
 *
 * @author Henrique
 */
public class ClienteDAO {
    private Connection conecta;
    
    public ClienteDAO(){
        this.conecta = ConnectionFactory.getInstance();
    }
    
    public void cadatrarCliente (Cliente obj){
        try {
            String cmdsql = "insert into cliente (nome,telefone,email) values (?,?,?)";
            
            PreparedStatement stm = conecta.prepareStatement(cmdsql);
            
            stm.setString(1, obj.getNome());
            stm.setString(2, obj.getTelefone());
            stm.setString(3, obj.getEmail());
            
            stm.execute();
            stm.close();;
            
        } catch (SQLException error) {
            throw new RuntimeException(error);
        }
    }
}
