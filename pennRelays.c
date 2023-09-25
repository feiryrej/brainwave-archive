#include <stdio.h>

void displayInstructions() {
    printf("\n\tPENN RELAYS!");
    printf("\n\n\tFour Tracks have entered the mile race at Penn Relays!");
    printf("\n\n\tThis program calculates the speed of runners in feet per second and meters per second.\n");
    printf("\tPlease enter the race time in minutes and seconds for each runner.\n");
}

float* calculateSpeed(int totalTime, const int FEET_PER_MILE, const float FEET_PER_METER) {
    static float speeds[2];
    speeds[0] = FEET_PER_MILE / (float)totalTime;  // feet per second
    speeds[1] = FEET_PER_MILE / (FEET_PER_METER * totalTime);  // meters per second
    return speeds;
}

int main() {
    int minutes, seconds;
    const int FEET_PER_MILE = 5280;
    const float FEET_PER_METER = 3.282;

    displayInstructions();

    // Runner 1
    printf("\n|Runner 1|\n");
    printf("\tEnter minutes: ");
    scanf("%d", &minutes);
    printf("\tEnter seconds: ");
    scanf("%d", &seconds);
    int totalTime = minutes * 60 + seconds;
    float* speeds = calculateSpeed(totalTime, FEET_PER_MILE, FEET_PER_METER);
    printf("\n\tRunner 1 ran at a speed of %.2f feet per second and %.2f meters per second.\n", speeds[0], speeds[1]);

    // Runner 2
    printf("\n|Runner 2|\n");
    printf("\tEnter minutes: ");
    scanf("%d", &minutes);
    printf("\tEnter seconds: ");
    scanf("%d", &seconds);
    totalTime = minutes * 60 + seconds;
    speeds = calculateSpeed(totalTime, FEET_PER_MILE, FEET_PER_METER);
    printf("\n\tRunner 2 ran at a speed of %.2f feet per second and %.2f meters per second.\n", speeds[0], speeds[1]);

    // Runner 3
    printf("\n|Runner 3|\n");
    printf("\tEnter minutes: ");
    scanf("%d", &minutes);
    printf("\tEnter seconds: ");
    scanf("%d", &seconds);
    totalTime = minutes * 60 + seconds;
    speeds = calculateSpeed(totalTime, FEET_PER_MILE, FEET_PER_METER);
    printf("\n\tRunner 3 ran at a speed of %.2f feet per second and %.2f meters per second.\n", speeds[0], speeds[1]);

    // Runner 4
    printf("\n|Runner 4|\n");
    printf("\tEnter minutes: ");
    scanf("%d", &minutes);
    printf("\tEnter seconds: ");
    scanf("%d", &seconds);
    totalTime = minutes * 60 + seconds;
    speeds = calculateSpeed(totalTime, FEET_PER_MILE, FEET_PER_METER);
    printf("\n\tRunner 4 ran at a speed of %.2f feet per second and %.2f meters per second.\n", speeds[0], speeds[1]);

    return 0;
}
