#include <iostream>



int main()
{
    // Lê o valor do troco
    unsigned int n;
    std::cin >> n;

    // Um vetor que contém os possíveis valores das moedas, em ordem decrescente
    unsigned short int moedas[] = { 100, 50, 25, 10, 5, 1 };

    // Declara o número mínimo de moedas
    unsigned int min_moedas = 0;

    // Índice da maior moeda que pode ser utilizada como troco
    unsigned short int ind_moeda = 0;

    // Modifica o troco a medida que o mesmo é convertido em moedas, incrementado o número mínimo de moedas
    while (n > 0)
    {
        min_moedas += n / moedas[ind_moeda];
        n = n % moedas[ind_moeda];
        ++ind_moeda;
    }

    // Apresenta o resultado
    std::cout << min_moedas << '\n';

    return 0;
}
