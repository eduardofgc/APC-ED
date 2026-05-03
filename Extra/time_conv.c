#include <stdio.h>

int main() {
    int horas;
    char time[100];

    scanf("%s", time);

    sscanf(time, "%2d", &horas);

    if (time[8] == 'P') { // PM case
        if (horas != 12) {
            horas += 12;
        }
    }
    else {
        if (horas == 12) {
            horas = 0;
        }
    }

    printf("%02d:%c%c:%c%c\n", horas, time[3], time[4], time[6], time[7]);

    return 0;
}