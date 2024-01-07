#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task>& tasks, const string& description);
void viewTasks(const vector<Task>& tasks);
void markTaskAsCompleted(vector<Task>& tasks, int taskIndex);
void removeTask(vector<Task>& tasks, int taskIndex);

int main() {
    vector<Task> tasks;  // Vector to store tasks

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();  // Clear input buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                markTaskAsCompleted(tasks, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back({description, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << setw(5) << "Index" << setw(20) << "Description" << setw(15) << "Status" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << setw(5) << i << setw(20) << tasks[i].description << setw(15)
             << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
        tasks[taskIndex].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}

void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskIndex);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index. Please enter a valid index." << endl;
    }
}