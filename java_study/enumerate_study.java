package java_study;

public class enumerate_study {
    public static void main(String args[]){
        /**
        System.out.println(week.Fri);
        System.out.println(week.Fri.name());
        System.out.println(week.Fri.ordinal());
        for(week value : week.values()){
            if(value == week.Sat){
                System.out.println("放假啦！");
            }
        }
         */

        int cur_day = 6;
        if(cur_day == week.Sun.ordinal()){
            System.out.println("放假啦");
        }
        else{
            System.out.println("滚去工作");
        }


        //week cur_day = week.Fri;
        //System.out.println(cur_day.ordinal());
    }
}

enum week{
    Mon(0),Tue(1),Wed(2),Thu(3),Fri(4),Sat(5),Sun(6);

    public final int day2int;

    private week(int day2int){
        this.day2int = day2int;
    }
}

class week_day{
    public static final int Mon = 0;
    public static final int Tue = 1;
    public static final int Wed = 2;
    public static final int Thu = 3;
    public static final int Fri = 4;
    public static final int Sat = 5;
    public static final int Sun = 6;
}
