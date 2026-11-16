package basic;

public class student {
    String name;
    int age;
    double cgpa;
    course[] courses = new course[5];
    int current_courses = 0;

    public student(String name, int age, double cgpa) {
        this.name = name;
        this.age = age;
        this.cgpa = cgpa;
    }

    public void add_course(course c) {
        courses[current_courses] = c;
        current_courses++;
        System.out.print("Course added\n");
    }

    public void show_courses(){
        for (int i = 0; i < current_courses; i++){
            System.out.println(courses[i].course_title + " -> " + courses[i].course_id);
        }
    }
}
