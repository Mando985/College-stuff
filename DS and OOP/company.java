import java.util.Scanner;

abstract class employee {
    String name;
    int id;
    double salary;

    employee(String name, int id, double salary) {
        this.name = name;
        this.id = id;
        this.salary = salary;
    }

    abstract double bonus();
    abstract void display();
}






class manager extends employee{
	int teamsize;
	
	manager(String name, int id, double salary, int teamsize) {
        super(name, id, salary);
        this.teamsize = teamsize;
    }
    
    void display(){
    	System.out.println("-----info-----\nEmployee name: "+name+"\nID: "+id+"\nSalary: "+salary+"\nTeam size: "+teamsize);
    }
    
    double bonus(){
    	return (salary+25000);
    }
}





class seniormanager extends manager{
	int stockoptions;
	seniormanager(String name, int id, double salary, int teamsize,int stockoptions) {
        super(name, id, salary,teamsize);
        this.stockoptions = stockoptions;
    }
    void display(){
    	super.display();
    	System.out.println("Stock Options: "+stockoptions);
    }
    double bonus(){
    	return super.bonus() + stockoptions*13;
    }
}




class developer extends employee {
    String[] programminglanguages;

    developer(String name, int id, double salary, String[] programminglanguages) {
        super(name, id, salary);
        this.programminglanguages = programminglanguages;
    }


    double bonus() {
        return salary+10000;
    }

    void display() {
        System.out.println("-----info-----\nEmployee name: "+name+"\nID: "+id+"\nSalary: "+salary+"\nProgramming Languages: ");
        for (String lang : programminglanguages) {
            System.out.print(lang + " ");
        }
        System.out.println();
    }


    void assigntask(String task) {
        System.out.println(name + " assigned task: " + task);
    }

    void assigntask(String task, int hours) {
        System.out.println(name + " assigned task: " + task + " for " + hours + " hours");
    }

    void assigntask(String task, String deadline) {
        System.out.println(name + " assigned task: " + task + ", deadline: " + deadline);
    }
}





class jrdeveloper extends developer{
	String mentor;
	
	jrdeveloper(String name, int id, double salary, String[] programminglanguages, String mentor){
	super(name,id,salary,programminglanguages);
	this.mentor=mentor;
	}
	
	void display() {
		super.display();	
		System.out.println("Mentor: "+mentor);
	}
	double bonus(){
		return salary+5000;
	}
}




class intern extends employee{
    int duration; 

    intern(String name, int id, double salary, int duration) {
        super(name, id, salary);
        this.duration = duration;
    }

    double bonus() {
        return salary+1000;
    }

    void display() {
        System.out.println("-----info-----\nEmployee name: "+name+"\nID: "+id+"\nSalary: "+salary+"\nDuration: "+duration);
    }
}





public class company {
	public static void main (String[] args){
	  
	 employee p2 = new manager("John", 2, 90000, 5);
        employee p1= new seniormanager("Madhav", 1, 120000, 10, 200);
        employee p3 = new developer("Leo", 3, 80000, new String[]{"Java", "Python"});
        employee p4 = new jrdeveloper("Yohan", 4, 60000, new String[]{"JavaScript"}, "Madhav");
        employee p5= new intern("Jaasim", 5, 5, 30);


        employee[] employees = {p1,p2,p3,p4,p5};

        System.out.println("== Company Employees ==");
        for (employee emp : employees) {
            emp.display();
            System.out.println("Salary after bonus: " + emp.bonus());
            System.out.println("--------------------------");
        }


        System.out.println("== Task Assignment Demo ==");
        
        developer p6 = new developer("Raj", 6, 80000, new String[]{"Java", "Python"});
        p6.assigntask("Fix bugs");
        p6.assigntask("Fix bugs", 5);
        p6.assigntask("Fix bugs", "Friday");
	System.out.println("--------------------------");
	
	
	}
	


}
