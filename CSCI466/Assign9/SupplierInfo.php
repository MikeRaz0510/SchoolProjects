<?php

    include("hiddeninfo.php");
    include("library.php");

    try 
    { // if something goes wrong, an exception is thrown
        $dsn = "mysql:host=courses; dbname=z1696323";
        $pdo = new PDO($dsn, $username, $password);

        $SName = $_POST["Supplier"];

        $sql = "SELECT S.S, SName, STATUS, CITY, P.P, PName, Quantity FROM S, P, SP WHERE S.S = SP.S AND P.P = SP.P AND SName = :SName";
        $prepared = $pdo->prepare($sql);
        $success = $prepared->execute(array(':SName' => $SName));

        if ($success == TRUE)
        {
            $rows = $prepared->fetchAll(PDO::FETCH_ASSOC);

            if (!empty($rows))
            {
                draw_table($rows);
            }
            else
            {
                echo "This supplier currently has no parts available.";
            }
        }

    }

    catch(PDOexception $e) 
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();  
    }
?>