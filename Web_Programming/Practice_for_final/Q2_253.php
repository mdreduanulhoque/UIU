<?php

$spd = $_POST["sold-per-day"];
$sd = $_POST["sale-duration"];
$t = $_POST["target"];

$total_items_sold = $spd * $sd;

if($total_items_sold >= 500){
    echo "<br>Excellent<br>";
}else if($total_items_sold >= 300 && $total_items_sold < 500){
    echo "<br>Good<br>";
}else if($total_items_sold >= 150 && $total_items_sold < 300){
    echo "<br>Average<br>";
}else if($total_items_sold < 150){
    echo "<br>Poor<br>";
}


if($total_items_sold < $t){
    echo "<br>Below target by ".($t - $total_items_sold)."<br>";
}else if($total_items_sold > $t){
    echo "<br>Above target by ".($total_items_sold - $t)."<br>";
}else{
    echo "<br>Target Match Exactly<br>";
}








?>