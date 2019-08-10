public class stack {
    private int maxsize;
    private int[] array;
    private int top;

    //构造函数
    public stack(int stack_size){
        maxsize = stack_size;
        array = new int[maxsize];
        top = -1;
    }

    //入栈，注意：数组的尾部是栈的顶部
    public void push(int value){
        top = top + 1;
        array[top] = value;
    }

    //出栈
    public void pop(){
        top = top - 1;
    }

    //输出栈，数组的倒序输出
    public void read(){
        for(int i=top;i>=0;i--){
            System.out.println(array[i]);
        }
    }

    //判满
    public boolean isfull(){
        if(top == maxsize - 1){
            return true;
        }
        else{
            return false;
        }
    }

    //判空
    public boolean isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    //返回已使用空间
    public int hasused(){
        return top + 1;
    }
}

//测试单元
class test{
    public static void main(String args[]){
        stack my_stack = new stack(3);
        my_stack.push(3);
        my_stack.push(2);
        my_stack.push(1);
        my_stack.read();
        System.out.println(my_stack.isempty());
        System.out.println(my_stack.isfull());
        System.out.println(my_stack.hasused());
        my_stack.pop();
        my_stack.read();
        System.out.println(my_stack.hasused());

    }
}
