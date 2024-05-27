import java.util.*;

class ArrayList{
public static void main(String args[])
  {
ArrayList<Integer> l1= new ArrayList<Integer>();
    l1.add(0);
    l1.add(4);
    l1.add(3);

    System.out.println(l1);
    System.out.println(l1.get(1));

    //
    l1.add(1,1);

    //set
    l1.set(0,5);
    //remove

    l1.remove(3);

    int len= l1.size();
    //for loops

    for(int i=0;i<len;i++)
      {
       System.out.println(l1.get(i));
      }


    //sort

    Collections.sort(l1);

  }

}
