import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListDemo2 {
    static void main(){
        ArrayList<Integer> al2 = new ArrayList<>();

        al2.add(10);
        al2.add(50);
        al2.add(30);
        al2.add(20);
        al2.add(90);
        al2.add(60);
        al2.remove(Integer.valueOf(90));

        // Print with iterator
        Iterator<Integer> itr = al2.iterator();
        while(itr.hasNext()){
            System.out.print(itr.next() + "  ");
        }
        System.out.println("");

        System.out.println("After removing 90: ");
        al2.forEach((i -> System.out.print(i + " ")));
    }
}
