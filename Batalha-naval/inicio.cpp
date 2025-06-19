#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <locale>
#include <unistd.h>
#define TAM 4

using namespace std;

int main () {
    setlocale(LC_ALL, "Portuguese");

    char tabuleiro[TAM][TAM];
    int RandLinha, RandColuna;

    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            tabuleiro[i][j] = '~';
}
}
srand(time(0));

    // Colocar 3 navios '#'
    int navios = 0;
    while (navios < 3) {
        RandLinha = rand() % TAM;
        RandColuna = rand() % TAM;
        if (tabuleiro[RandLinha][RandColuna] == '~') {
            tabuleiro[RandLinha][RandColuna] = '#';
            navios++;
}}

    // Colocar 1 submarino '*'
    bool colocado = false;
    while (!colocado) {
        RandLinha = rand() % TAM;
        RandColuna = rand() % TAM;
        if (tabuleiro[RandLinha][RandColuna] == '~') {
            tabuleiro[RandLinha][RandColuna] = '*';
            colocado = true;
}}

    // Colocar 1 porta-aviões '!'
    colocado = false;
    while (!colocado) {
        RandLinha = rand() % TAM;
        RandColuna = rand() % TAM;
        if (tabuleiro[RandLinha][RandColuna] == '~') {
            tabuleiro[RandLinha][RandColuna] = '!';
            colocado = true;
}}

    // Tabuleiro para mostrar ao jogador: só marca jogadas
char display[TAM][TAM];
for (int i=0; i<TAM; i++)
    for (int j=0; j<TAM; j++)
        display[i][j] = '~';

int naviosRestantes = 3;
int submarinoRestante = 1;
int portaAvioesRestante = 1;
int jogadaNum = 1;

while (true) {
    system("cls");

        // Mostrar tabuleiro para o jogador
    cout << "    ";
    for (int i='A'; i < 'A'+TAM; i++){
    cout << (char)i << " ";
}
    cout << endl;

    for (int i=0; i<TAM; i++) {
    cout << setw(3) << i+1 << " ";
    for (int j=0; j<TAM; j++) {
    cout << display[i][j] << " ";
}
    cout << endl;
}

cout << "\nJogada " << jogadaNum << endl;
        int linha;
        char coluna;
cout << "Linhas: (1-" << TAM << "): ";
cin >> linha;
cout << "Colunas: (A-" << (char)('A'+TAM-1) << "): ";
cin >> coluna;

int colunaIndex = toupper(coluna) - 'A';


        // Verifica o que tem no tabuleiro real
if (tabuleiro[linha - 1][colunaIndex] == '#') {
    cout << "Acertou o navio!" << endl;
    display[linha - 1][colunaIndex] = 'X';
    naviosRestantes--;
}
else if (tabuleiro[linha - 1][colunaIndex] == '*') {
    cout << "Acertou o submarino!" << endl;
    display[linha - 1][colunaIndex] = 'X';
    submarinoRestante--;
}
else if (tabuleiro[linha - 1][colunaIndex] == '!') {
    cout << "Acertou o porta-aviões!" << endl;
    display[linha - 1][colunaIndex] = 'X';
    portaAvioesRestante--;
}
else if (tabuleiro[linha - 1][colunaIndex] == '~') {
    cout << "Acertou a água!" << endl;
    display[linha - 1][colunaIndex] = 'O';
}

jogadaNum++;

if (naviosRestantes == 0 && submarinoRestante == 0 && portaAvioesRestante == 0) {
    cout << "Foi necessário " << jogadaNum << " jogadas" << endl;
    cout << "\nParabéns! Você afundou todos os navios!" << endl;
break;
}
 sleep(3);
}
return 0;
}
