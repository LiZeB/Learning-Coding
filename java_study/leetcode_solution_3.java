package java_study;

import java.util.Arrays;
import java.util.Map;

public class leetcode_solution_3 {
    public static void main(String args[]){
        //int[][] grid = {{1,3,1},{1,5,1},{4,2,1}};
        //System.out.println(min_path(grid));
        int[] array = {2,1,1,2};
        //System.out.println(rob(array));
        int[] list = {1,2,3,4};
        int[][] grid = {{1,2,3,4},{5,6,7,8}};
        int[][] test = {{1},{2},{3}};
        int target = 2;
        //System.out.println(grid_sort(test, target));
        System.out.println(binary_sort(test[0], 0));

        //System.out.println(Arrays.deepToString(test));
    }
    //寻找二维数组中，从左上到右下的最短路径
    public static int min_path(int[][] grid){
        int[][] result = new int[grid.length][grid[0].length];
        for(int i=grid.length-1;i>=0;i--){
            for(int j=grid[0].length-1;j>=0;j--){
                if(i == grid.length-1 && j == grid[0].length-1){
                    result[i][j] = grid[i][j];
                }
                else if(i == grid.length-1 && j != grid[0].length-1){
                    result[i][j] = grid[i][j] + result[i][j+1];
                }
                else if(i != grid.length-1 && j == grid[0].length-1){
                    result[i][j] = grid[i][j] + result[i+1][j];
                }
                else if(i != grid.length-1 && j != grid[0].length-1){
                    result[i][j] = grid[i][j] + Math.min(result[i+1][j], result[i][j+1]);
                }
            }
        }
        return result[0][0];
    }
    //打家劫舍，动态规划
    public static int rob(int[] nums){
        int len = nums.length;
        int[] result = new int[len];
        int final_ans = 0;
        if(len == 0){
            final_ans = 0;
        }
        else if(len == 1){
            //return nums[0];
            final_ans = nums[0];
        }
        else if(len == 2){
            //return Math.max(nums[0], nums[1]);
            final_ans = Math.max(nums[0], nums[1]);
        }
        else{
            result[0] = nums[0];
            result[1] = Math.max(nums[0], nums[1]);
            for(int i = 2; i<len; i++){
                result[i] = Math.max(result[i-1], result[i-2] + nums[i]);
            }
            final_ans = result[len-1];
        }
        return  final_ans;
    }

    //二维数组查找。
    public static boolean grid_sort(int[][] grid, int target){
        int chang = grid.length;
        int kuan = grid[0].length;
        int[] array = new int[chang * kuan];
        for(int i=0;i<chang;i++){
            for(int j=0;j<kuan;j++){
                array[(kuan * i) + j] = grid[i][j];
            }
        }
        int result = binary_sort(array, target);
        boolean ans = false;
        if(result == -1){ans = false;}
        if(result != -1){ans = true;}
        return ans;
    }

    //二分查找
    public static int binary_sort(int[] array, int target){
        int right = 0;
        int left = array.length - 1;
        int result = -1;
        while(right <= left){
            int mid = (right + left) >> 1;
            if(target > array[mid]){
                right = mid + 1;
            }
            else if(target < array[mid]){
                left = mid - 1;
            }
            else if(target == array[mid]){
                result = mid;
                break;//这里必须加个break，否则无法退出循环。
                      //在day1中写的那个只是判断是否存在的二分查找中，由于直接在这里return了，所以，一旦找到不仅仅结束了while循环，连整个方法都结束了，因为return了嘛
                      //而这个函数中，我把return放到了while循环外面，不加break的话，由于找到target之后并没有对right和left做改变，因此永远无法退出循环
                      //注意：return后面千万千万不要加break
            }
        }
        return result;
    }
}
