<?php

    include("hiddeninfo.php");
    include("library.php");

    try 
    { // if something goes wrong, an exception is thrown
        $dsn = "mysql:host=courses; dbname=z1696323";
        $pdo = new PDO($dsn, $username, $password);

    }


    catch(PDOexception $e) 
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();  
    }
?>