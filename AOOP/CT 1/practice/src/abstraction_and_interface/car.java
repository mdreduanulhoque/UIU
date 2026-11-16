package abstraction_and_interface;

public abstract class car {
    String model;
    int car_id;
    String color;

    public car(String model, int car_id, String color) {
        this.model = model;
        this.car_id = car_id;
        this.color = color;
    }

    abstract void engine_sound();

    void car_details(){
        System.out.println("Model: "+model);
        System.out.println("Car id: "+car_id);
        System.out.println("Color: "+color);
    }

}
