#include <iostream>
#include <vector>

#define INF -1000000001

void merge_sort(std::vector<int> & v)
{
    // Vetor tem até um elemento, portanto já está ordenado
    if (v.size() <= 1) return;

    // Divide o vetor original em dois
    std::vector<int> u1, u2;

    // Preenche os novos vetores
    for (unsigned int iii = 0; iii < v.size() / 2; ++iii) u1.push_back(v[iii]);
    for (unsigned int iii = v.size() / 2; iii < v.size(); ++iii) u2.push_back(v[iii]);

    // Ordena os novos vetores com Merge Sort
    merge_sort(u1);
    merge_sort(u2);

    // Adiciona um valor "infinito" ao final de cada um dos vetores
    u1.push_back(INF);
    u2.push_back(INF);

    // Percorre os elementos do vetor original, subsituindo os valores para realizar a ordenação
    for (int iii = 0, ind1 = 0, ind2 = 0; iii < v.size(); ++iii)
    {
        if (u1[ind1] > u2[ind2])
        {
            v[iii] = u1[ind1];
            ind1++;
        }
        else
        {
            v[iii] = u2[ind2];
            ind2++;
        }
    }

    return;
}

void print_vector(std::vector<int> &v)
{
    for (auto & elem : v)
    {
        std::cout << elem << " ";
    }
}

int main()
{
    // Lê o número de inteiros
    unsigned int n;
    std::cin >> n;

    // Preenche o vetor com os inteiros
    std::vector<int> v;
    for (unsigned int iii = 0; iii < n; ++iii)
    {
        int input;
        std::cin >> input;
        v.push_back(input);
    }

    // Chama o Merge Sort
    merge_sort(v);
    
    // Imprime o vetor ordenado
    print_vector(v);

    return 0;
}