import java.util.Scanner;

/**
 //字符进行算术运算时，会转换成ASCII值在进行运算。
 char num1 = '2';
 char num2 = '3';
 int ans = num1 + num2 - 2 * '0';
 System.out.println(ans);
 //数字和其ASCII值之间相差48，'0'的ASC码为48，就是：ASC(num) = int 'num' - 48(int '0')这种关系，所以两个数相加就减去2个'0'
 */

public class big_num_plus {
    public static void main(String args[]){

        Scanner reader = new Scanner(System.in);
        String num1 = reader.nextLine();
        String num2 = reader.nextLine();

        String num1_left = num1.split("\\.")[0];
        String num1_right = num1.split("\\.")[1];
        String num2_left = num2.split("\\.")[0];
        String num2_right = num2.split("\\.")[1];

        //首先计算小数点右边部分
        int right_length_minus = Math.max(num1_right.length(), num2_right.length()) - Math.min(num1_right.length(), num2_right.length());
        //小数点右边部分不需要反转补0
        for(int i=0;i<right_length_minus;i++){
            if(num1_right.length() < num2_right.length()){
                num1_right = num1_right + '0';
            }
            else{
                num2_left += '0';
            }
        }

        int jinwei_right = 0;
        int[] ans_right = new int[num1_right.length() + 1];
        int cur = 0;
        for(int i=num1_right.length() - 1;i>=0;i--){
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

        int len_min = Math.max(num1_left.length(), num2_left.length()) - Math.min(num1_left.length(), num2_left.length());
        //反转补0
        for(int i=0;i<len_min;i++){
            if(num1_left.length() < num2_left.length()){
                num1_left = num1_left + '0';
            }
            else{
                num2_left = num2_left + '0';
            }
        }

        int[] ans = new int[num1_left.length() + 1];
        int jinwei_left = ans_right[0];//小数点左边第一位的进位是小数点右边结果的第一位
        int cur_left = 0;
        for(int i=0;i<num1_left.length();i++){
            int sum = num1_left.charAt(i) + num2_left.charAt(i) - 2 * '0' + jinwei_left;
            cur_left = sum % 10;//取余数
            ans[i] = cur_left;
            jinwei_left = sum / 10;//取商
        }
        if(jinwei_left  == 1){
            ans[num1_left.length()] = 1;
        }

        StringBuffer result_left = new StringBuffer();
        if(jinwei_left == 1){
            result_left.append(1);
            for(int i=ans.length - 2;i>=0;i--){
                result_left.append(ans[i]);
            }
        }
        else {
            for (int i = ans.length - 1; i >= 0; i--) {
                result_left.append(ans[i]);
            }
        }
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
