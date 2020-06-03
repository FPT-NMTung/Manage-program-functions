/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: nmtung
 *
 * Created on June 3, 2020, 8:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/*
 * 
 */

//option 1: when user input = 1 (input date, month, year)
void checkValidDateMonthYear () {
    int day, month, year;
    int verifyDay, verifyMonth, verifyYear;
    
    do {
        printf("Day: ");
        verifyDay = scanf("%d", &day);
        __fpurge(stdin);

        printf("Month: ");
        verifyMonth = scanf("%d", &month);
        __fpurge(stdin);

        printf("Year: ");
        verifyYear = scanf("%d", &year);
        __fpurge(stdin);
        
        if (verifyDay != 1) {
            printf("\tEnter again (Wrong datatype of Day)\n");
        }
        if (verifyMonth != 1) {
            printf("\tEnter again (Wrong datatype of Month)\n");
        }
        if (verifyYear != 1) {
            printf("\tEnter again (Wrong datatype of Year)\n\n");
        }
        
        //if wrong datatype => input again
    } while (verifyDay != 1 || verifyMonth != 1 || verifyYear != 1);
    
    if (year < 1 || year > 9999) {
        printf("Not valid date\n");
    } else if (month < 1 || month > 12) {
        
    } else if (day < 1 || day > 31) {
        
    }
}


//function 1:Display menu and ask user to select the option
void displayMenu (int *choice) {
    int verifyInput;
    printf("\nMENU\n");
    printf("------------------------------\n\n");
    
    printf("1 - Processing date data\n");
    printf("2 - Character data\n");
    printf("3 - Quit\n");
    
    do {
        printf("Enter Your Choice: ");
        verifyInput = scanf("%d", choice);
        __fpurge(stdin);
        
        //if wrong => show to user what wrong
        if (verifyInput != 1) {
            printf("Wrong datatype! input again.\n");
        } else if (*choice < 1 || *choice > 3) {
            printf("sure your choice from 1 to 3.\n");
        }
        
        //if wrong datatype and choice not from 1 to 3 => input choice again
    } while (verifyInput != 1 || *choice < 1 || *choice > 3);
    
}

//function 2:Perform selects function
void runFunctionWithChoice (int choice) {    
    
    //choice to option 1 or option 2
    switch (choice) {
        case 1:
            checkValidDateMonthYear();
            break;
        case 2:
            printf("2\n");
            break;
    }
}

//option 2:

int main() {
    int choice;
    
    do {
        displayMenu(&choice);
        printf("%d\n", choice);

        runFunctionWithChoice(choice);
    } while (choice != 3);
    
}

