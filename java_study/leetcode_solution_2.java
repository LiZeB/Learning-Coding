package java_study;

import java.util.HashMap;
import java.util.Map;


//字符串部分
public class leetcode_solution_2 {
    //罗马数字转整型，左边大于右边则+，小于则-
    public static int roman2num(String roman){
        Map<Character, Integer>num_map = new HashMap<>();
        num_map.put('I', 1);
        num_map.put('V', 5);
        num_map.put('X', 10);
        num_map.put('L', 50);
        num_map.put('C', 100);
        num_map.put('D', 500);
        num_map.put('M', 1000);
        int sum = 0;
        for(int i = 0; i < roman.length() - 1; i++){
            if(num_map.get(roman.charAt(i)) >= num_map.get(roman.charAt(i + 1))){
                sum = sum + num_map.get(roman.charAt(i));
            }
            else{
                sum = sum - num_map.get(roman.charAt(i));
            }
        }
        sum = sum + num_map.get(roman.charAt(roman.length() - 1));
        return sum;
    }

    //字符串中最长不重复子串的长度,这种方法是错误的，
    public static int LengthofLongestSubstring(String s){
        int count = 0;
        int max_count = 0;
        int s_length = s.length();
        Map<Character, Integer>map = new HashMap<>();
        for(int i = 0; i < s.length(); i++){
            //这个if中，例如dvdf这个例子，在发现map中有重复的字符后，在map.clear()后应该put v和d，而这里只put了d。
            if(map.containsKey(s.charAt(i)) && i < s.length()-1){
                map.clear();
                map.put(s.charAt(i), i);
                if(count > max_count){
                    max_count = count;
                }
                count = 1;
            }
            else if(i == s.length()-1 && map.containsKey(s.charAt(i))){
                if(count > max_count){
                    max_count = count;
                }
            }
            else if(i == s.length()-1 && !map.containsKey(s.charAt(i))){
                count = count + 1;
                if(count > max_count){
                    max_count = count;
                }
            }
            else if(!map.containsKey(s.charAt(i)) && i < s.length()-1){
                count = count + 1;
                map.put(s.charAt(i), i);
            }
        }
        return max_count;
    }

    //字符串中最长不重复子串的长度，滑动窗口解法，使用了动态规划的思想
    public static int LongestSubstring(String s){
        int right = 0;
        int left = 0;
        int count = 0;
        Map<Character,Integer>map = new HashMap<>();
        while(right < s.length() && left < s.length()){
            if(!map.containsKey(s.charAt(left))){
                map.put(s.charAt(left), left);
                left = left + 1;
            }
            else{
                map.remove(s.charAt(right));
                right = right + 1;
            }
            count = Math.max(count, left - right);
        }
        return count;
    }

    public static void main(String args[]){
        String roman = "VI";
        int num = roman2num(roman);
        System.out.println(num);

        String s = "pwwkew";
        int longest = LongestSubstring(s);
        System.out.println("最长不重复子串长度为:" + longest);
  }
}
