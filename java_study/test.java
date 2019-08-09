package java_study;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class test {
    public static void main(String args[]){
        /**
        String[] test = {"flower", "flow","flight"};
        String ans = test[0];

        for(int i=1;i<test.length;i++){
            int j = 0;
            for(;j<Math.min(ans.length(), test[i].length());j++){
                if(ans.charAt(j) != test[i].charAt(j)){
                    //System.out.println(j);
                    break;
                }
            }
            System.out.println(j);
            ans = ans.substring(0,j);
        }
        System.out.println(ans);
        //System.out.println(ans.substring(0,1));
        **/

        /**
        int i = 0;
        for(;i<2;i++){
            System.out.printf("循环内：%d\n",i);
        }
        System.out.printf("循环外：%d\n",i);
        **/
        /**
        int num1 = 1;
        int num2 = num1;
        System.out.println(num1);
        num2 = 10;
        System.out.println(num1);

        int[] array1 = {1,2,3};
        int[] array2 = array1;
        System.out.println(Arrays.toString(array1));
        array2[0] = 10;
        System.out.println(Arrays.toString(array1));
         **/
        /**
        LinkedList my_list = new LinkedList();
        my_list.add(1);
        my_list.add('a');
        my_list.set(1,'b');
        //System.out.println(my_list);
        //my_list.remove('a');
        int[] array = {1,2,3,4,5};
        System.out.println(array);
        Arrays.asList(array);

        List<List> matrix = new ArrayList();
        matrix.add(Arrays.asList(1,2,3));
        matrix.add(Arrays.asList(4,5,6));

        List sub_matrix = new ArrayList();
        sub_matrix = matrix.subList(0,1);
         **/

        /**
        int[] test1 = {1};
        int[] test2 = test1;
        test2[0] = 2;
        int[] test3 = {2};
        System.out.println(Arrays.toString(test1));
        System.out.println(Arrays.toString(test2));
        System.out.println(test2.equals(test3));

        String a1 = "a";
        String a2 = a1;
        //a2 = "a";
        System.out.println(a1);
        System.out.println(a2);
        System.out.println(a1 == a2);
        System.out.println(a1.equals(a2));
        */
        Pattern my_pattern = Pattern.compile("\\D{3}-\\d{3}");
        Matcher my_str = my_pattern.matcher("abc-456-345-cvb-345 qwe-123");
        //System.out.println(my_str.matches());
        while(my_str.find()){
            System.out.println(my_str.group());
            //mSystem.out.println(my_str.group(1));
        }


    }


}
