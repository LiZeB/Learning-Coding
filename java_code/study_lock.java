import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class study_lock {
    static String obj_1 = "obj_1";
    static String obj_2 = "obj_2";
    static Lock my_lock = new ReentrantLock();
    static Lock my_lock_2 = new ReentrantLock();
    public static void main(String args[]){
        Runnable thread_job_1 = new job_1();
        Runnable thread_job_2 = new job_2();
        Thread my_thread_1 = new Thread(thread_job_1);
        Thread my_thread_2 = new Thread(thread_job_2);
        my_thread_1.start();
        my_thread_2.start();
    }
}

class job_1 implements Runnable{
    @Override
    public void run(){
        study_lock.my_lock.lock();//获取第一个锁

        System.out.println("当前线程：" + Thread.currentThread().getName() + "获得了：" + study_lock.obj_1);
        try{
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(Thread.currentThread().getName() + "获得了锁1：" +study_lock.my_lock.tryLock());
        System.out.println(Thread.currentThread().getName() + "获得了锁2：" +study_lock.my_lock_2.tryLock());

        study_lock.my_lock_2.lock();//尝试获取第二个锁，但在该线程sleep期间，另一个线程抢先获得了锁2
        System.out.println("当前线程：" + Thread.currentThread().getName() + "获得了：" + study_lock.obj_2);

        study_lock.my_lock_2.unlock();
        study_lock.my_lock.unlock();
    }
}

class job_2 implements Runnable{

    @Override
    public void run() {
        study_lock.my_lock_2.lock();

        System.out.println("当前线程：" + Thread.currentThread().getName() + "获得了：" + study_lock.obj_2);
        try{
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(Thread.currentThread().getName() + "获得了锁1：" +study_lock.my_lock.tryLock());
        System.out.println(Thread.currentThread().getName() + "获得了锁2：" +study_lock.my_lock_2.tryLock());

        study_lock.my_lock.lock();
        System.out.println("当前线程：" + Thread.currentThread().getName() + "获得了：" + study_lock.obj_1);

        study_lock.my_lock.unlock();
        study_lock.my_lock_2.unlock();
    }
}
