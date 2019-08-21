#include <stdio.h>
#include <math.h>

#define N 32

double hanning[N];
double hamming[N];
double blackmanharris[N];
double flattop[N];


void init_window_hanning() {
    int i;
    for (i = 0; i < N; i++) {
        hanning[i] = 0.5*(1.0-cos((2*M_PI*i)/(N-1)));
    }
}

void init_window_hamming() {
    int i;
    double a0, a1;
    a0 = 0.53836;
    a1 = 0.46164;
    for (i = 0; i < N; i++) {
        hamming[i] = a0 - a1*cos((2*M_PI*i)/(N-1));
    }
}

void init_window_blackmanharris() {
    int i;
    double a0, a1, a2, a3;
    a0 = 0.35875;
    a1 = 0.48829;
    a2 = 0.14128;
    a3 = 0.01168;
    for (i = 0; i < N; i++) {
        blackmanharris[i] = a0 - a1*cos((2*M_PI*i)/(N-1)) + a2*cos((4*M_PI*i)/(N-1)) - a3*cos((6*M_PI*i)/(N-1));
    }
}

void init_window_flattop() {
    int i;
    double a0, a1, a2, a3, a4;
    a0 = 0.21557895;
    a1 = 0.41663158;
    a2 = 0.277263158;
    a3 = 0.083578947;
    a4 = 0.006947368;
    for (i = 0; i < N; i++) {
        flattop[i] = a0 - a1*cos((2*M_PI*i)/(N-1)) + a2*cos((4*M_PI*i)/(N-1)) - a3*cos((6*M_PI*i)/(N-1)) + a4*cos((8*M_PI*i)/(N-1));
    }
}


int main(int argc, const char * argv[]) {
    
    init_window_hanning();
    init_window_hamming();
    init_window_blackmanharris();
    init_window_flattop();

    int i;
    printf("hanning\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%.3f\n", i, hanning[i]);
    }
    printf("\n\n");
    
    printf("hamming\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%.3f\n", i, hamming[i]);
    }
    printf("\n\n");
    
    printf("blackmanharris\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%.3f\n", i, blackmanharris[i]);
    }
    printf("\n\n");
    
    printf("flattop\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%.3f\n", i, flattop[i]);
    }
    printf("\n\n");
    
    
    return 0;
}
