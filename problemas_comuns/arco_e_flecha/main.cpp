#include <iostream>
#include <vector>

// Valor limite de comparação para Merge Sort
#define INF -1

unsigned long long int count_inversions(std::vector<long long int> & v)
{
    // Caso base da recursão
    if (v.size() <= 1) return 0;

    // Número de inversões
    unsigned long long int inv = 0;

    // Divisão do vetor original ao meio
    std::vector<long long int> u1, u2;
    for (unsigned int iii = 0; iii < v.size() / 2; ++iii) u1.push_back(v[iii]);
    for (unsigned int iii = v.size() / 2; iii < v.size(); ++iii) u2.push_back(v[iii]);

    // Acrescenta ao número de inversões as inversões dos vetores criados
    inv += count_inversions(u1);
    inv += count_inversions(u2);

    // Adiciona o elemento limite no final dos vetores
    u1.push_back(INF);
    u2.push_back(INF);

    // Redefine o vetor original e conta as inversões entre os vetores gerados
    for (unsigned int iii = 0, ind1 = 0, ind2 = 0; iii < v.size(); ++iii)
    {
        if (u1[ind1] > u2[ind2])
        {
            // Sem penalidades
            v[iii] = u1[ind1];
            ind1++;
        }
        else
        {
            // Com penalidade
            v[iii] = u2[ind2];
            ind2++;
            inv += u1.size() - ind1 - 1;
        }   
    }

    return inv;
}

int main()
{
    // Número de flechas
    unsigned int n;
    std::cin >> n;

    // Vetor com os valores do quadrado das distâncias ao centro de cada flecha, em ordem de lançamento
    std::vector<long long int> sq_dist;
    for (unsigned int iii = 0; iii < n; ++iii)
    {
        long int x_dist, y_dist;
        std::cin >> x_dist >> y_dist;
        sq_dist.push_back((x_dist * x_dist) + (y_dist * y_dist));
    }

    // Conta o número de inversões no vetor, correspondente ao número de penalidades, e imprime
    std::cout << count_inversions(sq_dist);

    return 0;
}