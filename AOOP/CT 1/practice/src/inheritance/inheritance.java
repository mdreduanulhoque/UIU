package inheritance;

public class inheritance {
    static void main() {
        rectangle rec = new rectangle(10, 23);
        double rec_breadth = rec.get_breadth();
        double rec_area = rec.get_area();

        System.out.println("Area of rectangle is: " + rec_area);
        System.out.println("Rectangle breadth: " + rec_breadth);

    }
}
