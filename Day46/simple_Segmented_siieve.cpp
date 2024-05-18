import java.util.*;
import java.io.*;

public class Main{
    public static void simple_segmented_sieve(int l, int h)
    {
        boolean[] prime = new boolean[h+1];
        
        
        for(int p=2;p*p<=h;p++)
        {
            int sm =(l/p)*p;
            if(sm<l)
            {
                sm+=p;
            }
            
            for(int i= sm;i<=h;i+=p)
            {
                prime[i]=true;
            }
            
            
        
        }
        
        for(int p=l;p<=h;p++)
        {
             if (prime[p] == false) {
                System.out.print(p + " ");
        }
        
    }
        }
    
    public static void main(String args[])
    {
        int prime =5;
        simple_segmented_sieve(4,11);
    }
}
