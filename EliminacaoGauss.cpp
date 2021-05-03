#include <iostream>

using namespace std;

bool imprime = true;
double a = 1.0, s = 1.0;
int N = 5;
double maior;
int *ptrlin = nullptr;
int *ptrcol = nullptr;
int lin = 0;
int col = 0;
double **A = nullptr;
double **A1 = nullptr;
double *b = nullptr;
double *b1 = nullptr;//
double *x = nullptr; //
int *ind = nullptr;
int indice ;
/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */
int numeroAleatorio(int minimo, int maximo);

void Gauss(double **&A, double *&b, double *&x);

double CalculaMaior(int indice, int N, double **&A);

void imprimeMatriz(int N, char *nome, double **&A);

void trocaLinha(int N, int ColInicial, int lin, int linDest, double **&A, double *&b);

void imprimeMatriz_Ab(int N, char *nome, double **&A, double *&b);

void imprimeMatriz_Ax_b(int N, char *nome, double **&A, double *&x, double *&b);

void trocaColuna(int N, int LinInicial, int col, int colDest, double **&A, int *&ind);

void eliminacaoGauss(int N, int lin, int col, double **&A, double *&b);

int main() {
    if (imprime) {
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

    for (int i = 0; i < N; i++) {
        A[i] = new double[N];
        b[i] = (double) numeroAleatorio(1, 100);
        for (int j = 0; j < N; j++) {
            A[i][j] = (double) numeroAleatorio(1, 100);
        }

    }

    Gauss(A, b, x);
    return 0;
}

/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */
int numeroAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

void Gauss(double **&A, double *&b, double *&x) {
    if (imprime) {
        printf("\n Vetor b = ");
        for (int i = 0; i < N; i++) {
            printf(" %6.2f ", b[i]);
        }
        /*
        printf("\n Matriz A = \n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf(" %6.2f ", A[i][j]);
            }
            printf("\n");
        }
        */
        //imprimeMatriz(N, "Matriz A =",A);
        imprimeMatriz_Ax_b(N, "Ax = b", A, x, b);
    }


    for (int i = 0; i < N; i++) {
        ind[i] = i;
        if (imprime)
            printf(" ind[%d] = %d ", i, ind[i]);
    }
    double AA[N][N];
    double bb[N];

    for(int i =0;i<N;i++){
        bb[i]=b[i];
        for(int j=0;j<N;j++)
            AA[i][j]=A[i][j];
    }
    ptrcol = &col;
    ptrlin = &lin;
    //maior =
    maior = 10;
    int ilin = 0;
    int jcol = 0;
    indice = 0;

    while (indice<N-1) {
        N=5;
        if (imprime) {
            imprimeMatriz_Ax_b(N, "Ax = b", A, x, b);
        }
        maior = CalculaMaior(indice,N, A);
        if (imprime) {
            printf("\n lin = %d col = %d  maior = %6.2f", lin, col, A[lin][col]);
        }

        if (lin != ilin)
            trocaLinha(N, 0, lin, ilin, A, b);

        if (imprime) {
            imprimeMatriz_Ax_b(N, "Ax = b", A, x, b);
        }

        if (col != jcol) {
            trocaColuna(N, 0, col, jcol, A, ind);
        }

        if (imprime) {
            imprimeMatriz_Ax_b(N, "Ax = b", A, x, b);
        }

        eliminacaoGauss(N, ilin, jcol, A, b);

        if (imprime) {
            imprimeMatriz_Ax_b(N, "Ax = b", A, x, b);
        }

        indice++;
        ilin = indice;
        jcol = indice;
    }

    for (int i = N-1;i>-1;i--){
        double soma = 0.0;
        for (int j = i;j<N-1;j++)
            soma +=  x[ind[i]]*A[i][j];
        x[ind[i]] = (b[i]-soma)/A[i][i];
    }

    if (imprime) {
        imprimeMatriz_Ax_b(N, "Ax = b", A, x, b);
    }


}

double CalculaMaior(int indice,int N, double **&A) {
    double maior = abs(A[indice][indice]);
    if (imprime) {
        printf("\nA[0][0] = %6.2f  N = %d", A[indice][indice], N);
    }
    for (int i = indice; i < N; i++)
        for (int j = indice; j < N; j++)
            if (abs(A[i][j]) > maior) {
                maior = A[i][j];
                if (imprime) {
                    printf("\nA[%d][%d] = %6.2f", i, j, A[i][j]);
                }
                *ptrlin = i;
                *ptrcol = j;
            }
    return maior;
}

void imprimeMatriz(int N, char *nome, double **&A) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %6.2f ", A[i][j]);
        }
        printf("\n");
    }
}

void imprimeMatriz_Ab(int N, char *nome, double **&A, double *&b) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %6.2f ", A[i][j]);
        }
        printf("    %6.2f\n", b[i]);
    }
}

void imprimeMatriz_Ax_b(int N, char *nome, double **&A, double *&x, double *&b) {
    printf("\n  %s \n", nome);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %8.1f ", A[i][j]);
        }
        printf("    x[%d]   %8.1f\n", ind[i], b[i]);
    }
}


void trocaLinha(int N, int ColInicial, int lin, int linDest, double **&A, double *&indX) {
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
    if (imprime)
        printf("A[%d][%d] = %6.2f",lin,col,A[lin][col]);
    for (int i = lin + 1; i < N; i++) {
        if (abs(A[i][col]) > 1e-14) {
            double aux2 = A[i][col];
            for (int j = 0; j < N; j++) {
                A[i][j] = A[i][j]  - A[lin][j]*aux2/aux1;
            }
            b[i] = b[i] - b[lin]*aux2/aux1;
        }
    }
}