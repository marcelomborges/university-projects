package aulapratica01;

public class Pessoa
{

    String nome;
    double peso, altura;

    double calculaIMC()
    {
        return peso / (altura * altura);
    }

    String avaliaIMC()
    {
        double imc = calculaIMC();
        if (imc < 18.5) {
            return "abaixo do peso!!!";
        }
        if (imc >= 18.5 && imc <= 25) {
            return "com peso normal.";
        }
        if (imc > 25 && imc <= 30) {
            return "acima do peso!";
        }
        return "obeso!!!";
    }
}
