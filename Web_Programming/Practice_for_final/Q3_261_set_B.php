<?php

$button_pressed = $_POST["action"];

$connection = new mysqli("localhost", "root","", "q3_set_b_261" );

if($button_pressed == "q1"){
    $sql = "SELECT BookTitle FROM Book_info WHERE Category = 'Programming' ORDER BY Price DESC";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Book Name: ".$row["BookTitle"]."<br>";
        }
    }
}
else if($button_pressed == "q2"){
    $sql = "SELECT BookTitle, Author, Price FROM Book_info WHERE Category = 'Programming' AND Price > 400 ";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Book Name: ".$row["BookTitle"]."Author Name: ".$row["Author"]."Price: ".$row["Price"]."<br>";
        }
    }
}
else if($button_pressed == "q3"){
    $sql = "SELECT Category, SUM(Stock) AS total_available  FROM Book_info GROUP BY Category";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Category Name: ".$row["Category"]."     Total Stock: ".$row["total_available"]."<br>";
        }
    }
}
else if($button_pressed == "q4"){
    $sql = "SELECT SUM(Price * Stock) as worth FROM book_info";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Book Shop New Worth : ".$row["worth"]."<br>";
        }
    } 
}
else if($button_pressed == "q5"){
    $sql1 = "UPDATE Book_info SET Price = Price - (Price * 0.1) WHERE Category = 'Language'";
    $connection->query($sql1);

    $sql = "SELECT BookTitle, Price FROM Book_info";
    $result = $connection->query($sql);

    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Book Name: ".$row["BookTitle"]."  Price: ".$row["Price"]."<br>";
        }
    }
}


?>