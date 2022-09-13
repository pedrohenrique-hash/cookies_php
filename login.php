<?php
$email_user = $_POST['email_user'];

$password_user= $_POST['password_user'];

include"include/Connection_mysql.inc";

$email_user = $connect->real_escape_string($email_user);

$password_user= $connect -> real_escape_string($password_user);

$result = $connect-> query("SELECT * FROM data_user WHERE  email_user = '$email_user'");

$line = $result-> num_rows;

if($line == 0 ){
	
	echo"<html><<body>";
	echo"<p align \"center\"> A senha está incorreta!</p>";
	echo"<p align = \"center\"> <a href \"login.html\"> Volta</p>";
	echo "</body> </html>";
}
else{
	setcookie("email_user", $email_user);
	setcookie("password_user",$password_user);
	header("Location: pagina_inicial.php");
}

?>