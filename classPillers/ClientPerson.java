package classPillers;

public class ClientPerson {
	public static void main(String[] args) {
		
		//Create a new person object
		PersonEncap p1;
		p1 = new PersonEncap("Sneha",23);
		
		
		//use getter to retrieve name
		String name = p1.getName();
		System.out.println("Name : "+name);
		
		//use setter to modify name
		p1.setName("Alice");
		String newName = p1.getName();		
		//use getter to see modified name
		System.out.println("new name : "+newName);
		
		
	}
}
