#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a train reservation
struct Reservation {
    char passengerName[50];
    int seatNumber;
};

// Constants
#define MAX_SEATS 100

// Function to display the menu
void displayMenu() {
    printf("\nRailway Reservation System\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. Check Seat Availability\n");
    printf("4. Display Passengers\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to book a ticket
void bookTicket(struct Reservation reservations[], int *totalReservations) {
    if (*totalReservations < MAX_SEATS) {
        struct Reservation newReservation;
        printf("Enter passenger name: ");
        scanf("%s", newReservation.passengerName);
        printf("Enter seat number (1-%d): ", MAX_SEATS);
        scanf("%d", &newReservation.seatNumber);

        // Check if the seat is available
        int i;
        for (i = 0; i < *totalReservations; i++) {
            if (reservations[i].seatNumber == newReservation.seatNumber) {
                printf("Seat already booked. Please choose another seat.\n");
                return;
            }
        }

        reservations[*totalReservations] = newReservation;
        (*totalReservations)++;
        printf("Ticket booked successfully!\n");
    } else {
        printf("No more seats available!\n");
    }
}

// Function to cancel a ticket
void cancelTicket(struct Reservation reservations[], int *totalReservations) {
    int seatNumber;
    printf("Enter seat number to cancel: ");
    scanf("%d", &seatNumber);

    int i;
    for (i = 0; i < *totalReservations; i++) {
        if (reservations[i].seatNumber == seatNumber) {
            // Move all subsequent reservations up by one position
            for (int j = i; j < (*totalReservations - 1); j++) {
                reservations[j] = reservations[j + 1];
            }
            (*totalReservations)--;
            printf("Ticket for seat %d is canceled.\n", seatNumber);
            return;
        }
    }

    printf("Seat %d not found or already canceled.\n", seatNumber);
}

// Function to check seat availability
void checkSeatAvailability(struct Reservation reservations[], int totalReservations) {
    int seatNumber;
    printf("Enter seat number to check: ");
    scanf("%d", &seatNumber);

    int i;
    for (i = 0; i < totalReservations; i++) {
        if (reservations[i].seatNumber == seatNumber) {
            printf("Seat %d is not available.\n", seatNumber);
            return;
        }
    }

    printf("Seat %d is available.\n", seatNumber);
}

// Function to display all passengers
void displayPassengers(struct Reservation reservations[], int totalReservations) {
    printf("\nPassenger List:\n");
    printf("Seat Number\tPassenger Name\n");
    for (int i = 0; i < totalReservations; i++) {
        printf("%d\t\t%s\n", reservations[i].seatNumber, reservations[i].passengerName);
    }
}

int main() {
    struct Reservation reservations[MAX_SEATS];
    int totalReservations = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket(reservations, &totalReservations);
                break;
            case 2:
                cancelTicket(reservations, &totalReservations);
                break;
            case 3:
                checkSeatAvailability(reservations, totalReservations);
                break;
            case 4:
                displayPassengers(reservations, totalReservations);
                break;
            case 5:
                printf("Exiting Railway Reservation System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}