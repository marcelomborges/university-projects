
package trabalhofinal;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class BatalhaNavalUmJogador
{
    public BatalhaNavalUmJogador (String resolucao)
    {
        int i, j;
        Jogador[] jogadores = new Jogador[2];
        jogadores[0] = new Aliado("Aliado");
        jogadores[1] = new Adversario("Inimigo");
        
        /*Parte 1 - Letras e Numeros ------------------------------------------------------------*/
        /*Parte 1.1 - Labels --------------------------------------------------------------------*/
        String[] letras = {"A","B","C","D","E","F","G","H","I","J"};
        String[] numeros = {"0","1","2","3","4","5","6","7","8","9"};
        
        JLabel[] letrasLateral1 = new JLabel[10];
        for(i = 0; i < letrasLateral1.length; i++)
        {
            letrasLateral1[i] = new JLabel("  " + letras[i] + "  ");
            letrasLateral1[i].setBorder(BorderFactory.createEtchedBorder());
        }
        
        JLabel[] numerosSuperior1 = new JLabel[10];
        for(i = 0; i < numerosSuperior1.length; i++)
        {
            numerosSuperior1[i] = new JLabel(numeros[i]);
            numerosSuperior1[i].setHorizontalAlignment(JLabel.CENTER);
            numerosSuperior1[i].setBorder(BorderFactory.createEtchedBorder());
        }
        
        JLabel[] letrasLateral2 = new JLabel[10];
        for(i = 0; i < letrasLateral2.length; i++)
        {
            letrasLateral2[i] = new JLabel("  " + letras[i] + "  ");
            letrasLateral2[i].setBorder(BorderFactory.createEtchedBorder());
        }
        
        JLabel[] numerosSuperior2 = new JLabel[10];
        for(i = 0; i < numerosSuperior2.length; i++)
        {
            numerosSuperior2[i] = new JLabel(numeros[i]);
            numerosSuperior2[i].setHorizontalAlignment(JLabel.CENTER);
            numerosSuperior2[i].setBorder(BorderFactory.createEtchedBorder());
        }
        
        JLabel[] letrasLateralBarcos = new JLabel[10];
        for(i = 0; i < letrasLateralBarcos.length; i++)
        {
            letrasLateralBarcos[i] = new JLabel("  " + letras[i] + "  ");
            letrasLateralBarcos[i].setBorder(BorderFactory.createEtchedBorder());
        }
        
        JLabel[] numerosSuperiorBarcos = new JLabel[10];
        for(i = 0; i < numerosSuperiorBarcos.length; i++)
        {
            numerosSuperiorBarcos[i] = new JLabel(numeros[i]);
            numerosSuperiorBarcos[i].setHorizontalAlignment(JLabel.CENTER);
            numerosSuperiorBarcos[i].setBorder(BorderFactory.createEtchedBorder());
        }
        
        /*Parte 1.2 - Painels -------------------------------------------------------------------*/
        JPanel painelLetras1 = new JPanel();
        painelLetras1.setLayout(new GridLayout(10,1));
        for(i = 0; i < letrasLateral1.length; i++)
        {
            painelLetras1.add(letrasLateral1[i]);
        }
        
        JPanel painelNumeros1 = new JPanel();
        painelNumeros1.setLayout(new GridLayout(1,10));
        for(i = 0; i < numerosSuperior1.length; i++)
        {
            painelNumeros1.add(numerosSuperior1[i]);
        }
        
        JPanel painelLetras2 = new JPanel();
        painelLetras2.setLayout(new GridLayout(10,1));
        for(i = 0; i < letrasLateral2.length; i++)
        {
            painelLetras2.add(letrasLateral2[i]);
        }
        
        JPanel painelNumeros2 = new JPanel();
        painelNumeros2.setLayout(new GridLayout(1,10));
        for(i = 0; i < numerosSuperior2.length; i++)
        {
            painelNumeros2.add(numerosSuperior2[i]);
        }
        
        JPanel painelLetrasBarcos = new JPanel();
        painelLetrasBarcos.setLayout(new GridLayout(10,1));
        for(i = 0; i < letrasLateralBarcos.length; i++)
        {
            painelLetrasBarcos.add(letrasLateralBarcos[i]);
        }
        
        JPanel painelNumerosBarcos = new JPanel();
        painelNumerosBarcos.setLayout(new GridLayout(1,10));
        for(i = 0; i < numerosSuperiorBarcos.length; i++)
        {
            painelNumerosBarcos.add(numerosSuperiorBarcos[i]);
        }
        
        /*---------------------------------------------------------------------------------------*/
        /*Parte 2 - Matrizes e Botoes -----------------------------------------------------------*/
        /*Parte 2.1 - Matriz de Defesa Aliada ---------------------------------------------------*/

        JButton[][] matrizBotoes1 = new JButton[10][10];
        for(i = 0; i < matrizBotoes1.length; i++)
        {
            for(j = 0; j < matrizBotoes1[i].length; j++)
            {
                matrizBotoes1[i][j] = new JButton(" ", new ImageIcon(this.getClass().getResource("/imagens/onda1"+resolucao)));
                matrizBotoes1[i][j].setDisabledIcon(new ImageIcon(this.getClass().getResource("/imagens/onda2"+resolucao)));
                matrizBotoes1[i][j].setToolTipText(letras[i]+numeros[j]);
            }
        }
        
        /*Parte 2.2 - Matriz de Ataque Inimiga --------------------------------------------------*/
        
        JButton[][] matrizBotoes2 = new JButton[10][10];
        for(i = 0; i < matrizBotoes2.length; i++)
        {
            for(j = 0; j < matrizBotoes2[i].length; j++)
            {
                matrizBotoes2[i][j] = new JButton(" ", new ImageIcon(this.getClass().getResource("/imagens/onda1"+resolucao)));
                matrizBotoes2[i][j].setDisabledIcon(new ImageIcon(this.getClass().getResource("/imagens/bomba2"+resolucao)));
                matrizBotoes2[i][j].setToolTipText(letras[i]+numeros[j]);
            }
        }
        
        /*Parte 2.3 - Matriz de Posicionamento da Frota -----------------------------------------*/
        JButton[][] matrizBotoesBarcos = new JButton[10][10];
        for(i = 0; i < matrizBotoesBarcos.length; i++)
        {
            for(j = 0; j < matrizBotoesBarcos[i].length; j++)
            {
                matrizBotoesBarcos[i][j] = new JButton(" ", new ImageIcon(this.getClass().getResource("/imagens/onda1"+resolucao)));
                matrizBotoesBarcos[i][j].setDisabledIcon(new ImageIcon(this.getClass().getResource("/imagens/onda2"+resolucao)));
                matrizBotoesBarcos[i][j].setToolTipText(letras[i]+numeros[j]);
            }
        }
        
        /*---------------------------------------------------------------------------------------*/
        /*Parte 3 - Construcao das Janelas ------------------------------------------------------*/
        JFrame janelaBarcos = new JFrame("Batalha Naval - 1 Player");
        janelaBarcos.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janelaBarcos.setSize(535, 550);
        janelaBarcos.setResizable(false);
        janelaBarcos.setLocationRelativeTo(null);
        
        JFrame janelaJogo = new JFrame("Batalha Naval - 1 Player");
        janelaJogo.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janelaJogo.setSize(1065, 580);
        janelaJogo.setResizable(false);
        janelaJogo.setLocationRelativeTo(null);
        
        /*Parte 3.1 - Janela de Posicionamento das Frotas ---------------------------------------*/       
        /*Parte 3.1.1 - Parte de Cima dessa Janela ----------------------------------------------*/
        JLabel posicionarFrotas = new JLabel("Insira sua Frota e clique em START:");
        posicionarFrotas.setHorizontalAlignment(JLabel.CENTER);
        posicionarFrotas.setBorder(BorderFactory.createEtchedBorder());
        
        /*Parte 3.1.2 - Parte Central dessa Janela ----------------------------------------------*/
        JPanel painelBarcosCentral = new JPanel();
        painelBarcosCentral.setLayout(new BorderLayout());
        
        JPanel painelBCSuperior = new JPanel();
        painelBCSuperior.setLayout(new BorderLayout());
        
        JLabel espacoBarcos = new JLabel(" BN");
        espacoBarcos.setBorder(BorderFactory.createEtchedBorder());
        
        JPanel painelMatrizBotoesBarcos = new JPanel();
        painelMatrizBotoesBarcos.setLayout(new GridLayout(10,10));
        
        /*Parte 3.1.3 - Parte de Baixo dessa Janela ---------------------------------------------*/
        JPanel painelBarcosInferior = new JPanel();
        painelBarcosInferior.setBorder(BorderFactory.createEtchedBorder());
        
        JButton start = new JButton("START");
        start.setEnabled(false);
        
        /*Parte 3.2 - Janela do Jogo Contra a Maquina -------------------------------------------*/
        /*Parte 3.2.1 - Parte de Cima dessa Janela ----------------------------------------------*/
        JPanel painelJogoSuperior = new JPanel();
        painelJogoSuperior.setLayout(new BorderLayout());
        
        JLabel tituloJogo = new JLabel("Batalha Naval");
        tituloJogo.setHorizontalAlignment(JLabel.CENTER);
        tituloJogo.setBorder(BorderFactory.createEtchedBorder());
        
        JPanel painelJogoGrades = new JPanel();
        painelJogoGrades.setLayout(new GridLayout(1,2));
        
        JLabel gradeAliada = new JLabel("Grade de Defesa");
        gradeAliada.setHorizontalAlignment(JLabel.CENTER);
        gradeAliada.setBorder(BorderFactory.createEtchedBorder());
        
        JLabel gradeInimiga = new JLabel("Grade de Ataque");
        gradeInimiga.setHorizontalAlignment(JLabel.CENTER);
        gradeInimiga.setBorder(BorderFactory.createEtchedBorder());
        
        /*Parte 3.2.2 - Parte Central dessa Janela ----------------------------------------------*/
        JPanel painelDefesaCentral = new JPanel();
        painelDefesaCentral.setLayout(new BorderLayout());
        
        JPanel painelDCSuperior = new JPanel();
        painelDCSuperior.setLayout(new BorderLayout());
        
        JLabel espaco1 = new JLabel(" BN");
        espaco1.setBorder(BorderFactory.createEtchedBorder());
        
        JPanel painelMatrizBotoes1 = new JPanel();
        painelMatrizBotoes1.setLayout(new GridLayout(10,10));
        
        /*Separacao------------------------------------------------------------------------------*/
        JPanel painelAtaqueCentral = new JPanel();
        painelAtaqueCentral.setLayout(new BorderLayout());
        
        JPanel painelACSuperior = new JPanel();
        painelACSuperior.setLayout(new BorderLayout());
        
        JLabel espaco2 = new JLabel(" BN");
        espaco2.setBorder(BorderFactory.createEtchedBorder());
        
        JPanel painelMatrizBotoes2 = new JPanel();
        painelMatrizBotoes2.setLayout(new GridLayout(10,10));
        
        JPanel painelJogoCentral = new JPanel();
        painelJogoCentral.setLayout(new GridLayout (1,2));
        
        /*Parte 3.2.3 - Parte de Baixo dessa Janela ---------------------------------------------*/
        JPanel painelJogoInferior = new JPanel();
        painelJogoInferior.setLayout(new GridLayout(1,2));
        
        JPanel painelJIEsquerda = new JPanel();
        painelJIEsquerda.setLayout(new GridLayout(2,1));
        
        JLabel ultimoAtaqueAliado = new JLabel ("Ultimo Ataque Aliado:");
        ultimoAtaqueAliado.setBorder(BorderFactory.createEtchedBorder());
        ultimoAtaqueAliado.setHorizontalAlignment(JLabel.CENTER);
        
        JLabel ultimoAtaqueAliadoAux = new JLabel (" ");
        ultimoAtaqueAliadoAux.setBorder(BorderFactory.createEtchedBorder());
        ultimoAtaqueAliadoAux.setHorizontalAlignment(JLabel.CENTER);
        ultimoAtaqueAliadoAux.setBackground(Color.white);
        
        JPanel painelJIDireita = new JPanel();
        painelJIDireita.setLayout(new GridLayout(2,1));
        
        JLabel ultimoAtaqueInimigo = new JLabel ("Ultimo Ataque Aliado:");
        ultimoAtaqueInimigo.setBorder(BorderFactory.createEtchedBorder());
        ultimoAtaqueInimigo.setHorizontalAlignment(JLabel.CENTER);
        
        JLabel ultimoAtaqueInimigoAux = new JLabel (" ");
        ultimoAtaqueInimigoAux.setBorder(BorderFactory.createEtchedBorder());
        ultimoAtaqueInimigoAux.setHorizontalAlignment(JLabel.CENTER);
        ultimoAtaqueInimigoAux.setBackground(Color.white);
        
        /*---------------------------------------------------------------------------------------*/
        /* Parte 4 - Acoes dos Botoes e Construcao ----------------------------------------------*/
        /*Parte 4.1 - Listeners -----------------------------------------------------------------*/
        /*Parte 4.1.1 - Acao para os botoes da Matriz1 ------------------------------------------*/
        
        
        /*Parte 4.1.2 - Acao para os botoes da Matriz2 ------------------------------------------*/
        ActionListener atirarCanhaoAliado = new ActionListener()
        {
            int i, linha, coluna, retornoAliado, controle, direcao;
            int[] retornoInimigo;
            String posicao, posicaoLinha, posicaoColuna;
            Embarcacoes barco1, barco2;
            
            public void actionPerformed(ActionEvent e)
            {
                JButton botaoClicado = (JButton)e.getSource();
                posicao = botaoClicado.getToolTipText();
                posicaoLinha = posicao.substring(0,1);
                posicaoColuna = posicao.substring(1,2);
                
                for(i = 0; i < letras.length; i++)
                {
                    if(posicaoLinha.equals(letras[i]))
                    {
                        linha = i;
                    }
                }
                coluna = Integer.parseInt(posicaoColuna);
                
                ultimoAtaqueAliadoAux.setText(posicao);
                
                matrizBotoes2[linha][coluna].setEnabled(false);
                
                retornoAliado = jogadores[0].ataqueAliado(jogadores[1].getMatrizNumeros(), linha, coluna);
                
                if(retornoAliado != 0)
                {
                    for(i = 0; i < 5; i++)
                    {
                        if(jogadores[1].getEmbarcacao(i).getIdentificadorBarco() == retornoAliado)
                        {
                            barco1 = jogadores[1].getEmbarcacao(i);
                        }
                    }
                    
                    barco1.levouTiro();
                    
                    if(barco1.afundou())
                    {
                        mostraBarcoNaMatrizBotoes(matrizBotoes2, barco1, resolucao, false);
                    }
                    
                    jogadores[1].tomarTiro(linha, coluna);
                }
                else /*Voce errou o tiro, logo, o inimigo realiza sua acao*/
                {
                    jogadores[1].tomarTiro(linha, coluna);
                    retornoInimigo = jogadores[1].ataqueInimigoAleatorio(jogadores[0].getMatrizNumeros());
                    do
                    {
                        controle = retornoInimigo[0];
                        linha = retornoInimigo[1];
                        coluna = retornoInimigo[2];
                        direcao = retornoInimigo[3];

                        posicaoLinha = letras[linha];
                        posicaoColuna = Integer.toString(coluna);
                        posicao = posicaoLinha + posicaoColuna;
                        
                        if(controle == 0)
                        {
                            ultimoAtaqueInimigoAux.setText(posicao);
                            matrizBotoes1[linha][coluna].setDisabledIcon(new ImageIcon(this.getClass().getResource("/imagens/bomba2"+resolucao)));
                            jogadores[0].tomarTiro(linha,coluna);
                        }
                        else
                        {
                            for(i = 0; i < 5; i++)
                            {
                                if(jogadores[0].getEmbarcacao(i).getIdentificadorBarco() == retornoInimigo[0])
                                {
                                    barco2 = jogadores[0].getEmbarcacao(i);
                                }
                            }
                        
                            barco2.levouTiro();
                            
                            ultimoAtaqueInimigoAux.setText(posicao);
                            
                            matrizBotoes1[linha][coluna].setDisabledIcon(new ImageIcon(this.getClass().getResource("/imagens/bomba1"+resolucao)));
                            jogadores[0].tomarTiro(linha,coluna);
                            if(!jogadores[1].venceuJogo())
                            {
                                retornoInimigo = jogadores[1].ataqueInimigoEstrategico(jogadores[0].getMatrizNumeros(), linha, coluna, direcao);
                            }
                            else
                            {
                                controle = 0;
                            }
                        }
                    }
                    while(controle != 0);
                }
                
                if((jogadores[0].venceuJogo())||(jogadores[1].venceuJogo()))
                {
                    if(jogadores[0].venceuJogo())
                    {
                        JOptionPane.showMessageDialog(null, "Voce Venceu!");
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null, "Voce Perdeu!");
                    }
                    System.exit(0);
                }
            }
        };
        
        for(i = 0; i < matrizBotoes2.length; i++)
        {
            for(j = 0; j < matrizBotoes2[i].length; j++)
            {
                matrizBotoes2[i][j].addActionListener(atirarCanhaoAliado);
            }
        }
        
        /*Parte 4.1.3 - Acao para os botoes da Matriz dos Barcos --------------------------------*/
        ActionListener colocarBarco = new ActionListener()
        {
            int i, j, linha, coluna, controle, indiceBarco;
            int direcao = 0, direcaoAux = 0;
            String posicao, posicaoLinha, posicaoColuna, direcaoString;
            Embarcacoes barco;
            
            public void actionPerformed(ActionEvent e)
            {
                JButton botaoClicado = (JButton)e.getSource();
                posicao = botaoClicado.getToolTipText();
                posicaoLinha = posicao.substring(0,1);
                posicaoColuna = posicao.substring(1,2);
                
                for(i = 0; i < letras.length; i++)
                {
                    if(posicaoLinha.equals(letras[i]))
                    {
                        linha = i;
                    }
                }
                coluna = Integer.parseInt(posicaoColuna);
                
                do
                {
                    try
                    {
                        direcaoString = JOptionPane.showInputDialog("Deseja inserir a embarcacao na (1)HORIZONTAL ou (2)VERTICAL:");
                    }
                    catch(Exception excecao)
                    {
                        
                    }
                }
                while((!"1".equals(direcaoString))&&(!"2".equals(direcaoString))&&(direcaoString != null));
                
                if(direcaoString != null)
                {
                    direcao = Integer.parseInt(direcaoString);
                }
                else
                {
                    return;
                }
                
                indiceBarco = jogadores[0].getIndiceInsercaoProximoBarco();
                controle = jogadores[0].inserirBarcoAliado(linha, coluna, direcao, indiceBarco);
                if(controle == 1)
                {
                    barco = jogadores[0].getEmbarcacao(indiceBarco);
                    mostraBarcoNaMatrizBotoes(matrizBotoesBarcos, barco, resolucao, false);
                }
                else
                {
                    JOptionPane.showMessageDialog(null, "Posicao Invalida", "ERROR", JOptionPane.ERROR_MESSAGE);
                }
                
                if(!jogadores[0].restamInserirBarcos())
                {
                    start.setEnabled(true);
                    for(i = 0; i < matrizBotoesBarcos.length; i++)
                    {
                        for(j = 0; j < matrizBotoesBarcos[i].length; j++)
                        {
                            matrizBotoesBarcos[i][j].setEnabled(false);
                        }
                    }
                }
            }
        };
        
        for(i = 0; i < matrizBotoesBarcos.length; i++)
        {
            for(j = 0; j < matrizBotoesBarcos[i].length; j++)
            {
                matrizBotoesBarcos[i][j].addActionListener(colocarBarco);
            }
        }
        
        /*Parte 4.1.4 - Acao para o botao START -------------------------------------------------*/
        start.addActionListener (new ActionListener()
        {
            int i, j;
            
            public void actionPerformed (ActionEvent e)
            {
                for(i = 0; i < matrizBotoes1.length; i++)
                {
                    for(j = 0; j < matrizBotoes1[i].length; j++)
                    {
                        matrizBotoes1[i][j].setDisabledIcon(matrizBotoesBarcos[i][j].getDisabledIcon());
                        matrizBotoes1[i][j].setEnabled(false);
                    }
                }
                
                jogadores[1].inserirFrotaInimiga();
                
                modificarMatrizBotoesPelaMatrizNumeros(matrizBotoes2, jogadores[1].getMatrizNumeros(), resolucao, true);
                
                janelaBarcos.setVisible(false);
                janelaJogo.setVisible(true);
            }
        });
        
        /*Parte 4.2 - Adds ----------------------------------------------------------------------*/
        /*Parte 4.2.1 - Janela de posicionamento de Frotas --------------------------------------*/
        painelBCSuperior.add(espacoBarcos, BorderLayout.WEST);
        painelBCSuperior.add(painelNumerosBarcos, BorderLayout.CENTER);
        for(i = 0; i < matrizBotoesBarcos.length; i++)
        {
            for(j = 0; j < matrizBotoesBarcos[i].length; j++)
            {
                painelMatrizBotoesBarcos.add(matrizBotoesBarcos[i][j]);
            }
        }
        
        painelBarcosCentral.add(painelBCSuperior, BorderLayout.NORTH);
        painelBarcosCentral.add(painelLetrasBarcos, BorderLayout.WEST);
        painelBarcosCentral.add(painelMatrizBotoesBarcos, BorderLayout.CENTER);
        
        painelBarcosInferior.add(start);
        
        janelaBarcos.getContentPane().add(posicionarFrotas, BorderLayout.NORTH);
        janelaBarcos.getContentPane().add(painelBarcosCentral, BorderLayout.CENTER);
        janelaBarcos.getContentPane().add(painelBarcosInferior, BorderLayout.SOUTH);
        janelaBarcos.setVisible(true);
        
        /*Parte 4.2.2 - Janela de jogo contra a Maquina -----------------------------------------*/
        painelJogoGrades.add(gradeAliada);
        painelJogoGrades.add(gradeInimiga);
        painelJogoSuperior.add(tituloJogo, BorderLayout.NORTH);
        painelJogoSuperior.add(painelJogoGrades, BorderLayout.CENTER);
        
        painelDCSuperior.add(espaco1, BorderLayout.WEST);
        painelDCSuperior.add(painelNumeros1, BorderLayout.CENTER);
        
        for(i = 0; i < matrizBotoes1.length; i++)
        {
            for(j = 0; j < matrizBotoes1[i].length; j++)
            {
                painelMatrizBotoes1.add(matrizBotoes1[i][j]);
            }
        }
        
        painelDefesaCentral.add(painelDCSuperior, BorderLayout.NORTH);
        painelDefesaCentral.add(painelLetras1, BorderLayout.WEST);
        painelDefesaCentral.add(painelMatrizBotoes1, BorderLayout.CENTER);
        
        painelACSuperior.add(espaco2, BorderLayout.WEST);
        painelACSuperior.add(painelNumeros2, BorderLayout.CENTER);
        
        for(i = 0; i < matrizBotoes2.length; i++)
        {
            for(j = 0; j < matrizBotoes2[i].length; j++)
            {
                painelMatrizBotoes2.add(matrizBotoes2[i][j]);
            }
        }
        
        painelAtaqueCentral.add(painelACSuperior, BorderLayout.NORTH);
        painelAtaqueCentral.add(painelLetras2, BorderLayout.WEST);
        painelAtaqueCentral.add(painelMatrizBotoes2, BorderLayout.CENTER);
        
        painelJogoCentral.add(painelDefesaCentral);
        painelJogoCentral.add(painelAtaqueCentral);
        
        painelJIEsquerda.add(ultimoAtaqueAliado);
        painelJIEsquerda.add(ultimoAtaqueAliadoAux);
        painelJIDireita.add(ultimoAtaqueInimigo);
        painelJIDireita.add(ultimoAtaqueInimigoAux);
        painelJogoInferior.add(painelJIEsquerda);
        painelJogoInferior.add(painelJIDireita);
        
        janelaJogo.getContentPane().add(painelJogoSuperior, BorderLayout.NORTH);
        janelaJogo.getContentPane().add(painelJogoCentral, BorderLayout.CENTER);
        janelaJogo.getContentPane().add(painelJogoInferior, BorderLayout.SOUTH);
        
        /*---------------------------------------------------------------------------------------*/
    }
    
    public void modificarMatrizBotoesPelaMatrizNumeros(JButton[][] matrizBotoes, int[][] matrizInteiros, String resolucao, Boolean habilitacao)
    {
        int i, j;
        for(i = 0; i < matrizBotoes.length; i++)
        {
            for(j = 0; j < matrizBotoes[i].length; j++)
            {
                if(matrizInteiros[i][j] != 0)
                {
                    matrizBotoes[i][j].setDisabledIcon(new ImageIcon(this.getClass().getResource("/imagens/bomba1"+resolucao)));
                }
                matrizBotoes[i][j].setEnabled(habilitacao);
            }
        }
    }
    
    public void mostraBarcoNaMatrizBotoes(JButton[][] matrizBotoes, Embarcacoes barco, String resolucao, Boolean habilitacao)
    {
        int i, linha, coluna, tamanho, direcao;
        String[] imagens;
        
        linha = barco.getLinhaPrincipal();
        coluna = barco.getColunaPrincipal();
        tamanho = barco.getNumQuadrados();
        direcao = barco.getDirecaoBarco();
        
        if(direcao == 1)
        {
            imagens = barco.getImagensHorizontal();
            
            for(i = 0; i < tamanho; i++)
            {
                matrizBotoes[linha][coluna+i].setDisabledIcon(new ImageIcon(this.getClass().getResource(imagens[i]+resolucao)));
                matrizBotoes[linha][coluna+i].setEnabled(habilitacao);
            }
        }
        else if (direcao == 2)
        {
            imagens = barco.getImagensVertical();
            
            for(i = 0; i < tamanho; i++)
            {
                matrizBotoes[linha+i][coluna].setDisabledIcon(new ImageIcon(this.getClass().getResource(imagens[i]+resolucao)));
                matrizBotoes[linha+i][coluna].setEnabled(habilitacao);
            }
        }
    }
}

