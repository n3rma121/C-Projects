#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void readList();
void writeList();
void deleteTask();

int main() {
    int choose;
    bool running = true;

    cout << "***** Welcome to your TODO app *****\n";

    do {
        cout << "________________________________________\n";
        cout << "Choose '1' to list your tasks\n"
             << "Choose '2' to see your tasks\n"
             << "Choose '3' to Delete Task\n"
             << "Choose '4' to exit the app\n";
        cout << "_________________________________________\n\n";
        cout << "-> ";
        cin >> choose;
        cin.ignore();
        switch (choose) {
            case 1:
                writeList();
                break;

            case 2:
                readList();
                break;

            case 3:
                deleteTask();
                break;

            case 4:
                running = false;
                cout << "\nExiting the app.\n";
                break;

            default:
                cout << "Please enter a valid choice.\n";
                break;
        }
    } while (running);

    return 0;
}

void readList() {
    ifstream fin("todo.txt");
    string line;
    int i = 1;
    while (getline(fin, line)) {
        cout << i++ << ": " << line << endl;
    }
    fin.close();
}

void writeList() {
    ofstream fout("todo.txt", ios::app);
    string line;
    cout << "Enter your task TODO (enter '-1' to exit): \n";
    while (getline(cin, line)) {
        if (line == "-1") {
            break;
        }
        fout << line << endl;
    }
    fout.close();
}

void deleteTask() {
    ifstream fin("todo.txt");
    ofstream fout("temp.txt"); // Create a temporary file

    string line;
    int lineToDelete;

    cout << "Enter the line number of the task to delete: ";
    cin >> lineToDelete;

    if (lineToDelete < 1) {
        cout << "Invalid line number.\n";
        return;
    }

    int currentLine = 0;
    while (getline(fin, line)) {
        currentLine++;
        if (currentLine != lineToDelete) {
            fout << line << endl; // Write lines other than the one to delete
        }
    }

    fin.close();
    fout.close();

    // Rename the temporary file to replace the original file
    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    cout << "Task deleted.\n";
}
