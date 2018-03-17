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
		<form class="ad_btns" action="parent_tf.php" method="post">
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
			<center><label style="color:#586ebc;font-size:24px;"><br><br><b><u>Teacher Feedback</b></u></label><br></center>
			<form method="post">
			<br><br><label style="font-size:18px;margin-left:180px;">Teacher Name:</label>
				<input name="teachname" type="text" class="inputdetails" style="margin-left:110px;" required /><br>
				<label style="font-size:18px;margin-left:180px;">Course Name:</label>
				<input name="course" type="text" class="inputdetails" style="margin-left:115px;" required /><br>
				<label style="font-size:18px;margin-left:50px;"><br><br><b><u>Enter the feedback below:-</u></b></label><br>
				<label><label><br>
				<textarea name="feedback" cols="100" rows="10" placeholder="Give Feedback about Teacher to Admin here..."  required></textarea><br><br>
				
				<center><input name="submit_bt" type="submit" id="submit_btn" value="Submit"/></center>
				</form>
				<?php
					if(isset($_POST['submit_bt']))
					{
						$teachname=$_POST['teachname'];
						$feedback=$_POST['feedback'];
						$username=$_SESSION['id'];
						$course=$_POST['course'];
						
						$query = "INSERT INTO teacher_feedback VALUES('".$username."','".$teachname."','".$course."','".$feedback."')";

						$query_run = mysqli_query($con,$query);
						
						if($query_run)
							echo '<script type="text/javascript"> alert("Your feedback is taken") </script>';
						else
							echo '<script type="text/javascript"> alert("Error!") </script>';
					}
					
					?>
				
				
		
	</div>	
	
	<div id="footer">
	</div>
</body>
</html>
