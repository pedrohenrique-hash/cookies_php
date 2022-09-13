<?php
	if(IsSet($_COOKIE['email_user'])){
		
		$email_user= $_COOKIE['email_user'];
	}

	if(IsSet($_COOKIE['password_user'])){
		
		$password_user = $_COOKIE['password_user'];
	}

	if(!(empty($email_user) OR empty($password_user))){
		
		include"include/Connection_mysql.inc";

		$email_user = $connect-> real_escape_string($email_user);

		$password_user = $connect -> real_escape_string($password_user);

	

	$result = $connect -> query("SELECT * FROM data_user WHERE email_user = '$email_user' AND
	password_user = '$password_user'");

	if($result -> num_rows == 0){
		
		setcookie("email_user");
		
		setcookie("password_user");

		echo "Você não efetou o login!";

		exit();
	}
}

else{
	echo"Você não efetou o <a href = 'login.html'>login</a>!";
	exit();
}
$connect ->close();
?>