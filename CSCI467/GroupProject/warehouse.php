<html><head><title>Warehouse</title></head><body>
 
<?php
    include("library.php");
    include("Styles.php");
    include("hiddeninfo.php");
?>

<div class="btn-group">
    <form action="Main.php" method="POST">
        <button onclick="history.go(-1);" > Home </button>
    </form>
</div>

<br><br>
<h1 style="text-align: center">Auto Parts</h1> <br>

<div class="btn-group" style="width:100%">

    <form action="shipping.php" method='POST'>
        <button style="margin-right: 100px;" class="button1" type="Submit">Shipping Interface</button>
    </form>

    <form action="receiving.php" method='POST'>
        <button type="Submit" class="button3" style="margin-right: 10px;" >Receiving Interface</button>
    </form>

    

</div>



</body>
</html>