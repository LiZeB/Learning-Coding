public class stack8link {

    private node4stack top;
    private int maxsize;
    private int count;

    //注意和link中的构造函数的区分，这里我的头节点不是null，而是一个value为null，next为null的节点
    public stack8link(int stack_size){
        top = new node4stack();
        maxsize = stack_size;
    }

    //入栈
    public void pull(Integer value){
        if(count < maxsize) {
            node4stack temp_node = new node4stack(value);
            temp_node.setNext(top);
            top = temp_node;
            count++;
        }
        else{
            System.out.println("达到容量上限！");
        }
    }

    //出栈
    public void pop(){
        if(count > 0){
            top = top.getNext();
            count--;
        }
        else{
            System.out.println("当前栈为空，无法删除！");
        }
    }

    //判空
    public boolean isempty(){
        if(top.getValue() == null){
            return true;
        }
        else{
            return false;
        }
    }

    //判满
    public boolean isfull(){
        if(count == maxsize){
            return true;
        }
        else{
            return false;
        }
    }

    //由于构造函数的不同，这里在读取链表的时候也和link中的发生了变化
    public void read(){
        node4stack cur = top;
        while(cur.getNext() != null){
            System.out.println(cur.getValue());
            cur = cur.getNext();
        }
    }

}

//用于构造栈的节点类
class node4stack{

    private Integer value;
    private node4stack next;

    //两种构造函数
    public node4stack(Integer value){
        this.value = value;
        this.next = null;
    }

    public node4stack(){
        this.value = null;
        this.next = null;
    }

    public void setNext(node4stack next){
        this.next = next;
    }

    public Integer getValue(){
        return this.value;
    }

    public node4stack getNext(){
        return this.next;
    }
}

//测试单元
class test_stack8link{
    public static void main(String args[]){
        stack8link my_link = new stack8link(3);
        System.out.println(my_link.isempty());
        System.out.println(my_link.isfull());
        my_link.pop();
        my_link.pull(1);
        my_link.pull(2);
        my_link.pull(3);
        my_link.read();
        System.out.println(my_link.isempty());
        System.out.println(my_link.isfull());
        my_link.pop();
        my_link.pop();
        my_link.pop();
        System.out.println(my_link.isempty());
        System.out.println(my_link.isfull());
    }
}

