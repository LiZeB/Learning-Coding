import java.util.Scanner;
public class dp_bag {
    /**
     * 测试用例：背包容量为6，共有3个物品：(3,5)、(2,4)、(4,2)
     * 多重背包测试用例：背包容量为10，共有4个物品：(2,3,2)、(2,4,3)、(1,2,2)、(4,5,3)
     * 测试0-1背包和完全背包的时候，把goods_nums[i] = reader.nextInt();注释掉
     */
    public static void main(String args[]){
        Scanner reader = new Scanner(System.in);
        int bag_cap = reader.nextInt();
        int goods_num = reader.nextInt();
        int[] goods_nums = new int[goods_num];
        int[] goods_cap = new int[goods_num];
        int[] goods_val = new int[goods_num];
        for(int i=0;i<goods_num;i++){
            goods_nums[i] = reader.nextInt();
            goods_cap[i] = reader.nextInt();
            goods_val[i] = reader.nextInt();
        }
        //System.out.println(bag_complete(bag_cap, goods_cap, goods_val));
        System.out.println(bag_multi(bag_cap, goods_nums, goods_cap, goods_val));
    }

    /**
     *0-1背包问题，一个物品最多只能取一次
     *状态转移方程：result[i][j] = max(result[i-1][j], result[i-1][j-goods_cap[i]] + goods_val[i])
     *其中i表示有i个物品，j表示背包容量
     */
    public static int bag_zeroone(int bag_cap, int[] goods_cap, int[] goods_val){
        int[][] result = new int[goods_cap.length + 1][bag_cap + 1];//之后的循环都是从1开始的，所以容量+1
        for(int i=1;i<=goods_cap.length;i++){//前i个物品，也就是物品的数量
            for(int j=1;j<=bag_cap;j++){//当前背包的容量
                if(goods_cap[i-1] > j){
                    result[i][j] = result[i-1][j];//当前物品大小大于当前背包容量，则不放这个物品，加不加这句对结果无影响，优化作用。
                }
                else{
                    //这里goods_cap和goods_val的i要减1，因为i是从1开始循环的。
                    result[i][j] = Math.max(result[i-1][j], result[i-1][j-goods_cap[i-1]] + goods_val[i-1]);
                }
            }
        }
        return result[goods_cap.length][bag_cap];
    }

    /**
     * 完全背包问题，每个物品可以取无数次
     * 状态转移方程：result[i][j] = max(result[i-1][j-k*goods_vap[i]] + goods_val[i]*k)
     * 其中，k表示第i个物品取多少次，k*goods_cap[i] < j
     */
    public static int bag_complete(int bag_cap, int[] goods_cap, int[] goods_val){
        int[][] result = new int[goods_cap.length + 1][bag_cap + 1];
        for(int i=0;i<goods_cap.length;i++){//这里我从0开始循环，和前面的对比来看，状态转移方程的变动
            for(int j=1;j<=bag_cap;j++) {//j=0的元素都为0，这个不用多说了
                if (j < bag_cap) {
                    result[i + 1][j] = result[i][j];
                }
                else{
                    for (int k = 0; k * goods_cap[i] <= j; k++) {//每个物品取k次
                        //注意这里的下标，可以和上面的对照着来看
                        result[i + 1][j] = Math.max(result[i + 1][j], result[i][j - k * goods_cap[i]] + k * goods_val[i]);
                    }
                }
            }
        }
        return result[goods_cap.length][bag_cap];
    }

    /**
     * 多重背包问题，每样物品有若干个
     * 状态转移方程：result[i][j] = max(result[i-1][j-k*goods_cap[i]] + goods_val[i]*k)
     * 状态转移方程和完全背包问题一样，只不过对k多了项约束
     * k < goods_nums[i] && k*goods_cap[i] < j
     * 在牛客网上超时了，只通过80%用例，需要继续优化
     */
    public static int bag_multi(int bag_cap, int[] goods_nums, int[] goods_cap, int[] goods_val){
        int[][] result = new int[goods_nums.length + 1][bag_cap + 1];
        for(int i=0;i<goods_nums.length;i++){
            for(int j=1;j<=bag_cap;j++){
                if(goods_cap[i] > j){
                    result[i + 1][j] = result[i][j];
                }
                else{
                    for(int k=0;k*goods_cap[i] <= j && k <= goods_nums[i];k++){
                        result[i + 1][j] = Math.max(result[i + 1][j], result[i][j - k*goods_cap[i]] + k*goods_val[i]);
                    }
                }
            }
        }
        return result[goods_nums.length][bag_cap];
    }

}


