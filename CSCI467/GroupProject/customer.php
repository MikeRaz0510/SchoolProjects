<html><head><title>Customer</title></head><body>
 
<?php
    include("Styles.php");
    include("hiddeninfo.php");

    $mysqli = new mysqli("localhost", "root", "fC^zHbT8W7xLY^Hp&N", "test");
    $results = $mysqli->query("SELECT * FROM Part");
?>

<div class="btn-group">
    <form action="Main.php" method="POST">
        <button onclick="history.go(-1);" > Home </button>
    </form>
</div>

<br><br>
<h1 style="text-align: center">Customer</h1> <br>

<?php

    echo "<div class='catalog' style='max-width: 1200px;margin-top:125px;'>";

    while($part_row = mysqli_fetch_row($results)){
        if(($part_row[0] % 4) == 1){
            echo "<div class='row-padding center' id='part'>
                    <div class='quarter'>
                        <img src='".($part_row[3])."' class='part'>
                        <div class='first-info-line'>
                            <span class='price'>$"
                                .$part_row[5]."
                            </span> Quantity Available: "
                                .$part_row[6]."
                        </div>
                        <p style = 'text-align: left;'>
                            <span class='part-name'>"
                                .$part_row[1]."
                            </span> "
                                .$part_row[2]."
                        </p>
                        <div class='part-weight-number'>Weight: "
                            .$part_row[4]."
                        </div>
                        <div class='part-weight-number'>Part Number: "
                            .$part_row[0]."
                        </div>
                        <button class='addtocart'>
                            <div class='pretext'>ADD TO CART</div>
                        </button>
                        <input class='part-input' type= 'number' min='0' step='1' value='0'>
                        </input>
                    </div>";
        }elseif(($part_row[0] % 4) == 0){
            echo "<div class='quarter'>
                    <img src='".($part_row[3])."' class='part'>
                    <div class='first-info-line'>
                        <span class='price'>$"
                            .$part_row[5]."
                        </span> Quantity Available: "
                            .$part_row[6]."
                    </div>
                    <p style = 'text-align: left;'>
                        <span class='part-name'>"
                            .$part_row[1]."
                        </span> "
                            .$part_row[2]."
                    </p>
                    <div class='part-weight-number'>Weight: "
                        .$part_row[4]."
                    </div>
                    <div class='part-weight-number'>Part Number: "
                        .$part_row[0]."
                    </div>
                    <button class='addtocart'>
                        <div class='pretext'>ADD TO CART</div>
                    </button>
                    <input class='part-input' type= 'number' min='0' step='1' value='0'>
                    </input>
                </div>
                </div>";
        }else{
            echo "<div class='quarter'>
                    <img src='".($part_row[3])."' class='part'>
                    <div class='first-info-line'>
                        <span class='price'>$"
                            .$part_row[5]."
                        </span> Quantity Available: "
                            .$part_row[6]."
                    </div>
                    <p style = 'text-align: left;'>
                        <span class='part-name'>"
                            .$part_row[1]
                        ."</span> "
                        .$part_row[2]."
                    </p>
                    <div class='part-weight-number'>Weight: "
                        .$part_row[4]."
                    </div>
                    <div class='part-weight-number'>Part Number: "
                        .$part_row[0]."
                    </div>
                    <button class='addtocart'>
                        <div class='pretext'>ADD TO CART</div>
                    </button>
                    <input class='part-input' type= 'number' min='0' step='1' value='0'>
                    </input>
                </div>";            
        }
    }

    echo "</div>"

?>

</body>
</html>
