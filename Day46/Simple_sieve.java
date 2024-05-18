import java.util.*;
import java.io.*;

public class Main()
  {
  public static void simplesieve(int limits){
boolean[] prime = new boolean[limits+1];
  for(int p=2;p<=limits;p++)
    {
   prime[p]=true;
    }


  for(int p=2;p<=limits;p++)
    {

if(prime[p]==true)
{
for(int i=p*p;i<=limits;i+=p)
  {
prime[i]=false;
  }

}
    }

for(int p=2;p<=limits;p++)

  {
if(prime[p]==true)
{
System.out.println(p+" ");
}

  }
  

  }
public static void main(String args[])
  {
simplesieve(5);
}
}
