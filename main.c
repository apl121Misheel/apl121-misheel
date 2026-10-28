#include <stdio.h>

int main() {
    float pm[7], sp[7], sum = 0, avg;
    int sd[7], i, j, mediumDays = 0;

    // 1) Оролт + 7) Оролтын шалгалт (do-while, || ашигласан)
    for (i = 0; i < 7; i++) {
        do {
            printf("Odor %d-iin PM2.5 (0-500): ", i + 1);
            scanf("%f", &pm[i]);
            if (pm[i] < 0 || pm[i] > 500) {
                printf("Алдаа: Утга 0-500 хооронд байх ёстой!\n");
            }
        } while (pm[i] < 0 || pm[i] > 500);

        sum = sum + pm[i];                      // 2) арифметик
        if (pm[i] > 50 && pm[i] <= 100) {       // 2) логик &&
            mediumDays++;
        }
        sp[i] = pm[i];                          // эрэмбэлэх хуулбар
        sd[i] = i + 1;
    }
    avg = sum / 7;

    // 4) 7 мөртэй, тэгшрэлттэй хүснэгт
    printf("\n--- 7 Хоногийн тайлан ---\n");
    printf("%-10s %8s   %s\n", "Өдөр", "PM2.5", "Ангилал");
    for (i = 0; i < 7; i++) {
        printf("%-10d %8.2f   ", i + 1, pm[i]);
        // 3) else-if шат
        if (pm[i] <= 50) {
            printf("Сайн\n");
        } else if (pm[i] <= 100) {
            printf("Дунд зэрэг\n");
        } else if (pm[i] <= 150) {
            printf("Сөрөг нөлөөтэй\n");
        } else if (pm[i] <= 200) {
            printf("Муу\n");
        } else {
            printf("Аюултай\n");
        }
    }
    printf("\nДундаж PM2.5: %.2f\n", avg);
    printf("Дунд зэргийн өдөр: %d\n", mediumDays);

    // 6) Эрэмбэлэлт (хуулбар дээр, өдрийг хамт солино)
    for (i = 0; i < 6; i++) {
        for (j = i + 1; j < 7; j++) {
            if (sp[i] < sp[j]) {
                float tp = sp[i]; sp[i] = sp[j]; sp[j] = tp;
                int td = sd[i];   sd[i] = sd[j]; sd[j] = td;
            }
        }
    }

    printf("\n--- Хамгийн бохир 3 өдөр ---\n");
    printf("%-6s %-10s %8s\n", "No", "Өдөр", "PM2.5");
    for (i = 0; i < 3; i++) {
        printf("%-6d %-10d %8.2f\n", i + 1, sd[i], sp[i]);
    }

    return 0;
}
