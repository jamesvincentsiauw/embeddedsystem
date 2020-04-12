<?php
    // Vincent 18217042 untuk keperluan sensor HC-SR04

    function OpenCon()
    {
        $host = 'localhost';
        $dbname = 'hardyval_esp_data';
        $username = 'hardyval';
        $password = 'Kudaliar1234';
        $conn = new mysqli($host, $username, $password, $dbname) or die("Connect failed: %s\n".$conn->error);

        return $conn;
    }

    function CloseCon($conn)
    {
        $conn->close();
    }
?>  
