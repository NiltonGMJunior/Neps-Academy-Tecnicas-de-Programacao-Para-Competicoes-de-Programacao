#include <iostream>

int main()
{
    // Lê o número de faixas de força "n" (2 <= n <= 1e5) e o número de ogros cujas forças foram medidas "m" (1 <= m <= 1e4)
    unsigned int n;
    unsigned short int m;
    std::cin >> n >> m;

    // Declara um vetor de forcas em que cada elemento "a" do vetor representa o limite superior de uma faixa de forças (1 <= a <= 1e9)
    unsigned int a[99999 + 1];
    // Lê os "n - 1" limites de força de cada faixa entre os índices 1 e n - 1 e guarda o índice 0 para o valor 0
    for (int iii = 0; iii < n - 1; ++iii) std::cin >> a[iii];

    // Declara um vetor de premiações em que cada elemento "f" representação a premiação para a faixa de força equivalente (1 <= f <= )
    unsigned int f[100000];
    // Lê os "n" valores das premiações para cada faixa de força (prêmio f[k] para faixa de força f[k - 1])
    for (int iii = 0; iii < n; ++iii) std::cin >> f[iii];

    // Declara um vetor com as forças de cada um dos ogros
    unsigned int o[10000];
    // Lê os "m" valores de forças para cada ogro
    for (int iii = 0; iii < m; ++iii) std::cin >> o[iii];

    // Para cada ogro
    for (int iii = 0; iii < m; ++iii)
    {
        if (o[iii] < a[0]) std::cout << f[0] << " ";
        else if (o[iii] >= a[n - 2]) std::cout << f[n - 1] << " ";
        else
        {
            // Faz uma busca para determinar qual o índice da faixa de força do ogro
            // O inicio, meio e fim do intervalo de busca são definidos
            unsigned int inicio = 0, meio, fim = n - 1;
            while (inicio <= fim)
            {
                // Redefine o meio
                meio = (inicio + fim) / 2;
                // Força dentro da faixa a[meio - 1] - a[meio]
                if (o[iii] < a[meio] && o[iii] >= a[meio - 1])
                {
                    break;
                }
                // Força maior do que a[meio]
                else if (o[iii] >= a[meio])
                {
                    inicio = meio + 1;
                }
                // Força menor do que a[meio]
                else
                {
                    fim = meio - 1;
                }
            }
            std::cout << f[meio] << " ";
        }
    }

    return 0;
}
