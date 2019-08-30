#include <iostream>

#define MAX_S 5000

int main()
{
    // Lê o valor s, representando o saque (0 <= s <= 5000)
    unsigned short int s;
    std::cin >> s;

    // Lê as quantidades disponíveis de notas de 2, 5, 10, 20, 50 e 100, nessa ordem
    // Guarda em um vetor
    unsigned short int n[6];
    for (int iii = 0; iii < 6; ++ iii) std::cin >> n[iii];
    // Sendo iii o índice do vetor n[iii], representando a disponibilidade da moeda de acordo com a tabela:
    // ÍNDICE   -   VALOR DA NOTA
    //      0   -   2
    //      1   -   5
    //      2   -   10
    //      3   -   20
    //      4   -   50
    //      5   -   100

    // Declara um vetor de combinações, que é preenchido com as combinações possíveis para a quantidade correspondente ao índice do vector
    // Isso é, combinacoes[iii] representa quantas maneiras distintas se pode representar o saque iii
    unsigned long long int combinacoes[MAX_S + 1] { 0 };
    // Para um saque de total 0, há apenas uma combinação possível (nenhuma moeda)
    combinacoes[0] = 1;

    for ()
}
