#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int DIM = 30;

void stampa_matrice(const bool mat[][DIM], int rig, int col);

void reset_matrice(bool mat[][DIM], int rig, int col);

int seleziona_cavallo(int rig);

int simulatore_gara(bool mat[][DIM], int rig, int col);

int inserisci_elemento_riga(bool mat[][DIM], int idx_rig, int col);


int main() {
    const int rig = 4;
    const int col = 10;

    // Imposto la matrice correttamente
    bool mat[DIM][DIM];
    reset_matrice(mat, rig, col);

    // Seleziono il cavallo vincente
    int scommessa = seleziona_cavallo(rig);
    int vincente = simulatore_gara(mat, rig, col);
    stampa_matrice(mat, rig, col);
    if (scommessa == vincente)
        cout << "Hai vinto!";
    else
        cout << "Hai perso! Il cavallo vincente e' " << vincente + 1 << endl;
    return 0;
}

void stampa_matrice(const bool mat[][DIM], const int rig, const int col) {
    for (int i = 0; i < rig; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void reset_matrice(bool mat[][DIM], int rig, int col) {
    for (int i = 0; i < rig; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = false;
        }
    }
}

int seleziona_cavallo(int rig) {
    int cavallo;
    do {
        cout << "Su quale cavallo scommetti [1-" << rig << "]: ";
        cin >> cavallo;
    } while (cavallo < 1 || cavallo > rig);
    return cavallo - 1;
}

int simulatore_gara(bool mat[][DIM], const int rig, const int col){
    srand(time(NULL));
    int idx_riga, idx_col;
    do{
        idx_riga = rand() % rig;
        idx_col = inserisci_elemento_riga(mat, idx_riga, col);
    } while (idx_col != col - 1);
    return idx_riga;
}

int inserisci_elemento_riga(bool mat[][DIM], const int idx_riga, const int col){
    for (int i = 0; i < col; ++i) {
        if (!mat[idx_riga][i]){
            mat[idx_riga][i] = true;
            return i;
        }
    }
    return -1;
}