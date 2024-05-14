<html><head><title>Shipping and Handling</title></head><body>
 
<?php
    include("library.php");
    include("Styles.php");
    include("hiddeninfo.php");
?>

<div class="btn-group">
    <form action="Main.php" method="POST">
        <button onclick="history.go(-1);" > Home </button>
    </form>

    <form action="edit.php" method='POST'>
        <button style="margin-right: 100px;" class="button1" type="Submit">Edit</button>
    </form>

</div>

<br><br>
<h1 style="text-align: center">Shipping and Handling</h1> <br>



<?php
    $servername = "courses"; 
    $dbname = "z1831762"; 

    // Database connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if (isset($_POST['MinWeight1']))
    {
        $sql = "UPDATE SHIPPING
                SET MinWeight = " . $_POST['MinWeight1'] . ",
                MaxWeight = " . $_POST['MaxWeight1'] . ",
                Price = " . $_POST['Price1'] . "
                WHERE BracketNum = 1;";

    $statement = $pdo->prepare($sql);
    $statement->execute();
    
    }

    if (isset($_POST['MinWeight2']))
    {
        $sql = "UPDATE SHIPPING
                SET MinWeight = " . $_POST['MinWeight2'] . ",
                MaxWeight = " . $_POST['MaxWeight2'] . ",
                Price = " . $_POST['Price2'] . "
                WHERE BracketNum = 2;";

    $statement = $pdo->prepare($sql);
    $statement->execute();
    }

 if (isset($_POST['MinWeight3']))
    {
        $sql = "UPDATE SHIPPING
                SET MinWeight = " . $_POST['MinWeight3'] . ",
                MaxWeight = " . $_POST['MaxWeight3'] . ",
                Price = " . $_POST['Price3'] . "
                WHERE BracketNum = 3;";

    $statement = $pdo->prepare($sql);
    $statement->execute();

    }
    
    $sql = "SELECT * FROM SHIPPING";

    $statement = $pdo->prepare($sql);
    $statement->execute();
    $rows = $statement->fetchAll(PDO::FETCH_ASSOC);

    draw_table($rows);

?>



</body>
</html>