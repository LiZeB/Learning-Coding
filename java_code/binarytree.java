import java.util.Arrays;
import java.util.LinkedList;

public class binarytree {
    /**
    //手动构造一棵树
    //创建节点
    private tree_node root = new tree_node(3);
    private tree_node left1 = new tree_node(2);
    private tree_node right1 = new tree_node(4);
    private tree_node right2 = new tree_node(5);

   //public int size = 0;

    //能不能输入一个数组，自动构造二叉树？？
    void make_tree(){
        //连接节点，构造树
        root.setLeft_child(left1);
        root.setRight_child(right1);
        right1.setLeft_child(right2);
    }
     */
    private tree_node root;

    //返回根节点
    tree_node getRoot(){
        return root;
    }

    //数组转二叉搜索树，对于边界部分有疑问，为什么end != array.length - 1???
    tree_node array2bst(int[] array, int start, int end){
        Arrays.sort(array);
        if(start == end){
            return null;
        }
        else{
            int mid = (start + end) / 2;
            tree_node bst_root = new tree_node(array[mid]);
            bst_root.setLeft_child(array2bst(array, start, mid));
            bst_root.setRight_child(array2bst(array, mid + 1, end));
            root = bst_root;
            return bst_root;
            /**为什么这么写不对？？？？？
            root = new tree_node(array[mid]);
            root.setLeft_child(array2bst(array, start, mid));
            root.setRight_child(array2bst(array,mid + 1, end));
            return root;
             */
        }
    }

    //判断一个数是否在二叉搜索树中
    boolean isIn(int value){
        tree_node cur = root;
        while(cur != null){
            if(value < cur.getValue()){
                cur = cur.getLeft_child();
            }
            else if(value > cur.getValue()){
                cur = cur.getRight_child();
            }
            else if(value == cur.getValue()){
                return true;
            }
        }
        return false;
    }

    //二叉搜索树插入节点
    void insert_node(int value){
        tree_node cur_node = new tree_node(value);
        if(root == null){
            root = cur_node;
        }
        else{
            tree_node temp_root = root;
            while(temp_root != null) {
                if (value > temp_root.getValue()) {
                    if (temp_root.getRight_child() == null) {
                        temp_root.setRight_child(cur_node);
                        break;
                    } else {
                        temp_root = temp_root.getRight_child();
                    }
                } else {
                    if (temp_root.getLeft_child() == null) {
                        temp_root.setLeft_child(cur_node);
                        break;
                    } else {
                        temp_root = temp_root.getLeft_child();
                    }
                }
            }
        }
    }

    //删除二叉树的一个节点
    tree_node delete_node(tree_node rroot, int value){
        if(rroot == null){
            return null;
        }
        if(rroot.getValue() == value){
            //情况1：如果该节点的右子树为null，则直接删除该节点，并将其左节点放置在它原本的位置
            if(rroot.getRight_child() == null){
                return rroot.getLeft_child();
            }
            //情况2：如果该节点的右子树不为null，则找出其右子树中最小的节点，放置在它原本的位置
            tree_node min_node = rroot.getRight_child();//用于记录最小节点
            tree_node min_parent = rroot;//用于记录最小节点的父节点，这个在之后删除子树中的最小节点时要用
            //寻找最小节点
            while(min_node != null && min_node.getLeft_child() != null){
                min_parent = min_node;
                min_node = min_node.getLeft_child();
            }
            //在原来的子树上删除找到的最小节点
            min_parent.setLeft_child(min_node.getRight_child());

            //把找到的最小节点放到要删除的那个节点的位置
            min_node.setLeft_child(rroot.getLeft_child());
            min_node.setRight_child(rroot.getRight_child());
            return rroot;
        }
        //找到那个节点所在的位置
        else if(rroot.getValue() > value){
            rroot.setLeft_child(delete_node(rroot.getLeft_child(), value));
        }
        else if(rroot.getValue() < value){
            rroot.setRight_child(delete_node(rroot.getRight_child(), value));
        }
        root = rroot;
        return rroot;
    }

    //判空
    public boolean isEmpty(){
        return root.getLeft_child() == null && root.getRight_child() == null;
    }

    //前序遍历，遍历完全部左子树后再遍历右子树
    void pre_travel(tree_node root){
        if(root != null){
            System.out.print(root.getValue() + " -> ");
            pre_travel(root.getLeft_child());
            pre_travel(root.getRight_child());
        }
    }

    //中序遍历
    void mid_travel(tree_node root){
        if(root != null){
            mid_travel(root.getLeft_child());
            System.out.print(root.getValue() + " -> ");
            mid_travel(root.getRight_child());
        }
    }

    //后序遍历
    //震惊！！！遍历居然这么有规律！！！
    void post_travel(tree_node root){
        if(root != null){
            post_travel(root.getLeft_child());
            post_travel(root.getRight_child());
            System.out.print(root.getValue() + " -> ");
        }
    }

    //层次遍历，使用队列，先进先出
    void level_travel(tree_node root){
        LinkedList<tree_node> queue = new LinkedList<>();//offer和poll是LinkedList才有的方法，普通的ArrayList没有。
        tree_node current;
        queue.offer(root);//往队列末尾添加元素
        while(!queue.isEmpty()){
            current = queue.poll();//移除并获得队列的第一个元素
            System.out.print(current.getValue() + " -> ");
            if(current.getLeft_child() != null){
                queue.offer(current.getLeft_child());
            }
            if(current.getRight_child() != null){
                queue.offer(current.getRight_child());
            }
        }
    }

    //统计节点个数，递归实现
    int tree_size(tree_node root){
        if(root == null){
            return 0;
        }
        else{
            return 1 + tree_size(root.getLeft_child()) + tree_size(root.getRight_child());//这里的1表示当前节点不为null
        }
    }

    //统计树的高度
    int tree_height(tree_node root){
        if(root == null){
            return 0;
        }
        else{
            int i = 1 + tree_height(root.getLeft_child());//同上，这里的1也表示当前节点不为null
            int j = 1 + tree_height(root.getRight_child());
            return Math.max(i, j);
        }
    }
}

//树节点
class tree_node{
    private int value;
    private tree_node left_child;
    private tree_node right_child;

    tree_node(Integer cur_value){
        value = cur_value;
        left_child = null;
        right_child = null;
    }

    void setValue(int value){
        this.value = value;
    }

    void setLeft_child(tree_node cur_left_child){
        this.left_child = cur_left_child;
    }

    void setRight_child(tree_node cur_right_child){
        this.right_child = cur_right_child;
    }

    tree_node getLeft_child(){
        return this.left_child;
    }

    tree_node getRight_child(){
        return this.right_child;
    }

    int getValue(){
        return this.value;
    }
}

//测试
class test_tree{
    public static void main(String args[]){

        binarytree tree = new binarytree();
        int[] array = {-10, -3, 0, 5, 9};
        tree.array2bst(array, 0, array.length);
        tree.insert_node(4);
        //tree_node root = tree.array2bst(array, 0, array.length);
        //tree.make_tree();
        //System.out.println(tree.isEmpty());
        //tree.insert_node(1);
        tree.delete_node(tree.getRoot(), -10);
        System.out.println("前序遍历");
        tree.pre_travel(tree.getRoot());
        System.out.println("\n中序遍历");
        tree.mid_travel(tree.getRoot());
        System.out.println("\n后序遍历");
        tree.post_travel(tree.getRoot());
        System.out.println("\n层次遍历");
        tree.level_travel(tree.getRoot());
        System.out.println("\n当前树共有：" + tree.tree_size(tree.getRoot()) + " 个节点");
        System.out.println("当前树的高度为：" + tree.tree_height(tree.getRoot()));
        System.out.println(tree.isIn(-10));
    }
}