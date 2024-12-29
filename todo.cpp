#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool isCompleted;

    Task(string desc) {
        description = desc;
        isCompleted = false;
    }

    void markAsCompleted() {
        isCompleted = true;
    }

    void display() {
        cout << description << " [" << (isCompleted ? "Completed" : "Pending") << "]" << endl;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        cout << "Task added: " << taskDescription << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". ";
            tasks[i].display();
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }
        tasks[taskIndex - 1].markAsCompleted();
        cout << "Task " << taskIndex << " marked as completed." << endl;
    }

    void removeTask(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task " << taskIndex << " removed." << endl;
    }
};

void showMenu() {
    cout << "\nTo-Do List Menu" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;
    int taskIndex;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore newline left by cin

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskAsCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}