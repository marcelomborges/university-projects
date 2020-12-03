<!doctype html>
<html lang="pt-BR">
        <head>
                <!-- Required meta tags -->
                <meta charset="utf-8">
                <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

                <!-- Bootstrap CSS -->
                <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">
                <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-popRpmFF9JQgExhfw5tZT4I9/CI5e2QcuUZPOVXb1m7qUmeR2b50u+YFEYe1wgzy" crossorigin="anonymous"></script>
                
                <title>Trabalho 5 - Exercicio 2</title>
        </head>
        <body>
                <div class="container-sm my-3">

                        <table class="table table-primary">
                                <thead>
                                        <tr>
                                                <th scope="col">Número Sequencial</th>
                                                <th scope="col">Nome do Produto</th>
                                                <th scope="col">Descrição do Produto</th>
                                        </tr>
                                </thead>
                                <tbody>
                                        <?php
                                        $produtos=["Barbarian","Cleric","Druid","Fighter","Monk","Paladin","Ranger","Sorcerer","Warlock","Wizard"];
                                        $descricao=["Fantasia de Barbaro","Fantasia de Clerigo","Fantasia de Druida", "Fantasia de Guerreiro", "Fantasia de Monge", "Fantasia de Paladino", "Fantasia de Patrulheiro", "Fantasia de Feiticeiro", "Fantasia de Bruxo", "Fantasia de Mago"];

                                        if(isset($_GET["qde"]))
                                                $qde = intval($_GET["qde"]);
                                        
                                        for($i = 0; $i < $qde; $i++) {
                                                $num=rand(0,9);
                                                echo <<<HTML
                                                <tr>
                                                        <td>$i</td>
                                                        <td>$produtos[$num]</td>
                                                        <td>$descricao[$num]</td>
                                                </tr>
                                                HTML;
                                        }
                                        ?>

                                </tbody>
                        </table>
                </div>
        </body>
</html>