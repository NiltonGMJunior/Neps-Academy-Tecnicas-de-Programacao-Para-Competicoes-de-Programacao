#include <iostream>

int main()
{
    // Lê o número de casas "n"
    unsigned int n;
    std::cin >> n;

    // Cria um vetor para armazenar, em ordem crescente, o número das casas e o faz
    unsigned int c[100000];
    for (unsigned int iii = 0; iii < n; ++iii) std::cin >> c[iii];

    // Lê o valor "k" da soma dos números das duas casas onde se encontram os brinquedos
    unsigned int k;
    std::cin >> k;

    for (unsigned int iii = 0; iii < n; ++iii)
    {
        // Averigua se c[iii] é suficientemente grande para ser uma das casas onde se esconde o brinquedo, somando-o com o maior valor possível para as casas
        if (c[iii] + c[n - 1] >= k)
        {
            // Declara um valor alvo a ser buscado no vetor
            unsigned int alvo = k - c[iii];

            // Declara os índices de início, meio e fim da busca
            unsigned int inicio = iii, meio, fim = n - 1;
            // Realiza a busca binária
            while (inicio <= fim)
            {
                // Redeifne o valor do meio
                meio = (inicio + fim) / 2;
                // Verifica se o valor do meio é o alvo
                if (c[meio] == alvo) break;
                // Verifica se o valor do meio está acima do alvo
                else if (c[meio] > alvo) fim = meio - 1;
                // Caso o valor do meio esteja abaixo do alvo
                else inicio = meio + 1;
            }
            // Se o alvo foi encontrado, imprime o resultado e interrompe o laço
            if (c[meio] == alvo)
            {
                std::cout << c[iii] << " " << c[meio];
                break;
            }
        }
    }

    return 0;
}
