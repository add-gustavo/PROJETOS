<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conversões</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <?php
    $number = $_POST['number'] ?? 0;
    ?>
    <main>
        <form action="<?= $_SERVER['PHP_SELF'] ?>" method="post">
            <label for="number">Número Decimal</label>
            <input type="number" name="number" id="number" value="<?= htmlspecialchars($number) ?>" required>
            <button type="submit">Converter</button>
        </form>
    </main>
    <main>
        <?php
        if ($number > 0) {
            echo "<h1>Conversões</h1>";

            function convertNumber($number, $base)
            {
                $original = $number;
                $steps = [];
                $converted = '';

                while ($number > 0) {
                    $remainder = $number % $base;
                    $steps[] = [
                        'dividendo' => $number,
                        'divisor' => $base,
                        'resto' => $base === 16 && $remainder >= 10 ? strtoupper(dechex($remainder)) : $remainder,
                    ];
                    $converted = ($base === 16 ? strtoupper(dechex($remainder)) : $remainder) . $converted;
                    $number = intdiv($number, $base);
                }

                $baseName = [
                    2 => 'Binário',
                    8 => 'Octal',
                    16 => 'Hexadecimal'
                ][$base];

                echo "<h2>Base $baseName</h2>";
                echo "<table class='divisao'>";
                echo "<tr><th>Dividendo</th><th>Divisor</th><th>Resto</th></tr>";
                foreach ($steps as $step) {
                    echo "<tr>";
                    echo "<td>{$step['dividendo']}</td>";
                    echo "<td>{$step['divisor']}</td>";
                    echo "<td>{$step['resto']}</td>";
                    echo "</tr>";
                }
                echo "</table>";


                echo "<p>O número decimal <strong>$original</strong> em $baseName é: <strong>$converted</strong></p>";
            }

            // Conversões
            convertNumber($number, 2);
            convertNumber($number, 8);
            convertNumber($number, 16);
        }
        ?>
    </main>
</body>

</html>