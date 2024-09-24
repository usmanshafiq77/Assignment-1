#include <iostream>
#include <string>
using namespace std;

// Structure for each task node
struct Task {
    int taskID;
    string description;
    int priority;
    Task* next;
};

int main() {
    Task* head = nullptr;  // Initialize an empty task list
    int choice, id, priority;
    string description;

    do {
        cout << "\nTask Management Menu:\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove the highest priority task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Add a new task
            cout << "Enter task ID: ";
            cin >> id;
            
            cout << "Enter task description: ";
            cin>>description;
            
            cout << "Enter task priority: ";
            cin >> priority;

            // Here we are creating a new task
            Task* newTask = new Task();
            newTask->taskID = id;
            newTask->description = description;
            newTask->priority = priority;
            newTask->next = nullptr;

            // How to insert task based on priority
            if (head == nullptr || head->priority < priority) {  // Insert at head
                newTask->next = head;
                head = newTask;
            } else {  //How to nsert in correct position based on priority
                Task* temp = head;
                while (temp->next != nullptr && temp->next->priority >= priority) {
                    temp = temp->next;
                }
                newTask->next = temp->next;
                temp->next = newTask;
            }
            cout << "Task added successfully.\n";

        } else if (choice == 2) {
            // The code for view all tasks
            if (head == nullptr) {
                cout << "No tasks available.\n";
            } else {
                Task* temp = head;
                while (temp != nullptr) {
                    cout << "Task ID: " << temp->taskID << ", Description: " << temp->description << ", Priority: " << temp->priority << endl;
                    temp = temp->next;
                }
            }

        } else if (choice == 3) {
            // The code for remove the highest priority task
            if (head == nullptr) {
                cout << "No tasks to remove.\n";
            } else {
                Task* temp = head;
                head = head->next;
                delete temp;
                cout << "Removed the task with the highest priority.\n";
            }

        } else if (choice == 4) {
            // The code for remove a task by ID
            cout << "Enter task ID to remove: ";
            cin >> id;

            if (head == nullptr) {
                cout << "No tasks to remove.\n";
            } else if (head->taskID == id) {  // If the task is at the head
                Task* temp = head;
                head = head->next;
                delete temp;
                cout << "Task with ID " << id << " removed.\n";
            } else {
                Task* temp = head;
                Task* prev = nullptr;

                while (temp != nullptr && temp->taskID != id) {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp == nullptr) {
                    cout << "Task with ID " << id << " not found.\n";
                } else {
                    prev->next = temp->next;
                    delete temp;
                    cout << "Task with ID " << id << " removed.\n";
                }
            }

        } else if (choice == 5) {
            cout << "Exiting the program.\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
