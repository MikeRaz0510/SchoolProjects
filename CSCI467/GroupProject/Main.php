<html><head><title>Auto Parts</title></head><body>
 
<?php
    include("library.php");
    include("Styles.php");
    include("hiddeninfo.php");

    print_r($_POST);

?>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
<h1 style="text-align: center">Auto Parts</h1> <br>

<div class="btn-group" style="width:100%">


    <form action="customer.php" method='POST'>
        <button style="margin-right: 100px;" class="button1" type="Submit">Customer Interface</button>
    </form>

    <form action="admin.php" method='POST'>
        <button type="Submit" class="button3" style="margin-right: 100px;" >Admin Interface</button>
    </form>

    <form action="warehouse.php" method='POST'>
        <button type="Submit" class="button2" style="margin-right: 100px;" >Warehouse Interface</button>
    </form>

    

</div>


</body>
</html>