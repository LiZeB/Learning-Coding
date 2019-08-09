package java_study;

import javax.print.DocFlavor;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

//数组部分
public class leetcode_solution_1 {
    //两数相加，暴力解法
    public static int[] two_sum(int[] array, int target){
        int length = array.length;
        int[] result = new int[2];
        for(int i=0;i<length-1;i++){
            for (int j=i+1;j<length;j++){
                if(array[i] + array[j] == target){
                    result[0] = i;
                    result[1] = j;
                }
            }
        }    return result;
    }

    //两数相加，哈希表，一边添加一边查询，遍历一遍即可
    public static int[] two_sum_map(int[] array, int target) {
        Map<Integer, Integer> array2map = new HashMap<>();
        int[] result = new int[2];
        for (int i = 0; i < array.length; i++) {
            if (array2map.containsKey(target - array[i])) {
                //return new int[]{array2map.get(target - array[i]), i};
                result[0] = array2map.get(target - array[i]);
                result[1] = i;
                //return result;
            }
            array2map.put(array[i], i);
        }
        return result;
    }

    //两数相加，哈希表，遍历两遍
    public static int[] two_sum_map_2(int[] array, int target){
        Map<Integer, Integer> array2map = new HashMap<>();
        int[] result = new int[2];

        for(int i=0; i<array.length; i++){
            array2map.put(array[i], i);
        }

        for(int j=0; j<array.length;j++){
            if(array2map.containsKey(target - array[j]) && array2map.get(target - array[j]) != j){
                result[1] = j;
                result[0] = array2map.get(target - array[j]);
            }
        }
        return result;
    }

    //删除数组中的重复数，数组为有序数组，双指针法,若原数组共有i个不重复数字，那么这种方法就是把原数组的前i个元素改为了不重复数字，后len-i个数字没做改动。
    public static int removeDuplicates(int[] array){
        int i = 0;
        for(int j = 1; j < array.length; j++){
            if(array[i] != array[j]){
                i = i + 1;
                array[i] = array[j];
            }
        }
        return i+1;
    }

    //数组中有且只有一个重复数字，找出它，使用了哈希表，方法同两数相加的类似
    public static int repetive_num(int[] array) {
        Map<Integer, Integer> map = new HashMap<>();
        int result = 0;
        for(int i = 0; i < array.length; i++){
            if(map.containsKey(array[i])){
                result = array[i];
            }
            map.put(array[i], i);
        }
        return result;
    }

    //二分查找，mid即为所查找数字的下标
    public static boolean binary_sort(int[] array, int target){
        int right = 0;
        int left = array.length - 1;
        while(right <= left){
            int mid = (right + left) >> 1;
            if(target < array[mid]){
                left = mid - 1;
            }
            else if(target > array[mid]){
                right = mid + 1;
            }
            else if(target == array[mid]){
                return true;
            }
        }
        return false;
    }

    //找出数组中唯一一个不重复数字,利用哈希表
    public static int alone_num(int[] array){
        Map<Integer, Integer> map = new HashMap<>();
        int result = 0;
        for(int i = 0; i < array.length; i++){
            if(map.containsKey(array[i])) {
                map.put(array[i], 2);
            }
            else{
                map.put(array[i], 1);
            }
        }

        for(int key : map.keySet()){
            int value = map.get(key);
            if(value == 1){
                result = key;
            }
        }
        return result;
    }


    public static void main(String args[]){
        int[] array = {1,2,3,4};
        int target = 4;
        int[] result = new int[2];
        result = two_sum_map_2(array, target);
        System.out.println(Arrays.toString(result));

        int[] array2 = {4,3,1,2,5,3};
        int result_2 = repetive_num(array2);
        System.out.println(result_2);

        System.out.println(binary_sort(array, 5));

        int[] array3 = new int[] {1,1,2,3,3,4,4};
        System.out.println(alone_num(array3));
    }
}
