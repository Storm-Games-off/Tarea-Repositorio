#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUMNOS 2000

typedef struct {
    long long cuenta;
    double max_calificacion;
} Alumno;

int comparar(const void *a, const void *b) {
    const Alumno *x = (const Alumno *)a;
    const Alumno *y = (const Alumno *)b;

    if (x->cuenta < y->cuenta) return -1;
    if (x->cuenta > y->cuenta) return 1;
    return 0;
}

int main(void) {
    int n;
    Alumno alumnos[MAX_ALUMNOS];
    int total_alumnos = 0;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        long long cuenta;
        double calificacion;

        scanf("%lld %lf", &cuenta, &calificacion);

        int encontrado = 0;
        for (int j = 0; j < total_alumnos; j++) {
            if (alumnos[j].cuenta == cuenta) {
                encontrado = 1;
                if (calificacion > alumnos[j].max_calificacion) {
                    alumnos[j].max_calificacion = calificacion;
                }
                break;
            }
        }

        if (!encontrado) {
            alumnos[total_alumnos].cuenta = cuenta;
            alumnos[total_alumnos].max_calificacion = calificacion;
            total_alumnos++;
        }
    }

    qsort(alumnos, total_alumnos, sizeof(Alumno), comparar);

    if (total_alumnos == 0) {
        printf("0");
        return 0;
    }

    printf("%d\n", total_alumnos);

    for (int i = 0; i < total_alumnos; i++) {
        printf("%lld %f", alumnos[i].cuenta, alumnos[i].max_calificacion);
        if (i < total_alumnos - 1) {
            printf("\n");
        }
    }

    return 0;
}
