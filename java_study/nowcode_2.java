package java_study;

public class nowcode_2 {
    public static void main(String args[]){
        int[][] grid = {{1,2,3,4},{5,6,7,8}};
        int target = 6;
        System.out.println(grid_sort(target, grid));
    }
    //查找二维数组
    public static boolean grid_sort(int target, int [][] array) {
        int chang = array.length;
        if(chang == 0){return false;}
        else{
            int kuan = array[0].length;
            for(int i=0;i<chang;i++){
                if(binary_sort(array[i], target)){return true;}
            }
            return false;
        }
    }
    public static boolean binary_sort(int[] array, int target){
        int right = 0;
        int left = array.length-1;
        while(right <= left){
            int mid = (right + left) >> 1;
            if(target > array[mid]){right = mid + 1;}
            else if(target < array[mid]){left = mid - 1;}
            else if(target == array[mid]){return true;}
        }
        return false;
    }
}
