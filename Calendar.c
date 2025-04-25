#include <stdio.h>
// Function to get the day of the week for a given date
// It returns an integer representing the day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)

int getDayOfWeek(int day, int month, int year) {
    int adjustment, mm, yy;
     // Adjustment for months January and February in the Gregorian calendar
    adjustment = (14 - month) / 12;
     // Calculate the year and month for the algorithm
    yy = year - adjustment;
    mm = month + 12 * adjustment - 2;
    // Zeller's congruence formula to calculate the day of the week
    return (day + yy + yy / 4 - yy / 100 + yy / 400 + (31 * mm) / 12) % 7;
}
// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfWeek, daysInMonth;

    // Handle leap year for February
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days[1] = 29;
    }

    daysInMonth = days[month - 1];
    dayOfWeek = getDayOfWeek(1, month, year);

    printf("\n  Calendar for %s %d\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print spaces for the first week
    for (int i = 0; i < dayOfWeek; i++) {
        printf("     ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%5d", day);
        if ((day + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return 1;
    }

    printCalendar(month, year);

    return 0;
}
