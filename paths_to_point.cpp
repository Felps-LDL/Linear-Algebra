#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define MAXN 10100
#define INTMAX 10000000000
#define pii pair<int, int> 
#define delta 0.0000001
#define ALL(x) x.begin(), x.end()
#define ll long long
 
using namespace std;

int A[5][5], vertice1, vertice2, possibilidades = 0;

int aij(int linha, int coluna)
{
    // Descobrindo o elemento aij correspondente na matriz A^2
    int elemento = 0;
    for (int i = 0; i < 5; i++) elemento += A[linha - 1][i] * A[i][coluna - 1];

    return elemento;
}

int aij3(int linha, int coluna)
{
    // Descobrindo o elemento aij correspondente na matriz A^3
    int elemento = 0;
    for (int i = 0; i < 5; i++) elemento += aij(linha, i + 1) * A[i][coluna - 1];

    return elemento;
}

void seta_valores()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            A[i][j] = 0;
        }
    }

    A[0][1] = A[0][2] = A[0][3] = A[0][4] = 1;
    A[1][0] = A[1][2] = A[1][3] = 1;
    A[2][1] = A[2][3] = 1;
    A[3][2] = A[3][4] = 1;
    A[4][3] = 1;
}

int menu()
{
    int opcao;
    cout << "MENU\n";
    cout << "1 - Direta\n";
    cout << "2 - 1 sinal\n";
    cout << "3 - 2 sinais\n";
    cout << "4 - Todas as possibilidades\n";
    cout << "5 - Sair\n\n";
    cout << "Opcao: ";
    cin >> opcao;

    return opcao;
}

void lista_caminhos(int opcao)
{
    if (opcao == 1)
    {
        if(A[vertice1 - 1][vertice2 - 1]) cout << vertice1 << " -> " << vertice2 << endl;
    }
    else if (opcao == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            // Descobrir qual vizinho do vértice 1 que chega no vértice 2
            if (A[vertice1 - 1][i] && A[i][vertice2 - 1])
            {
                cout << vertice1 << " -> " << i + 1 << " -> " << vertice2 << endl;
            }
        }
    }
    else
    {
        // Vasculhar os vizinhos do vertice 1 que se ligam em algum outro vértice que possua como vizinho o vertice 2
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                // Verificando quem é vizinho do vértice 1
                if (!A[vertice1 - 1][i]) break;
                
                // Verificando os vizinhos desse primeiro vizinho e vendo se eles conseguem chegar no vértice 2
                if (A[i][j] && A[j][vertice2 - 1])
                {
                    cout << vertice1 << " -> " << i + 1 << " -> " << j + 1 << " -> " << vertice2 << endl;
                }
            }
        }
    }
}

// Ideia das opções sempre a mesma
// Descobrir o número de possibilidades e verificar se tem existem caminhos possíveis
// Se existir mostrá-los de acordo com a opção que o usuário escolher

void opcao1()
{
    possibilidades = A[vertice1 - 1][vertice2 - 1];
    cout << "Possibilidade(s): " << possibilidades << endl;
    
    if (possibilidades == 0) return;
    
    cout << "Caminho(s):\n";
    lista_caminhos(1);
}

void opcao2()
{
    possibilidades = aij(vertice1, vertice2);
    cout << "Possibilidade(s): " << possibilidades << endl;
    
    if (possibilidades == 0) return;

    cout << "Caminho(s):\n";
    lista_caminhos(2);
}

void opcao3()
{
    possibilidades = aij3(vertice1, vertice2);
    cout << "Possibilidade(s): " << possibilidades << endl;

    if (possibilidades == 0) return;

    cout << "Caminho(s):\n";

    lista_caminhos(3);
}

void opcao4()
{
    possibilidades = aij3(vertice1, vertice2) + aij(vertice1, vertice2) + A[vertice1 - 1][vertice2 - 1];
    cout << "Possibilidade(s): " << possibilidades << endl;

    if (possibilidades == 0) return;

    cout << "Caminho(s):\n";

    lista_caminhos(1);
    lista_caminhos(2);
    lista_caminhos(3);
}

int main()
{
    // Colocando os valores na matriz
    seta_valores();

    // Pegando os vértices
    cout << "Primeiro vertice: ";
    cin >> vertice1;
    cout << "Segundo vertice: ";
    cin >> vertice2;

    while (true)
    {
        int opcao;
        opcao = menu();

        if (opcao == 5) break;
        if (opcao < 1 || opcao > 5) cout << "Opcao invalida\n";
        
        if (opcao == 1) opcao1();
        if (opcao == 2) opcao2();
        if (opcao == 3) opcao3();
        if (opcao == 4) opcao4();
    }

    cout << "Fim :)\n";
    
    return 0;
}
