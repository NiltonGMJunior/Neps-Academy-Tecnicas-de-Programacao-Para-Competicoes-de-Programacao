#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX_N 1010
#define MAX_P 1010
#define MAX_R 1001000

// Define a estrutura da caixa como o peso e a resitência líquida (já descontando o peso).
struct Caixa
{
    unsigned int peso;
    unsigned int resistencia;
};

// Define a estrutura de uma pilha de caixas a partir da resistência da pilha, número de caixas e vetor de caixas correspondentes.
struct Pilha
{
    unsigned int resistencia;
    unsigned short int tamanho;
    Caixa *caixas;
};

// Imprime os dados de uma caixa.
void imprimeCaixa(const Caixa &caixa)
{
    std::cout << "Peso: " << caixa.peso << " / Resistência: " << caixa.resistencia << '\n';
}

// Imprime os dados de uma pilha de caixas.
void imprimePilha(const Pilha &pilha)
{
    std::cout << "Resistência: " << pilha.resistencia << '\n';
    std::cout << "Tamanho: " << pilha.tamanho << '\n';
    for (unsigned short int iii = 0; iii < pilha.tamanho; ++iii)
        imprimeCaixa(pilha.caixas[iii]);
}

// Função base para ordenação do vetor de caixas. Essa função possibilita que o sort ordene as caixas em ordem não-crescente de resistência líquida.
// Retorna verdadeiro se a "caixa_a" deve ser inserida antes da "caixa_b" no vetor ordenado.
// Caso as resitências sejam equivalentes, o peso se torna critério de desempate. Caixas com menor peso vêm primeiro no vetor ordenado.
bool comparaCaixas(const Caixa &caixa_a, const Caixa &caixa_b)
{
    if (caixa_a.resistencia > caixa_b.resistencia)
        return true;

    if (caixa_a.resistencia == caixa_b.resistencia)
        return caixa_a.peso <= caixa_b.peso;

    return false;
}

// Abordagem top-dowm para se obter a pilha com o maior número de caixas possível.
// A ideia é, para cada item, definir se

int main()
{
    // Lê o número "n" de caixas disponíveis para empilhamento (1 <= n <= 1000).
    unsigned short int n;
    std::cin >> n;

    // Vetor "caixas" com as caixas válidas. Uma caixa válida tem resitência "r" maior ou igual à seu peso "p". (1 <= p <= 1000, 1 <= r <= 1000000).
    unsigned int p, r;
    Caixa *caixas = new Caixa[MAX_N];
    if (!caixas)
    {
        std::cout << "Falha ao alocar memória. Finalizando o programa.\n";
        exit(-1);
    }

    // Adiciona as caixas ao vetor.
    for (unsigned short int iii = 0; iii < n; ++iii)
    {
        std::cin >> p >> r;
        caixas[iii].peso = p;
        caixas[iii].resistencia = r - p;
    }

    // Ordena as caixas em ordem não-crescente de resitência (líquida). A pilha mais resistente possível será a pilha com apenas a caixa de maior resitência.
    std::sort(caixas, caixas + n, comparaCaixas);

    // Tabela de memoização "tab". A tabela tem tantas linhas quantas forem as caixas válidas mais uma linha para o caso onde nenhum caixa é utilizada, e o número de colunas é correspondente ao maior valor possível de resistência da pilha mais um (resistência zero).
    // Cada entrada tab[i][j] na tabela é a quantidade máxima de caixas que podem ser inseridas na pilha ao se incluir ou não a caixa[i] quando a pilha têm resistência j;
    unsigned short int **tab = new unsigned short int *[1 + n];
    if (!tab)
    {
        std::cout << "Falha ao alocar memória. Finalizando o programa.\n";
        exit(-1);
    }
    
    // Resistência máxima possível para a pilha.
    unsigned int resistencia_maxima = caixas[0].resistencia;

    for (unsigned short int iii = 0; iii < n; ++iii)
    {
        tab[iii] = new unsigned short int[1 + resistencia_maxima];
        if (!tab[iii])
        {
            std::cout << "Falha ao alocar memória. Finalizando o programa.\n";
            exit(-1);
        }
    }

    // Zera as entradas da tabela.
    std::memset(tab, 0, sizeof(tab[0][0]) * (1 + n) * (1 + caixas[0].resistencia));

    // Construindo a tabela.
    // O primeiro laço percorre todos os itens do vetor caixa, començando pelo item vazio (caso onde nenhum item seria incluido).
    // O segundo laço percorre os possíveis valores de resistência da pilha. Se a resistência da pilha for maior do que o peso do item sendo considerado, acrescenta o item à pilha.
    for (unsigned short int iii = 0; iii <= n; ++iii)
    {
        for (unsigned int jjj = 0; jjj <= resistencia_maxima; ++jjj)
        {

            if (iii == 0 || jjj == 0)
                tab[iii][jjj] = 0;
            else if 
        }
    }

    return 0;
}
