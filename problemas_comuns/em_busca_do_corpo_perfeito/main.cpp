#include <bits/stdc++.h> 

#define MAX_N 2000

// Vetores com os pesos e quantidades de proteína em cada pedaço
unsigned int pesos[MAX_N], prot[MAX_N];

// Tabela de memoização, com o peso máximo para cada pedaço e o restante a ser ingerido
long long int tab[MAX_N][MAX_N];


unsigned short int max_proteina(unsigned short int n, unsigned short int ind, unsigned short int p)
{
    // Caso não hajam mais pedaços à verificar ou não aguenta mais comer
    if (ind == n || p == 0) return tab[ind][p] = 0;


    // Valor já identificado na tabela
    if (tab[ind][p] != -1) return tab[ind][p];

    // Caso não comer o pedaço atual
    unsigned short int nao_come = max_proteina(n, ind + 1, p);

    // Verifica se pode comer o pedaço atual
    if (p >= pesos[ind])
    {
        // Comendo o pedaço atual
        unsigned short int come = prot[ind] + max_proteina(n, ind + 1, p - pesos[ind]);
        // Retorna o máximo possível entre comer e não comer
        return tab[ind][p] = std::max(nao_come, come);
    }

    // Não foi possível comer mais um pedaço
    return tab[ind][p] = nao_come;

}

int main()
{
    // Peso máximo que pode ser ingerido e número de pedaços disponíveis
    unsigned short int p, n;
    std::cin >> p >> n;

    // Seta os valores da tabela de memoização para -1
    memset(tab, -1, sizeof(tab));

    // Popula os valores dos pesos e quantidade de proteína de cada pedaço
    for (unsigned short int iii = 0; iii < n; ++iii)
    {
        std::cin >> pesos[iii] >> prot[iii];
    }

    // Máximo de protéina possível com os pedaços disponíveis
    unsigned short int max_prot = max_proteina(n, 0, p);

    // Imprime o resultado
    std::cout << max_prot << "\n";

    return 0;
}