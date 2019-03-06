#include <iostream>
#include <algorithm>

#define MAX_N 1000

struct Caixa
{
    short int p;
    long int r;
};

struct Pilha
{
    bool indice_caixas[MAX_N] { false };
    unsigned short int quantidade_caixas;
    long int resistencia;
};

// Retorna a caixa_a se esta possuir uma diferença entre r e p maior do que a caixa_b, e acaixa_b caso contrário
// Se ambas as caixas possuirem a mesma diferença entre r e p, retorna a caixa com o menor peso
bool compara_caixas(const Caixa &caixa_a, const Caixa &caixa_b)
{
    if (caixa_a.r - caixa_a.p == caixa_b.r - caixa_b.p) return caixa_a.p <= caixa_b.p;
    return caixa_a.r - caixa_a.p > caixa_b.r - caixa_b.p;
}

int main()
{
    // Lê o número "n" de caixas a serem empilhadas (1 <= n <= 1e3)
    unsigned short int n;
    std::cin >> n;

    // Nas próximas "n" linhas, lê os valores de peso "p" e resistência "r" de cada uma das caixas
    // Armazena os valores num vetor de estruturas do tipo caixa
    Caixa caixas[MAX_N];
    for (unsigned short int iii = 0; iii < n; ++iii) std::cin >> caixas[iii].p >> caixas[iii].r;

    // Ordena as caixas de acordo com a diferença entre sua resistência e peso
    std::sort(caixas, caixas + n, compara_caixas);

    // Declara uma pilha de caixas
    Pilha pilha;

    // Verifica se a caixa que confere a maior resistência inicial à pilha tem resistência positiva
    if (caixas[0].r - caixas[0].p >= 0)
    {
        // Empilha a melhor caixa e incrementa a pilha
        pilha.indice_caixas[0] = true;
        pilha.quantidade_caixas++;
        pilha.resistencia = caixas[0].r - caixas[0].p;

        // Enquanto houveram caixas viáveis, verifica qual a melhor caixa a ser empilhada
        bool ha_caixas_viaveis = true;
        // Guarda o índice da melhor caixa após cada passada
        while (ha_caixas_viaveis)
        {
            ha_caixas_viaveis = false;
            // Guarda o índice da melhor caixa à cada iteração
            short int ind_melhor_caixa = -1;
            for (unsigned short int iii = 0; iii < n; ++iii)
            {
                // Verifica as seguintes condições:
                // - Se a caixa ainda não foi adicionada na pilha
                // - Se a resistência da caixa é maior ou igual à seu peso
                // - Se o peso da caixa é menor ou igual à resistência da pilha
                if (!pilha.indice_caixas[iii] && caixas[iii]. r >= caixas[iii].p && caixas[iii].p <= pilha.resistencia)
                {
                    // Se passou nos testes de validade, verifica se o índice da melhor caixa ainda não foi definido
                    if (ind_melhor_caixa == -1)
                    {
                        // Índice ainda não foi definido, a caixa atual se torna a melhor
                        ind_melhor_caixa = iii;
                    }
                    else
                    {
                        // Índice já foi redefinido, procura um candidato melhor
                        if (std::min(pilha.resistencia - caixas[iii].p, caixas[iii].r - caixas[iii].p) >= std::min(pilha.resistencia - caixas[ind_melhor_caixa].p, caixas[ind_melhor_caixa].r - caixas[ind_melhor_caixa].p))
                        {
                            ind_melhor_caixa = iii;
                        }
                    }
                    ha_caixas_viaveis = true;
                }
            }
            // Se alguma caixa viável foi encontrada, adiciona a melhor na pilha
            if (ha_caixas_viaveis)
            {
                pilha.indice_caixas[ind_melhor_caixa] = true;
                pilha.quantidade_caixas++;
                pilha.resistencia = std::min(pilha.resistencia - caixas[ind_melhor_caixa].p, caixas[ind_melhor_caixa].r - caixas[ind_melhor_caixa].p);
            }
        }

    }
    //
    else
    {
        pilha.quantidade_caixas = 0;
    }

    // Apresenta a quantidade de caixas na pilha
    std::cout << pilha.quantidade_caixas << '\n';

    return 0;
}
