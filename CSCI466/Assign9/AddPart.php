<?php

    include("hiddeninfo.php");
    include("library.php");

    try 
    { // if something goes wrong, an exception is thrown
        $dsn = "mysql:host=courses; dbname=z1696323";
        $pdo = new PDO($dsn, $username, $password);

        $P = $_POST["Number"];
        $PName = $_POST["Name"];
        $Color = $_POST["Color"];
        $Weight = $_POST["Weight"];

        //echo $P . $PName . $Color . $Weight;

        //print_r($_POST);

        $sql = "INSERT INTO P VALUES (\':P\', \':PName\', \':COLOR\', \':WEIGHT\')";
        $prepared = $pdo->prepare($sql);
        $success = $prepared->execute(array(':P' => $P, ':PName' => $PName, ':COLOR' => $Color, ':WEIGHT' => $Weight));

        if($success = TRUE)
        {
            echo "Part Added";
        }

        $sql2 = "SELECT * FROM P";
        $rs = $pdo->query($sql2);
		$rows = $rs->fetchAll(PDO::FETCH_ASSOC);
        draw_table($rows);

    }


    catch(PDOexception $e) 
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();  
    }
?>