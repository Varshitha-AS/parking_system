#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For abs()

#define MAX_SLOTS 10

int slot_numbers[MAX_SLOTS];
bool slots_occupied[MAX_SLOTS];

void initializeParkingLot() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        slot_numbers[i] = i + 1;
        slots_occupied[i] = false;
    }
}

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

void parkVehicle() {
    int nearest_slot = findNearestVacantSlot();

    if (nearest_slot == -1) {
        printf("Sorry, parking lot is full\n");
        return;
    }

    slots_occupied[nearest_slot] = true;
    printf("Vehicle parked at slot %d\n", slot_numbers[nearest_slot]);
}

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

void displayParkingLot() {
    printf("Parking Lot Status:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        printf("Slot %d: %s\n", slot_numbers[i],
               slots_occupied[i] ? "Occupied" : "Vacant");
    }
}
-
int main() {
    int choice;

    initializeParkingLot();

    do {
        printf("\n1. Park Vehicle\n2. Unpark Vehicle\n3. Display Parking Lot\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                parkVehicle();
                break;
            case 2:
                unparkVehicle();
                break;
            case 3:
                displayParkingLot();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}