#include <iostream>

#define MAX_N 1000

int main()
{
    // Declara os valores de n, m e k
    unsigned short int n, k;
    unsigned int m;
    std::cin >> n >> k >> m;

    // Coeficientes a_i (a_i = a[i], começa do 1 para facilitar correlação com o enunciado)
    long int a[MAX_N + 1];
    for (unsigned short int iii = 1; iii <= n; ++iii) std::cin >> a[iii];

    // Valores base da recursão f_i (f_i = f[i], começa do 1 para facilitar correlação com o enunciado)
    long long int f[MAX_N];
    for (unsigned short int iii = 1; iii <= n; ++iii) std::cin >> f[iii];

    // Abordagem bottom-up, a partir dos n primeiros valores de f, calcula f_(n+1) = f[n + 1] até que se alcance o índice k (f[k])
    for (unsigned short int iii = n + 1; iii <= k; ++iii)
    {
        // Inicializa o valor de f_(i + 1) como 0
        f[iii] = 0;
        // Incrementa f_(i + 1)
        for (unsigned short int jjj = 1; jjj <= n; ++jjj) f[iii] += a[jjj] * f[iii - jjj];
        f[iii] = f[iii] % m;
    }

    // Apresenta o resultado
    std::cout << f[k];

    return 0;
}
