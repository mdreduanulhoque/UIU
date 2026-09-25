<?php

$people = (int)$_POST["total-student"];
$sps = (int)$_POST["slice-per-student"];
$spp = (int)$_POST["slice-per-pizza"];
$price_per_slice = 1050 / $spp;

$total_pizza = ceil(($people * $sps)/$spp);
$leftover_slices = ($total_pizza * $spp) - ($people * $sps);

echo "Total Pizzas: ".$total_pizza." || Leftover Slices: ".$leftover_slices." || Wasted Money: ".($leftover_slices*$price_per_slice)."";








?>