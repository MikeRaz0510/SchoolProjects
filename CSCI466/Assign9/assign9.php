<?php
    echo "<html><head><title></title></head><body>";
    include("hiddeninfo.php");
	include("library.php");

    try 
    { // if something goes wrong, an exception is thrown
        //connect to database
		$dsn = "mysql:host=courses; dbname=z1696323";
        $pdo = new PDO($dsn, $username, $password);

		//run query
        $rs = $pdo->query("Select * FROM S;");
		$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
		
		//label and draw table
		echo "<h1> Suppliers Table </h1>" ;	
		draw_table($rows);

		//run querry
		$rs = $pdo->query("Select * FROM P;");
		$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
		
		//label and draw table
		echo "<h1> Products Table </h1>";
		draw_table($rows);
	
		//run query and label Form	
		$rs = $pdo->query("Select PName FROM P;");
		echo "<h1> Parts </h1>";

		//Form open 
		echo "<form action=\"PartInfo.php\" method=\"POST\">";
		
		//print out each part in the database
		foreach($rs as $row)
		{
			echo "<input type=\"radio\" name=\"Product\" value=". $row["PName"] . " />". $row["PName"] . "\n"; 	
		}

		//submit form
		echo "<input type=\"submit\"/>";
		echo "</form>";
	    
		//run query, label and open form
		$rs = $pdo->query("Select SName FROM S;");
		echo "<h1> Suppliers </h1>";
		echo "<form action=\"SupplierInfo.php\" method=\"POST\">";
		
		//print out wach supplier
		foreach($rs as $row)
		{
			echo "<input type=\"radio\" name=\"Supplier\" value=". $row["SName"] . " />". $row["SName"] . "\n"; 	
    	}

		//submit form
		echo "<input type=\"submit\"/>";
		echo "</form>";

		//run query, label and open form
		echo "<h1> Purchasing form </h1>";
		echo "<form action=\"Purchasing.php\" method=\"POST\">";
		$rs = $pdo->query("Select PName, P FROM P;");

		//print out all products
		foreach($rs as $row)
		{
			echo "<input type=\"radio\" name=\"Product\" value=". $row["P"] . " />". $row["PName"] . "\n"; 	
		}
		echo "<br/>";

		//run query to print out all suppliers
		$rs = $pdo->query("Select SName, S FROM S;");
		foreach($rs as $row)
		{
			echo "<input type=\"radio\" name=\"Supplier\" value=". $row["S"] . " />". $row["SName"] . "\n"; 	
    	}
		echo "<br/>";

		//prompt user for quanity of purchase, submit 
		echo "Quantity <input type=\"text\" name=\"Quantity\" value=\"0\"/> ";
		echo "<input type=\"submit\" value=\"Place Order\"/>";
		echo "</form>";

		//label new form
		echo "<h1> Add Part to database </h1>";
		echo "<form action=\"AddPart.php\" method=\"POST\">";
		
		//prompt user for each detail of a new part
		echo "Product Number <input type=\"text\" name=\"Number\"/> </br>";
		echo "Product Name <input type=\"text\" name=\"Name\"/> </br>";
		echo "Product Color <input type=\"text\" name=\"Color\"/> </br>";
		echo "Product Weight <input type=\"text\" name=\"Weight\"/> </br>";
		echo "<input type=\"submit\" value=\"Add Part\"/>";
		echo "</form>";

		//label and open form
		echo "<h1> Adjust Database info </h1>";
		echo "<form action=\"Adjust.php\" menthod=\"POST\">";

		//run query
		$rs = $pdo->query("Select PName FROM P;");
		echo "<h3> Select Part </h3>";
		
		//print out each part
		foreach($rs as $row)
		{
			echo "<input type=\"radio\" name=\"Product\" value=". $row["PName"] . " />". $row["PName"] . "\n"; 	
		}
		echo "<br/>";

		//run query and print out all suppliers
		$rs = $pdo->query("Select SName FROM S;");
		echo "<h3> Select Supplier </h3>";
		foreach($rs as $row)
		{
			echo "<input type=\"radio\" name=\"Supplier\" value=". $row["SName"] . " />". $row["SName"] . "\n"; 	
    	}
		echo "<br/>";

		//propt user for amount to add
		echo "<h3> Amount Available </h3>";
		echo "Quantity <input type=\"text\" name=\"Quantity\"/> ";
		echo "<input type=\"submit\" value=\"Place Order\"/>";
		echo "</form>";
	
	}

	catch(PDOexception $e) 
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();
    }


?>
</html>
