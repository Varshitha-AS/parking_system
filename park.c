#include "assignment1.h"
void parkVehicle() {
    int nearest_slot = findNearestVacantSlot();

    if (nearest_slot == -1) {
        printf("Sorry, parking lot is full\n");
        return;
    }

    slots_occupied[nearest_slot] = true;
    printf("Vehicle parked at slot %d\n", slot_numbers[nearest_slot]);
}