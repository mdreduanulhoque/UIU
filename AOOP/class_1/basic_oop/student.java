package basic_oop;

public class student {
    String student_name;
    String student_email;
    int student_id;

    course[] courses = new course[5];
    int courses_taken = 0;

    public student(String student_name, int student_id, String student_email) {
        this.student_name = student_name;
        this.student_id = student_id;
        this.student_email = student_email;
    }

    void add_course(course c){
        courses[courses_taken] = c;
        courses_taken++;
        System.out.println("Course added");
    }

    void show_courses(){
        for(int i = 0; i < courses_taken; i++){
            System.out.println(courses[i].course_id + "  " + courses[i].course_name);
        }
    }
}
