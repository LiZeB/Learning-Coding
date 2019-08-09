package java_study;

import java.util.Map;

public class leetcode_solution_4 {
    public static void main(String args[]) {
        String test = "abccba";
        //System.out.println(longest_substring(test));
        System.out.println(test.substring(0, 2));
        int[] array = {2, 3, -2, 4, -2};
        System.out.println(biggest_sum_sub(array));
    }

    //寻找最长回文子串
    public static String longest_substring(String s) {
        if (s.length() == 1) {
            return s;
        }
        String result = s.substring(0, 1);
        boolean[][] dp = new boolean[s.length()][s.length()];
        for (int right = 1; right < s.length(); right++) {
            for (int left = 0; left < right; left++) {
                if (s.charAt(right) == s.charAt(left) && (right - left <= 2 || dp[left + 1][right - 1] == true)) {
                    dp[left][right] = true;
                    if (right - left + 1 > result.length()) {
                        result = s.substring(left, right + 1);//左闭右开的关系，right + 1才是真正取到了要取的字符。
                    }
                }
            }
        }
        return result;
    }

    //寻找子串最大乘积
    public static int biggest_sub(int[] array) {
        int result = Integer.MIN_VALUE;
        //int result = array[0];
        int imax = 1;
        int imin = 1;
        for (int i = 0; i < array.length; i++) {
            if (array[i] < 0) {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = Math.max(imax * array[i], array[i]);
            imin = Math.min(imin * array[i], array[i]);
            result = Math.max(result, imax);
        }
        return result;
    }

    //寻找子串最大和
    public static int biggest_sum_sub(int[] array) {
        int result = array[0];
        int cur = 0;
        for(int i=0;i<array.length;i++){
            if(cur > 0){
                cur = cur + array[i];
            }
            else{
                cur = array[i];
            }
            result = Math.max(result, cur);
        }
        return result;
    }
}