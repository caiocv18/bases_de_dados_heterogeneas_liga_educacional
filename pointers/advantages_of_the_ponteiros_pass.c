//
// Created by caiocv18 on 22/05/2024.
//

#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void movePoint(Point *p, int deltaX, int deltaY) {
    p->x += deltaX; // Atualiza a coordenada x
    p->y += deltaY; // Atualiza a coordenada y
}

int main() {
    Point pt = {10, 20};
    printf("Ponto inicial: (%d, %d)\n", pt.x, pt.y);

    movePoint(&pt, 5, -3); // Passa o ponteiro para a struct
    printf("Ponto após movimentação: (%d, %d)\n", pt.x, pt.y);

    return 0;
}