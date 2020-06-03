#include <stdio.h>
#include <math.h>

void swapFloat(float &a, float &b) {
    float t = a;
    a = b;
    b = t;
}

float math(float x) {
    return sqrt((1 / 5) + pow(exp(x),1.0/5)) / abs(log(pow(x,2)) - 1.3);
}

int main(void) {
    bool executable = false;

    int n = 0;
    float a, b = 0;

    printf("\nВведите N: ");
    scanf("%d", &n);
    printf("Введите A: ");
    scanf("%f", &a);
    printf("Введите B: ");
    scanf("%f", &b);

    if (a > b) {
        swapFloat(a, b);
    }

    if (a == b) {
        n = 1;
    }

    if (n > 0) {
        executable = true;
    }

    if (executable) {
        printf("\nN       x              y");
        if (n == 1) {
            float x = a + ((b - a) / 2);
            printf("\n%d       %2.2f           %2.2f", n, x, math(x));
        } else {
            for (int i = 0; i < n; i++) {
                float x = (a + (b - a)/(n - 1) * (i));
                printf("\n%d       %2.2f           %2.2f", i + 1, x, math(x));
            }
        }
        printf("\n");
    } else {
        printf("\nПрограмма не может быть выполнена с заданным набором параметров\n");
    }

    return 0;
}
