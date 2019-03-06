#include <iostream>

struct Medicao
{
    unsigned long int maior;
    unsigned long int menor;
};

int main()
{
    // Lê o número de mergulhos (1 <= n <= 1e4)
    unsigned short int n;
    std::cin >> n;

    // Lê o comprimento da fita em metros (1 <= m <= 5e5)
    unsigned long int m;
    std::cin >> m;

    // Lê as medições e as armazena as duas medições possíveis num vetor de n estruturas do tipo Medicao (0 <= medicoes.menor <= medicoes.maior <= m)
    Medicao medicoes[10000];
    for (int iii = 0; iii < n; ++iii)
    {
        // Lê a medição
        unsigned long int medicao;
        std::cin >> medicao;

        // Armazena no vetor de estruturas
        if (medicao <= m - medicao)
        {
            medicoes[iii].menor = medicao;
            medicoes[iii].maior = m - medicao;
        }
        else
        {
            medicoes[iii].menor = m - medicao;
            medicoes[iii].maior = medicao;
        }
    }

    // Declara o menor comprimento possível do último mergulho
    // Importante saber que um mergulho NUNCA é mais curto que o anterior
    unsigned long int menor_mergulho = medicoes[0].menor;

    // Declara a menor soma possível do comprimento total dos mergulhos
    long long int menor_soma = menor_mergulho;

    // Percorre a estrutura de medicoes em busca do menor comprimento possivel do total dos mergulhos
    // Se, em algum caso, o valor da maior medicao possivel de um determinado mergulho for menor do que a menor medicao do mergulho atual, indica que houve engano nas anotações e retorna -1
    for (unsigned short int iii = 1; iii < n; ++iii)
    {
        // Verifica se o menor comprimento do próximo mergulho é maior ou igual ao menor mergulho atual
        if (menor_mergulho <= medicoes[iii].menor)
        {
            menor_mergulho = medicoes[iii].menor;
        }
        // Verifica se o maior comprimento do próximo mergulho é maior ou igual ao menor mergulho atual
        else if (menor_mergulho <= medicoes[iii].maior)
        {
            menor_mergulho = medicoes[iii].maior;
        }
        // Se nenhuma das duas condições anteriores for satisfeita, a sequência é inválida
        else
        {
            menor_soma = -1;
            break;
        }
        // Redefine a menor soma do comprimento dos mergulhos
        menor_soma += menor_mergulho;
    }

    // Apresenta o resultado
    std::cout << menor_soma;

    return 0;
}
