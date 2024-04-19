package com.encapsulation;

	public class Person {
	    // Private variables to represent the state (data) of the object
	    private String name;
	    private int age;

	    // Constructor to initialize the object's state
	    public Person() {
	    	name = "NA";
	    	age = 0;
	    }
	    
	    
	    public Person(String name, int age) {
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
	    
	    public String toString() {
	    	return "Name : "+name+"   age : "+age;
	    }
	}

