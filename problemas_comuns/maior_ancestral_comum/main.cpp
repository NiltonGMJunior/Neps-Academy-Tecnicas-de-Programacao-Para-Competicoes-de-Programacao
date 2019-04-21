#include <iostream>
#include <cstring>

#define MAXN 1010

// Define os vetores com as sequências n e m
unsigned short int seq_n[MAXN], seq_m[MAXN];

// Define a tabela de memoização para o algoritmo que encontra a maior subsequência comum
short int tab[MAXN][MAXN];

unsigned short int lcs(const unsigned short int a, const unsigned short int b)
{
    if (tab[a][b] >= 0) return tab[a][b];
    if (a == 0 || b == 0) return tab[a][b] = 0;
    if (seq_n[a - 1] == seq_m[b - 1]) return tab[a][b] = 1 + lcs(a - 1, b - 1);
    return tab[a][b] = std::max(lcs(a - 1, b), lcs(a, b - 1));
}

int main()
{
    // Lê os comprimentos n e m de duas sequeências de genes
    unsigned short int n, m;
    std::cin >> n >> m;

    // Lê os genes das sequências de comprimento n e m
    for (unsigned short int iii = 0; iii < n; ++iii) std::cin >> seq_n[iii];
    for (unsigned short int iii = 0; iii < m; ++iii) std::cin >> seq_m[iii];

    // Preenhe a tabela de memoização
    memset(tab, -1, MAXN * MAXN * sizeof(tab[0][0]));
    
    // Define o comprimento da maior subsequência comum entre seq_n e seq_m
    unsigned short int lcs_nm = lcs(n, m);

    // Imprime as diferenças entre os comprimentos das sequências e da maior subsequência comum
    std::cout << n - lcs_nm << " " << m - lcs_nm << "\n";
    return 0;
}