<?php

$connection = new mysqli("localhost", "root", "", "q3_251");

if ($connection->connect_error){
    die("Connection failed ". $connection->connect_error);
}

echo "<h3> Query 1 </h3> ";
$sql = "SELECT PerformanceRating, COUNT(*) as total_number FROM employee_final GROUP BY PerformanceRating";
$result = $connection->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "Rating: " . $row["PerformanceRating"] . "\tTotal Number: " . $row["total_number"] . "<br>";
    }
}
echo "<br>SELECT PerformanceRating, COUNT(*) as total_number FROM employee_final GROUP BY PerformanceRating <br><br>";

echo "<h3> Query 2 </h3> ";
$sql = "UPDATE employee_final SET PerformanceRating = 'C' WHERE salary < 40000 AND PerformanceRating NOT LIKE 'D'" ;
$connection->query($sql);
echo "Query: UPDATE employee_final SET PerformanceRating = 'C' WHERE salary < 40000 AND PerformanceRating NOT LIKE 'D' <br><br>";

echo "<h3> Query 3 </h3> ";
$sql = "UPDATE employee_final SET salary = salary + 5000 WHERE salary > 50000 AND (salary+5000 <= 60000)";
$result = $connection->query($sql);
echo "Query: UPDATE employee_final SET salary = salary + 5000 WHERE salary > 50000 AND (salary+5000 <= 60000) <br><br>";


echo "<h3> Query 4 </h3> ";
$sql = "SELECT DepartmentName, COUNT(EmployeeID) as total_emp FROM employee_final GROUP BY DepartmentName ORDER BY total_emp DESC";
$result = $connection->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "Department Name: " . $row["DepartmentName"] ." \tTotal Employee: " . $row["total_emp"] . "<br>";
    }
}
echo "<br>Query: SELECT DepartmentName, COUNT(EmployeeID) as total_emp FROM employee_final GROUP BY DepartmentName ORDER BY total_emp DESC)";

?>