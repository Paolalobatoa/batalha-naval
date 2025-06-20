#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10
#define SHIP_SIZE 3
#define HABILITY_SIZE 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

void inicializaTabuleiro(int tab[TAB_SIZE][TAB_SIZE]) {
    for(int i=0; i<TAB_SIZE; i++)
        for(int j=0; j<TAB_SIZE; j++)
            tab[i][j] = AGUA;
}

void exibeTabuleiro(int tab[TAB_SIZE][TAB_SIZE]) {
    printf("\nTabuleiro:\n");
    for(int i=0; i<TAB_SIZE; i++) {
        for(int j=0; j<TAB_SIZE; j++) {
            if(tab[i][j] == AGUA) printf("0 ");
            else if(tab[i][j] == NAVIO) printf("3 ");
            else if(tab[i][j] == HABILIDADE) printf("5 ");
            else printf("? "); 
        }
        printf("\n");
    }
}

void criaCone(int cone[HABILITY_SIZE][HABILITY_SIZE]) {
    for(int i=0; i<HABILITY_SIZE; i++)
        for(int j=0; j<HABILITY_SIZE; j++)
            cone[i][j] = 0;

    for(int i=0; i<HABILITY_SIZE; i++) {
        int start = 2 - i;
        int end = 2 + i;
        if(start < 0) start = 0;
        if(end >= HABILITY_SIZE) end = HABILITY_SIZE - 1;
        for(int j=start; j<=end; j++) {
            cone[i][j] = 1;
        }
    }
}


void criaCruz(int cruz[HABILITY_SIZE][HABILITY_SIZE]) {
    for(int i=0; i<HABILITY_SIZE; i++)
        for(int j=0; j<HABILITY_SIZE; j++)
            cruz[i][j] = 0;

    int mid = HABILITY_SIZE / 2;

    for(int i=0; i<HABILITY_SIZE; i++) {
        cruz[mid][i] = 1;
        cruz[i][mid] = 1; 
    }
}


void criaOctaedro(int octa[HABILITY_SIZE][HABILITY_SIZE]) {
    for(int i=0; i<HABILITY_SIZE; i++)
        for(int j=0; j<HABILITY_SIZE; j++)
            octa[i][j] = 0;

    int mid = HABILITY_SIZE / 2; 

    for(int i=0; i<HABILITY_SIZE; i++) {
        for(int j=0; j<HABILITY_SIZE; j++) {
            int dist = abs(i - mid) + abs(j - mid);
            if(dist <= 2) {
                octa[i][j] = 1;
            }
        }
    }
}

void aplicaHabilidade(int tab[TAB_SIZE][TAB_SIZE], int habilidade[HABILITY_SIZE][HABILITY_SIZE], int origemLinha, int origemColuna) {
    int meio = HABILITY_SIZE / 2;

    for(int i=0; i<HABILITY_SIZE; i++) {
        for(int j=0; j<HABILITY_SIZE; j++) {
            if(habilidade[i][j] == 1) {
                int linTab = origemLinha + (i - meio);
                int colTab = origemColuna + (j - meio);

                if(linTab >=0 && linTab < TAB_SIZE && colTab >=0 && colTab < TAB_SIZE) {
                    if(tab[linTab][colTab] == AGUA) {
                        tab[linTab][colTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}


void posicionaNavioHorizontal(int tab[TAB_SIZE][TAB_SIZE], int linha, int coluna, int tamanho) {
    for(int i=0; i<tamanho; i++) {
        tab[linha][coluna+i] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];
    inicializaTabuleiro(tabuleiro);

    posicionaNavioHorizontal(tabuleiro, 2, 2, SHIP_SIZE); 
    posicionaNavioHorizontal(tabuleiro, 5, 5, SHIP_SIZE); 

    int cone[HABILITY_SIZE][HABILITY_SIZE];
    int cruz[HABILITY_SIZE][HABILITY_SIZE];
    int octaedro[HABILITY_SIZE][HABILITY_SIZE];

    criaCone(cone);
    criaCruz(cruz);
    criaOctaedro(octaedro);

    int origemConeLinha = 1, origemConeColuna = 4;
    int origemCruzLinha = 6, origemCruzColuna = 2;
    int origemOctaedroLinha = 7, origemOctaedroColuna = 7;

    aplicaHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicaHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicaHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna);

    exibeTabuleiro(tabuleiro);

    return 0;
}
