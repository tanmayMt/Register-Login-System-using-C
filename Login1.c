#include <stdio.h>
#include <conio.h>
#include <string.h> //strcmp()
#include <stdlib.h> //system()
int main()
{
    system("cls");
    char ch;
    char pass[20], saved_pass[20], user_name[20], saved_name[20];
name:
    printf("Enter username : ");
    scanf("%s", user_name);

    FILE *ptr;
    ptr = fopen("password.txt", "r");

    fscanf(ptr, "%s%s", saved_name, saved_pass);
    if (strcmp(user_name, saved_name) != 0)
    {
        printf("\n********INCOREECT USERNAME******** \nPlease Try again\n");
        goto name;
    }
    else
    {
    start:

        printf("Enter your password  : ");
        int i = 0;
        while (1) // Infinite Loop for taking password
        {
            ch = getch(); // we use getch() so that every time user enter a character the compiler will able to print asterisk sign instead of character itself
            // If use press Enter Loop will be terminated
            if (ch == 13) // 13 is ASCII Value of Enter or '\0'
            {
                pass[i] = '\0'; // Concatenate a null character '\0' at the end of "password" string.
                break;
            }
            // In case if you type wrong password by mistake then we can't erase from prompt input
            else if (ch == 8) // ASCII value of backspace ( "\b" ) is 8
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (ch == 9 || ch == 32) // ASCII value 9->Tab 32->Space
            {
                continue;
            }
            else
            {
                pass[i++] = ch; // For taking next character of password string
                printf("*");    // After adding each charcter asterisk sign will be printed.
            }
        }

        int l = strcmp(pass, saved_pass);
        if (l == 0)
        {
            printf("\n\n******LOGIN SUCCESSFUL******\n");
        }
        else
        {
            printf("\n\n******INCORRECT PASSWORD******\nPlease Try again...\n\n");
            goto start;
        }
        fclose(ptr);
        return 0;
    }
}