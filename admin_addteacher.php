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
	
	<div id="admin-button-wrapper">
		<form class="ad_btns" action="admin_addteacher.php" method="post">
			<input type="button" id="add_teacher" value="Add Teacher"/>
			<input type="button" id="add_course" value="Add Course"/>
			<input type="button" id="add_student" value="Add Student"/>
			<div class="details" action="admin_addteacher.php">
			<button class="details-btns">View/Edit Details</button>
			<div class="details-content" >
			<a href="#">Student details</a><br>
			<a href="#">Teacher details</a><br>
			<a href="#">Course details</a>
			</div>
			</div>
			<div class="reports" action="admin_addteacher.php">
			<button class="report-btns">Reports</button>
			<div class="report-content" >
			<a href="#">View Attendance Report</a><br>
			<a href="#">View Grades Report</a>
			</div>
			</div>
			<input type="button" id="view_feedback" value="View Feedback"/>
		</form>
	</div>
	<div id="add_t">
		<center><label style="color:#586ebc;font-size:24px;"><br><br><b><u>ADD TEACHER</b></u></label><br></center>
				<label><label><br>
				<b><label style="font-size:18px;margin-left:180px;">Full Name:</label>
				<input type="text" class="inputdetails" style="margin-left:115px;"/><br>
				<label style="font-size:18px;margin-left:180px;">Mobile No:</label>
				<input type="text" class="inputdetails" style="margin-left:115px;" /><br>
				<label style="font-size:18px;margin-left:180px;">Email ID:</label>
				<input type="text" class="inputdetails" style="margin-left:125px;" /><br>
				<label style="font-size:18px;margin-left:180px;">Highest Qualification:</label>
				<input type="text" class="inputdetails" style="margin-left:30px;"/><br><br></b>
				
				<center><input type="submit" id="submit" value="Submit"/></center><br>
		
	</div>	
	
	<div id="footer">
	</div>
</body>
</html>
