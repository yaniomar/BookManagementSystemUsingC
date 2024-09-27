#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100  // Maximum number of books
#define NAMESIZE 50  // Maximum length of the name of the book

// Yanal Omar
// 1230156
// Lab section 11
// Lecture section 2

// Function declarations
void displayMainMenu();
void addBook(char names[][NAMESIZE], int bins[], double prices[], int *size);
void removeBook(char names[][NAMESIZE], int bins[], double prices[], int *size);
void searchForBook(char names[][NAMESIZE], int bins[], double prices[], int size);
void uploadDataFile(char names[][NAMESIZE], int bins[], double prices[], int *size);
void updateDataFile(char names[][NAMESIZE], int bins[], double prices[], int size);
void printBooks(char names[][NAMESIZE], int bins[], double prices[], int size);

int main()
{
    int size = 0;  // Number of books currently in the system
    int bins[MAXSIZE];  // Array to store book bin numbers
    double prices[MAXSIZE];  // Array to store book prices
    char names[MAXSIZE][NAMESIZE];  // Array to store book names
    int choice;

    printf("Welcome to my BookStore Management System\n");

    // Load initial data from file
    uploadDataFile(names, bins, prices, &size);

    do
    {
        // Display the main menu and get user choice
        displayMainMenu();
        scanf("%d", &choice);

        // Handle user choice
        if (choice == 1)
        {
            addBook(names, bins, prices, &size);
        }
        else if (choice == 2)
        {
            removeBook(names, bins, prices, &size);
        }
        else if (choice == 3)
        {
            searchForBook(names, bins, prices, size);
        }
        else if (choice == 4)
        {
            printBooks(names, bins, prices, size);
        }
        else if (choice == 5)
        {
            // Save data and exit
            updateDataFile(names, bins, prices, size);
        }
        else
        {
            printf("No such choice, please enter a valid number\n");
        }
    } while (choice != 5);

    printf("Thank you for using my BookStore Management System, Goodbye!\n");
    return 0;
}

// Function to display the main menu
void displayMainMenu()
{
    printf("\n");
    printf("Please select an operation (1-5):\n");
    printf("1- Add a Book\n");
    printf("2- Remove a Book\n");
    printf("3- Search for a Book\n");
    printf("4- Print Book List\n");
    printf("5- Exit System\n");
    printf("\n");
}

// Function to add a book
void addBook(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    int bin;
    double price;
    char name[NAMESIZE];

    // Check if the library is full
    if (*size >= MAXSIZE)
    {
        printf("Error: The library is full\n");
        return;
    }

    // Get book bin from the user
    printf("Enter the bin number of the book: ");
    scanf("%d", &bin);

    // Check if the book already exists
    for (int i = 0; i < *size; i++)
    {
        if (bin == bins[i])
        {
            printf("Error: Book is already in the library\n");
            return;
        }
    }
    // Get book name from the user
    printf("Enter the name of the book: ");
    scanf("%s", name);
    // Get book price from the user
    printf("Enter the price of the book: ");
    scanf("%lf", &price);

    // Insert the new book in the correct position (sorted order)
    int i;
    for (i = *size - 1; i >= 0 && bins[i] > bin; i--)
    {
        bins[i + 1] = bins[i];
        prices[i + 1] = prices[i];
        strcpy(names[i + 1], names[i]);
    }

    bins[i + 1] = bin;
    prices[i + 1] = price;
    strcpy(names[i + 1], name);

    (*size)++;
    printf("Book with bin %d has been added\n", bin);
}

// Function to remove a book
void removeBook(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    int bin;
    int check = 0;

    // Check if the library is empty
    if (*size == 0)
    {
        printf("Error: The library is empty\n");
        return;
    }

    // Get the bin number of the book to remove
    printf("Enter the bin number of the book you want to remove: ");
    scanf("%d", &bin);

    // Find and remove the book
    for (int i = 0; i < *size; i++)
    {
        if (bin == bins[i])
        {
            for (int j = i; j < (*size) - 1; j++)
            {
                bins[j] = bins[j + 1];
                prices[j] = prices[j + 1];
                strcpy(names[j], names[j + 1]);
            }
            check = 1;
            (*size)--;
            break;
        }
    }

    if (check == 0)
        printf("Error: Book with bin %d does not exist\n", bin);
    else
        printf("Book with bin %d has been removed\n", bin);
}

// Function to search for a book
void searchForBook(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    int bin;
    int check = 0;

    // Check if the library is empty
    if (size == 0)
    {
        printf("Error: The library is empty\n");
        return;
    }

    // Get the bin number of the book to search
    printf("Enter the bin number to search: ");
    scanf("%d", &bin);

    // Print the book details if found
    printf("---------------------------------------------------+----------------+-----------------\n");
    printf("|                    Book Name                     |   Book Bin     |   Book Price   |\n");
    printf("--------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++)
    {
        if (bin == bins[i])
        {
            printf("|%-49s |   %-12d |   %-12.2lf |\n", names[i], bins[i], prices[i]);
            check = 1;
            break;
        }
    }

    if (check == 0){
        printf("Error: Book with bin %d does not exist\n", bin);
        return 0;
    }

    printf("--------------------------------------------------------------------------------------\n");
}

// Function to print all books
void printBooks(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    // Check if the library is empty
    if (size == 0)
    {
        printf("Error: The library is empty\n");
        return;
    }

    // Print the book list
    printf("---------------------------------------------------+----------------+-----------------\n");
    printf("|                    Book Name                     |   Book Bin     |   Book Price   |\n");
    printf("--------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("|%-49s |   %-12d |   %-12.2lf |\n", names[i], bins[i], prices[i]);
    }
    printf("--------------------------------------------------------------------------------------\n");
}

// Function to upload data from a file
void uploadDataFile(char names[][NAMESIZE], int bins[], double prices[], int *size)
{
    printf("Uploading data file ...\n");

    // Open the file for reading
    FILE *file = fopen("books.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    // Read data from the file
    while (fscanf(file, "%s %d %lf", names[*size], &bins[*size], &prices[*size]) != EOF)
    {
        (*size)++;
    }

    // Close the file
    fclose(file);
    printf("Data file uploaded\n");
}

// Function to update data file
void updateDataFile(char names[][NAMESIZE], int bins[], double prices[], int size)
{
    printf("Updating data file ...\n");

    // Open the file for writing
    FILE *file = fopen("books.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write data to the file
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s %d %.2lf\n", names[i], bins[i], prices[i]);
    }

    // Close the file
    fclose(file);
    printf("Data file updated\n");
}
