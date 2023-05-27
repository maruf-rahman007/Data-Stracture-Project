#include <iostream>
#include <windows.h> // Required for Windows-specific console functions

using namespace std;

// Function to set the cursor position in the console
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to set the console text color
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Custom circular queue implementation
class CircularQueue
{
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;
    int cnt;

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity + 99999];
        this->front = 0;
        this->rear = -1;
        this->count = 0;
        this->cnt = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return count == capacity;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(int dishCleaningTime)
    {
        if (isFull())
        {
            cout << "\n\n\t\t\t\t\t Dish washer is full. Cannot add more dishes." << endl;
            return;
        }
        rear++;
        arr[rear] = dishCleaningTime;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\n\n\t\t\t\t\t Dish washer is empty. No dishes to clean." << endl;
            return ;
        }
        front++;
        count--;
        cout << "\n\n\t\t\t\t\t  Another Dish Cleaned ........ \n";
        cnt++;
        return ;
    }

    int getNumCleanedDishes()
    {
        return cnt;
    }

    int getTotalCleaningTime()
    {
        int totalCleaningTime = 0;
        for (int i = front; i <= rear; i++)
        {
            totalCleaningTime += arr[i];
        }
        return totalCleaningTime;
    }

    int getNumRemainingDishes()
    {
        return count;
    }
};

// Function to validate and get input from the user
int getInput(const string& prompt, const string& errorMsg = "")
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (value < 1)
        {
            cout << "Invalid input. Please try again." << endl;
            cin.clear(); // Clear the error flag
        }
        else
        {
            break;
        }
    }
    return value;
}

void Title()
{
    gotoxy(42, 4);
    cout << "---------------------\n";
    gotoxy(42, 5);
    cout << " Premium Dish Washer \n\n";
    gotoxy(42, 6);
    cout << "---------------------\n\n\n";
}

int main()
{
    Title();
    int capacity, dishCleaningTime;
    int totalDishes = 0;

    capacity = getInput("\t\t\t Enter the capacity of the dish washer: ", "Invalid capacity. Please enter a positive integer.");

    CircularQueue dishWasher(capacity);
    system("cls"); // Clear the console screen
    while(1)
    {
        Title();
        int choise;
        gotoxy(42, 9);
        cout << "1. Number of Dish Cleaned \n";
        gotoxy(42, 10);
        cout << "2. Total Required Cleaning Time \n";
        gotoxy(42, 11);
        cout << "3. Number of Dish Remaining \n";
        gotoxy(42, 12);
        cout << "4. Clean Dish \n";
        gotoxy(42, 13);
        cout << "5. Add Dish  \n";
        gotoxy(42, 14);
        cout<< "Which One You Want To Do : ";
        gotoxy(69, 14);
        cin >> choise;
        switch(choise)
        {
        case 1 :
            cout << "\n\n\t\t\t\t\t Number of Dishes Cleaned: " << dishWasher.getNumCleanedDishes() << endl;
            break;
        case 2 :
            cout << "\n\n\t\t\t\t\t Total Required Cleaning Time: " << dishWasher.getTotalCleaningTime() << " minutes" << endl;
            break;
        case 3 :
            cout << "\n\n\t\t\t\t\t Number of Dish Remaining: " << dishWasher.getNumRemainingDishes() << endl;
            break;
        case 4 :
            dishWasher.dequeue();
            break;
        case 5 :
            int time ;
            cout << "\n\n\t\t\t\t\t Enter the cleaning time for the dish (in minutes): ";
            cin >> time;
            dishWasher.enqueue(time);
            break;
        default :
            cout << "\n\n \t\t\t\t\t Turning Dish Washer Off \n";
            return 0;

        }
        getchar();
        cout << "\n\n\t\t\t\t\t Press Any Key To Continue........ " <<
        getchar();
        system("cls");
    }

    return 0;
}
