package basic_oop;

public class oop_main {
    static void main() {
        course c1 = new course(1, "AOOP");
        course c2 = new course(2, "Web Programming");

        student s1 = new student("ghr", 123, "eur@jufj");
        s1.add_course(c1);
        s1.add_course((c2));

        s1.show_courses();
    }
}
