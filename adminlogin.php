<?php

?>
<!DOCTYPE html>
<html>
<head>
<title>Student Academic Profile Management System</title>
<link rel="stylesheet" href="css/style.css">
</head>

<body style="background-color:#f8c291">
	<div id="main-wrapper">
		<img src="imgs/students.jpg" class="studpic"/>
		<center><h1>STUDENT PROFILE MANAGEMENT SYSTEM</h1></center>
		
	</div>
	
	<div id="button-wrapper">
		<form class="btns" action="index.php" method="post">
			<input type="button" id="home" value="Home"/>
			<input type="button" id="aboutus" value="About us"/>
			<input type="button" id="contactus" value="Contact us"/>
		</form>
	</div>
	<div id="choice-wrapper">
		<center><br><br><br><label style="color:#586ebc"><b><u>Admin Login</u></b></label><br>
		<form class="adminlog" action="adminlogin.php" method="post">
			<br><input type="text" class="inputvalues" placeholder="Admin ID" style="text-align:centre"/><br>
			<input type="password" class="inputvalues" placeholder="Password" style="text-align:centre"/><br><br>
		</form>
		</center>
	</div>	
	
	<div id="footer">
	</div>
</body>
</html>
