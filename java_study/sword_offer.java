package java_study;

import java.util.HashMap;
import java.util.Map;

public class sword_offer {
    public static int repetive_num(int[] array){
        Map<Integer,Integer> map = new HashMap<>();
        int result = 0;
        for(int i=0;i<array.length;i++){
            if(map.containsKey(array[i])){
                result = array[i];
                break;
            }
            map.put(array[i], i);
        }
        return result;
    }

    public static void main(String args[]){
        int result;
        int[] array = new int[] {1,2,4,3,2};
        result = repetive_num(array);
        System.out.println(result);

    }
}
