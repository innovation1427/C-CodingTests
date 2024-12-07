//함수 포인터의 배열을 사용한 Home AutoMation Simulation

#include <stdio.h>

typedef void (*ActionFunction)(void);

void turnOnLights(){
    printf("Lights turned on.\n");
}

void adjustThermostat(){
    printf("Thermostat adjusted. \n");
}

void playMusic() {
    printf("Music playing.\n");
}

int main() {
    ActionFunction actionTable[] = {
    turnOnLights,
    adjustThermostat,
    playMusic
    };
    int userChoice;

    printf("Enter your choice (1 for lights, 2 for thermostat, 3 for music): ");
    scanf("%d", &userChoice);

    if (userChoice >= 1 && userChoice <= 3) {
        ActionFunction selectedAction = actionTable[userChoice - 1];
        selectedAction();
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}