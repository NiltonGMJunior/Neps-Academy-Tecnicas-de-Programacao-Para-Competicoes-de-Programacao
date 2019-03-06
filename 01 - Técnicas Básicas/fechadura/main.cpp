#include <iostream>

int main()
{
    // Declara e lê a quantidade de pinos da fechadura (n) e a altura dos pinos para a qual a fechadura será desbloqueada (m) em milímetros
    unsigned short int n, m;
    std::cin >> n >> m;

    // Declara um vetor com as alturas dos pinos da fechadura e lê as n alturas em milímetros
    short int alturas[1000];
    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> alturas[iii];
    }

    // Para esse problema, é garantido que todos os testes possuirão uma solução válida
    // O número de alterações é definido
    unsigned int alteracoes = 0;

    // Percorre os pinos até a penúltima posição, corrigindo os apres sempre de acordo com o primeiro dos dois pinos
    // A entrada sempre garantirá uma solução válida
    for (int iii = 0; iii < n - 1; ++iii)
    {
        // Verifica se o primeiro pino do par (iii, iii + 1) precisa ser alterado
        if (alturas[iii] != m)
        {
            // Em caso positivo, realiza a alteração no par e incrementa o contador de alterações
            // Para o caso em que o pino é mais alto
            if (alturas[iii] > m)
            {
                alteracoes += alturas[iii] - m;
                alturas[iii + 1] -= alturas[iii] - m;
            }
            // Para o case em que o pino é mais baixo
            else
            {
                alteracoes += m - alturas[iii];
                alturas[iii + 1] += m - alturas[iii];
            }
            // Redefine a altura (para a finalidade do algoritmo, esse passo não é necessário pois a altura não tornará a ser avaliada, podendo se assumir que a mesma já foi ajustado no final do laço)
            alturas[iii] = m;
        }
    }

    // TODO: Estudar e entender o porquê da seguinte implementação não solucionar corretamente o problema
    // // O algoritmo implementado funciona da seguinte maneira
    // // As alturas são corrigidas de fora para dentro, isso, é, os pinos das extremidades tem suas alturas acertadas e, em seguida, corrigem-se os pinos mais internos
    // // Em cada iteração, altera-se (se necessário) os pinos nas duas primeiras e duas últimas posições, de acordo com o valor dos pinos da primeira e última posição (respectivamente)
    // // Desse modo, após cada iteração, o primeiro e último pino são corrigidos, e o problema se torna o de solucionar uma fechadura de tamanho n - 2 (como se fosse por recurssão)
    // // O laço é percorrido um número [(n - 1) / 2] vezes (com divisão inteira, valendo para n par e ímpar)
    // // Para n = 5, por exemplo, ajustam-se os pinos nesta ordem:
    // // Pinos 0 e 1 - 1a iteração - pino 0 corrigido
    // // Pinos 3 e 4 - 1a iteração - pino 4 corrigido
    // // Pinos 1 e 2 - 2a iteração - pino 1 corrigido
    // // Pinos 2 e 3 - 2a iteração - pinos 2 e 3 corrigidos - termina o laço - pois garante-se que o algoritmo funcionará (entradas sempre válidas)
    // for (int iii = 0; iii < (n - 1) / 2; ++iii)
    // {
    //     // Verifica se o pino mais à esquerda necessita de ajuste
    //     if (alturas[iii] != m)
    //     {
    //         // Se necessitar, verifica se deve ser ajustado para baixo
    //         if (alturas[iii] > m)
    //         {
    //             // Ajusta o número de alterações e o pino à direita de acordo
    //             alteracoes += alturas[iii] - m;
    //             alturas[iii + 1] -= alturas[iii] - m;
    //         }
    //         // Se o pino necessitar de ajuste para cima
    //         else
    //         {
    //             // Ajusta o número de alterações e o pino à direita de acordo
    //             alteracoes += m - alturas[iii];
    //             alturas[iii + 1] += m - alturas[iii];
    //         }
    //         // Corrige o pino com a altura correta
    //         alturas[iii] = m;
    //     }
    //
    //     // Verifica se o pino mais à direita necessita de ajuste
    //     if (alturas[n - 1 - iii] != m)
    //     {
    //         // Se necessitar, verifica se deve ser ajustado para baixo
    //         if (alturas[n - 1 - iii] > m)
    //         {
    //             // Ajusta o número de alterações e o pino à esquerda de acordo
    //             alteracoes += alturas[n - 1 - iii] - m;
    //             alturas[n - 2 - iii] -= alturas[n - 1 - iii] - m;
    //         }
    //         // Se o pino necessitar de ajuste para cima
    //         else
    //         {
    //             // Ajusta o número de alterações e o pino à esquerda de acordo
    //             alteracoes += m - alturas[n - 1 - iii];
    //             alturas[n - 2 - iii] += m - alturas[n - 1 - iii];
    //         }
    //         // Corrige o pino com a altura correta
    //         alturas[n - 1 - iii] = m;
    //     }
    // }

    // Apresenta o número de alterações
    std::cout << alteracoes;

    return 0;
}
