#include "assignment1.h"

void displayParkingLot() {
    printf("Parking Lot Status:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        printf("Slot %d: %s\n", slot_numbers[i],
               slots_occupied[i] ? "Occupied" : "Vacant");
    }
}