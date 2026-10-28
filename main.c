#include <stdio.h>

// PM2.5 утгаар ангиллын нэр буцаах
void GetAQIClass(float pm, char* result) {
    if (pm <= 50) {
        snprintf(result, 50, "Сайн");
    } else if (pm <= 100) {
        snprintf(result, 50, "Дунд зэрэг");
    } else if (pm <= 150) {
        snprintf(result, 50, "Сөрөг нөлөөтэй");
    } else if (pm <= 200) {
        snprintf(result, 50, "Муу");
    } else if (pm <= 300) {
        snprintf(result, 50, "Маш муу");
    } else {
        snprintf(result, 50, "Аюултай");
    }
}

int main() {
    float pm[7];
    int day[7];

    // 7 өдрийн утгыг авах
    for (int i = 0; i < 7; i++) {
        do {
            printf("Өдөр %d-ийн PM2.5: ", i + 1);
            scanf("%f", &pm[i]);
            if (pm[i] < 0) {
                printf("Алдаа: Утга сөрөг байж болохгүй!\n");
            }
        } while (pm[i] < 0);
        day[i] = i + 1;
    }

    // Том утгаас бага руу эрэмбэлэх (өдрийг хамт солино)
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (pm[i] < pm[j]) {
                float tempPm = pm[i];
                pm[i] = pm[j];
                pm[j] = tempPm;

                int tempDay = day[i];
                day[i] = day[j];
                day[j] = tempDay;
            }
        }
    }

    // Хамгийн бохир 3 өдөр
    printf("\nХАМГИЙН БОХИР 3 ӨДӨР:\n");
    for (int i = 0; i < 3; i++) {
        char category[50];
        GetAQIClass(pm[i], category);
        printf("%d. %d-р өдөр: PM2.5 = %.2f (%s)\n", i + 1, day[i], pm[i], category);
    }

    return 0;
}