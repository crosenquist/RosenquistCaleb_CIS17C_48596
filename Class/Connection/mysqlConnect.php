<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Connect</title>
</head>

<body>
	<?php
	mysql_connect('localhost','root');
	mysql_select_db('test');
	$query="SELECT * FROM entity_assignments";
	$rs=mysql_query($query) or die(mysql_error());
	echo "<table border='1'><tr>";
	echo "<th>name</th>";
	echo "<th>points_possible</th>";
	echo "<th>weight</th>";
	echo "<th>description</th>";
	echo "</tr>";
	while($record=mysql_fetch_array($rs)){
		echo "<tr>";
		echo "<td>".$record['name']."</td>";
		echo "<td>".$record['points_possible']."</td>";
		echo "<td>".$record['weight']."</td>";
		echo "<td>".$record['description']."</td>";
	}
	echo "</table>";
	?>
</body>
</html>