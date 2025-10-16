import java.util.Scanner;

	class account{

	private int accnumber;
	private double balance;
	private String name;

	public account(){
		this.accnumber=0;
		this.balance=0;
		this.name="N/a";
	}
	
	public account(String name,int accountnum, double balance){
		this.accnumber=accountnum;
		this.balance=balance;
		this.name=name;
	}
	
	void deposit(double amount){
		this.balance+= amount;
		System.out.println(balance+" has been deposited"+"\n");
	}
	
	void withdraw(double ammount){
		if( this.balance<=0 || ammount>this.balance){
			System.out.println("Insufficent funds for the withdraw"+"\n");
		}
		else {
			this.balance-=ammount;
			System.out.println(ammount+" has been withdrawn.\nYour bank balance is now "+this.balance+"\n");
		}
	}
	
	void balance(){
		System.out.println("Your current balance is: "+this.balance+"\n");	
	}
	
	void details(){		
		System.out.println("Name of the account holder is " +name);
		System.out.println("Your account number is "+ this.accnumber);
		System.out.println("Your balance is "+ this.balance+"\n");
	}
}

public class demobank{
	public static void main(String[] args){
		Scanner scanner= new Scanner(System.in);
		account account1= new account();
		account account2= new account("Madhav",1122566,10000);
		account1.details();	
		account2.details();
		int flag=1;	
		while (flag==1)
		{
			System.out.println("For Account 2, would you like to\n[1]Deposit\n[2]Withdraw\n[3]See Balance\n[4]See Full Details\n[0]Exit");
			int opt= scanner.nextInt();
			if (opt==1)
			{
				System.out.println("How much would you like to deposit?");
				double amount=scanner.nextInt();
				account2.deposit(amount);
			}
			else if(opt==2)
			{
				System.out.println("How much would you like to withdraw?");
				double amount=scanner.nextInt();
				account2.withdraw(amount);
			}
			else if(opt==3)
			{
				account2.balance();
			}
			else if(opt==4)
			{
				account2.details();
			}
			else if(opt==0)
			{
				System.out.println("Exiting....");	
				flag=0;		
			}
			else
			{
				System.out.println("Please Enter a valid option");
			}
		
		
		}
		


	}	
}
