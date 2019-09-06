public class clone_study {
    public static void main(String args[]){
        
    }
}

class teacher implements Cloneable{
    private String name;

    public teacher(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }

    public void setName(String nname){
        this.name = nname;
    }

    //重写clone方法
    public Object clone() throws CloneNotSupportedException{
        return (teacher) super.clone();
    }

}

class object_test implements Cloneable{
    private String name;
    private int age;
    private teacher my_teacher;

    object_test(String name, int age, teacher tea){
        this.name = name;
        this.age = age;
        this.my_teacher = tea;
    }

    public String getName(){
        return this.name;
    }

    public int getAge(){
        return this.age;
    }

    public void setName(String name_2){
        this.name = name_2;
    }

    public String getTeacher(){
        return this.my_teacher.getName();
    }

    public void setMy_teacher(teacher tteacher){
        this.my_teacher = tteacher;
    }

    //重写clone方法，实现深拷贝
    public Object clone() throws CloneNotSupportedException{
        object_test new_object = (object_test) super.clone();
        new_object.my_teacher = (teacher) my_teacher.clone();
        return new_object;
    }

    public static void main(String args[]) {
        teacher cur_teacher = new teacher("guo");
        object_test object_3 = new object_test("aa", 11, cur_teacher);
        try {
            System.out.println("对象3的老师：" + object_3.getTeacher());
            object_test object_4 = (object_test) object_3.clone();
            System.out.println("对象4的老师：" + object_4.getTeacher());
            cur_teacher.setName("xu");
            System.out.println("修改后对象3的老师：" + object_3.getTeacher());
            System.out.println("修改后对象4的老师：" + object_4.getTeacher());
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }





}
