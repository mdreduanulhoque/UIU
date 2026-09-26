-- Creating dataabse
CREATE DATABASE q3_243;
USE q3_243;

-- Creating table
CREATE TABLE student_final(
    StudentID INT NOT NULL PRIMARY KEY,
    StudentName TEXT,
    CourseID INT,
    CourseTitle TEXT,
    Grade INT,
    LetterGrade TEXT
    );

-- Inset Data
INSERT INTO student_final VALUES (1, "Karim Uddin", 101, "Web Programming", 85, "B"),
(2, "Rahim Ahmed", 101, "Web Programming", 92, "A"), 
(3, "Jashim Hossain", 102, "Project Management", 78, "C"), 
(4, "Jasica Ahmed", 101, "Web Programming", 65, "D"),
(5, "Faria Karim", 102, "Project Management", 95, "A"), 
(6, "Niassoh Dihan", 103, "System Analysis and Design", 80, "B");
