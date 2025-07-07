#include <iostream>
using namespace std;

int** storinginput(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            arr[i][j] = 0;

    return arr;
}

void displayarray(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        cout << "Row " << i + 1 << ":    ";
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
    cout << "--------------------------------------------------------\n";
}

void bookseat(int**& arr, int row, int col)
{
    int keyrow = 0, keycol = 0;
    cout << "Enter the row (1-" << row << "): ";
    cin >> keyrow;
    cout << "Enter the seat number (1-" << col << "): ";
    cin >> keycol;

    if (keyrow < 1 || keyrow > row || keycol < 1 || keycol > col)
    {
        cout << "Invalid seat coordinates!\n--------------------------------------------------------\n";
        return;
    }

    if (arr[keyrow - 1][keycol - 1] == 1)
    {
        cout << "Seat is already booked!\n--------------------------------------------------------\n";
        return;
    }

    arr[keyrow - 1][keycol - 1] = 1;
    cout << "Seat Booked successfully\n--------------------------------------------------------\n";
}

void cancelseat(int**& arr, int row, int col)
{
    int keyrow = 0, keycol = 0;
    cout << "Enter the row (1-" << row << "): ";
    cin >> keyrow;
    cout << "Enter the seat number (1-" << col << "): ";
    cin >> keycol;

    if (keyrow < 1 || keyrow > row || keycol < 1 || keycol > col)
    {
        cout << "Invalid seat coordinates!\n--------------------------------------------------------\n";
        return;
    }

    if (arr[keyrow - 1][keycol - 1] == 0)
    {
        cout << "Seat is already empty!\n--------------------------------------------------------\n";
        return;
    }

    arr[keyrow - 1][keycol - 1] = 0;
    cout << "Seat Canceled successfully\n--------------------------------------------------------\n";
}

void calculatetotal(int** arr, int row, int col)
{
    int available = 0, booked = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            (arr[i][j] == 0) ? available++ : booked++;

    cout << "Available seats: " << available << endl;
    cout << "Booked seats   : " << booked << endl;
    cout << "--------------------------------------------------------\n";
}

int main()
{
    int row = 5, col = 10;
    int** arr = new int* [row];

    for (int i = 0; i < row; i++)
        arr[i] = new int[col];

    arr = storinginput(arr, row, col);

    cout << "\n================= Welcome to Cinema Seat Booking System =================\n";

    while (true)
    {
        int choice;
        cout << "1. Show All Seats\n2. Book a Seat\n3. Cancel a Seat\n4. Count Available and Booked Seats\n5. Exit\n";
        cout << "Enter your choice here: ";
        cin >> choice;
        cout << "\n--------------------------------------------------------\n";

        if (choice == 1)
            displayarray(arr, row, col);
        else if (choice == 2)
            bookseat(arr, row, col);
        else if (choice == 3)
            cancelseat(arr, row, col);
        else if (choice == 4)
            calculatetotal(arr, row, col);
        else if (choice == 5)
            break;
        else
            cout << "Invalid choice. Try again!\n--------------------------------------------------------\n";
    }

    for (int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
