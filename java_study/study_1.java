package java_study;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class study_1 {
    public static void main(String[] args){
        /**int x = 1;
        System.out.println("x_1: "+ x);
        x = 10;
        System.out.println("x_2: "+ x);
        int n = x;
        System.out.println("n_1: "+n);
        x = 20;
        System.out.println("n_2: "+n);
        System.out.println("x_3: "+x);
        */

        /**
        Scanner scanner = new Scanner(System.in);
        //var input = new Scanner(System.in);
        System.out.print("please input your name:");
        String name = scanner.nextLine();
        System.out.print("please input your age:\n");
        int age = scanner.nextInt();
        System.out.printf("your name is %s, and you age is %d",name,age);
        */

        /**
        int[] my_list = new int[10];

        System.out.printf("The length of the list is %d\n",my_list.length);
        for (int i=0;i<=8;i++){
            my_list[i] = i;
            System.out.printf("当前为数组第 %d 个元素赋值\n",i);
        }
        String list_2 = Arrays.toString(my_list);
        System.out.printf("The list is %s\n",list_2);
        my_list[9] = 100;
        System.out.printf("更改后的数组为%s\n",Arrays.toString(my_list));
        */

        /**
        System.out.print("请输入数组长度：");
        Scanner reader = new Scanner(System.in);
        int list_length = reader.nextInt();
        int[] my_list = new int[list_length];
        System.out.printf("创建的数组长度为：%d\n",my_list.length);
        System.out.printf("创建的数组为：%s\n",Arrays.toString(my_list));
         */

        /**
        int[] my_list = {7,4,717,9,1,2,5,4};
        int num = 1;
        for(int n:my_list){
            System.out.printf("数组的第 %d 个元素为: %d \n", num, n);
            num ++;
        }
        System.out.println("以上是方法1遍历数组");
        System.out.println("");
        int num_2 = 1;
        for(int i = 0; i<my_list.length; i++){
            System.out.printf("数组的第 %d 个元素为：%d \n", num_2, my_list[i]);
            num_2++;
        }
        System.out.println("以上是方法2遍历数组");
        System.out.println("");


        int num_3 = my_list.length;
        for (int j = my_list.length - 1; j>=0; j--){
            System.out.printf("数组的第 %d 个元素为：%d\n",num_3, my_list[j]);
            num_3--;
        }
        System.out.println("以上是倒序遍历数组");
        */

        /**
        System.out.println("请输入一个数组，数字之间用空格分开，回车结束");
        Scanner reader =new Scanner(System.in);
        String input = reader.nextLine();
        String[] input_2 = input.split(" ");

        //将输入从字符串类型转换成整型
        int[] list = new int[input_2.length];
        for (int j=0; j<list.length; j++){
            list[j] = Integer.parseInt(input_2[j]);
        }

        //int[] ans = study_1.Bomb_sort_2(list);
        quick_sort(list,0,list.length-1);
        //int[] pre_list = {1,2,3,4,5,6};
        //int[] ans = remove_list(pre_list,3);
        System.out.println(Arrays.toString(list));

        ArrayList my_list = new ArrayList();
        my_list.add("a");
        my_list.add(1);
        my_list.add("b");
        my_list.add(2);
        System.out.println(my_list);
        my_list.remove("a");
        System.out.println(my_list);
        System.out.println(my_list.size());
        my_list.add(1,"c");
        System.out.println(my_list);
         */

        int[][] arr = {{1,2,3,4}, {5,6,7,8}};
        System.out.println(Arrays.deepToString(arr));
        System.out.println(Arrays.toString(arr[1]));
        System.out.println(arr[1][1]);

        Student dongzan = new Student("dongzan",18);



        }



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

        //向数组插入1个元素
        public static int[] insert_list(int[] list, int insert_location, int insert_num){
            if(insert_location>list.length){
                insert_location = list.length;
            }
            int[] new_list = new int[list.length+1];
            for(int i=0;i<insert_location;i++){
                new_list[i] = list[i];
            }
            new_list[insert_location] = insert_num;
            for(int j=insert_location+1;j<new_list.length;j++){
                new_list[j] = list[j-1];
            }
            return new_list;
        }

        //删除数组指定位置的元素
        public static int[] remove_list(int[] list,int remove_location){
            if (remove_location>=list.length){
                remove_location = list.length-1;
            }
            int[] new_list = new int[list.length-1];
            for(int i=0;i<remove_location;i++){
                new_list[i] = list[i];
            }

            for(int j=remove_location;j<new_list.length;j++){
                new_list[j]= list[j+1];
            }
            return new_list;
        }

    }


