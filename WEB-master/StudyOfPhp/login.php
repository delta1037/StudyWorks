<?php
/**
 * Created by PhpStorm.
 * User: geniusrabbit
 * Date: 18-1-3
 * Time: 下午9:15
 */


$servername = "localhost";
$username = "root";
$password = "*****";
$IP ="39.108.124.169";

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

$acc = $_POST["account"];
$pas = $_POST["password"];
$pas = md5($pas);

if($acc==NULL){
    echo "<p style='color: red'>用户名不能为空,正在跳转。。。</p>";
    header("refresh:1.5;url=login.html");
    exit;
}

$result=mysqli_query($conn,"SELECT * FROM ACC_Password WHERE account='$acc'");
$row=mysqli_fetch_array($result);

if($row['password']!=$pas){
    echo "<p style='color: red'>密码错误,正在跳转</p>";
    header("refresh:0.5;url=login.html");
}
else{
    echo "<p style='color: green'>登录成功,正在跳转。。。</p>";
    header("refresh:1;url=SUM/HOME.html");
    exit;
}

$conn->close();
