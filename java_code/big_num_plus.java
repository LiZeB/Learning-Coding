import java.util.Scanner;

/**
 //字符进行算术运算时，会转换成ASCII值再进行运算。
 char num1 = '2';
 char num2 = '3';
 int ans = num1 + num2 - 2 * '0';
 System.out.println(ans);
 数字和其ASCII值之间相差48，'0'的ASC码为48，就是：ASC(num) = int 'num' + 48(int '0')这种关系，所以两个数相加就减去2个'0'
 
 使用条件：不能针对负数进行加减
 **/

public class big_num_plus {
    public static void main(String args[]){

        Scanner reader = new Scanner(System.in);
        String num1 = reader.nextLine();
        String num2 = reader.nextLine();

        String num1_left = num1.split("\\.")[0];
        String num1_right = num1.split("\\.")[1];
        String num2_left = num2.split("\\.")[0];
        String num2_right = num2.split("\\.")[1];

        //首先计算小数点右边需要补0的个数
        int right_length_minus = Math.abs(num1_right.length() - num2_right.length()); 
        
        //将两个数小数点右边部分进行补0
        for(int i=0;i<right_length_minus;i++){
            if(num1_right.length() < num2_right.length()){
                num1_right += '0';
            }
            else{
                num2_right += '0';
            }
        }

        int jinwei_right = 0;
        int[] ans_right = new int[num1_right.length() + 1];   //保存右边的计算结果，多一位保存最高位进位
        int cur = 0;
        for(int i= num1_right.length() - 1;i>=0;i--){
            int sum = num1_right.charAt(i) + num2_right.charAt(i) - 2 * '0' + jinwei_right;
            cur = sum % 10;
            jinwei_right = sum / 10;
            ans_right[i + 1] = cur;
        }
        if(jinwei_right == 1){
            ans_right[0] = 1;
        }

        //接下来计算小数点左边部分
        num1_left = new StringBuffer(num1_left).reverse().toString();
        num2_left = new StringBuffer(num2_left).reverse().toString();

        int len_min = Math.abs(num1_left.length() - num2_left.length());
        //反转补0
        for(int i=0;i<len_min;i++){
            if(num1_left.length() < num2_left.length()){
                num1_left = num1_left + '0';
            }
            else{
                num2_left = num2_left + '0';
            }
        }

        int nums = Math.max(num1_left.length(),num2_left.length());
        int[] ans_left = new int[nums + 1];  //保存左边的计算结果，多一位保存最高位进位
        int jinwei_left = ans_right[0];   //小数点左边第一位的进位是小数点右边结果的第一位
        int cur_left = 0;
        for(int i=0;i<num1_left.length();i++){
            int sum = num1_left.charAt(i) + num2_left.charAt(i) - 2 * '0' + jinwei_left;
            cur_left = sum % 10;//取余数
            ans_left[i] = cur_left;
            jinwei_left = sum / 10;//取商
        }
        
        // 将左边的计算结果拼接在一起
        StringBuffer result_left = new StringBuffer();
        if(jinwei_left  == 1){
            ans_left[nums] = 1;
            for(int i=ans_left.length -1;i>=0;i--){    
                result_left.append(ans_left[i]);
            }
        }
        else {
            for(int i=ans_left.length -2;i>=0;i--){    //这个-2害我还想了一下为啥减2，为啥不写注释
                result_left.append(ans_left[i]);
            }
        }

        // 将右边的计算结果拼接在一起
        StringBuffer result_right = new StringBuffer();
        for(int j=1;j<ans_right.length;j++){
            result_right.append(ans_right[j]);
        }
        
        StringBuffer final_ans = new StringBuffer();
        final_ans.append(result_left);
        final_ans.append(".");
        final_ans.append(result_right);
        System.out.println(final_ans);
    }
}
