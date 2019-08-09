package java_study;


import test_1.test;

public class Person{
    /**
    public static void main(String args[]){
        Student dongzan = new Student();
        dongzan.name = "dongzan";
        //dongzan.age = 18;
        dongzan.set_age(18);
        //int dongzan_age = dongzan.get_age();
        System.out.printf("dongzan's age is %d\n",dongzan.get_age());


    }
    */
    public static void main(String args[]){
        Student dongzan = new Student("dongzan",18);
        dongzan.name = "dongzan";

        dongzan.set_age(18);


        //System.out.printf("my age is %d\n", dongzan.get_age());

        Student.run();
        Student.run("dongzan");


    }



}

class Student{

    public String name;
    private int age;

    public Student(String name, int age){
        this.name = name;
        this.age = age;
    }

    public void set_age(int age){
        this.age = age;

    }

    private int get_age(){
        return this.age;
    }

    public static void run(){
        System.out.println("I am running!");
    }

    public static void run(String name){
        System.out.printf("%s is running\n",name);
    }




}
