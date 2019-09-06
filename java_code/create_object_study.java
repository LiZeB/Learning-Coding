import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class create_object_study {
    public static void main(String args[]){
        //使用new新建一个对象
        person dongzan = new person("dongzan", 18);
        animal cat = new animal("cat", dongzan);
        System.out.println(cat.getKind() + cat.getHost());

        /**
        //使用class类的newInstance新建一个对象
        try{
            //person konata = dongzan.getClass().newInstance();
            Class konataClass = Class.forName("person");//这里的"person"，这个字符串是要和你新建的类的名字对应的，不是随便写的
            person konata =(person) konataClass.newInstance();
            System.out.println(konata.getName());
        }catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        }
         */

        //使用Contructor类的newInstance方法
        try{
            //获取类对象
            Class konataClass = Class.forName("person");
            //获取构造器
            Constructor constructor = konataClass.getConstructor();
            //通过构造器新建对象
            person konata = (person) constructor.newInstance();
            System.out.println(konata.getName());
        } catch (ClassNotFoundException | NoSuchMethodException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}

class animal{
    private String kind;
    private person host;

    public animal(String kind, person host){
        this.kind = kind;
        this.host = host;
    }

    public String getKind(){
        return this.kind;
    }

    public String getHost(){
        String host_name = this.host.getName();
        return host_name;
    }
}

class person{
    private String name;
    private int age;

    public person(String name, int age){
        this.name = name;
        this.age = age;
    }

    public person(){
        this.name = "default";
        this.age = 18;
    }

    public String getName(){
        return this.name;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAge(int age){
        this.age = age;
    }
}
