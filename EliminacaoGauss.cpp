#include <iostream>

using namespace std;
bool imprime1 = false;
bool imprime = true;
double a = 1.0, s = 1.0;
int N = 4;
double maior;
int *ptrlin = nullptr;
int *ptrcol = nullptr;
int lin = 0;
int col = 0;
double **A = nullptr;
double *b = nullptr;
double *b1 = nullptr;//
double *x = nullptr; //
int *ind = nullptr;
int indice;

/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */
int numeroAleatorio(int minimo, int maximo);
void Gauss(double **&A, double *&b, double *&x);
double CalculaMaior(int indice, int N, double **&A);
void imprimeMatriz(char *nome, double A[][N]);
void trocaLinha(int N, int ColInicial, int lin, int linDest, double **&A, double *&b);
void imprimeMatriz_Ab(char *nome, double **&A, double *&b);
void imprimeMatriz_Ax_b(char *nome, double **&A, double *&x, double *&b);
void trocaColuna(int N, int LinInicial, int col, int colDest, double **&A, int *&ind);
void eliminacaoGauss(int N, int lin, int col, double **&A, double *&b);
void imprimeMatriz_Ax_b2(int N, char *nome, double **&A, double *&x, double *&b);
void multiplica(double A[][N],double x[N],double *&b1);

int main() {
    if (imprime1) {
        cout << "\nHello, World!";
        printf("\nSize of a = %d e de s = %d,  a = %f,  s = %f", sizeof(a), sizeof(s), a, s);
        for (int i = 1; i <= 5; i++) {
            s = s * a;
            printf("\nFatorial de %d eh %7.3e", i, s);
            a = a + 1.0;
        }
    }
    //srand((unsigned) time(0)); //para gerar números aleatórios reais.
    srand(1); //Para gerar os mesmos numeros.

    A = new double *[N];
    b = new double[N];
    x = new double[N];
    ind = new int[N];
    double bb[N];
    double AA[N][N];
    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        b[i] = (double) numeroAleatorio(1, 10);
        bb[i] = b[i];
        for (int j = 0; j < N; j++) {
            A[i][j] = (double) numeroAleatorio(1, 10);
            AA[i][j] = A[i][j];
        }
    }

    imprimeMatriz_Ab("Matriz A b",A, b);

    Gauss(A, b, x);

    double soma ;
    printf("\n");
    for (int i = 0; i < N; i++) {
        soma = 0.0;
        for (int j = 0; j < N; j++) {
            printf(" %8.2f ", AA[i][j]);
            soma += AA[i][j]*x[j];
        }
        printf("     %8.5f    %8.2f  AproxAx = %8.5f\n", x[i], bb[i] , soma);
    }


    b1 = new double[N];
    multiplica(AA,x,b1);

    for(int i=0;i<N;i++)
        printf(" %5.2f  ",b1[i]);
    return 0;
}

void multiplica(double A[][N],double x[N],double *&b1){
    double soma;
    for (int i=0;i<N;i++){
        soma = 0.0;
        for(int j=0;j<N;j++){
            soma += A[i][j]*x[j];
        }
        b1[i]=soma;
    }


}

/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */
int numeroAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

void Gauss(double **&A, double *&b, double *&x) {
    if (imprime1) {
        printf("\n Vetor b = ");
        for (int i = 0; i < N; i++) {
            printf(" %6.2f ", b[i]);
        }

        imprimeMatriz_Ax_b("Ax = b", A, x, b);
    }


    for (int i = 0; i < N; i++) {
        ind[i] = i;
        if (imprime1)
            printf(" ind[%d] = %d ", i, ind[i]);
    }

    ptrcol = &col;
    ptrlin = &lin;
    //maior =
    maior = 10;
    int ilin = 0;
    int jcol = 0;
    indice = 0;

    while (indice < N - 1) {

        if (imprime1) {
            imprimeMatriz_Ax_b("Ax = b", A, x, b);
        }
        maior = CalculaMaior(indice, N, A);
        if (imprime1) {
            printf("\n lin = %d col = %d  maior = %6.2f", lin, col, A[lin][col]);
        }

        if (lin != ilin)
            trocaLinha(N, 0, lin, ilin, A, b);

        if (imprime1) {
            imprimeMatriz_Ax_b("Ax = b", A, x, b);
        }

        if (col != jcol) {
            trocaColuna(N, 0, col, jcol, A, ind);
        }

        if (imprime1) {
            imprimeMatriz_Ax_b("Ax = b", A, x, b);
        }

        eliminacaoGauss(N, ilin, jcol, A, b);

        if (imprime1) {
            imprimeMatriz_Ax_b("Ax = b", A, x, b);
        }

        indice++;
        ilin = indice;
        jcol = indice;
    }

    for (int i = N - 1; i > -1; i--) {
        double soma = 0.0;
        for (int j = i; j < N-1 ; j++)
            soma += x[ind[j+1]] * A[i][j+1];
        x[ind[i]] = (b[i] - soma) / A[i][i];
        if (imprime1) {
            printf("x[%d] = %12.10f ", i, x[ind[i]]);
        }
    }


    if (imprime1) {
        imprimeMatriz_Ax_b2(N, " Final Ax = b", A, x, b);
    }


}

double CalculaMaior(int indice, int N, double **&A) {
    double maior = abs(A[indice][indice]);
    if (imprime1) {
        printf("\nA[0][0] = %10.5f  N = %d", A[indice][indice], N);
    }
    for (int i = indice; i < N; i++)
        for (int j = indice; j < N; j++)
            if (abs(A[i][j]) > maior) {
                maior = A[i][j];
                if (imprime1) {
                    printf("\nA[%d][%d] = %10.5f", i, j, A[i][j]);
                }
                *ptrlin = i;
                *ptrcol = j;
            }
    return maior;
}

void imprimeMatriz(char *nome, double A[][N]) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %10.5f ", A[i][j]);
        }
        printf("\n");
    }
}

void imprimeMatriz_Ab(char *nome, double **&A, double *&b) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %10.5f ", A[i][j]);
        }
        printf("    %10.5f\n", b[i]);
    }
}

void imprimeMatriz_Ax_b(char *nome, double **&A, double *&x, double *&b) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %10.5f ", A[i][j]);
        }
        printf("    x[%d]   %10.5f\n", ind[i], b[i]);
    }
}

void imprimeMatriz_Ax_b2(int N, char *nome, double **&A, double *&x, double *&b) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %10.2f ", A[i][j]);
        }
        printf("    x[%d] = %10.5f     %10.2f\n", ind[i], x[ind[i]], b[i]);
    }
}


void trocaLinha(int N, int ColInicial, int lin, int linDest, double **&A, double *&b) {
    if (lin != linDest) {
        double aux = b[lin];
        b[lin] = b[linDest];
        b[linDest] = aux;
        double linaux[N];
        for (int j = 0; j < N; j++)
            linaux[j] = A[lin][j];
        for (int j = 0; j < N; j++) {
            A[lin][j] = A[linDest][j];
            A[linDest][j] = linaux[j];
        }

    }

}

void trocaColuna(int N, int LinInicial, int col, int colDest, double **&A, int *&ind) {
    if (col != colDest) {
        int aux = ind[col];
        ind[col] = ind[colDest];
        ind[colDest] = aux;
        double colaux[N];
        for (int i = 0; i < N; i++)
            colaux[i] = A[i][col];
        for (int i = 0; i < N; i++) {
            A[i][col] = A[i][colDest];
            A[i][colDest] = colaux[i];
        }

    }

}

void eliminacaoGauss(int N, int lin, int col, double **&A, double *&b) {
    double aux1 = A[lin][col];
    if (imprime1)
        printf("A[%d][%d] = %6.2f", lin, col, A[lin][col]);
    for (int i = lin + 1; i < N; i++) {
        if (abs(A[i][col]) > 1e-14) {
            double aux2 = A[i][col];
            for (int j = 0; j < N; j++) {
                A[i][j] = A[i][j] - A[lin][j] * aux2 / aux1;
            }
            b[i] = b[i] - b[lin] * aux2 / aux1;
        }
    }
}

