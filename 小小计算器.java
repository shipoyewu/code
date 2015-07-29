package calc;

import java.awt.Button;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.awt.event.ContainerListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.EventListener;

public class zuoye extends Frame {
	
	myPan1 P_L;
	myPan2 P_R;
	TextField text;
	double num1 = 0;
	double num2 = 0;
	int op;
	boolean result = false;
	
	public zuoye(String str){
		super(str);	
		addWindowListener(new close());;
		setLocation(400,400);
		setSize(250, 200);
		setLayout(new FlowLayout(FlowLayout.CENTER, 8, 10));
		
		text = new TextField(23);
		text.setSize(100,50);
		text.setBackground(Color.white);
		text.setEditable(false);
		add(text);
		P_L = new myPan1();
		add(P_L);
		P_R = new myPan2();
		add(P_R);
		setVisible(true);
		
	}
	
	class myPan1 extends Panel{
		Button[] btn = new Button[12];
		
		myPan1(){
			setBackground(Color.LIGHT_GRAY);
			for(int i = 0;i < 10;i++){
				btn[i] = new Button(""+i);
				
			}
			btn[10] = new Button("+/-");
			btn[11] = new Button(".");
			setLayout(new GridLayout(4,3));
			
			add(btn[7]);btn[7].addActionListener(new pre_7());
			add(btn[8]);btn[8].addActionListener(new pre_8());
			add(btn[9]);btn[9].addActionListener(new pre_9());
			add(btn[4]);btn[4].addActionListener(new pre_4());
			add(btn[5]);btn[5].addActionListener(new pre_5());
			add(btn[6]);btn[6].addActionListener(new pre_6());
			add(btn[1]);btn[1].addActionListener(new pre_1());
			add(btn[2]);btn[2].addActionListener(new pre_2());
			add(btn[3]);btn[3].addActionListener(new pre_3());
			add(btn[0]);btn[0].addActionListener(new pre_0());
			add(btn[10]);btn[10].addActionListener(new pre_10());
			add(btn[11]);btn[11].addActionListener(new pre_11());
		}
		
		class pre_7 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"7"); 
			}		
		}
		class pre_8 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"8"); 
			}		
		}
		class pre_9 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"9"); 
			}		
		}
		class pre_5 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"5"); 
			}		
		}
		class pre_6 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"6"); 
			}		
		}
		class pre_1 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"1"); 
			}		
		}
		class pre_2 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"2"); 
			}		
		}
		class pre_3 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"3"); 
			}		
		}
		class pre_4 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				text.setText(text.getText()+"4"); 
			}		
		}
		class pre_0 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				String tex = text.getText();
				if(tex.isEmpty()){
					tex = "0.";
				}
				else {
					tex += '0';
				}
				text.setText(tex);
			}		
		}
		class pre_10 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String tex = text.getText();
				if(!tex.isEmpty()){
					if(tex.charAt(0) == '-'){
						tex = tex.substring(1, tex.length());
					}
					else if(tex.charAt(0) == '.'){
						tex = "-0" + tex;
					}
					else {
						tex = "-"+tex;
					}
				}
				text.setText(tex);
			}		
		}
		class pre_11 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(op==-1){
					text.setText("");
					op = 0;
				}
				String tex = text.getText(); 
				if(tex.isEmpty()){
					tex = "0.";
				}
				else{
					int flag = 1;
					for(int i =0;i < tex.length();i++){
						if(tex.charAt(i) == '.'){
							flag = 0;
							break;
						}
					}
					if(flag == 1){
						tex = tex+".";
					}
				}
				text.setText(tex);
			}		
			
		}
	}
	
	class myPan2 extends Panel{
		Button[] btn = new Button[12];
		
		myPan2(){
			setBackground(Color.LIGHT_GRAY);
			btn[0] = new Button("+");btn[0].addActionListener(new pre_0());
			btn[1] = new Button("sin");btn[1].addActionListener(new pre_1()); 
			btn[2] = new Button("cos");btn[2].addActionListener(new pre_2());
			btn[3] = new Button("-");btn[3].addActionListener(new pre_3());
			btn[4] = new Button("sqrt");btn[4].addActionListener(new pre_4());
			btn[5] = new Button("CE");btn[5].addActionListener(new pre_5());
			btn[6] = new Button("*");btn[6].addActionListener(new pre_6());
			btn[7] = new Button("y^x");btn[7].addActionListener(new pre_7());
			btn[8] = new Button("<=");btn[8].addActionListener(new pre_8());
			btn[9] = new Button("/");btn[9].addActionListener(new pre_9());
			btn[10] = new Button("ln");btn[10].addActionListener(new pre_10());
			btn[11]= new Button("=");btn[11].addActionListener(new pre_11());
			setLayout(new GridLayout(4,3));
		
			for(int i = 0;i < 12;i++){
				add(btn[i]);
			}
		}
		
		class pre_0 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				String tex = text.getText();
				if(tex.isEmpty()){
					num1 = 0;
				}
				else {
					num1 = Double.parseDouble(tex);
				}
				op = 1;
				text.setText("");
			}
		}
		
		class pre_3 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				String tex = text.getText();
				if(tex.isEmpty()){
					num1 = 0;
				}
				else {
					num1 = Double.parseDouble(tex);
				}
				op = 2;
				text.setText("");
			}
		}
		class pre_6 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				String tex = text.getText();
				if(tex.isEmpty()){
					num1 = 0;
				}
				else {
					num1 = Double.parseDouble(tex);
				}
				op = 3;
				text.setText("");
			}
		}
		
		class pre_9 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				String tex = text.getText();
				if(tex.isEmpty()){
					num1 = 0;
				}
				else {
					num1 = Double.parseDouble(tex);
				}
				op = 4;
				text.setText("");
			}
		}
		
		class pre_1 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				if(op == 0){
					num1 = Double.parseDouble(text.getText());
				}
				text.setText(String.valueOf(Math.sin(num1)));
				op = -1;
				num1 = Math.sin(num1);
			
			}
			
		}
		class pre_2 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				if(op == 0){
					num1 = Double.parseDouble(text.getText());
				}
				text.setText(String.valueOf(Math.cos(num1)));
				op = -1;
				num1 = Math.cos(num1);
			}
		}
		
		class pre_4 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				if(op == 0){
					num1 = Double.parseDouble(text.getText());
				}
				text.setText(String.valueOf(Math.sqrt(num1)));
				op = -1;
				num1 = Math.sqrt(num1);
			}
		}
		class pre_10 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				if(op == 0){
					num1 = Double.parseDouble(text.getText());
				}
				text.setText(String.valueOf(Math.log(num1)));
				op = -1;
				num1 = Math.log(num1);
			}
		}
		class pre_8 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				String tex = text.getText();
				if(!tex.isEmpty()){
					tex = tex.substring(0,tex.length()-1);
				}
				text.setText(tex);
			}
		}
		class pre_7 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				String tex = text.getText();
				if(tex.isEmpty()){
					num1 = 0;
				}
				else {
					num1 = Double.parseDouble(tex);
				}
				op = 5;
				text.setText("");
			}
		}
		class pre_5 implements ActionListener{
			@Override
			public void actionPerformed(ActionEvent e) {
				op = 0;
				text.setText("");
			}
		}
		class pre_11 implements ActionListener{

			@Override
			public void actionPerformed(ActionEvent arg0) {
				String tex = text.getText();
//				System.out.println(op);
				
				switch(op){
					case 0:{
						break;
					}
					case 1:{
						if(tex.isEmpty()){
							num2 = 0;
						}
						else {
							num2 = Double.parseDouble(text.getText());
						}
						text.setText(num1+num2+"");
					
						op = -1;
						break;
					}
					case 2:{
						if(tex.isEmpty()){
							num2 = 0;
						}
						else {
							num2 = Double.parseDouble(text.getText());
						}
						text.setText(num1-num2+"");
						op = -1;
						break;
					}
					case 3:{
						if(tex.isEmpty()){
							num2 = 0;
						}
						else {
							num2 = Double.parseDouble(text.getText());
						}
						text.setText(num1*num2+"");
						op = -1;
						break;
					}
					case 4:{
						if(tex.isEmpty()){
							num2 = 0;
						}
						else {
							num2 = Double.parseDouble(text.getText());
						}
						try{
							text.setText(num1/num2+"");
						}catch(Exception e){
							
						}
						
						op = -1;
						break;
					}
					case 5:{
						if(tex.isEmpty()){
							num2 = 0;
						}
						else {
							num2 = Double.parseDouble(text.getText());
						}
						try{
							text.setText(Math.pow(num1, num2)+"");
						}catch(Exception e){
							text.setText("发生了数学错误");
						}
						
						op = -1;
						break;
					}
				}
			}
			
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new zuoye("myCalc");
		
	}

}
 

class close implements WindowListener{

	@Override
	public void windowActivated(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowClosed(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowClosing(WindowEvent e) {
		// TODO Auto-generated method stub
		System.exit(0);
	}

	@Override
	public void windowDeactivated(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowDeiconified(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowIconified(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void windowOpened(WindowEvent e) {
		// TODO Auto-generated method stub
		
	}
	
	
}