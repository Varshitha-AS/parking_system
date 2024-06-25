#include "assingment1.h"
int findNearestVacantSlot() {
    int nearest_slot = -1;
    int min_distance = MAX_SLOTS + 1; // Initialize to a value greater than maximum possible distance

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (!slots_occupied[i]) {
            // Calculate distance of this slot from the center (assumed to be slot 5)
            int distance = abs(slot_numbers[i] - (MAX_SLOTS / 2 + 1));
            if (distance < min_distance) {
                min_distance = distance;
                nearest_slot = i;
            }
        }
    }

    return nearest_slot;
}
