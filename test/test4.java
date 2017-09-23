package test;

public class Main {

	public static void main(String[] args){
		//TODO Auto-generated method stub
		
		String name = 'N';
		String surname = 'R';
		int age = 25;		
		

		Person an;
		an = new Person(name,surname,age);

		Person nb = new Person('J','J');

		surname = an.getSurname();

		bn.setSurname(surname);


		Person[] spisak;

		spisak=new Person[10];

		spisak[0]=an;
		spisak[1]=bn;

		System.out.println(spisak[0]);
	}

}
