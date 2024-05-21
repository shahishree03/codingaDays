import java.util.*;
import java.io.*;

import java.lang.*;

public class Main{
    public static boolean isPresent(String str, ArrayList<String> res)
    {
        for(String s:res)
        {
            if(str.equals(s))
            {
                return true;
            }
        }
        return false;
    }
    public static ArrayList<String> UniquePermutation(String str)
    {
        if(str.length()==0)
        {
            ArrayList<String> base = new ArrayList<>();
            base.add("");
            return base;
        }
        
        char ch = str.charAt(0);
        String remaining = str.substring(1);
        ArrayList<String> prev = UniquePermutation(remaining);
        
        ArrayList<String> res = new ArrayList<>();
        
        for(String s:prev)
        {
            for(int i=0;i<=s.length();i++)
            {
                String f = s.substring(0,i)+ch+s.substring(i);
                
                if(!isPresent(f,res))
                {
                    res.add(f);
                }
            }
        }
        
        return res;
    }
    public  static void main(String args[])
    {
        String s="abbb";
        System.out.println(UniquePermutation(s));
        
    }
}
