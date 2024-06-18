#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int menu();
void signup();
void login();
// void forgot();
// void change_password();
// void delete_account();

struct account
{
    char first_name[20];
    char last_name[20];
    char username[30];
    char phone[15];
    char gender;
    char DOB[10];
    char pass1[20];
};

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}

int main()
{
    while (1)
    {
        system("cls");
        switch (menu())
        {
        case 1:
            signup();
            break;

        case 2:
            login();
            break;

        case 3:
            // forgot();
            break;

        case 4:
            // change_password();
            break;

        case 5:
            // delete_account();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}

int menu()
{
    int c;
    printf("\n******************MAIN MENU******************\n");
    divider();
    printf("\n1.SIGNUP\n");
    printf("2.LOGIN\n");
    printf("3.FORGOT PASSOWRD OR USERNAME\n");
    printf("4.CHANGE PASSWORD\n");
    printf("5.DELETE ACCOUNT\n");
    printf("6.EXIT\n");
    divider();
    printf("\nEnter your choice : ");
    scanf("%d", &c);
    return c;
}

void takepassword(char pass[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }
}

void signup()
{
    struct account u;
    system("cls");
    char pass2[20];
    printf("CREATING NEW ACCOUNT \n");
    divider();
    printf("\nENTER your first name : ");
    scanf("%s", u.first_name);
    printf("Enter last name : ");
    scanf("%s", u.last_name);
    printf("Enter your username : ");
    scanf("%s", u.username);
    printf("Enter your phone number : ");
    scanf("%s", u.phone);
    fflush(stdin);
    printf("Enter Gender : ");
    scanf("%c", &u.gender);
    printf("Enter your DOB : ");
    scanf("%s", u.DOB);

    printf("Enter password : ");
    takepassword(u.pass1);

conf_pass:
    printf("\nConfirm password : ");
    // scanf("%s", pass2);
    takepassword(pass2);

    if (strcmp(u.pass1, pass2))
    {
        printf("\nINCORRECT PASSWORD \n\n");
        goto conf_pass;
    }
    else
    {
        printf("\nACCOUNT CREATED SUCCESSFULLY\n\n");
        getch();

        FILE *fp = fopen("account.txt", "w");
        fwrite(&u, sizeof(struct account), 1, fp);
        fclose(fp);
    }
}

void login()
{
    system("cls");
    char user[30], log_pass[20];

    struct account u;
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fp);

name:
    printf("Enter Username : ");
    scanf("%s", user);
    if (strcmp(u.username, user))
    {
        printf("\nPLEASE ENTER CORRECT USERNAME\n ");
        goto name;
    }

    else
    {
    logpass:
        printf("Enter password : ");
        takepassword(log_pass);
        if (strcmp(u.pass1, log_pass))
        {
            printf("\nINCORRET PASSWORD \n");
            goto logpass;
        }
        else
        {
            system("cls");
            printf("\n************ WELCOME %s ************\n", u.first_name);
            divider();

            printf("\nYour Details \n");
            divider();
            printf("\nUsername     : %s\n", u.username);
            printf("First name   : %s\n", u.first_name);
            printf("Last name    : %s\n", u.last_name);
            printf("Phone number : %s\n", u.phone);
            printf("Gender       : %c\n", u.gender);
            printf("Password     : %s\n", u.pass1);
        }
        getch();
    }
    fclose(fp);
}