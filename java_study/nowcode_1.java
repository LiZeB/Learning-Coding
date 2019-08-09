package java_study;

import javax.print.DocFlavor;
import javax.security.sasl.SaslClient;
import java.util.*;

public class nowcode_1 {
    //输入输出练习1
    public static void main(String args[]){
        /**
        Scanner reader = new Scanner(System.in);
        System.out.println("请输入数组的数量");
        int num = reader.nextInt();
        for(int i=0;i<num;i++){
            System.out.printf("请输入第%d组数\n",i+1);
            long a = reader.nextLong();
            long b = reader.nextLong();
            long c = reader.nextLong();
            if(a+b>c){
                System.out.printf("Case #%d: %s\n",i+1,"true");
            }
            else{
                System.out.printf("Case #%d: %s\n",i+1,"false");
            }
        }
         **/
        //System.out.println(isprime(1));
        //sushu();
        //recode();
        /**
        Map<Character,String>day = new HashMap<>();
        day.put('A',"MON");
        day.put('B',"TUE");
        day.put('C',"WED");
        day.put('D',"THU");
        day.put('E',"FRI");
        day.put('F',"SAT");
        day.put('G',"SUN");
        Map<Character,Integer>time_1 = new HashMap<>();
        time_1.put('0',0);
        time_1.put('1',1);
        time_1.put('2',2);
        time_1.put('3',3);
        time_1.put('4',4);
        time_1.put('5',5);
        time_1.put('6',6);
        time_1.put('7',7);
        time_1.put('8',8);
        time_1.put('9',9);
        time_1.put('A',10);
        time_1.put('B',11);
        time_1.put('C',12);
        time_1.put('D',13);
        time_1.put('E',14);
        time_1.put('F',15);
        time_1.put('G',16);
        time_1.put('H',17);
        time_1.put('I',18);
        time_1.put('J',19);
        time_1.put('K',20);
        time_1.put('L',21);
        time_1.put('M',22);
        time_1.put('N',23);
        //char[] test = new char[3];
        ArrayList test = new ArrayList();
        test.add('D');
        test.add('E');
        test.add(4);
        System.out.println(test);
        System.out.print(day.get(test.get(0)) + ' ');
        //char time_2 = test.get(1);
        System.out.printf("%02d:",time_1.get(test.get(1)));
        System.out.printf("%02d",test.get(2));
         **/
        recode();



    }

    /**
     练习2
    A1 = 能被5整除的数字中所有偶数的和；
    A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
    A3 = 被5除后余2的数字的个数；
    A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
    A5 = 被5除后余4的数字中最大数字。
    **/
    public static void question_2(){
        Scanner reader = new Scanner(System.in);
        System.out.println("请输入测试用例的个数");
        int num = reader.nextInt();
        //System.out.printf("需要输入%d个数\n",num);
        int[] array = new int[num];
        System.out.println("请输入测试用例");
        for(int i=0;i<num;i++){
            array[i] = reader.nextInt();
        }
        //System.out.println(Arrays.toString(array));
        int A1 = 0;
        int A2 = 0;
        double A2_1 = 0;
        int A2_count = 0;
        int A3 = 0;
        double A4 = 0;
        int A4_count = 0;
        int A5 = 0;
        for(int j=0;j<array.length;j++){
            if(array[j]%5 == 0 & array[j]%2 == 0){
                A1 = A1 + array[j];
                System.out.println(array[j]);
            }
            if(array[j]%5 == 1){
                A2_1 = A2_1 + array[j]*Math.pow(-1,A2_count);
                A2_count = A2_count + 1;
            }
            if(array[j]%5 == 2){
                A3 = A3 + 1;
            }
            if(array[j]%5 == 3){
                A4 = A4 + array[j];
                A4_count++;
            }
            if(array[j]%5 == 4){
                A5 = Math.max(A5,array[j]);
            }

        }
        A2 = (int)A2_1;
        A4 = A4/A4_count;
        if(A1 == 0){
            System.out.printf("N ");
        }
        else{
            System.out.printf("%d ",A1);
        }
        if(A2 == 0){
            System.out.printf("N ");
        }
        else{
            System.out.printf("%d ",A2);
        }
        if(A3 == 0){
            System.out.printf("N ");
        }
        else{
            System.out.printf("%d ",A3);
        }
        if(A4_count == 0){
            System.out.printf("N ");
        }
        else{
            System.out.printf("%.1f ",A4);
        }
        if(A5 == 0){
            System.out.printf("N ");
        }
        else{
            System.out.printf("%d ",A5);
        }
    }

    public static void sushu(){
        Scanner reader = new Scanner(System.in);
        System.out.println("请输入区间");
        int right = reader.nextInt();
        int left = reader.nextInt();
        //System.out.printf("right:%d\n",right);
        //System.out.printf("left: %d\n",left);
        int count = 0;
        int i = 0;
        //int[] array = new int[left];
        ArrayList array = new ArrayList();
        while(count < left){
            if(isprime(i)){
                //array[count] = i;
                array.add(i);
                count = count + 1;
            }
            i++;
        }
        System.out.println(array);
        for(int j=0;j<=right-2;j++){
            array.remove(0);
        }
        System.out.println(array);
        for(int j=0;j<array.size();j++){
            if((j+1) % 10 == 0){
                System.out.println(array.get(j));
            }
            else if(j+1 == array.size()){
                System.out.print(array.get(j));
            }
            else{
                System.out.printf("%d ",array.get(j));
            }
        }
    }

    public static boolean isprime(int num){
        if(num == 1 || num == 0){
            return false;
        }
        else if(num == 2 || num == 3){
            return true;
        }
        else{
            int sqrt = (int) Math.sqrt(num);
            for(int i=2;i<=sqrt;i++){
                if(num % i == 0){
                    return false;
                }
            }
            return true;
        }
    }

    public static void recode(){
        Scanner reader = new Scanner(System.in);
        System.out.println("请输入暗号");
        String s1 = reader.next();
        String s2 = reader.next();
        String s3 = reader.next();
        String s4 = reader.next();
        //System.out.println(s1);
        ArrayList time_array = new ArrayList();
        //char[] time_array = new char[3];
        int s1_start = 0;
        int s2_start = 0;
        /**
        Map<Character,String>day = new HashMap<>();
        day.put('A',"MON");
        day.put('B',"TUE");
        day.put('C',"WED");
        day.put('D',"THU");
        day.put('E',"FRI");
        day.put('F',"SAT");
        day.put('G',"SUN");
         **/
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                if(s1.charAt(i) == s2.charAt(j) && Character.isUpperCase(s1.charAt(i)) && Character.isUpperCase(s2.charAt(j))){
                    time_array.add(s1.charAt(i));
                    //time_array[0] = s1.charAt(i);
                    s1_start = i;
                    s2_start = j;
                }
            }
        }
        for(int i=s1_start+1;i<s1.length();i++){
            for(int j=s2_start+1;j<s2.length();j++){
                if(Character.isLetterOrDigit(s1.charAt(i)) && Character.isLetterOrDigit(s2.charAt(j)) && s1.charAt(i) == s2.charAt(j)){
                    time_array.add(s1.charAt(i));
                    //time_array[1] = s1.charAt(i);
                }
            }
        }

        for(int i=0;i<s3.length();i++){
            if(s3.charAt(i) == s4.charAt(i) && Character.isLetter(s3.charAt(i)) && Character.isLetter(s4.charAt(i))){
                time_array.add(i);
                //time_array[2] = (char) i;
            }
        }
        //System.out.println(Arrays.toString(time_array));
        Map<Character,String>day = new HashMap<>();
        day.put('A',"MON");
        day.put('B',"TUE");
        day.put('C',"WED");
        day.put('D',"THU");
        day.put('E',"FRI");
        day.put('F',"SAT");
        day.put('G',"SUN");
        Map<Character,Integer>time_1 = new HashMap<>();
        time_1.put('0',0);
        time_1.put('1',1);
        time_1.put('2',2);
        time_1.put('3',3);
        time_1.put('4',4);
        time_1.put('5',5);
        time_1.put('6',6);
        time_1.put('7',7);
        time_1.put('8',8);
        time_1.put('9',9);
        time_1.put('A',10);
        time_1.put('B',11);
        time_1.put('C',12);
        time_1.put('D',13);
        time_1.put('E',14);
        time_1.put('F',15);
        time_1.put('G',16);
        time_1.put('H',17);
        time_1.put('I',18);
        time_1.put('J',19);
        time_1.put('K',20);
        time_1.put('L',21);
        time_1.put('M',22);
        time_1.put('N',23);
        System.out.print(day.get(time_array.get(0)) + ' ');
        //char time_2 = test.get(1);
        System.out.printf("%02d:",time_1.get(time_array.get(1)));
        System.out.printf("%02d",time_array.get(2));

    }

}
