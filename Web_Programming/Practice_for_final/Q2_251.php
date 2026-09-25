<?php

$people = (int)$_POST["total-people"];
$capacity = (int)$_POST["capacity"];
$price = (int)$_POST["cost-per-person"];

$venue_needed = ceil($people/$capacity);
$empty_seat = ($venue_needed * $capacity) - $people;

echo "Total Venues: ".$venue_needed." || Empty Seats: ".$empty_seat." || Wasted Money: ".($empty_seat*$price)."";








?>