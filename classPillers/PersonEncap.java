package classPillers;

public class PersonEncap {
	
	    // Private variables to represent the state (data) of the object
	    private String name;
	    private int age;

	    // Constructor to initialize the object's state
	    public PersonEncap(String name, int age) {
	        this.name = name;
	        this.age = age;
	    }

	    // Public methods to provide controlled access to the private variables
	    public String getName() {
	        return name;
	    }

	    public void setName(String name) {
	        this.name = name;
	    }

	    public int getAge() {
	        return age;
	    }

	    public void setAge(int age) {
	        this.age = age;
	    }

}
