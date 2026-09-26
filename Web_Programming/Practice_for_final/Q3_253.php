<?php

$button_pressed = $_POST["action"];

$connection = new mysqli("localhost", "root","", "q3_253" );

if($button_pressed == "q1"){
    $sql = "SELECT Status, COUNT(LoanID) as loan_books FROM Book_loans GROUP BY Status HAVING COUNT(LoanID) > 1";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Status: ".$row["Status"]." Number of Books: ".$row["loan_books"]."<br>";
        }
    }
}
else if($button_pressed == "q2"){
    $sql = "UPDATE Book_loans SET Status = 'Grace Period', PenaltyFee = 0 WHERE Status = 'Overdue' AND DaysOverdue < 7 ";
    $connection->query($sql);
    echo "Data Updated";
}
else if($button_pressed == "q3"){
    $sql = "UPDATE Book_loans SET PenaltyFee = PenaltyFee + (0.1 * PenaltyFee) WHERE PenaltyFEE > 20 AND PenaltyFee + (0.1 * PenaltyFee) <= 50";
    $connection->query($sql);
    echo "Data Updated";
}
else if($button_pressed == "q4"){
    $sql = "SELECT BookTitle, SUM(PenaltyFee) as total_income FROM book_loans GROUP BY BookTitle ORDER BY SUM(PenaltyFee) DESC";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "Book Name: ".$row["BookTitle"]." Collected Fee: ".$row["total_income"]."<br>";
        }
    } 
}



?>