-- Creating dataabse
CREATE DATABASE q3_252;
USE q3_252;

-- Creating table
CREATE TABLE sales_data(
    SaleID INT NOT NULL PRIMARY KEY,
    ProductName TEXT, 
    CategoryID INT,
    CategoryName TEXT,
    Quantity INT,
    Revenue INT
    );

-- Inset Data
INSERT INTO sales_data VALUES (1, "Laptop", 301, "Electronics", 5, 350000),
(2, "Mouse", 301, "Electronics", 15, 45000), 
(3, "Chair", 302, "Furniture", 8, 64000), 
(4, "Desk", 302, "Furniture", 6, 72000), 
(5, "Bottle", 303, "Accessories", 20, 30000), 
(6, "Pen", 303, "Accessories", 25, 20000);
