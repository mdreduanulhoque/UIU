<?php

$connection = new mysqli("localhost", "root", "", "q3_243");

if ($connection->connect_error){
    die("Connection failed ". $connection->connect_error);
}

echo "<h3> Query 1 </h3> ";
$sql = "SELECT LetterGrade, COUNT(*) as total_number FROM student_final GROUP BY LetterGrade";
$result = $connection->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "Grade: " . $row["LetterGrade"] . "\tTotal Number: " . $row["total_number"] . "<br>";
    }
}
echo "<br>SELECT LetterGrade, COUNT(*) as total_number FROM student_final GROUP BY LetterGrade <br><br>";

echo "<h3> Query 2 </h3> ";
$sql = "UPDATE student_final SET LetterGrade = 'C' WHERE Grade < 75 AND LetterGrade NOT LIKE 'D'" ;
$connection->query($sql);
echo "Query: UPDATE student_final SET LetterGrade = 'C' WHERE Grade < 75 AND LetterGrade NOT LIKE 'D' <br><br>";

echo "<h3> Query 3 </h3> ";
$sql = "UPDATE student_final SET Grade = Grade + 5 WHERE Grade > 80 AND (Grade + 5 <= 90)";
$result = $connection->query($sql);
echo "Query: UPDATE student_final SET Grade = Grade + 5 WHERE Grade > 80 AND (Grde + 5 <= 90) <br><br>";


echo "<h3> Query 4 </h3> ";
$sql = "SELECT CourseTitle, COUNT(StudentID) as total_std FROM student_final GROUP BY CourseTitle ORDER BY total_std DESC";
$result = $connection->query($sql);
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "Course Title: " . $row["CourseTitle"] ." \tTotal student: " . $row["total_std"] . "<br>";
    }
}
echo "<br>Query: SELECT CourseTitle, COUNT(StudentID) as total_std FROM student_final GROUP BY CourseTitle ORDER BY total_std DESC";

?>