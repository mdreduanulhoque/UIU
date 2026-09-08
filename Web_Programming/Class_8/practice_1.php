<?php

$item_name = $_POST["item-name"];
$item_count = $_POST["item-count"];

$button_pressed = $_POST["action"];

$connection = new mysqli("localhost", "root","", "web_php_1" );

if($button_pressed == "add"){
    $sql = "INSERT INTO items (name, stock) VALUES ('$item_name', $item_count)";
    $connection->query($sql);
    echo "<br>".$item_name." is add in database with quantity ".$item_count;
}
else if($button_pressed == "buy"){
    $sql = "UPDATE items SET stock = stock - $item_count WHERE name = '$item_name'";
    $connection->query($sql);
    $sql1 = "INSERT INTO order_log (name, quantity) VALUES ('$item_name', $item_count)";
    $connection->query($sql1);
    echo "<br>".$item_name." has reduced from database by quantity ".$item_count;
}
else if($button_pressed == "restock"){
    $sql = "UPDATE items SET stock = stock + $item_count WHERE name = '$item_name'";
    $connection->query($sql);
    echo "<br>".$item_name." has added into database by quantity ".$item_count;
}
else if($button_pressed == "show"){
    $sql = "SELECT * FROM items";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "item name: ".$row["name"]." item count: ".$row["stock"]."<br>";
        }
    } 
}
else if($button_pressed == "sales_log"){
    $sql = "SELECT * FROM order_log";
    $result = $connection->query($sql);
    if($result->num_rows > 0){
        while($row = $result->fetch_assoc()){
            echo "item name: ".$row["name"]." item count: ".$row["quantity"]."<br>";
        }
    } 
}

?>