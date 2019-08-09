package java_study;

public class my_runnable implements Runnable {
    @Override
    public void run() {
        System.out.println("1.1");
        go();
        //String name = Thread.currentThread().getName();
        //System.out.println(name);
        //for(int i=0;i<100;i++){
            //String name = Thread.currentThread().getName();
            //System.out.println(name);
        //}
    }
    public void go(){
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("1.2 ");
        go_again();
    }
    public void go_again(){
        System.out.println("1.3");
    }
}

class test_thread{
    public static void main(String args[]){
        Runnable test = new my_runnable();
        Thread my_thread = new Thread(test);
        //Thread my_thread2 = new Thread(test);
        //my_thread.setName("我是新线程1");
        //my_thread2.setName("我是新线程2");
        my_thread.start();
        //my_thread2.start();
        System.out.println("2");
        //System.out.println("我是主线程");
    }
}