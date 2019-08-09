package java_study;

import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class nowcode_3 {
    /**
     //方向，输入1为转动的次数，输入2为具体转动方向，输出最后的朝向
    public static void main(String args[]){
        Scanner reader = new Scanner(System.in);
        int len = reader.nextInt();
        //String[] dir = new String[len];
         String dir = reader.next();
         //System.out.println(dir.charAt(0));
        int x = 0;
        for(int i=0;i<len;i++){
            if(dir.charAt(i) == 'L') x = x - 1;
            if(dir.charAt(i) == 'R') x = x + 1;
        }
        while(x < 0){x = x + 4;}
        int ans = x % 4;
        System.out.println(ans);
        char result = 'N';
        switch(ans){
            case 0 :
                result = 'N';
                break;
            case 1 :
                result = 'E';
                break;
            case 2 :
                result = 'S';
                break;
            case 3 :
                result = 'W';
                break;
        }
        System.out.println(result);
    }
     */
    public static void main(String args[]){
        Scanner reader = new Scanner(System.in);
        System.out.println("请输入工作的数量");
        int works_num = reader.nextInt();
        System.out.println("请输入人数");
        int people_num = reader.nextInt();
        int[][] work = new int[works_num][2];
        for(int i=0;i<works_num;i++){
            System.out.printf("请输入第%d份工作的难度和报酬，用空格分开\n",i);
            work[i][0] = reader.nextInt();//难度
            work[i][1] = reader.nextInt();//报酬
        }
        //System.out.println(Arrays.deepToString(work));
        Arrays.sort(work,(e1,e2)->(int)(e1[0]-e2[0]));
        for(int i=1;i<people_num;i++){
            work[i][1] = Math.max(work[i][1], work[i-1][1]);
        }
        //System.out.println(Arrays.deepToString(work));
        //Map<Integer,Integer> work_map = new TreeMap<>();
        TreeMap work_map = new TreeMap();
        for(int i=0;i<works_num;i++){
            work_map.put(work[i][0], work[i][1]);
        }
        //System.out.println(work_map);
        int[] ability = new int[people_num];
        int[] result = new int[people_num];
        for(int i=0;i<people_num;i++){
            System.out.printf("请输入第%d个人的能力\n",i);
            ability[i] = reader.nextInt();
        }
        //System.out.println(Arrays.toString(ability));
        for(int i=0;i<people_num;i++){
            Integer max_ability = (Integer) work_map.floorKey(ability[i]);
            if(max_ability != null){
                result[i] = (int) work_map.get(max_ability);
            }
            else{
                result[i] = 0;
            }
        }
        System.out.println(Arrays.toString(result));
    }

}
