#include "data_stat.h"

double max(double *data, int n) {
    double m = data[0];
    for (int i = 1; i < n; i++)
        if (m < data[i]) m = data[i];
    return m;
}

double min(double *data, int n) {
    double m = data[0];
    for (int i = 1; i < n; i++)
        if (m > data[i]) m = data[i];
    return m;
}

double mean(double *data, int n) {
    double avr = data[0];
    for (int i = 1; i < n; i++) {
        avr = avr + data[i];
    }
    avr = avr / n;
    return avr;
}

double variance(double *data, int n) {
    double vr = 0;
    double avr = mean(data, n);
    for (int i = 0; i < n; i++) {
        vr = vr + (data[i] - avr) * (data[i] - avr);
    }
    vr = vr / n;
    return vr;
}