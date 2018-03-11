<?php
	require 'dbconfig/config.php';
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
		<form class="btns" action="adminlogin.php" method="post">
			<input type="button" id="home" value="Home"/>
			<input type="button" id="aboutus" value="About us"/>
			<input type="button" id="contactus" value="Contact us"/>
		</form>
	</div>
	<div id="choice-wrapper">
		<center><br><br><br><label style="color:#586ebc"><b><u>Admin Login</u></b></label><br>
		<form class="adminlog" action="adminlogin.php" method="post">
			<br><input name="ad_id" type="text" class="inputvalues" placeholder="Admin ID" required /><br>
			<input name="ad_psd" type="password" class="inputvalues" placeholder="Password" required /><br><br>
			<input name="login" type="button" id="login_btn" value="Login" /><br>
		</form>
		
		<?php
			if(isset($_POST['login']))
			{
				echo '<script type="text/javascript"> alert("Login button clicked") </script>';
				$userid=$_POST['ad_id'];
				$passwd=$_POST['ad_psd'];				
			}
		?>
		</center>
		
		
	</div>	
	
	<div id="footer">
	</div>
</body>
</html>
