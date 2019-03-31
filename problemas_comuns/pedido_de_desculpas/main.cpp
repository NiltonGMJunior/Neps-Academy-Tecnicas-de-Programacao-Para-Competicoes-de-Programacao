#include <bits/stdc++.h>

// Comprimento máximo do cartão
#define MAX_C 1000

// Máximo número de frases coletadas
#define MAX_F 50

// Número de caracteres por frase (8 <= N <= 200)
unsigned short int caracteres[MAX_F];

// Número de desculpas for por frase (1 <= D <= 25)
unsigned short int desculpas[MAX_F];

// Tabela de memoização (frase atual x caracteres restantes)
short int tab[MAX_F][MAX_C];

unsigned short int max_desculpas(unsigned short int f, unsigned short int ind, unsigned short int c)
{
    // Se não há mais caracteres a serem preenchidos ou não há mais frases, retorna 0 após atualizar tabela
    if (ind == f || c == 0) 
        return tab[ind][c] = 0;
    
    // Se o valor já foi identificado na tabela
    if (tab[ind][c] != -1)
        return tab[ind][c];

    // Número máximo de desculpas sem incluir a frase atual
    unsigned short int sem_frase = max_desculpas(f, ind + 1, c);

    // Se a frase atual cabe no cartão
    if (c >= caracteres[ind])
    {
        // Máximo de desculpas incluindo a frase atual
        unsigned short int com_frase = desculpas[ind] + max_desculpas(f, ind + 1, c - caracteres[ind]);
        // Redefine a tabela e retorna o máximo possível com ou sem a frase
        return tab[ind][c] = std::max(sem_frase, com_frase);
    }

    // Caso não seja possível incluir a frase atual, retorna o valor sem a frase e atualiza a tabela
    return tab[ind][c] = sem_frase;
}

int main()
{
    // Teste atual
    unsigned short int teste = 0;
    
    // Número de caracteres no cartão e número de frases a serem lidas
    unsigned short int c, f;

    while (true)
    {
        // Lê o máximo de caracteres no cartão e o número de possíveis frases
        std::cin >> c >> f;
        // Se ambos forem zero, termina o programa
        if (c == 0 && f == 0) 
            break;
        // Incrementa o teste (necessário apenas para o padrão de saída)
        teste++;

        // Reseta a tabela de memoização com os valores em -1
        memset(tab, -1, sizeof(tab));

        // Preenche os vetores de caracteres e números de desculpas por frase
        for (unsigned short int iii = 0; iii < f; ++iii)
            std::cin >> caracteres[iii] >> desculpas[iii];

        unsigned short int num_max_desculpas = max_desculpas(f, 0, c);

        std::cout << "Teste " << teste << "\n" << num_max_desculpas << "\n\n";
    }
    
    return 0;
}