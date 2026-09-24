<?php

$cpc = $_POST["credit-per-course"];
$ncc = $_POST["number-of-course-completed"];
$tc = $_POST["target-credit"];

$total_completed_credit = $cpc * $ncc;

if($total_completed_credit >= 120){
    echo "<br>Excellent<br>";
}else if($total_completed_credit >= 90 && $total_completed_credit < 120){
    echo "<br>Good<br>";
}else if($total_completed_credit >= 60 && $total_completed_credit < 90){
    echo "<br>Average<br>";
}else if($total_completed_credit < 60){
    echo "<br>Poor<br>";
}


if($total_completed_credit < $tc){
    echo "<br>Below target by ".($tc - $total_completed_credit)." credit<br>";
}else if($total_completed_credit > $tc){
    echo "<br>Above target by ".($total_completed_credit = $tc)." credit<br>";
}else{
    echo "<br>Target Match Exactly<br>";
}








?>