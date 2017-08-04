package test;

public class Main {

	public static void main(String[] args){
		//TODO Auto-generated method stub
		
		char p = 'j';
		
		double e = 2.35;
		double m = e * 23;

		float z=0;
		z=e/m;

		int m = 2 + 3;
		int n = 30-20;
		
		
		if(n<10)
			n=n*n;
		else
			n=m;

		if(m>7){
		   m=2;
		}			


		int i=0;
		while(i<11){
			System.out.println("Brojac je: " + i);
			i++;
		}
		
		//Inicijalizacija niza
		int []niz;
		niz=new int[10];

		for(i=0;i<10;i++){
			niz[i]=i;
		}
		//drugi nacin inicijalizacije niza
		int[] niz2={10,20,30,40,60};
	        
                //Inicijalizacija matrica
		int[][] matrica;
		matrica=new int[10][5];


	}

}
