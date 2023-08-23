#include <stdio.h>
#include <stdlib.h>

// Função para adição
float add(float a, float b) {
    return a + b;
}

// Função para subtração
float subtract(float a, float b) {
    return a - b;
}

// Função para multiplicação
float multiply(float a, float b) {
    return a * b;
}

// Função para divisão
float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erro: divisao por zero!\n");
        return 0.0;
    }
}

// Função para converter decimal para binário
void decimalToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Função para converter decimal para hexadecimal
void decimalToHexadecimal(int num) {
    printf("%X", num);
}

int main() {
    int choice;
    float num1, num2;
    char ch;

    printf("Calculadora Simples\n");
    printf("1. Adicao\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n");
    printf("Escolha uma operacao (1/2/3/4): ");
    scanf("%d", &choice);

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    switch (choice) {
        case 1:
            printf("Resultado: %.2f\n", add(num1, num2));
            break;
        case 2:
            printf("Resultado: %.2f\n", subtract(num1, num2));
            break;
        case 3:
            printf("Resultado: %.2f\n", multiply(num1, num2));
            break;
        case 4:
            printf("Resultado: %.2f\n", divide(num1, num2));
            break;
        default:
            printf("Opcao invalida!\n");
    }

    // Conversão decimal para binário
    int decimalNum;
    printf("Digite um numero decimal para converter para binario: ");
    scanf("%d", &decimalNum);
    printf("Binario: ");
    decimalToBinary(decimalNum);
    printf("\n");

    // Conversão decimal para hexadecimal
    printf("Digite um numero decimal para converter para hexadecimal: ");
    scanf("%d", &decimalNum);
    printf("Hexadecimal: ");
    decimalToHexadecimal(decimalNum);
    printf("\n");

    return 0;
}
