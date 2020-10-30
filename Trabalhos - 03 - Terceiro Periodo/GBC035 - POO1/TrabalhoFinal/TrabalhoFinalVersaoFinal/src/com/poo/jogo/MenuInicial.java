package com.poo.jogo;

import com.poo.efeitosSonoros.Sounds;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class MenuInicial {

    public MenuInicial() throws IOException {

        JFrame telaInicial = new JFrame("Batalha Naval");
        BackGroundImagem diag = new BackGroundImagem("NavyWar.jpg");//Cria um JPanel com imagem de fundo
        Sounds sound = new Sounds();//Necessario para acessar os metodos do pacot efeitos
        sound.playWavLoop("Action");
        ArrayList<Integer> dimension = new ArrayList<>();
        ArrayList<String> audio = new ArrayList<>();
        dimension.add(1024);//Dimensoes para a tela com as matrizes
        dimension.add(768);
        audio.add("Ativado");

        //Organizacao dos botoes na tela principal**********
        JButton play = new JButton("Play");
        play.setIcon(new ImageIcon("BotaoPlay.png"));
        play.setBounds(300, 200, 200, 100);
        play.setBorder(BorderFactory.createEmptyBorder());
        play.setContentAreaFilled(false);
        play.setFocusable(false);
        JButton options = new JButton("Options");
        options.setIcon(new ImageIcon("BotaoOptions.png"));
        options.setBounds(300, 300, 200, 100);
        options.setBorder(BorderFactory.createEmptyBorder());
        options.setContentAreaFilled(false);
        options.setFocusable(false);
        JButton exit = new JButton("Exit");
        exit.setIcon(new ImageIcon("BotaoExit.png"));
        exit.setBounds(300, 400, 200, 100);
        exit.setBorder(BorderFactory.createEmptyBorder());
        exit.setContentAreaFilled(false);
        exit.setFocusable(false);
        ///*************************************************

        ///Listeners****************************************
        ActionListener trataTeclaPlay = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (audio.get(0).equals("Desativado")) {
                    telaInicial.setVisible(false);
                    try {
                       String dimensao = dimension.get(0) + "x" + dimension.get(1);
                       BatalhaNavalUmJogador batalha = new BatalhaNavalUmJogador((dimensao + ".jpg"), audio);
                    } catch (IOException ex) {
                        Logger.getLogger(MenuInicial.class.getName()).log(Level.SEVERE, null, ex);
                    }
                } else {
                    sound.playShot("HittingMan");
                    telaInicial.setVisible(false);
                    String dimensao = dimension.get(0) + "x" + dimension.get(1);
                    sound.stopSounds();
                    try {
                        BatalhaNavalUmJogador batalha = new BatalhaNavalUmJogador(dimensao + ".jpg", audio);
                    } catch (IOException ex) {
                        Logger.getLogger(MenuInicial.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        };

        ActionListener trataTeclaExit = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (audio.get(0).equals("Desativado")) {
                    System.exit(0);
                } else {
                    sound.playShot("HittingMan");
                    System.exit(0);
                }
            }
        };

        ActionListener trataTeclaOptions = new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    if (audio.get(0).equals("Desativado")) {
                        JanelaOpcoes option = new JanelaOpcoes(sound, dimension, audio);
                    } else {
                        sound.playShot("HittingMan");
                        JanelaOpcoes option = new JanelaOpcoes(sound, dimension, audio);
                    }
                } catch (IOException ex) {
                    Logger.getLogger(MenuInicial.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        };
        ///*************************************************

        play.addActionListener(trataTeclaPlay);
        exit.addActionListener(trataTeclaExit);
        options.addActionListener(trataTeclaOptions);

        ///Montagem*****************************************
        telaInicial.setSize(800, 600);
        telaInicial.setLocationRelativeTo(null);
        telaInicial.setResizable(false);
        telaInicial.getContentPane().add(play);
        telaInicial.getContentPane().add(options);
        telaInicial.getContentPane().add(exit);
        telaInicial.getContentPane().add(diag, BorderLayout.CENTER);
        telaInicial.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        telaInicial.show();
        ///*************************************************
    }
}
