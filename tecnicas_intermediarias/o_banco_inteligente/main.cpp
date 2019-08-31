#include <iostream>
#include <vector>

#define MAX_S 5000
#define MAX_N 6

long long int totalCombinacoes(const unsigned short int s, const unsigned short int (&n[MAX_N]))
{
    return 1;
}

int main()
{
    // Lê o valor s, representando o saque (0 <= s <= 5000)
    unsigned short int s;
    std::cin >> s;

    // Lê as quantidades disponíveis de notas de 2, 5, 10, 20, 50 e 100, nessa ordem, e as guarda no vetor n
    // Sendo iii o índice do vetor n[iii], representando a disponibilidade da moeda de acordo com a tabela:
    // ÍNDICE   -   VALOR DA NOTA
    //      0   -   2
    //      1   -   5
    //      2   -   10
    //      3   -   20
    //      4   -   50
    //      5   -   100
    std::vector<unsigned short int> n;
    unsigned short int temp;
    for (unsigned short int iii = 0; iii < MAX_N; ++iii)
    {
        std::cin >> temp;
        n.push_back(temp);
    }

    // Declara um vetor de combinações, que é preenchido com as combinações possíveis para a quantidade correspondente ao índice do vector
    // Isso é, comb[iii] representa quantas maneiras distintas se pode representar o saque iii
    long long int comb[MAX_S + 1];

    // Para um saque de total 0, há apenas uma combinação possível (nenhuma moeda)
    comb[0] = 1;
}
