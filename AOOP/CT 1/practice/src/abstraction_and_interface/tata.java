package abstraction_and_interface;

public class tata extends car{
    public tata(String model, int car_id, String color) {
        super(model, car_id, color);
    }

    @Override
    void engine_sound() {
        System.out.println("Tata engine sound: ssssss----ee-e-e-ee--e-s-ss-s");
    }
}
