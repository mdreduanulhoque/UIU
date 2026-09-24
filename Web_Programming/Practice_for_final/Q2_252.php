<?php

$people = $_POST["total-people"];
$capacity = $_POST["seat-capacity"];
$price = $_POST["ticket-price"];

$screen_needed = ceil($people/$capacity);
$empty_seat = ($screen_needed * $capacity) - $people;

echo "Total Screens: ".$screen_needed." || Empty Seats: ".$empty_seat." || Wasted Money: ".($empty_seat*$price)."";








?>