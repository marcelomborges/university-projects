/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.poo.jogo;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ButtonGroup;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;

public class MenuBar extends JFrame {

    public MenuBar() {
        // Cria uma barra de menu para o JFrame
        JMenuBar menuBar = new JMenuBar();

        // Adiciona a barra de menu ao  frame
        setJMenuBar(menuBar);

        // Define e adiciona dois menus drop down na barra de menus
        JMenu fileMenu = new JMenu("File");
        menuBar.add(fileMenu);

        // Cria e adiciona um item simples para o menu
        JMenuItem helpAction = new JMenuItem("Help");
        JMenuItem exitAction = new JMenuItem("Exit");

        ActionListener help = new ActionListener() {
            public void actionPerformed(ActionEvent e) {

            }
        };

        ButtonGroup bg = new ButtonGroup();
        fileMenu.add(helpAction);
        fileMenu.addSeparator();
        fileMenu.add(exitAction);
    }
}
