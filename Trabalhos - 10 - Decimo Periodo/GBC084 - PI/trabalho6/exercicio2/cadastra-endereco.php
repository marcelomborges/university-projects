<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

// Inicializa e resgata dados do cliente
$cep = $logradouro = $bairro = $cidade = $estado = "";
if (isset($_POST["cep"])) $cep = $_POST["cep"];
if (isset($_POST["logradouro"])) $logradouro = $_POST["logradouro"];
if (isset($_POST["bairro"])) $bairro = $_POST["bairro"];
if (isset($_POST["cidade"])) $cidade = $_POST["cidade"];
if (isset($_POST["estado"])) $estado = $_POST["estado"];

$sql = <<<SQL
  INSERT INTO base_enderecos_ajax (cep, logradouro, bairro, cidade, estado)
  VALUES (?, ?, ?, ?, ?)
  SQL;

try {
  $stmt1 = $pdo->prepare($sql);
  $stmt1->execute([$cep, $logradouro, $bairro, $cidade, $estado]);

  header("location: ../index.html");
  exit();
} 
catch (Exception $e) {
  if ($e->errorInfo[1] === 1062)
    exit('Dados duplicados: ' . $e->getMessage());
  else
    exit('Falha ao cadastrar os dados: ' . $e->getMessage());
}
