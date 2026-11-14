package inheritance;

// we can not create a object of abstract class

abstract class s{
    abstract double area();
    void display(){
        System.out.println("S");
    }
}

class c extends s implements interface_{
    int radius;

    public c(int radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        return radius*radius*3.14;
    }

    @Override
    public void check() {
        System.out.println("From interface");
    }
}

// Can not contain any normal function
// all variable are final and can not be changes

interface interface_{
    void check();
}

public class abstract_class {
    static void main() {
        c c1 = new c(1);
        c1.check();
        System.out.println(c1.area());
    }
}
