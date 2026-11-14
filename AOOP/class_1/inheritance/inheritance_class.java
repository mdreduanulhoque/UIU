package inheritance;

class shape{
    public void display(){
        System.out.println("Shape");
    }
}

class circle extends shape{
    public void display(){
        System.out.println("Circle");
    }
}

public class inheritance_class {
    static void main(){
        circle c1 = new circle();
        c1.display();
    }
}
