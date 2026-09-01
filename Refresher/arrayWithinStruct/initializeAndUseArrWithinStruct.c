// Example of an initialization and use of the Array within Structure

// C program to demonstrate the array within structures
#include <stdio.h>
#include <string.h>

// Defining array within structure
struct Employee {
    // character array to store name of the employee
    char Name[20];
    int employeeID;
    // integer array to maintain the record of the attendance of the employee
    int WeekAttendance[7];
};

int main()
{
    // defining structure of type Employee
    struct Employee emp;

    // adding data
    emp.employeeID = 1;
    strcpy(emp.Name, "Rohit");
    int week;
    for(week=0; week<7; week++){
        emp.WeekAttendance[week] = 1;   // e.g., mark present each day
    }

    // printing the data
    printf("Employee ID: %d - Employee Name: %s\n", emp.employeeID, emp.Name);
    printf("Attendance\n");
    for(week=0; week<7; week++){
        printf("%d ", emp.WeekAttendance[week]);
    }
    printf("\n");

    return 0;
}

/*
I modified it since there are something from geeksforgeeks 
that didn't made sense
*/