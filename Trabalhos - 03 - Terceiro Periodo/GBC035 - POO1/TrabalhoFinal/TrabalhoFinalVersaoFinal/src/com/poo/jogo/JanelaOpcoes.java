package com.poo.jogo;

import com.poo.efeitosSonoros.Sounds;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.IOException;
import static java.lang.Character.isDigit;
import java.util.ArrayList;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class JanelaOpcoes {

    String aux;
    int x = 800, y = 600;
    String aux1 = "Ativado";

    public JanelaOpcoes(Sounds sound, ArrayList<Integer> dimension, ArrayList<String> audio) throws IOException {
        JFrame option = new JFrame("Options");
        BackGroundImagem option1 = new BackGroundImagem("options.jpg");
        JLabel dimensao = new JLabel("selecione a dimensao:");
        JComboBox<String> combo = new JComboBox<>();
        JLabel som = new JLabel("ativar musica e sons:");
        JComboBox<String> combo1 = new JComboBox<>();

        ///Conteudo do menu de opcoes***************************
        dimensao.setBounds(10, 25, 200, 50);
        dimensao.setFont(new Font("SEGA LOGO FONT", Font.PLAIN, 12));
        dimensao.setForeground(Color.WHITE);
        som.setBounds(10, 100, 200, 50);
        som.setFont(new Font("SEGA LOGO FONT", Font.PLAIN, 12));
        som.setForeground(Color.WHITE);
        combo.setBounds(300, 25, 150, 40);
        combo1.setBounds(300, 100, 150, 40);
        ///******************************************************

        ///Montagem dos combobox*********************************
        combo.addItem("1280x1024");
        combo.addItem("1024x768");
        combo.setSelectedItem("1024x768");
        combo1.addItem("Ativado");
        combo1.addItem("Desativado");
        combo.setSelectedItem("Ativado");
        ///******************************************************

        combo.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent event) {
                if (event.getStateChange() == ItemEvent.SELECTED) {
                    aux = combo.getSelectedItem().toString();
                    char c;
                    int i;
                    String auxiliador = "";

                    int p;
                    for (i = 0; i < aux.length(); i++) {
                        c = aux.charAt(i);
                        if (isDigit(aux.charAt(i))) {
                            auxiliador += aux.charAt(i);
                        } else {
                            p = Integer.parseInt(auxiliador);
                            auxiliador = "";
                            dimension.set(0, p);
                        }
                    }
                    p = Integer.parseInt(auxiliador);
                    dimension.set(1, p);
                }
            }
        });

        combo1.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent event) {
                if (event.getStateChange() == ItemEvent.SELECTED) {
                    aux = combo1.getSelectedItem().toString();
                    audio.set(0, aux);
                    if (aux.equals("Desativado")) {
                        sound.stopSounds();
                    }
                }
            }
        });

        ///Montagem do JFrame************************************
        option.add(dimensao);
        option.add(combo);
        option.add(som);
        option.add(combo1);
        option.getContentPane().add(option1);
        option.setSize(500, 200);
        option.setResizable(false);
        option.setVisible(true);
        option.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        ///*******************************************************
    }
}
