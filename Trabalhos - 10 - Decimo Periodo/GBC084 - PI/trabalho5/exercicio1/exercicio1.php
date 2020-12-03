<!doctype html>
<html lang="pt-BR">
        <head>
                <!-- Required meta tags -->
                <meta charset="utf-8">
                <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

                <!-- Bootstrap CSS -->
                <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">
                <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-popRpmFF9JQgExhfw5tZT4I9/CI5e2QcuUZPOVXb1m7qUmeR2b50u+YFEYe1wgzy" crossorigin="anonymous"></script>
                
                <title>Trabalho 5 - Exercicio 1</title>

                <style>
                        .caixa {
                                border: solid 1px grey;
                                padding: 10px;
                                margin: 10px;
                        }
                </style>
        </head>
        <body>
                <div class="container-sm my-3">
                        <?php
                        if(isset($_POST["cep"]))
                                $cep = trim($_POST["cep"]);
                        if(isset($_POST["logradouro"]))
                                $logradouro = trim($_POST["logradouro"]);
                        if(isset($_POST["bairro"]))
                                $bairro = trim($_POST["bairro"]);
                        if(isset($_POST["cidade"]))
                                $cidade = trim($_POST["cidade"]);
                        if(isset($_POST["estado"]))
                                $estado = trim($_POST["estado"]);  

                        echo <<<HTML
                        <div class="row my-3">
                                <div class="col-sm-2 my-3 form-floating">
                                        <span class="caixa">$cep</span>
                                </div>
                                <div class="col-sm-4 my-3 form-floating">
                                        <span class="caixa">$logradouro</span>
                                </div>
                                <div class="col-sm-2 my-3 form-floating">
                                        <span class="caixa">$bairro</span>
                                </div>
                                <div class="col-sm-2 my-3 form-floating">
                                        <span class="caixa">$cidade</span>
                                </div>
                                <div class="col-sm-2 my-3 form-floating">
                                        <span class="caixa">$estado</span>
                                </div>
                        </div>     
                        HTML;
                        ?>
                </div>
        </body>
</html>