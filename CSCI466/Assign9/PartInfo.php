<?php

    include("hiddeninfo.php");
    include("library.php");

    try 
    { // if something goes wrong, an exception is thrown
        $dsn = "mysql:host=courses; dbname=z1696323";
        $pdo = new PDO($dsn, $username, $password);

        $PName = $_POST["Product"];

        $sql = "SELECT S.S, SName, P.P, PName, Quantity FROM S, P, SP WHERE S.S = SP.S AND P.P = SP.P AND PName =:PName";
        $prepared = $pdo->prepare($sql);
        $success = $prepared->execute(array(':PName' => $PName));

        if ($success == TRUE)
        {
            $rows = $prepared->fetchAll(PDO::FETCH_ASSOC);

            draw_table($rows);
        }
    }


    catch(PDOexception $e) 
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();  
    }
?>