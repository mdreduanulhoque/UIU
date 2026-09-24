<?php

$md = $_POST["mission-distance"];
$ec = $_POST["energy-consumption"];
$bc = $_POST["battery-capacity"];

$total_energy_required = $md * $ec;
$battery_needed = ceil($total_energy_required / $bc);
$unused_energy_percentace = ((($battery_needed * $bc) - $total_energy_required) / ($battery_needed * $bc)) * 100;
$unused_energy = (($battery_needed * $bc) - $total_energy_required) ;

if($unused_energy_percentace <= 10){
    echo "<br>Efficient<br>Unused Energy: ".$unused_energy."";
}else if($unused_energy_percentace > 10 && $unused_energy_percentace <= 25){
    echo "<br>Acceptable<br>Unused Energy: ".$unused_energy."";
}else if($unused_energy_percentace > 25){
    echo "<br>Wasteful<br>Unused Energy: ".$unused_energy."";
}

?>