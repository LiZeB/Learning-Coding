package java_study;

public class save_out implements Runnable {
    account my_account = new account();
    @Override
    public void run() {
        for(int i=0;i<10;i++){
            out(20);
            if(my_account.check() < 0){
                System.out.println("已透支");
            }
        }
    }

    private void out(int out_money){
        System.out.println(Thread.currentThread().getName() + "想要消费");
        if(my_account.check() >= out_money){
            //System.out.println(Thread.currentThread().getName() + "想要消费");
            try{
                System.out.println(Thread.currentThread().getName() + "已检查完毕余额，余额为：" + my_account.check() +"，开始睡觉。");
                Thread.sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName() + "已睡醒，准备消费。");
            my_account.money_out(out_money);
            System.out.println(Thread.currentThread().getName() + "完成消费，当前余额为：" + my_account.check());
        }
        else{
            System.out.println("余额已不够" + Thread.currentThread().getName() + "的消费！当前余额为：" + my_account.check());
        }

    }
}

class account{
    private volatile int all_money = 100;

    public int check(){
        return all_money;
    }

    public void money_out(int consume){
        all_money = all_money - consume;
    }
}

class Main{
    public static void main(String args[]){
        Runnable thread_job = new save_out();
        Thread thread1 = new Thread(thread_job);
        Thread thread2 = new Thread(thread_job);
        thread1.setName("Tom");
        thread2.setName("Jerry");
        thread1.start();
        thread2.start();
    }
}
