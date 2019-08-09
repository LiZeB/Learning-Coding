package java_study;

import java.util.Arrays;

public class leetcode_solution_7 {

    public static void main(String args[]){
        int[] nums = {0,1,2};
        int target = 3;
        System.out.println(three_sum_closest(nums, target));
    }

    public static int three_sum_closest(int[] nums, int target){
        Arrays.sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0;i<nums.length;i++){
            int right = nums.length - 1;
            int left = i + 1;
            while(left < right){
                int cur_sum = nums[i] + nums[left] + nums[right];
                if(Math.abs(target - cur_sum) < Math.abs(target - ans)){
                    ans = nums[i] + nums[left] + nums[right];
                }
                if(cur_sum > target) right--;
                if(cur_sum < target) left++;
                if(cur_sum == target) return 0;
            }
        }
        return ans;
    }
}
