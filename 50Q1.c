#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// d12718@di.uminho.pt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 7

char *mystrcat(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
        ;
    for (j = 0; s2[j] != '\0'; ++j, ++i) {
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

// 11

void strrev(char s[]) {
    int i, j;
    int tam = strlen(s);
    int slen = tam;
    char tmp[slen];
    strcpy(tmp, s);
    slen--;

    for (i = 0; i < tam; i++, slen--) {
        s[i] = tmp[slen];
    }
    s[i] = '\0';
}

// 12
int isVowel(char c) {
    int r = 0;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U')
        r = 1;

    return r;
}

// 12
void strnoV(char s[]) {
    int i, k = 0;
    char tmp[strlen(s)];

    for (i = 0; s[i] != '\0'; ++i) {
        if (isVowel(s[i]) == 0) {
            tmp[k] = s[i];
            ++k;
        }
    }

    for (i = 0; tmp[i] != '\0'; ++i) {
        s[i] = tmp[i];
    }
    s[i] = '\0';
}

// 14
char charMaisfreq(char s[]) {
    int i, j;
    int counter;
    int max = 0;
    char cmax = '0';

    for (i = 0; s[i] != '\0'; ++i) {
        counter = 0;
        for (j = 0; s[j] != '\0'; ++j) {
            if (s[i] == s[j]) counter++;
        }
        if (max < counter) {
            max = counter;
            cmax = s[i];
        }
    }
    return cmax;
}

// 15
int iguaisConsecutivos(char s[]) {
    if (s[0] == '\0') {
        return 0;
    }
    int max = 1;
    int buffer = 1;
    int i;
    for (i = 0; s[i] != 0; i++) {
        if (s[i] == s[i + 1]) {
            buffer++;
        } else {
            if (buffer > max) {
                max = buffer;
            }
            buffer = 1;
        }
    }
    return max;
}

// 20
int contaPal(char s[]) {
    int i;
    int counter = 0;

    for (i = 0; s[i] != '\0'; ++i) {
        if ((s[i] != ' ') && (s[i + 1] == ' ') ||
            (s[i] != ' ') && (s[i + 1] == '\0'))
            counter++;
    }
    return counter;
}

// 21

int contaVogais(char s[]) {
    int counter = 0;
    int i;

    for (i = 0; s[i] != '\0'; ++i) {
        if (isVowel(s[i]) == 1) counter++;
    }
    return counter;
}

// 22
int contida(char a[], char b[]) {
    int i, j;
    int flag = 0;

    for (i = 0; i < strlen(a); ++i) {
        for (j = 0; j < strlen(b); ++j) {
            if (a[i] == b[j]) flag = 1;
        }

        if (flag == 0) return 0;
    }
    return 1;
}

// 23
int palindrome(char s[]) {
    int i, j;

    if (strlen(s) <= 1)
        return 1;

    else {
        for (i = 0, j = strlen(s) - 1; i != j; ++i, --j) {
            if (s[i] != s[j]) return 0;
        }
    }
    return 1;
}

// 24
int remRep(char x[]) {
    int i, j;
    int *repetidos = calloc(strlen(x), sizeof(int));
    int counter = 0;

    for (i = 0; x[i] != '\0'; ++i) {
        for (j = i + 1; x[j] != '\0'; ++j) {
            if (x[i] == x[j]) {
                repetidos[j] = 1;
            }
        }
        if (repetidos[i] == 0) {
            x[counter++] = x[i];
        } else {
            x[i] = '\0';
        }
    }

    return counter;
}

// 30
int menosFreq(int v[], int N) {
    int i, j;
    int counter;
    int min = N;
    int num;

    for (i = 0; i < N; ++i) {
        counter = 0;
        for (j = i + 1; j < N && v[i] == v[j]; ++j) {
            counter++;
        }
        if (counter < min) {
            min = counter;
            num = v[i];
        }
        i = j - 1;
    }
    return num;
}

// 31
int maisFreq(int v[], int N) {
    int i, j;
    int counter = 0;
    int max = 0;
    int num;

    for (i = 0; i < N; ++i) {
        counter = 0;
        for (j = 0; j < N; ++j) {
            if (v[i] == v[j]) counter++;
        }

        if (counter > max) {
            max = counter;
            num = v[i];
        }
    }
    return num;
}

// 31
int maisFreq(int v[], int N) {
    int i, j;
    int counter = 0;
    int max = 0;
    int num;

    for (i = 0; i < N; ++i) {
        counter = 0;
        for (j = 0; j < N; ++j) {
            if (v[i] == v[j]) counter++;
        }

        if (counter > max) {
            max = counter;
            num = v[i];
        }
    }
    return num;
}

// 33
int elimRep(int v[], int n) {
    int i, j;
    int *repetidos = calloc(n, sizeof(int));
    int counter = 0;

    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (v[i] == v[j]) {
                repetidos[j] = 1;
            }
        }
        if (repetidos[i] == 0) {
            v[counter++] = v[i];
        }
    }

    return counter;
}
// 34
int elimRepOrd(int v[], int N) {
    int counter = 1;
    int atual = v[0];
    int i = 1;

    for (i = 1; i < N; ++i) {
        if (atual != v[i]) {
            v[counter++] = v[i];
            atual = v[i];
        }
    }
    return counter;
}

// 35 --ver--
int comunsOrd(int a[], int na, int b[], int nb) {
    int comuns = 0;
    int aCounter = 0, bCounter = 0;
    while (aCounter < na && bCounter < nb) {
        if (a[aCounter] < b[bCounter]) {
            aCounter++;
        } else if (a[aCounter] > b[bCounter]) {
            bCounter++;
        } else {
            aCounter++;
            bCounter++;
            comuns++;
        }
    }
    return comuns;
}

// 36
int comuns(int a[], int na, int b[], int nb) {
    int i, j;
    int counter = 0;

    for (i = 0; i < na; ++i) {
        for (j = 0; j < nb; ++j) {
            if (a[i] == b[j]) {
                counter++;
                break;
            }
        }
    }
    return counter;
}

// 37
int minInd(int v[], int n) {
    int i;
    int min = v[0];
    int index;

    for (i = 0; i < n; ++i) {
        if (v[i] < min) {
            min = v[i];
            index = i;
        }
    }
    return index;
}

// 38
void somasAc(int v[], int Ac[], int N) {
    int i;

    Ac[0] = v[0];

    for (i = 1; i < N; ++i) {
        Ac[i] = Ac[i - 1] + v[i];
    }
}

// 39
int triSup(int N, float m[N][N]) {
    int i, j;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < i; ++j) {
            if (m[i][j] != 0) return 0;
        }
    }
    return 1;
}

// 40
void transposta(int N, float m[N][N]) {
    float matrix[N][N];
    int i, j;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            matrix[i][j] = m[j][i];
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            m[i][j] = matrix[i][j];
        }
    }
}

// 41
void addTo(int N, int M, int a[N][M], int b[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}
