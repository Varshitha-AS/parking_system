#include "assignment1.h"
void unparkVehicle() {
    int slot_number;
    printf("Enter slot number to unpark: ");
    scanf("%d", &slot_number);

    if (slot_number < 1 || slot_number > MAX_SLOTS) {
        printf("Invalid slot number\n");
        return;
    }

    if (!slots_occupied[slot_number - 1]) {
        printf("Slot already vacant\n");
    } else {
        slots_occupied[slot_number - 1] = false;
        printf("Vehicle removed from slot %d\n", slot_number);
    }
}

