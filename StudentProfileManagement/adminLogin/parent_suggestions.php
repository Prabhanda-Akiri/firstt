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
	
	<div id="admin-button-wrapper">
		<form class="ad_btns" action="parent_suggestions.php" >
			<a href="parent_viewnotices.php"><input type="button" id="add_teacher" value="View Notices/Events"/></a>
			<a href="parent_complaints.php"><input type="button" id="add_course" value="View Complaints"/></a>
			<a href="parent_suggestions.php"><input type="button" id="add_course" value="Give Suggestions"/></a>
			<div class="details" action="parent_complaints.php">
			<button class="details-btns">Give Feedback</button>
			<div class="details-content" >
			<a href="parent_sf.php">About Student</a><br>
			<a href="parent_tf.php">About Teacher</a>
			</div>
			</div>
			<div class="reports" action="parent_complaints.php">
			<button class="report-btns">View Student Report</button>
			<div class="report-content" >
			<a href="parent_atr.php">Attendance Report</a><br>
			<a href="parent_gr.php">Grades Report</a>
			</div>
			</div>
			<a href="index.php"><input type="button" id="add_teacher" value="Log Out"/></a>
		</form>
	</div>
	
	<div id="add_t" style="text-align:left;">
		<label style="font-size:20px;margin-left:350px;"><br><br><b><u>Enter your suggestions below:-</u></b></label><br>
				<label><label><br>
				<form method="post">
				<textarea name="suggest" cols="100" rows="10" placeholder="Give Suggestions to Admin about this Student Profile Management here..."  required ></textarea><br><br>
				
				<center><input name="submit_bt" type="submit" id="submit_btn" value="Submit"/></center>
				</form>
				<?php
					
					if(isset($_POST['submit_bt']))
					{
						$suggestion=$_POST['suggest'];
						$username=$_SESSION['id'];
						
						
						$query = "INSERT INTO suggestions VALUES('".$username."','".$suggestion."')";

						$query_run = mysqli_query($con,$query);
						
						if($query_run)
							echo '<script type="text/javascript"> alert("Your suggestion is taken") </script>';
						else
							echo '<script type="text/javascript"> alert("Error!") </script>';
					}
					?>
		
	</div>	
	
	<div id="footer">
	</div>
</body>
</html>
