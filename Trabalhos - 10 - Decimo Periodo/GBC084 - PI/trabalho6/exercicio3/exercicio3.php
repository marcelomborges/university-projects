<?php

require "conexaoMysql.php";
$pdo = mysqlConnect();

try {

  $sql = <<<SQL
  SELECT *
  FROM base_enderecos_ajax
  SQL;

  $stmt = $pdo->query($sql);
} catch (Exception $e) {
  exit('Ocorreu uma falha: ' . $e->getMessage());
}
?>

<!DOCTYPE html>
<html lang="pt-BR">
        <head>
                <meta charset="UTF-8">

                <meta name="viewport" content="width=device-width, initial-scale=1">
                        
                <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">        
        </head>
        <body>
            <main>
                    <div class="container-sm my-3">

                            <table class="table table-default">
                                    <thead>
                                            <tr>
                                                    <th scope="col">CEP</th>
                                                    <th scope="col">Logradouro</th>
                                                    <th scope="col">Bairro</th>
                                                    <th scope="col">Cidade</th>
                                                    <th scope="col">Estado</th>
                                            </tr>
                                    </thead>
                                    <tbody>
                                        <?php
                                        while ($row = $stmt->fetch()) {

                                            $cep = htmlspecialchars($row['cep']);
                                            $logradouro = htmlspecialchars($row['logradouro']);
                                            $bairro = htmlspecialchars($row['bairro']);
                                            $cidade = htmlspecialchars($row['cidade']);
                                            $estado = htmlspecialchars($row['estado']);

                                            echo <<<HTML
                                            <tr>
                                                <td>$cep</td> 
                                                <td>$logradouro</td>
                                                <td>$bairro</td>
                                                <td>$cidade</td>
                                                <td>$estado</td>
                                            </tr>      
                                            HTML;
                                        }
                                        ?>
                                    </tbody>
                            </table>
                    </div>
                </main>
        </body>
</html>