#include <iostream>

int main()
{
    // Declara e lê a quantidade de pinos da fechadura (n) e a altura dos pinos para a qual a fechadura será desbloqueada (m) em milímetros
    unsigned short int n, m;
    std::cin >> n >> m;

    // Declara um vetor com as alturas dos pinos da fechadura e lê as n alturas em milímetros
    unsigned short int alturas[1000];
    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> alturas[iii];
    }

    // Para esse problema, é garantido que todos os testes possuirão uma solução válida

    // O loop percorrerá os pares de pinos, verificando se o primeiro pino do par deve subir ou descer para alcançar m
    // O loop é repetido até que todas as alturas sejam ajustadas para m
    // O número de alterações é contado
    
    return 0;
}
