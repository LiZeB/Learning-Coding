public class link
{
    public node head;

    //注意这里构造函数和stack8link中的不同，这里我直接把头节点设为了null
    public link(){
        this.head = null;
    }

    //从头添加元素
    public void add(int value){
        node cur = new node(value);
        cur.setNext(head);//这一步很重要，只是我暂时还没想明白。。。【其实这一步很简单】
        head = cur;
    }

    //将数组转换成链表
    public node array2link(int[] array){
        int len = array.length;
        node cur = new node(array[0]);
        cur.setNext(head);
        head = cur;
        for(int i=1;i<len;i++){
            cur.setNext(new node(array[i]));
            cur = cur.getNext();
        }
        return head;
    }

    //输出一整个链表
    public void read_link(){
        node cur = head;
        while(cur != null){
            System.out.println(cur.getValue());
            cur = cur.getNext();
        }
    }

    //统计链表长度
    public int count_link(){
        node cur = head;
        int count = 0;
        while(cur != null){
            count++;
            cur = cur.getNext();
        }
        return count;
    }

    //向链表插入元素
    public void insert_link(int index, int value){
        //node cur = head;
        if(index == 0){
            node cur = new node(value);
            cur.setNext(head);
            head = cur;
        }
        else {
            node cur = head;
            int count = 0;
            while (count < index - 1) {
                count++;
                cur = cur.getNext();
            }
            node curr = cur.getNext();
            node insert_node = new node(value);
            cur.setNext(insert_node);
            insert_node.setNext(curr);
        }
    }

    //删除链表元素
    public void delete_link(int index){
        if(index == 0){
            node cur = head;
            head = cur.getNext();
        }
        else{
            int count = 0;
            node cur = head;
            while(count < index - 1){
                count++;
                cur = cur.getNext();
            }
            node curr = cur.getNext().getNext();
            cur.setNext(curr);
        }
    }

    //判断一个数是否在链表中，如果在，则输出其位置，如果不在则输出-1
    public int isContainsValue_link(int value){
        node cur = head;
        int count = 0;
        while(cur != null){
            if(cur.getValue() == value){
                return count;
            }
            cur = cur.getNext();
            count++;
        }
        return -1;
    }

    //删除链表中值为value的节点(仅删除第一个)
    public void delete_value(int value){
        node cur = head;
        node cur_quick = cur.getNext();
        if(cur.getValue() == value){
            cur = cur.getNext();
            head = cur;
        }
        else{
            while(cur_quick != null){
                if(cur_quick.getValue() == value){
                    cur.setNext(cur_quick.getNext());
                }
                cur = cur.getNext();
                cur_quick = cur_quick.getNext();
            }
        }
    }

    //输出链表中间的节点的value和index
    public int[] middle_link(){
        int[] ans = new int[2];
        node quick = head;
        node slow = head;
        int count = 0;
        while(quick != null && quick.getNext() != null){
            quick = quick.getNext();
            slow = slow.getNext();
            if(quick != null){
                quick = quick.getNext();
            }
            count++;
        }
        ans[0] = count;
        ans[1] = slow.getValue();
        return ans;
    }

    //冒泡排序，仅交换节点的value而不交换节点
    public void bubble_sort(){
        node cur = head;
        //System.out.println("头节点的value：" + cur.getValue());
        for(int i=0;i<this.count_link() - 1;i++){
            node left = head;
            node right = left.getNext();
            for(int j=0;j<this.count_link() - i - 1;j++){
                if(left.getValue() > right.getValue()){
                    int temp_value = left.getValue();
                    left.setValue(right.getValue());
                    right.setValue(temp_value);
                }
                left = left.getNext();
                right = right.getNext();
            }
        }
    }

    //选择排序，同样只是交换value而不交换节点本身，逻辑好像有点不太对？？？
    public void select_sort(){
        node cur = head;
        for(int i=0;i<this.count_link();i++){
            node cur_min = cur;
            node move = cur.getNext();
            for(int j=i+1;j<this.count_link();j++){
                //int min_value = cur_min.getValue();
                if(move.getValue() < cur_min.getValue()){
                    int temp_value = move.getValue();
                    move.setValue(cur_min.getValue());
                    cur_min.setValue(temp_value);
                }
                move = move.getNext();
            }
            //cur_min = cur_min.getNext();
            cur = cur.getNext();

        }
    }
}
class node{
    private int value;
    private node next;

    public node(Integer value){
        this.value = value;
    }

    public void setNext(node next){
        this.next = next;
    }

    public node getNext(){
        return this.next;
    }

    public void setValue(int new_value){
        this.value = new_value;
    }

    public int getValue(){
        return this.value;
    }
}

//测试单元
class test_link{
    public static void main(String args[]){
        int[] array = {5,2,1,3,6,7,4,9,8};
        link my_link = new link();
        my_link.array2link(array);
        my_link.read_link();
        //my_link.bubble_sort();
        my_link.select_sort();
        my_link.read_link();
    }
}
