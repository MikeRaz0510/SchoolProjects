<html><head><title>Order Search</title></head><body>
 
<?php
    session_start();
    include("library467.php");
    include("Styles.php");
    include("hiddeninfo.php");

    if (!isset($_SESSION['count'])) 
    {
        $_SESSION['count'] = 0;
    } 
    else 
    {
        $_SESSION['count']++;
    }
?>

<div class="btn-group">
    <form action="Main.php" method="POST">
        <button onclick="history.go(-1);" > Home </button>
    </form>
</div>

<br><br>
<h1 style="text-align: center">Order Search</h1> <br>


<?php
    $servername = "courses"; 
    $dbname = "z1831762"; 

    // Database connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT * FROM ORDERS";

    echo "<form action='SelectedOrder.php' method='POST'>";
    echo "<label for='OrderNum'><b> Select Order </b></label><br>";
    echo "<input type='text' placeholder='Enter Order Num' name='OrderNum'><br>";
    echo "<input type='Submit'></form>";
    echo "<br><br>";

    if(isset($_GET["sort"]))
    {
        $cat = $_GET["sort"];

        $order = ($_SESSION['count'] % 2 == 0) ? "ASC" : "DESC";

        Switch($cat)
        {
            case "OrderNum":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY OrderNum ";
            }break;
            case "CustName":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY CustName ";
            }break;
            case "OrderDate":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY OrderDate ";
            }break;
            case "OrderSubTotal":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY OrderSubTotal ";
            }break;
            case "Status":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY Status ";
            }break;
            case "Email":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY Email ";
            }break;
            case "PhoneNum":
            {
                $sql = "SELECT * 
                        FROM ORDERS
                        Order BY PhoneNum ";
            }break;
            default:
            {
                $sql = "SELECT * 
                        FROM ORDERS";
            }
        }
        $sql .= $order . ';';
    
    }

    $statement = $pdo->prepare($sql);
    $statement->execute();
    $rows = $statement->fetchAll(PDO::FETCH_ASSOC);

    drawOrderTable($rows);
?>

<div class="btn-group" style="width:100%">
  

</div>



</body>
</html>