#include <iostream>
#include <algorithm>

struct Consulta
{
    unsigned int inicio;
    unsigned int fim;
};

bool compara_consultas(const Consulta &consulta_a, const Consulta &consulta_b)
{
    return consulta_a.fim <= consulta_b.fim;
}

int main()
{
    // Lê o número de consultas marcadas pela secretária (n)
    unsigned short int n;
    std::cin >> n;

    // Declara um vetor que armazena as consultas
    Consulta consultas[10000];

    for (int iii = 0; iii < n; ++iii)
    {
        // Lê o horário de início e o horário de término de cada consulta e guarda na matriz
        std::cin >> consultas[iii].inicio >> consultas[iii].fim;
    }

    // Define o máximo de consultas
    unsigned short int maximo_consultas = 1;

    // Ordena o vetor de consultas, com as consultas que terminam primeiro na frente
    std::sort(consultas, consultas + n, compara_consultas);

    // Define a consulta atual
    Consulta consulta_atual = consultas[0];

    // Percorre o vetor de consultas, verificando os conflitos e incrementando o maximo de consultas de acordo
    for (int iii = 1; iii < n; ++iii)
    {
        // Verifica se o término da consulta atual conflita com o ínicio da próxima consulta (que possui o menor horário de término)
        if (consultas[iii].inicio >= consulta_atual.fim)
        {
            // Caso não haja conflito, admite esta nova consulta, que, já que não há nenhuma outra que termina mais cedo, é a melhor possível
            consulta_atual = consultas[iii];
            // Incrementa o número máximo de consultas
            ++maximo_consultas;
        }
    }

    // Apresenta o número máximo de consultas
    std::cout << maximo_consultas;

    return 0;
}
