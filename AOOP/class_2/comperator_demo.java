import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;

class Student implements Comparable<Student>{
    int id;
    String name;
    double cgpa;

    public Student(int id, String name, double cgpa) {
        this.id = id;
        this.name = name;
        this.cgpa = cgpa;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", cgpa=" + cgpa +
                '}';
    }

    @Override
    public int compareTo(Student o) {
        if(this.id > o.id){
            return 1;
        }
        else{
            return -1;
        }


    }
}


public class comperator_demo {
    static void main(){
        ArrayList<Student> als = new ArrayList<>();

        als.add((new Student(1, "yubvfs", 2.6)));
        als.add((new Student(7, "yufhufs", 3.6)));
        als.add((new Student(4, "yfs", 1.6)));
        als.add((new Student(3, "ysaeufs", 2.8)));
        als.add((new Student(9, "ybhufs", 2.63)));

        Collections.sort(als);
        Iterator<Student> itr = als.iterator();
        while (itr.hasNext()){
            System.out.println(itr.next());
        }

        System.out.println("");

//        itr = als.iterator();
//        while (itr.hasNext()){
//            Student temp = itr.next();
//            if(temp.cgpa < 3.0){
//                temp.cgpa += 0.2;
//            }
//        }
//
//        itr = als.iterator();
//        while (itr.hasNext()){
//            Student temp = itr.next();
//            if(temp.cgpa < 2.0){
//                als.remove(itr);
//            }
//        }
//
//        itr = als.iterator();
//        while (itr.hasNext()){
//            System.out.println(itr.next());
//        }

        for(int i = 0; i < als.size(); i++){
            if(als.get(i).cgpa < 3.0){
                als.get(i).cgpa = als.get(i).cgpa + 0.2;
            }
            if(als.get(i).cgpa < 2.0){
                als.remove(i);
            }
        }


        itr = als.iterator();
        while (itr.hasNext()){
            System.out.println(itr.next());
        }
    }
}
