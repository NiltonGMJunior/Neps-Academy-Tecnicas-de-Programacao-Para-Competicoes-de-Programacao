#include <iostream>
#include <vector>

// Valor além do limite dos elementos do vetor a ser ordenado (necessário para o Merge Sort)
#define INF 60001

// Contagem de inversões por Merge Sort modificado
unsigned int count_inversions(std::vector<unsigned short int> & vector)
{
    // Caso base da recursão
    if (vector.size() <= 1) return 0;

    // Total de inversões
    unsigned int inv = 0;

    // Divisão ao meio do vetor
    std::vector<unsigned short int> u1, u2;
    for (unsigned short int iii = 0; iii < vector.size() / 2; ++iii) u1.push_back(vector[iii]);
    for (unsigned short int iii = vector.size() / 2; iii < vector.size(); ++iii) u2.push_back(vector[iii]);

    // Ordenação dos vetores u1 e u2
    inv += count_inversions(u1);
    inv += count_inversions(u2);

    // Adiciona um valor "infinito" no final dos vetores
    u1.push_back(INF);
    u2.push_back(INF);

    // Merging dos vetores
    for (unsigned short int iii = 0, ind1 = 0, ind2 = 0; iii < vector.size(); ++iii)
    {
        if (u1[ind1] <= u2[ind2])
        {
            vector[iii] = u1[ind1];
            ind1++;
        }
        else
        {
            vector[iii] = u2[ind2];
            ind2++;
            // Atualiza o número de inversões (contabiliza -1 pois foi adicionado o valor INF em u1 e u2)
            inv += u1.size() - ind1 - 1;
        }
    }

    return inv;
}

int main()
{
    // Número de elementos no vetor
    unsigned short int n;
    std::cin >> n;

    // Cria e popula o vetor
    std::vector<unsigned short int> vector;
    for (unsigned short int iii = 0; iii < n; ++iii)
    {
        unsigned short int input;
        std::cin >> input;
        vector.push_back(input);
    }

    // Chama a função que realiza a contagem de inversões e imprime o resultado
    std::cout << count_inversions(vector);

    return 0;
}