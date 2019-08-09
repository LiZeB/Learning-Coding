package java_study;

public class Student_3 {
    public static void main(String args[]){
        dog husky = new dog("husky","dog",18);
        System.out.println(husky.kind);

        animal hashiqi = new dog("husky","dog",18);
        System.out.println(hashiqi instanceof animal);
        //dog hashiqi_2 = new animal("husky_2","dong");

        person xiaoming = new student();
        xiaoming.run();

    }
}

class person{
    public void run(){
        System.out.println("a person is running");
    }
}

class student extends person{
    public void run(){
        System.out.println("a student is running");
    }
}

class animal{
    private String name;
    protected String kind;

    public animal(String name,String kind){
        this.name = name;
        this.kind = kind;
    }


}

class dog extends animal{
    private int age;
    public dog(String name,String kind,int age){
        super(name, kind);
        this.age = age;
    }
}






