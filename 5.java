CalculatorClient.java
// This is the actual client program using Calculator interface
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.net.MalformedURLException;
import java.rmi.NotBoundException;
import java.util.*;
public class CalculatorClient {
	public static void main(String[] args) {
		try {
				Calculator c = (Calculator) Naming.lookup("rmi://localhost/CalculatorService");
				Scanner sc = new Scanner(System.in);
				System.out.print("Enter the first number, a = ");
				int a = sc.nextInt();
				System.out.print("Enter the second number, b = ");
				int b = sc.nextInt();
				sc.close();
				System.out.println();
				System.out.print("The sum of a and b = ");
				System.out.println(c.add(a, b));
				System.out.print("The difference of a and b = ");
				System.out.println(c.sub(a, b));
				System.out.print("The product of a and b = ");
				System.out.println(c.mul(a, b));
				System.out.print("The division of a and b = ");
				System.out.println(c.div(a, b));
			}
			catch (MalformedURLException murle) {
				System.out.println();
				System.out.println("MalformedURLException");
				System.out.println(murle);
			}
			catch (RemoteException re) {
				System.out.println();
				System.out.println("Remote Exception");
				System.out.println(re);
			}
			catch (NotBoundException nbe) {
				System.out.println();
				System.out.println("NotBoundException");
				System.out.println(nbe);
			}
			catch (java.lang.ArithmeticException ae) {
				System.out.println();
				System.out.println("java.lang.ArithmeticException");
				System.out.println(ae);
		}
	}
}