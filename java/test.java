import java.util.*;
import java.util.Collections.*;

public class test {

     public static void main(String[] args) {
        

         int[] a={1,3,5,6};
         
         int target=2;
         int result = ceiling(a,target);
         //System.out.println(result);

         
    }
    static int ceiling(int[] arr,int target){
        
        int start=0;
        int end=arr.length-1;
        int mid=0;
        while(start <=end){
          mid=start+(end-start)/2;

          if(arr[mid]==target)
               return arr[mid];
          else if(arr[mid]>target)
               end=--mid;
          else
               start=++mid;
        }
        return arr[mid];
    }
}
