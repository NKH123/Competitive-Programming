import java.math.BigInteger;
import java.util.Scanner;
public class big{
	public static void playWithInt(){
		Scanner sc=new Scanner(System.in);
		//int s1=sc.nextInt();
		//System.out.println(s1*s1);
		BigInteger one =new BigInteger("465654654654654");
		BigInteger two=new BigInteger("465654654654654");
		System.out.println(two.add(one));
		String s2=sc.next();
		BigInteger x=new BigInteger(s2,2);
		System.out.println(x.toString(8));
	}

	public static void main(String arg[]){
		playWithInt();

	}
}