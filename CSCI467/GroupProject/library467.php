<body>

<?php
//database

include("hiddeninfo.php");

//connect or print error
$dsn = "mysql:host=courses; dbname=z1696323";
$options = [
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_EMULATE_PREPARES   => false,
];

function draw_table($rows)
	{
		echo "<table border=1 cellspacing=1>";
	
		foreach($rows[0] as $key => $item)
		{
			echo "<th>$key</th>";
		}
	
		foreach($rows as $row)
		{
			echo "<tr>";
            foreach($row as $item)
            {
			    echo "<td>". $item . "</td>";
            }
            echo "<tr>";
		}
	
		echo "</table>"; 
	}

  function drawOrderTable($rows)
{
  echo "<table id='Orders' border=2 cellspacing=3 style='width:20%'>";
  echo "<colgroup> <col span='20' style='background-color:white'> </colgroup>";
  echo "<tr>";
  foreach($rows[0] as $Key => $item )
    {
    echo "<td> <form action=\"search.php\" method='GET'><input type=\"Submit\" name=\"sort\" value=\"$Key\"\></form></td>";
  }

  echo "</tr>";
  foreach($rows as $row)
    {
    echo "<tr>";
    foreach($row as $col) 
        {
      echo "<td>$col</td>";
    }
    echo "</tr>";
  }
  echo " </tr>";
  echo "</table>";
}
?>

  </body>
</html>