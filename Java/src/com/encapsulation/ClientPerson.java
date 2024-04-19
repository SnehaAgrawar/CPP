package com.encapsulation;

public class ClientPerson {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person p1 = new Person("Sneha",23);
		System.out.println(p1.toString());
		
		String nm = p1.getName();
		System.out.println("Old name : "+nm);
		
		p1.setName("John");
		System.out.println("New name : "+p1.getName());
	}
}
