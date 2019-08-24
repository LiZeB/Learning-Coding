public class data_convert {

    //获取变量的类型
    public static String getType(Object o){
        return o.getClass().toString();
    }

    public static void main(String args[]){

        //低级向高级的自动转换
        int a = 1;
        long b = 2;
        System.out.println("a + b 的结果的类型为：" + getType(a + b));//被自动转换成long了

        //高级向低级的强制转换
        System.out.println("b的初始类型为：" + getType(b));
        int c = (int) b;
        System.out.println("c的类型为：" + getType(c));

        double cc = 1.1;
        float dd = (float) cc;
        System.out.println("dd的类型为：" + getType(dd));

        //char向高级转换比较特殊，放在最后的字符和数字的相互转换

        //高级向低级转换会丢失精度
        int d = (int) 12.3 + (int) 45.6;
        System.out.println(d);//d的运算结果为57，丢失了精度
        System.out.println("d的类型为：" + getType(d));

        //装包和拆包
        //从输出结果中可以看到，所有的类型都变成了包装类，这是因为发生了装包和拆包

        Integer aa = 3;//这就是一个装包的过程
        int bb = aa;//拆包了

        //字符串类型转换，这是重点

        //数字转换成字符串
        //1、通过String.valueOf()转换
        float num = (float) 1.111;
        String num_str = String.valueOf(num);
        System.out.println("num_str：" + num_str);
        System.out.println("num_str的类型为：" + getType(num_str));

        //2、通过.toString()转换
        String num_str_2 = Float.toString(num);
        System.out.println("num_str_2：" + num_str_2);
        System.out.println("num_str_2的类型为：" + getType(num_str_2));

        //3、加上一个""，字符串和
        String num_str_3 = num + "";
        System.out.println("num_str_3：" + num_str_3);
        System.out.println("num_str_3的类型为：" + getType(num_str_3));

        //字符串转换成数字
        String str = "11";
        int str2num = Integer.parseInt(str);//这里还有一个拆包的过程
        System.out.println("str2num：" + str2num);
        System.out.println("str2num的类型为：" + getType(str2num));

        double str2num_2 = Float.parseFloat(str);
        System.out.println("str2num_2：" + str2num);
        System.out.println("str2num_2的类型为：" + getType(str2num));

        //字符转换成数字
        //减去0的ASCII（48）即可
        char num_char = '9';
        int char2num = num_char - 48;
        System.out.println("字符转换为数字的结果：" + char2num);

        //或者直接减'0'
        int char2num_2 = num_char - '0';
        System.out.println("char2num_2的结果：" + char2num_2);

        //0-9之间的数字转换成char，（超过9的就变成字符串了）
        //同理可得，直接加上0的ASCII就好了
        int num_int = 8;
        char num2char = (char) (num_int + 48);
        System.out.println("数字转换字符的结果：" + num2char);

        //或者直接加'0'
        char num2char_2 = (char)(num_int + '0');
        System.out.println("num2char_2的结果：" + num2char_2);
    }
}
