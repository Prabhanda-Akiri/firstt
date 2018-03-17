<?php
	session_start();
	require 'dbconfig/pconfig.php';
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
		<center><br><br><br><label style="color:#586ebc;font-size:25px;"><b><u>Parent Login</u></b></label><br>
		<form class="adminlog" action="parentlogin.php" method="post">
			<br><input name="userid" type="text" class="inputvalues" placeholder="Parent ID" required /><br>
			<input name="passwd" type="password" class="inputvalues" placeholder="Password" required /><br><br>
			<input name="login" type="submit" id="login_btn" value="Login" /><br>
		</form>
		
		<?php
			if(isset($_POST['login']))
			{
				//echo '<script type="text/javascript" > alert("Login button clicked") </script>';
				$userid=$_POST['userid'];
				$passwd=$_POST['passwd'];	
				
				$query="select * from login WHERE username='$userid' and password='$passwd'";
				$query_run=mysqli_query($con,$query);
				
				if(mysqli_num_rows($query_run)>0)
				{
					$_SESSION['id']=$userid;
					header("location:parent_viewnotices.php");
		
				}
				
				else
				{
					echo '<script type="text/javascript" > alert("Invalid username or password") </script>';
				}
			}
			
		?>
		</center>
</body>
</html>