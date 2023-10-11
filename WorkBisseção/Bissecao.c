#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>

double equation(double R, double Q0, double L, double C, double T) {
    return (Q0 * exp(-R / (2 * L))) * cos(sqrt((1 / (L * C)) - pow(R / (2 * L), 2)) * T);
}

int main() {
    initscr();  // Inicializa a biblioteca ncurses
    start_color();  // Inicializa cores

    init_pair(1, COLOR_RED, COLOR_BLACK);  // Define um par de cores

    double a = 20;
    double b = 100.0;
    double Q0 = 1.0;
    double L = 5.0;
    double C = 1e-4;
    double T = 0.05;
    double target = 0.01;
    int max_iter = 50;
    double epsilon = 1e-6;

    double c, fc;

    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2;
        fc = equation(c, Q0, L, C, T);

        if (fabs(fc / Q0 - target) < epsilon) {
            attron(COLOR_PAIR(1));  // Ativa a cor vermelha
            printw("Solução encontrada: R = %lf\n", c);
            attroff(COLOR_PAIR(1));  // Desativa a cor vermelha
            break;
        }

        if (fc / Q0 > target)
            b = c;
        else
            a = c;
    }

    refresh();
    getch();
    endwin();  // Encerra a biblioteca ncurses

    return 0;
}
