package inheritance;

public class rectangle extends shape{
    public rectangle(double length, double width){
        super(length, width);
    }

    public double get_breadth(){
        return 2*(length+width);
    }

}
