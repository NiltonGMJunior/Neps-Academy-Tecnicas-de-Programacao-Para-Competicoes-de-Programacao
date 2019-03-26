#include <iostream>
#include <algorithm>

#define MAX_N 1000

unsigned int cont_recurs = 0; // APENAS PARA BENCHMARK! APAGAR APÓS DEPURAÇÃO!

struct Caixa
{
    long int p;
    long int r;
};

// TODO: Buscar alternativas ao algoritmo implementado na função maior_pilha que rodem em O(f(n)) < O(n!). O algoritmo atualmente implementado aparentemente funcional, mas é muito custoso
/**
* Recursão para determinar o maior número possível de caixas que se pode empilhar.
* A ideia é que, a partir da pilha com a maior resistência possível e uma caixa candidata a ser empilhada.
* 1 - Verifica se a caixa pode ser empilhada (isto é, se o peso da caixa é menor ou igual à resistência total da pilha);
* 2 - Desmembra a recursão em duas possibilidades, ou empilha a caixa e verifica com a próxima candidata, ou não empilha a caixa;
*/
int maior_pilha(const long int resistencia_pilha, const Caixa *caixas, const unsigned short int indice_caixa, const unsigned short int total_caixas)
{
    std::cout << "Numero de chamadas a recursao: " << ++cont_recurs << "\n"; // APENAS PARA BENCHMARK! APAGAR APÓS DEPURAÇÃO!

	// Caso base da recursão (não há mais caixas a serem empilhadas ou a resistência da pilha está limitada)
	if (indice_caixa > total_caixas || resistencia_pilha == 0) return 0;
	// Caso contrário
	else 
	{
		// Verifica se a caixa candidata tem peso maior do que a resistência total da pilha ou não suporta a si mesma
		if (caixas[indice_caixa].p > resistencia_pilha || caixas[indice_caixa].p > caixas[indice_caixa].r)
		{
			// Caso positivo, tenta a próxima caixa e ignora essa
			return maior_pilha(resistencia_pilha, caixas, indice_caixa + 1, total_caixas);
		}
		else
		{
			// Caso contrário, define a resistência da pilha como o mínimo entre a resistência da caixa no topo e a resistência da pilha com a caixa no topo
			long int nova_resistencia = std::min(resistencia_pilha, caixas[indice_caixa].r) - caixas[indice_caixa].p;
			// Retorna o máximo possível entre empilhar ou não a caixa
			unsigned short int pilha_com_caixa = 1 + maior_pilha(nova_resistencia, caixas, indice_caixa + 1, total_caixas);
			unsigned short int pilha_sem_caixa = maior_pilha(resistencia_pilha, caixas, indice_caixa + 1, total_caixas);
			return std::max(pilha_com_caixa, pilha_sem_caixa);
		}
	}
}

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

    // Declara a quantidade de caixas na pilha
    unsigned int quantidade_caixas = 0;

    // Verifica se a caixa que confere a maior resistência inicial à pilha tem resistência positiva
    if (caixas[0].r - caixas[0].p >= 0)
    {
        // Faz a chamada à função recursiva que determina a maior pilha possível
		quantidade_caixas =  maior_pilha(caixas[0].r - caixas[0].p, caixas, 0, n);
    }
    // Caso contrário, a quantidade permanece zero

    // Apresenta a quantidade de caixas na pilha
    std::cout << quantidade_caixas << '\n';

    return 0;
}
