package java_study;

import java.util.Arrays;
import java.util.Scanner;

public class test333 {
    public static void main(String args[]){
        Scanner reader = new Scanner(System.in);
        String num1 = reader.nextLine();
        //String num2 = reader.nextLine();

        String[] num11 = num1.split("\\.");
        StringBuffer num1_left = new StringBuffer(num11[0]);
        System.out.println(num1_left);
    }


}
