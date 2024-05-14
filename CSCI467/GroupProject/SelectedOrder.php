<html><head><title>OrderInfo</title></head><body>
 
<?php
    session_start();
    include("library467.php");
    include("Styles.php");
    include("hiddeninfo.php");
?>

<div class="btn-group">
    <form action="Main.php" method="POST">
        <button onclick="history.go(-1);" > Home </button>
    </form>
</div>

<br><br>

<div class="btn-group">
    <form action="search.php" method="POST">
        <button onclick="history.go(-1);" > Search Orders </button>
    </form>
</div>

<br><br>
<h1 style="text-align: center">Order Info</h1> <br>

<?php
        $servername = "courses"; 
        $dbname = "z1831762"; 
    
        // Database connection
        $conn = new mysqli($servername, $username, $password, $dbname);
    
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

    $sql = "SELECT ORDERS.*, PART.PartName, PART.PartNum, Description, Weight, Price, Quantity 
            FROM PART, ORDERS, PARTSORDERED
            WHERE PART.PartNum = PARTSORDERED.PartNum
            AND ORDERS.OrderNum = PARTSORDERED.OrderNum
            AND ORDERS.OrderNUM = ";

    $sql .= $_POST["OrderNum"] . ';';

    $statement = $pdo->prepare($sql);
    $statement->execute();
    $rows = $statement->fetchAll(PDO::FETCH_ASSOC);

    draw_table($rows);
?>
<div class="btn-group" style="width:100%">
  

</div>



</body>
</html>