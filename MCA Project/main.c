#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct Student
{
    char studentName[50];
    char studentID[15];
    char studentDepartment[10];
    char studentAddress[100];
    char studentContactNumber[15];
    float studentCGPA;
} Student;

void createAccount();
void displayInformation();
void updateInformation();
void deleteInformation();
void searchInformation();

int main()
{
    char option;

    while (option != '0')
    {
        system("cls");
        printf("\t\t====== Student Management System NIT Raipur ======\n");
        printf("\n\t\t\t1. Create Student Account");
        printf("\n\t\t\t2. Display All Students Information");
        printf("\n\t\t\t3. Update Student Information");
        printf("\n\t\t\t4. Delete Student Information");
        printf("\n\t\t\t5. Search Student Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayInformation();
            break;
        case '3':
            updateInformation();
            break;
        case '4':
            deleteInformation();
            break;
        case '5':
            searchInformation();
            break;
        case '0':
            printf("\n\t\t\t====== Thank You ======");
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return 0;
}

void createAccount()
{
    FILE *fileOne = fopen("studentInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t====== Create Student Account ======\n");

    printf("\n\t\t\tEnter Student's Name: ");
    getchar();
    gets(stundentInformation.studentName);
    printf("\t\t\tEnter Student's ID: ");
    gets(stundentInformation.studentID);
    printf("\t\t\tEnter Student's Department: ");
    gets(stundentInformation.studentDepartment);
    printf("\t\t\tEnter Student's Address: ");
    gets(stundentInformation.studentAddress);
    printf("\t\t\tEnter Student's Contact Number: ");
    gets(stundentInformation.studentContactNumber);
    printf("\t\t\tEnter Student's Current CGPA: ");
    scanf("%f", &stundentInformation.studentCGPA);

    fwrite(&stundentInformation, sizeof(stundentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored successfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displayInformation()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t\t====== All Students Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Department", "Address", "Contact", "CGPA");
    printf("\t\t----------------------------------------------------------------------------------------");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", stundentInformation.studentName, stundentInformation.studentID, stundentInformation.studentDepartment, stundentInformation.studentAddress, stundentInformation.studentContactNumber, stundentInformation.studentCGPA);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void updateInformation()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update Students Information ======\n");

    printf("\n\t\t\tEnter Student's ID: ");
    getchar();
    gets(tempInformation.studentID);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentID, tempInformation.studentID) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option:\n\t\t\t1.Update Student Name\n\t\t\t2.Update Student Department\n\t\t\t3.Update Student Address\n\t\t\t4.Update Student ContactNumber\n\t\t\t5.Update Student CPGA");
            printf("\n\n\t\t\tEnter Your Option: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's Name to Update: ");
                getchar();
                gets(tempInformation.studentName);
                strcpy(studentInformation.studentName, tempInformation.studentName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's Department to Update: ");
                getchar();
                gets(tempInformation.studentDepartment);
                strcpy(studentInformation.studentDepartment, tempInformation.studentDepartment);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Address to Update: ");
                getchar();
                gets(tempInformation.studentAddress);
                strcpy(studentInformation.studentAddress, tempInformation.studentAddress);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's ContactNumber to Update: ");
                getchar();
                gets(tempInformation.studentContactNumber);
                strcpy(studentInformation.studentContactNumber, tempInformation.studentContactNumber);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's CGPA to Update: ");
                scanf("%f", &tempInformation.studentCGPA);
                studentInformation.studentCGPA = tempInformation.studentCGPA;

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void deleteInformation()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Student Information ======\n");

    printf("\n\t\t\tEnter Student's ID: ");
    getchar();
    gets(tempInformation.studentID);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentID, tempInformation.studentID) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchInformation()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    Student studentInformation;

    int choice, flag = 0;
    char studentID[20], studentDepartment[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search Student Information ======\n");

    printf("\n\t\t\tChoose your option:\n\t\t\t1.Search by Student ID\n\t\t\t2.Search by Student Department");
    printf("\n\n\t\t\tEnter Your Option: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student ID: ");
        getchar();
        gets(studentID);
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (strcmp(studentInformation.studentID, studentID) == 0)
            {
                flag++;
                printf("\n\t\t\tStudent Name: %s\n\t\t\tStudent ID: %s\n\t\t\tStudent Department: %s\n\t\t\tStudent Address: %s\n\t\t\tStudent ContactNumber: %s\n\t\t\tStudent CGPA: %.2f\n", studentInformation.studentName, studentInformation.studentID, studentInformation.studentDepartment, studentInformation.studentAddress, studentInformation.studentContactNumber, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student Department: ");
        getchar();
        gets(studentDepartment);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Department", "Address", "Contact", "CGPA");
        printf("\t\t----------------------------------------------------------------------------------------");
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (stricmp(studentInformation.studentDepartment, studentDepartment) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", studentInformation.studentName, studentInformation.studentID, studentInformation.studentDepartment, studentInformation.studentAddress, studentInformation.studentContactNumber, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}