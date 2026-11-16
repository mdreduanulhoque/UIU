package basic;

public class main {
    public static void main(String[] args) {
        course c1 = new course("Biology For Engineers", "BIO 3105");
        course c2 = new course("Structured Programming Language", "CSE 1112");

        student s1 = new student("Rakib", 19, 3.20);

        s1.add_course(c1);
        s1.add_course(c2);

        s1.show_courses();
    }
}
