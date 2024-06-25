#include "assignment1.h"
#include "initialize.c"
#include "nearest.c"
#include "park.c"
#include "unpark.c"
#include "display.c"

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