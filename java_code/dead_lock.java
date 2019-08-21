public class dead_lock {
    public static String lock_1 = "lock_1";
    public static String lock_2 = "lock_2";
    public static void main(String args[]){
        Runnable job_1 = new thread_1_job();
        Runnable job_2 = new thread_2_job();
        Thread my_thread_1 = new Thread(job_1);
        Thread my_thread_2 = new Thread(job_2);
        my_thread_1.start();
        my_thread_2.start();
    }
}

class thread_1_job implements Runnable{
    @Override
    public void run() {
        try{
            synchronized (dead_lock.lock_1){
                System.out.println("当前线程：" + Thread.currentThread().getName() + ",它锁住了：" + dead_lock.lock_1);
                Thread.sleep(1000);
                //从这里开始，两个线程就进入相互等待对方释放锁的死锁状态了。
                synchronized (dead_lock.lock_2){
                    System.out.println("当前线程：" + Thread.currentThread().getName() + ",尝试获得：" + dead_lock.lock_2);
                }
            }
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class thread_2_job implements Runnable{
    public void run(){
        try{
            synchronized (dead_lock.lock_2){
                System.out.println("当前线程：" + Thread.currentThread().getName() + ", 它锁住了：" + dead_lock.lock_2);
                Thread.sleep(1000);
                synchronized (dead_lock.lock_1){
                    System.out.println("当前线程：" + Thread.currentThread().getName() + ",尝试获得：" + dead_lock.lock_1);
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
