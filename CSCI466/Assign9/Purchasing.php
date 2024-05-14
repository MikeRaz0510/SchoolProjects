<?php

    include("hiddeninfo.php");
    include("library.php");

    try 
    { // if something goes wrong, an exception is thrown
        $dsn = "mysql:host=courses; dbname=z1696323";
        $pdo = new PDO($dsn, $username, $password);

        $Quantity = $_POST["Quantity"];
        $SName = $_POST["Supplier"];
        $PName = $_POST["Product"];

        $sql = "SELECT *  FROM SP WHERE S = :S AND P = :P";
        $prepared = $pdo->prepare($sql);
        $success = $prepared->execute(array(':S' => $SName, ':P' => $PName));
        
        if ($success == TRUE)
        {
            $rows = $prepared->fetchAll(PDO::FETCH_ASSOC);

            foreach($rows as $row)
            {
                $total = $row['QUANTITY'];
            }
            $newTotal = $total - $Quantity;

            echo "This supplier had " . $total . " of the selected part available and now has " . $newTotal; 

            draw_table($rows);
        }
        $sql2 = "UPDATE SP SET QUANTITY = :QUANTITY WHERE S = :S AND P = :P ";
        $prepared = $pdo->prepare($sql2);
        $success = $prepared->execute(array(':QUANTITY' => $newTotal, ':S' => $SName, ':P' => $PName));

        $prepared = $pdo->prepare($sql);
        $success = $prepared->execute(array(':S' => $SName, ':P' => $PName));

        if ($success == TRUE)
        {
            echo "Purchase Recieved: Database updated";
            $rows = $prepared->fetchAll(PDO::FETCH_ASSOC);
            draw_table($rows);
        }

    }


    catch(PDOexception $e) 
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();  
    }
?>