package java_study;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class leetcode_solution_6 {
    public static void main(String args[]){
        //String[] test = {"c","c", "b"};
        //System.out.println(test[0].substring(0,0));
        //System.out.println(Longest_common_prefix(test));
        //for(int i=0;i<1;i++){
        //    System.out.println(i);
        //}
        //ArrayList test_2 = new ArrayList();
        //System.out.println(test_2);
        int[] test_3 = {-1, 0, 1, 2, -1, -4};
        System.out.println(three_num_plus(test_3));

    }

    //寻找最长公共子串
    public static String Longest_common_prefix(String[] strs){
        if(strs.length == 0){
            return "";
        }
        else{
            String ans = strs[0];
            for(int i=1;i<strs.length;i++){
                int j = 0;
                for(;j<Math.min(ans.length(), strs[i].length());j++){
                    if(ans.charAt(j) != strs[i].charAt(j)){
                        System.out.println(j);
                        break;
                    }
                }
                ans = ans.substring(0,j);
                if(ans == ""){return "";}
            }
            return ans;
        }
    }

    //三数之和，寻找数组中三个元素相加为0的子数组，子数组不能重复
    public static List<List<Integer>> three_num_plus(int[] array){
        List<List<Integer>> ans = new ArrayList();
        Arrays.sort(array);
        //int[][] ans = new int[][]
        if(array == null || array.length < 3){return ans;}
        for(int i=0;i<array.length;i++){
            if(array[i] > 0) break;
            if(i>0 && array[i] == array[i-1]) continue;
            int right = array.length - 1;
            int left = i + 1;
            while(left < right) {
                int sum = array[i] + array[right] + array[left];
                if (sum > 0) right--;
                if (sum < 0) left++;
                if (sum == 0){
                    ans.add(Arrays.asList(array[i], array[left], array[right]));
                    while(left < right && array[right] == array[right - 1]) right--;
                    while(left < right && array[left] == array[left + 1]) left++;
                    right--;
                    left++;
                }
            }
        }
        return ans;
    }

}
