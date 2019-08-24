import java.util.Arrays;

//大根堆
public class heap {
    private int[] my_heap;
    private int max_size;
    private int current_size;

    //构造函数
    heap(int size){
        my_heap = new int[size];
        max_size = size;
        current_size = 0;
    }

    //打印
    void print_heap(){
        int[] temp_arr = java.util.Arrays.copyOf(my_heap,current_size);
        System.out.println(Arrays.toString(temp_arr));
    }

    //返回堆的根节点
    int heap_head(){
        return my_heap[0];
    }

    //返回堆已用容量
    int heap_size(){
        return current_size;
    }

    //判空
    boolean isEmpty(){
        return current_size == 0;
    }

    //判满
    boolean isFull(){
        return current_size == max_size;
    }

    //插入一个元素（向上调整）
    void insert(int value){
        if(current_size == 0){my_heap[0] = value;}
        if(current_size == max_size){System.out.println("当前堆已满，无法添加。");}
        else{
            int temp_index = current_size;
            my_heap[temp_index] = value;//先将这个元素放到最后一个节点上,如果满足大根堆的条件，那么它就在那里不动了。
            int parent = (temp_index - 1) / 2;//其父节点索引
            //如果value大于当前所在位置对应的父节点的值，则需要更新，与父节点交换位置即可。
            while(temp_index > 0 && my_heap[parent] < my_heap[temp_index]){
                //交换节点位置
                my_heap[temp_index] = my_heap[parent];
                my_heap[parent] = value;
                //更新索引
                temp_index = parent;
                parent = (temp_index - 1) / 2;
            }
        }
        current_size++;
    }

    //删除一个元素(指定索引，而不是value)，还需要好好消化一下！！！
    void delete(int index){
        //首先把最后一个叶子节点的值赋给需要删除的index
        my_heap[index] = my_heap[current_size - 1];
        //向下调整
        down_adjust(index);
        //删除最后一个元素
        //my_heap[current_size] = 0;
        current_size--;
    }

    //向下调整
    void down_adjust(int index){
        int temp = my_heap[index];
        //每次调整位置都是比较当前位置和它的左右儿子的值
        for(int i = 2 * index + 1;i < current_size - 1;i = 2 * i + 1){
            if(i<current_size && my_heap[i] < my_heap[i+1]){
                i++;//找到左右儿子中较大的那个
            }
            if(temp > my_heap[i]){
                break;//如果当前所在位置比它的左右儿子都大，就说明找到合适的位置了，结束。
            }
            else{
                //否则，把左右儿子中大的那个就编程爸爸了，index放到儿子的位置，更新index，继续调整
                my_heap[index] = my_heap[i];
                index = i;
            }
        }
        my_heap[index] = temp;
    }

    //数组转换成堆
    void array2heap(int[] array){
        if(array.length > max_size){System.out.println("容量不足，请扩容！");}
        else{
            for (int value : array) {
                this.insert(value);
            }
        }
    }
}

//测试单元
class test_heap{
    public static void main(String args[]){
        heap my_heap = new heap(8);
        int[] array = {4,7,5,6,2,3,1,8};
        my_heap.array2heap(array);
        my_heap.print_heap();
        my_heap.delete(2);
        my_heap.print_heap();

        //堆排序
        System.out.println(my_heap.heap_size());
        int[] sorted = new int[my_heap.heap_size()];
        for(int i=my_heap.heap_size()-1;i>=0;i--){
            sorted[i] = my_heap.heap_head();
            my_heap.delete(0);
        }
        System.out.println(Arrays.toString(sorted));
    }
}
