import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
public class fruittest 
{
    public static void main(String[] args){

      List<Fruit> list=new ArrayList<>();
      list.add(new Fruit("apple",0.5f));
      list.add(new Fruit("orange",0.8f));
      list.add(new Fruit("a",0.1f));
      list.add(new Fruit("ap",0.87f));
      list.add(new Fruit("app",0.45f));
      list.add(new Fruit("appl",0.001f));
      list.add(new Fruit("a123",0.234f));
      list.add(new Fruit("a456",0.023f));
      Collections.sort(list,new CompareObj());
      
      Iterator it=list.iterator();
      while(it.hasNext()){
         Fruit f=(Fruit) it.next();
         System.out.println(f.name +  f.probability);
      }
   }
}

class CompareObj implements Comparator<Fruit>{
   public int compare(Fruit f1,Fruit f2){
         if(f1.probability > f2.probability)
            return -1;

         return 1;
   }
}

class Fruit{
   String name;
   float probability;

   Fruit(){
   }
   Fruit(String name,float probability){
        this.name=name;
        this.probability=probability;
   }
}