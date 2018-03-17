<?php
	
	require 'dbconfig/pconfig.php';
?>
<!DOCTYPE html>
<html>
<head>
<title>Student Academic Profile Management System</title>
<link rel="stylesheet" href="css/style.css">
</head>

<body style="background-image:url('imgs/board.jpg');background-color:#f8c291;background-size:100%;">
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
	
	<div id="add_t">
		<center><label style="color:#586ebc;font-size:24px;"><br><br><b><u>Notices and Events</b></u></label><br></center>
				<label><label><br>
			
				
				<?php
					echo '<table>
					<thead>
					<tr>
					<th style="background-color:#7f8c8d;color:black;width:170px;height:30px;"><b>DATE</b></th>
					<th style="background-color:#7f8c8d;color:black;width:590px;height:30px;"><b>Notices/Events</b></th>
					</tr>
					</thead>
					<tbody>
					';
					
					$query="SELECT * FROM notices";
					if($is_query_run=mysqli_query($con,$query))
					{
						while($query_executed=mysqli_fetch_assoc($is_query_run))
						{
							echo '<tr>
							<td style="background-color:#d35400;color:white;width:170px;height:30px;">'.$query_executed['date'].'</td>
							<td style="background-color:#d35400;color:white;width:590px;height:30px;">'.$query_executed['notice'].'</td>
							</tr>
							';
						}
						
						echo '
						</tbody>
						</table>';
					}
					else
						echo " Error in Execution";
					
				?>
				
				
				<br>
				<br><br>
				<br>
				<br>
				
		
	</div>	
	
	<div id="footer">
	</div>
</body>
</html>
