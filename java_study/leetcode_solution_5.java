package java_study;

import java.util.Arrays;

public class leetcode_solution_5 {
    static int test = 10;
    public static void main(String args[]){
        //int num = 10;
        //System.out.println(isprime_2(num));
        //int target = 2;
        //System.out.println(count_prime(target));
        //int[] test = {0,0,1,1,1,1,2,3,3};
        //System.out.println(remove_repeate_2(test));
        //int[] test = {2,3,1,2,4,3};
        //System.out.println(min_subarray(test,7));
        test = test + 10;
        System.out.println(test);

    }

    public static int count_prime(int target){
        int count = 0;
        for(int i=0;i<target;i++){
            if(isprime_2(i)){count++;}
        }
        return count;
    }


    public static boolean isprime_2(int num){
        if(num == 0 || num == 1){return false;}
        if(num == 2 || num == 3){return true;}
        else{
            int sqrt =(int) Math.sqrt(num);
            for(int i=2;i<=sqrt;i++){
                if(num % i == 0){
                    return false;
                }
            }
            return true;
        }
    }


    public static int remove_repeate_2(int[] array){
        int i = 0;
        for(int n:array){
            if(i < 2 || n != array[i-2]){
                array[i] = n;
                i = i + 1;
            }
        }
        return i;
    }

    /**
    public static int min_subarray(int[] array, int target){
        int min = array.length;
        //int result_left = 0;
        //int result_right = 0;
        for(int left=0;left<array.length;left++){
            int sum = 0;
            int right = left;
            while(sum<target && right < array.length){
                sum = sum + array[right];
                right++;
            }
            if((right - left + 1) < min && sum >= target){
                min = right - left + 1;
                //result_left = left;
                //result_right = right;
            }
        }
        return min;
    }
     **/
    //双指针法，寻找符合条件的最小子串
    public static int min_subarray(int[] array, int target){
        int right = 0;
        int left = 0;
        int sum = 0;
        int result = array.length + 1;
        while(right < array.length){
            if(sum + array[right] < target){
                sum = sum + array[right];
                right++;
            }
            else{
                result = Math.min(result, right - left + 1);
                sum = sum - array[left];
                left++;
            }
        }
        if(result == array.length + 1){
            return 0;
        }
        else{
            return result;
        }
    }
}


