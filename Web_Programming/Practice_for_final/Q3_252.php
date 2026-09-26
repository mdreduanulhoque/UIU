<?php

$connection = new mysqli("localhost", "root", "", "q3_252");

if ($connection->connect_error){
    die("Connection failed ". $connection->connect_error);
}

echo "<h3> Query 1 </h3> ";
$sql = "SELECT CategoryName, SUM(revenue) as total_revenue FROM sales_data GROUP BY CategoryName";
$result = $connection->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "Category: " . $row["CategoryName"] . "\tTotal Revenue: " . $row["total_revenue"] . "<br>";
    }
}
echo "<br>Query: SELECT CategoryName, SUM(revenue) as total_revenue FROM sales_data GROUP BY CategoryName <br><br>";

echo "<h3> Query 2 </h3> ";
$sql = "UPDATE sales_data SET CategoryName = 'Low Performing' WHERE revenue < 40000" ;
$connection->query($sql);
echo "Query: UPDATE sales_data SET CategoryName = 'Low Performing' WHERE revenue < 40000 <br><br>";

echo "<h3> Query 3 </h3> ";
$sql = "UPDATE sales_data SET revenue = revenue + (revenue* 0.1) WHERE revenue > 70000";
$result = $connection->query($sql);
echo "Query: UPDATE sales_data SET revenue = revenue + (revenue* 0.1) WHERE revenue > 70000 <br><br>";


echo "<h3> Query 4 </h3> ";
$sql1 = "ALTER TABLE sales_data ADD COLUMN label TEXT DEFAULT 'Regular Seller'";
$connection->query($sql1);
$sql = "UPDATE sales_data SET label = 'Top Seller' WHERE revenue > (SELECT AVG(revenue) FROM sales_data WHERE CategoryName = sales_data.CategoryName)";
$connection->query($sql);
$sql2 = "SELECT ProductName, CategoryName, label FROM sales_data";
$result = $connection->query($sql2);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "Product Name: " . $row["ProductName"] ." \tCategory: " . $row["CategoryName"] . "\tLabel: " . $row["label"] . "<br>";
    }
}
echo "<br>Query: ALTER TABLE sales_data ADD COLUMN label TEXT DEFAULT 'Regular Seller' <br>UPDATE sales_data SET label = 'Top Seller' WHERE revenue > (SELECT AVG(revenue) FROM sales_data WHERE CategoryName = sales_data.CategoryName)<br>SELECT ProductName, CategoryName, label FROM sales_data";

?>