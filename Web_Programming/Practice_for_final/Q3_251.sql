-- Creating dataabse
CREATE DATABASE q3_251;
USE q3_251;

-- Creating table
CREATE TABLE employee_final(
    EmployeeID INT NOT NULL PRIMARY KEY,
    EmployeeName TEXT,
    DepartmentID INT,
    DepartmentName TEXT,
    Salary INT,
    PerformanceRating TEXT
    );

-- Inset Data
INSERT INTO employee_final VALUES (1, "Arif Rahman", 201, "Software Development", 45000, "B"),
(2, "Marium Khan", 201, "Software Development", 52000, "A"), 
(3, "Sabbir Hossain", 202, "Quality Assurance", 38000, "C"), 
(4, "Samira Begum", 203, "UI/UX Design", 42000, "B");
