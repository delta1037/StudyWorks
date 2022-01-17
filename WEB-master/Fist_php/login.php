<?php
$servername = "localhost";
$username = "root";
$password = "5258wawj";

$conn = new mysqli($servername,$username,$password);

if($conn->connect_error){
    die("连接失败：".$conn->connect_error);
}
else{
    echo "\n";
}

$sql = "CREATE DATABASE IF NOT EXISTS AccountDB";

if ($conn->query($sql) === TRUE) {
    echo "\n";
}else{
    echo "创建数据库失败: " . $conn->error."\n";
}

$sql = "USE AccountDB;";

if ($conn->query($sql) === TRUE) {
    echo "\n";
}else{
    echo "数据库使用失败: " . $conn->error."\n";
}

$sql = "CREATE TABLE  IF NOT EXISTS Id_Password(
    id       VARCHAR(30) NOT NULL,
    password VARCHAR(128) NOT NULL
);";

if ($conn->query($sql) === TRUE) {
    echo "\n";
} else {
    echo "创建数据表错误: " . $conn->error."\n";
}

$acc = $_POST["account"];
$pas = $_POST["password"];
$pas = md5($pas);

$sql = "INSERT INTO Id_Password (id,password)
VALUES ('$acc','$pas')";

if ($conn->query($sql) === TRUE) {
    echo "记录插入成功\n";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error."\n";
}

$conn->close();


?>