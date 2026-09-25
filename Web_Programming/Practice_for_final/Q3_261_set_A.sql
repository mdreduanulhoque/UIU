-- Creating dataabse
CREATE DATABASE q3_set_a_261;
USE q3_set_a_261;

-- Creating table
CREATE TABLE tourist_spot(
    spotID INT AUTO_INCREMENT PRIMARY KEY,
    SpotName TEXT,
    Region TEXT, 
    Category TEXT,
    Rating DOUBLE(10, 2),
    EntryFee INT,
    VisitorsPerYear INT
    );

-- Inset Data
INSERT INTO tourist_spot VALUES (1, "Cox's Bazar Beach", "CTG", "Beach", 4.9, 0, 150000),
(2, "Sundarbans Forest", "KHL", "Nature", 4.3, 150, 80000), 
(3, "Ratargul Forest", "SYL", "Nature", 4.8, 100, 60000), 
(4, "Kuakata Beach", "PTU", "Beach", 4.5, 0, 90000), 
(5, "Shat Gambuj Mosque", "BGH", "Heritage", 4.7, 30, 70000), 
(6, "Paharpur", "NWG", "Heritage", 4.1, 30, 40000);

