<?php
/**
 * Created by PhpStorm.
 * User: geniusrabbit
 * Date: 18-1-3
 * Time: 下午11:41
 */


$servername = "localhost";
$username = "root";
$password = "*****";

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

$sql = "CREATE TABLE  IF NOT EXISTS ACC_Password(
    account    TEXT(50) NOT NULL,
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

if($acc==NULL){
    echo "<p style='color: red'>用户名不能为空,正在跳转。。。</p>";
    header("refresh:1.5;url=logup.html");
    exit;
}

$result=mysqli_query($conn,"SELECT * FROM ACC_Password WHERE account='$acc'");
$row=mysqli_fetch_array($result);

if($row['account'] !=NULL){
    echo "<p style='color: red'>用户名已经存在,正在跳转。。。</p>";
    header("refresh:1.5;url=logup.html");
    exit;
}

$sql = "INSERT INTO ACC_Password(account,password)VALUES ('$acc','$pas')";

if ($conn->query($sql) === TRUE) {
    echo "<p style='color: green'>注册成功,正在跳转。。。</p>";
    header("refresh:0.5;url=login.html");

} else {
    echo "Error: " . $sql . "<br>" . $conn->error."\n";
}

$conn->close();


?>
