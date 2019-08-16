import java.util.Arrays;

public class sort {
    //冒泡排序
    public static int[] Bomb_sort(int[] list){
        for (int i=0;i<list.length-1;i++){
            for (int j=0;j<list.length-1-i;j++){
                if (list[j]>list[j+1]){
                    int mid = list[j];
                    list[j] = list[j+1];
                    list[j+1] = mid;
                }
            }
        }
        return list;
    }

    //使用冒泡降序排序
    public static int[] Bomb_sort_2(int[] list){
        for (int i=0;i<list.length-1;i++){
            for (int j=0;j<list.length-1-i;j++){
                if (list[j]<list[j+1]){
                    int mid =list[j];
                    list[j] = list[j+1];
                    list[j+1] = mid;
                }
            }
        }
        return list;
    }

    //选择排序
    public static int[] change_sort(int[] list){
        for (int i=0;i<list.length;i++){
            int min = list[i];
            int min_num = i;
            for (int j=i;j<list.length;j++){
                if(list[j]<min){
                    min = list[j];
                    min_num = j;
                }
            }
            int mid = list[i];
            list[i] = min;
            list[min_num] = mid;
        }
        return list;
    }

    //插入排序
    public static int[] insert_sort(int[] list){
        for (int i=1;i<list.length;i++){
            for (int j=0;j<i;j++){
                if(list[i]<list[j]){
                    int mid = list[i];
                    list[i] = list[j];
                    list[j] = mid;
                }

            }
        }
        return list;
    }

    //快速排序
    public static void quick_sort(int[] a, int low, int high){
        if(low>=high)
            return;
        int i = low;
        int j = high;
        int key = a[i];
        while(i<j){
            while(i<j && a[j]>=key){
                j--;
            }
            if(i<j){
                a[i++]=a[j];
            }
            while(i<j && a[i]<=key){
                i++;
            }
            if(i<j){
                a[j--] = a[i];
            }
        }
        a[i] = key;
        quick_sort(a,low,i-1);
        quick_sort(a,i+1,high);
    }

    //二分查找--递归
    public static int mid_sort(int[] array, int start, int end, int value){
        if(start <= end){
            int middle = (start + end) / 2;
            if(array[middle] == value){
                return middle;
            }
            else if(array[middle] < value){
                return mid_sort(array, middle + 1, end, value);
            }
            else{
                return mid_sort(array, start, middle - 1, value);
            }
        }
        else{
            return -1;
        }
    }

    //二分查找--通常
    public static int mid_sort_2(int[] array, int value){
        int start = 0;
        int end = array.length - 1;
        while(start <= end){
            int middle = (start + end) / 2;
            if(array[middle] == value){
                return middle;
            }
            else if(array[middle] < value){
                start = middle + 1;
                //end = end;
            }
            else{
                //start = start;
                end = middle - 1;
            }
        }
        return -1;
    }

    public static void main(String args[]){
        int[] array = {11};
        //array = Bomb_sort(array);
        //System.out.println(mid_sort(array,0, array.length - 1, 10));
        System.out.println(mid_sort(array, 0, array.length - 1, 11));
    }
}

