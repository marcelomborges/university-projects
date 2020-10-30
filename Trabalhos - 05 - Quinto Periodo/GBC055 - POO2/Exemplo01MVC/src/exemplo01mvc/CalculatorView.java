package exemplo01mvc;
//This is the View
//Its only job is to display what the user sees
//It performs no calculations, but instead passes
//information entered by the user to whomever needs
//it. 

import java.awt.event.ActionListener;

import javax.swing.*;

public class CalculatorView extends JFrame{

	private JLabel additionLabel1 = new JLabel("Op1");
	private JTextField firstNumber  = new JTextField(10);
	private JLabel additionLabel2 = new JLabel("Op2");
	private JTextField secondNumber = new JTextField(10);
	private JButton calculateButton = new JButton("Soma");
	private JButton calculateButton2 = new JButton("Subtrai");
	private JTextField calcSolution = new JTextField(10);
	
	CalculatorView(){
		
		// Sets up the view and adds the components
		
		JPanel calcPanel = new JPanel();
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(600, 200);
		
		calcPanel.add(additionLabel1);
		calcPanel.add(firstNumber);
		calcPanel.add(additionLabel2);
		calcPanel.add(secondNumber);
		calcPanel.add(calculateButton);
		calcPanel.add(calculateButton2);
		calcPanel.add(calcSolution);
		
		this.add(calcPanel);
		
		// End of setting up the components --------
		
	}
	
	public int getFirstNumber(){
		
		return Integer.parseInt(firstNumber.getText());
		
	}
	
	public int getSecondNumber(){
		
		return Integer.parseInt(secondNumber.getText());
		
	}
	
	public int getCalcSolution(){
		
		return Integer.parseInt(calcSolution.getText());
		
	}
	
	public void setCalcSolution(int solution){
		
		calcSolution.setText(Integer.toString(solution));
		
	}
	
	// If the calculateButton is clicked execute a method
	// in the Controller named actionPerformed
	
	void addSomaListener(ActionListener listenForCalcButton){
		calculateButton.addActionListener(listenForCalcButton);
	}
	
	void addSubtraiListener(ActionListener listenForCalcButton){
		calculateButton2.addActionListener(listenForCalcButton);
		
	}
	
	// Open a popup that contains the error message passed
	
	void displayErrorMessage(String errorMessage){
		
		JOptionPane.showMessageDialog(this, errorMessage);
		
	}
	
}	