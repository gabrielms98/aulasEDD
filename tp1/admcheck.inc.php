<?php

include 'includes/dbh.inc.php';

if(isset($_SESSION['u_id'])){

  $nome = $_SESSION['u_id'];
  $sql = "SELECT usuario, adm FROM usuarios WHERE usuario='$nome' AND adm='1'; ";
  $result = mysqli_query($conn, $sql);
  $resultCheck = mysqli_num_rows($result);

  if($resultCheck>0){

  } else{
      header("Location: index.php");
    }
}




?>
