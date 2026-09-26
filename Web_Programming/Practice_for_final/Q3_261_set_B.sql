-- Creating dataabse
CREATE DATABASE q3_set_b_261;
USE q3_set_b_261;

-- Creating table
CREATE TABLE book_info(
    BookID INT PRIMARY KEY,
    BookTitle TEXT,
    Author TEXT,
    Category TEXT, 
    Price INT, 
    Stock INT 
    );

-- Inset Data
INSERT INTO book_info VALUES (1, "Web Basics", "John Smith", "Programming", 450, 10),
(2, "Database Guide", "Alice Roy", "Programming", 550, 8), 
(3, "English Grammar", "Mary Khan", "Language", 300, 15), 
(4, "Business Math", "David Lee", "Business", 400, 12), 
(5, "Python Mastery", "Sara Ahmed", "Programming", 600, 5), 
(6, "French Made Easy", "Paul Costa", "Language", 350, 7);

