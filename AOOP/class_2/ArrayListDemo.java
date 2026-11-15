import java.util.ArrayList;

public class ArrayListDemo {
    static void main(){
        ArrayList<String> al = new ArrayList<>();
        al.add("A");
        al.add("B");
        al.add("C");
        al.add("D");
        al.add("E");
        al.add("F");
        al.add("G");
        al.add(5, "AA");

        System.out.println("After adding elements size " + al.size());

        al.set(0, "CC");

        // Iterative loop
        for (int i = 0; i < al.size(); i++){
            System.out.print(al.get(i) + " ");
        }
        System.out.println("");

        // Remove "AA"
        al.remove("AA");

        // For-each function
        System.out.println("After removing AA: ");
        al.forEach(e -> System.out.print(e + "  "));
    }
}
