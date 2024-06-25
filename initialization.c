#include "assignment1.h"
void initializeParkingLot() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        slot_numbers[i] = i + 1;
        slots_occupied[i] = false;
    }
}

