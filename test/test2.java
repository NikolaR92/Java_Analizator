package test;

public class Person{
	char name;
	char surname;
	int age;
	
	public Person(){

	}

	public Person(char name){
		name=name;
	}

	public Person(char name,char surname){
		name=name;
		surname=surname;

	}

	public Person(char name, char surname, int age){
		name=name;
		surname=surname;
		age=age;
	}

	//komentar
	public Person(Person ab){
		this.name = ab.getName( );
		super.surname = ab.surname;
		age = ab.age;
	}	
	
	public char setName(char newName){
		name=newName;
	}

	
	public char getName(){
		return name;
	}	
	
	
	public char setSurname(char newSurname){
		surname=newSurname;
	}

	
	public char getSurname(){
		return surname;
	}

}
