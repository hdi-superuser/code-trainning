import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
 
 
public class Main {
    
    public static Scanner cin = new Scanner(System.in);
    
    public static void main(String[] args) throws IOException  {
        
        /*
        FileInputStream fi = new FileInputStream("D:/java.inp"); 
        Scanner in = new Scanner(fi);
        FileOutputStream fo = new FileOutputStream("D:/java.out");
        PrintWriter out = new PrintWriter(fo);
        */
        
        //BufferedReader in = new BufferedReader(new FileReader(new File("D:/java.inp")));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        DecimalFormat df = new DecimalFormat("#.000"); 
        
        //------------------------------------------------------------------------------//
        
        BigInteger bs = BigInteger.valueOf(1000000007);
        
        BigInteger c[][] = new BigInteger[60][60]; 
        for (int i=1;i<=55;i++)
        	for (int j=1;j<=55;j++) c[i][j] = BigInteger.valueOf(0);
       
        c[1][1] = c[1][0] = BigInteger.valueOf(1);
        
        for (int i=2;i<=55;i++)
        	for (int j=0;j<=i;j++)
        		if (j == 0) 
        			c[i][j] = BigInteger.valueOf(1);
        		else 
        			c[i][j] = c[i-1][j].add(c[i-1][j-1]);
 
        //for (int i=2;i<=5;i++)
        //	for (int j=0;j<=i;j++) System.out.println(i+ " " + j + " " + c[i][j]);
        
        String s;
        BigInteger f[] = new BigInteger[100];
        
        while ((s = in.readLine()) != null) {
        	
        	String t[] = s.split(" ");
        	long n = Long.parseLong(t[0]);
        	int k = Integer.parseInt(t[1]);
        	
        	for (int i=1;i<=k;i++) f[i] = BigInteger.valueOf(0);
        	f[1] = BigInteger.valueOf(n*(n+1)/2);
        	
        	BigInteger q = BigInteger.valueOf(n+1);
        	
        	for (int i=2;i<=k;i++) {
        		
        		BigInteger tmp1 = BigInteger.valueOf(1);
        		for (int j=1;j<=i+1;j++) tmp1 = tmp1.multiply(q);
       
        		BigInteger tmp2 = BigInteger.valueOf(0);
        		for (int j=2;j<=i;j++) {
        			BigInteger x = c[i+1][j];
        			tmp2 = tmp2.add(x.multiply(f[i-j+1]));
        		}
        		
        		tmp1 = tmp1.subtract(q);
        		tmp1 = tmp1.subtract(tmp2);
        		f[i] = tmp1;
        		f[i] = f[i].divide(BigInteger.valueOf(i+1));
        		
        	}
        	
        	//System.out.println(f[k]);
        	System.out.println(f[k].mod(bs));
        	
        }
        
    }
    
    
}  
