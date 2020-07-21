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
#include <string.h>

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
    
    if ((year < 1 || year > 9999) || (month < 1 || month > 12)) {
        printf("Not valid date 1\n");
    } else {
        if (year % 4 == 0 && month == 2 && (day < 1 || day > 29)) {
            printf("Not valid date 2\n");
        } else if (year % 4 != 0 && month == 2 && (day < 1 || day > 28)) {
            printf("Not valid date 3\n");
        } else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
            printf("Not valid date 4\n");
        } else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 10 || month == 12) && (day < 1 || day > 31)) {
            printf("Not valid date 5\n");
        } 
    }
}

//option 2: 
void option2 () {
    char *character;
    character = (char *) malloc (0 * sizeof(char));
    
    do {
        gets(character);
        __fpurge(stdin);
        
        if (strlen(character) != 2) {
            printf("your input need 2 character\n");
        }
    } while (strlen(character) != 2);
    
    character = realloc(character, 2 * sizeof(char));
    printf("output: %s\n", character);    
    
    char firstChar = character[0], secondChar = character[1];
    
    if (firstChar < secondChar) {
        int temp = firstChar;
        firstChar = secondChar;
        secondChar = temp;
    }
    
    for (int i = firstChar; i >= secondChar; i--) {
        printf("%c: %d\n", i, i);
    }
}

//function 1:Display menu and ask user to select the option
void displayMenu (int *choice) {
    int verifyInput;
    printf("             MENU\n");
    printf("------------------------------\n");
    
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
            option2();
            break;
    }
}

//option 2:

int main() {
    int choice;
    
    do {
        displayMenu(&choice);

        runFunctionWithChoice(choice);
    } while (choice != 3);
    
}
