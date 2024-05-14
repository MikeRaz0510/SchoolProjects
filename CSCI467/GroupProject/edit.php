<html><head><title>Edit Shipping</title></head><body>
 
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
<h1 style="text-align: center">Edit Shipping Costs</h1> <br>

<form action="sandh.php" method='POST'>
    <label for="Bracket"><b>Bracket 1: Size Small<pre>&#9</pre></b></label>

    <input type="text" placeholder="Enter Minimum Weight" name="MinWeight1" required>

    <input type="text" placeholder="Enter Maximum Weight" name="MaxWeight1" required>

    <input type="text" placeholder="Enter Price" name="Price1" required>

    <br><br>

    <label for="Bracket"><b>Bracket 2: Size Medium<pre>&#9</pre></b></label>

    <input type="text" placeholder="Enter Minimum Weight" name="MinWeight2" required>

    <input type="text" placeholder="Enter Maximum Weight" name="MaxWeight2" required>

    <input type="text" placeholder="Enter Price" name="Price2" required>

    <br><br>

    <label for="Bracket"><b>Bracket 3: Size Large<pre>&#9</pre></b></label>

    <input type="text" placeholder="Enter Minimum Weight" name="MinWeight3" required>

    <input type="text" placeholder="Enter Maximum Weight" name="MaxWeight3" required>

    <input type="text" placeholder="Enter Price" name="Price3" required>

    <br><br>
    
    <button onclick="myalert()">Edit Bracket Info</button>
</form>

<script>
    function myalert() {
        if(alert("Bracket Info Updated")){

        }
    }
</script>

</body>
</html>