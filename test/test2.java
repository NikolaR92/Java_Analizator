package test;

public class Person{
	String name;
	String surname;
	int age;
	
	public Person(){

	}

	public Person(String name){
		this.name=name;
	}

	public Person(String name,String surname){
		this.name=name;
		this.surname=surname;

	}

	public Person(String name, String surname, int age){
		this.name=name;
		this.surname=surname;
		this.age=age;
	}

	public Person(Person a){
		this.name=a.getName();
		this.surname=a.surname;
		this.age=a.age;
	}

	//set method for name
	public void setName(String newName){
		this.name=newName;
	}

	//get method for name
	public String getName(){
		return this.name;
	}	
	
	//set method for surname
	public void setSurname(String newSurname){
		surname=newSurname;
	}

	//get method for surname
	public String getSurname(){
		return surname;
	}

}
