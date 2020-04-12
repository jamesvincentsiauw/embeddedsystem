<!DOCTYPE html>
<html>
<body>
<?php
  // Vincent 18217042 untuk keperluan sensor HC-SR04

  include 'db_config.php';

  $conn = OpenCon();

  $sql = 'SELECT * FROM DistanceData  ORDER BY id DESC';

  echo '<table cellspacing="5" cellpadding="5">
        <tr> 
          <td>ID</td> 
          <td>Sensor</td> 
          <td>Location</td> 
          <td>Distance (CM)</td>
          <td>Timestamp</td> 
        </tr>';

  if ($result = $conn->query($sql)) {
      while ($row = $result->fetch_assoc()) {
          $row_id = $row['id'];
          $row_sensor = $row['sensor'];
          $row_location = $row['location'];
          $row_distance = $row['distance'];
          $row_reading_time = $row['reading_time'];

          echo '<tr> 
                  <td>'.$row_id.'</td> 
                  <td>'.$row_sensor.'</td> 
                  <td>'.$row_location.'</td> 
                  <td>'.$row_distance.'</td>
                  <td>'.$row_reading_time.'</td> 
                </tr>';
      }
      $result->free();
  }

  CloseCon($conn);
?> 
</table>
</body>
</html>