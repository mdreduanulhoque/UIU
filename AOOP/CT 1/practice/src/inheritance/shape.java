package inheritance;

public class shape{
    double length;
    double width;

    public shape(double length, double width) {
        this.length = length;
        this.width = width;
    }

    double get_area(){
        return length*width;
    }
}
