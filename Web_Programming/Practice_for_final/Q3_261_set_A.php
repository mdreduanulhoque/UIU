<?php

$button_pressed = $_POST["action"];

$connection = new mysqli("localhost", "root","", "q3_set_a_261" );

if($button_pressed == "q1"){
    $sql = "SELECT SpotName, Region, Rating FROM tourist_spot WHERE Rating > 4.5 AND SpotName LIKE '%Beach%' ORDER BY Rating DESC";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Spot Name: ".$row["SpotName"]."     Region: ".$row["Region"]."     Rating: ".$row["Rating"]."<br>";
        }
    }
}
else if($button_pressed == "q2"){
    $sql = "UPDATE tourist_spot SET Rating = Rating + 0.2, EntryFee = EntryFee + (EntryFee * 0.1) WHERE (Rating > 4.0 AND Rating <= 4.5) AND EntryFee > 0";
    $connection->query($sql);
    echo "Database Updated <br>";
}
else if($button_pressed == "q3"){
    $sql = "SELECT Category, COUNT(SpotName) AS total_spots, AVG(Rating) AS avg_rating, SUM(VisitorsPerYear) AS total_visitors  FROM tourist_spot GROUP BY Category HAVING AVG(Rating) > 4.4 ORDER BY AVG(Rating) DESC";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Category Name: ".$row["Category"]."     Total Spot: ".$row["total_spots"]."     Average Rating: ".$row["avg_rating"]."     Total Visitor Per Year: ".$row["total_visitors"]."<br>";
        }
    }
}
else if($button_pressed == "q4"){
    $sql = "SELECT Region, SUM(EntryFee * VisitorsPerYear) as estimated_revenue FROM tourist_spot GROUP BY Region HAVING estimated_revenue > 1000000 ORDER BY estimated_revenue DESC ";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Region name: ".$row["Region"]." Yearly Estimated Revenue: ".$row["estimated_revenue"]."<br>";
        }
    } 
}


?>