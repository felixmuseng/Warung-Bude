#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Variables.cpp"
#include "AddDish.cpp"
#include "RemoveDish.cpp"
#include "AddCustomer.cpp"
#include "SearchCustomer.cpp"
#include "ViewWarteg.cpp"
#include "Order.cpp"

const char* detectOS() 
{
    #ifdef _WIN64
    return "Windows 64-bit";
    #elif _WIN32
    return "Windows 32-bit";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}

void printlogo()
{
    system("cls || clear");
    char text[255];
    FILE *fp = fopen("splash-screen.txt", "r");
    while(fscanf(fp, "%[^\n]%*c", text) != EOF)
    {
        printf("%s\n", text);
    }
    fclose(fp);
}

void exit_page()
{
    system("cls || clear");
    printf("Please expand your terminal to full screen!\n");
    printf("Press enter to continue...\n");
    getchar();
    getchar();
    printlogo();
}

void welcome_page()
{
    time_t current;
    current = time(NULL);
    printf("System: %s\n",detectOS());
    printf("%s",ctime(&current));
    puts("1. Add Dish");
    puts("2. Remove Dish");
    puts("3. Add Customer");
    puts("4. Search Customer");
    puts("5. View Warteg");
    puts("6. Order");
    puts("7. Payment");
    puts("8. Exit Warteg");
}

int main_menu_input()
{
    int option;
    scanf("%d", &option);
    return option;
}

void main_menu()
{
    int input;
    system("cls || clear");
    welcome_page();
    do
    {
        printf(">> ");
        input = main_menu_input();
        switch (input)
        {
        case 1:
            AddDish();
            break;
        case 2:
        	RemoveDish();
            break;
        case 3:
        	AddCustomer();
            break;
        case 4:
            SearchCustomer();
            break;
        case 5:
            ViewWarteg();
            break;
        case 6:
        	Order();
            break;
        case 7:
            return;//ga kuat lagi saya bang dh ngantuk, kalo sabar coming soon besok bang
            break;
        case 8:
            exit_page();
            break;
        }
    } while (input < 1 || input > 8);
}

int main()
{
    main_menu();
    return 0;
}