#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define ANSI color codes
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"

// Define icons
#define CHECKMARK "✔"
#define CROSS "✖"
#define WARNING "⚠"
#define CLIPBOARD "📋"
#define PLUS "➕"
#define MINUS "➖"
#define SCROLL "📜"
#define DOOR "🚪"
#define STAR "🌟"
#define CHECKBOX_CHECKED "☑"
#define CHECKBOX_UNCHECKED "☐"

class Todo
{
private:
    vector<pair<string, bool>> tasks; // Pair of task and its done status

public:
    void addTask(const string &task)
    {
        tasks.emplace_back(task, false); // Add task with "undone" status
        cout << GREEN << CHECKMARK << " Task added successfully!" << RESET << "\n";
    }

    void removeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks.erase(tasks.begin() + index);
            cout << RED << CROSS << " Task removed successfully!" << RESET << "\n";
        }
        else
        {
            cout << RED << WARNING << " Invalid task number!" << RESET << "\n";
        }
    }

    void toggleTaskStatus(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].second = !tasks[index].second; // Toggle the done status
            cout << GREEN << CHECKMARK << " Task status updated successfully!" << RESET << "\n";
        }
        else
        {
            cout << RED << WARNING << " Invalid task number!" << RESET << "\n";
        }
    }

    void listTasks() const
    {
        if (tasks.empty())
        {
            cout << YELLOW << CLIPBOARD << " No tasks available." << RESET << "\n";
        }
        else
        {
            cout << BLUE << CLIPBOARD << " Your Tasks:" << RESET << "\n";
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                cout << CYAN << i + 1 << ". "
                     << (tasks[i].second ? CHECKBOX_CHECKED : CHECKBOX_UNCHECKED) << " "
                     << tasks[i].first << RESET << "\n";
            }
        }
    }
};

int main()
{
    Todo todo;
    int choice;
    do
    {
        cout << "\n"
             << PURPLE << STAR << " Todo Program " << STAR << RESET << "\n";
        cout << CYAN << "1. " << PLUS << " Add Task" << RESET << "\n";
        cout << CYAN << "2. " << MINUS << " Remove Task" << RESET << "\n";
        cout << CYAN << "3. " << SCROLL << " List Tasks" << RESET << "\n";
        cout << CYAN << "4. " << CHECKMARK << " Mark Task Done/Undone" << RESET << "\n";
        cout << CYAN << "5. " << DOOR << " Exit" << RESET << "\n";
        cout << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cin.ignore(); // Clear input buffer
            string task;
            cout << YELLOW << "Enter task: " << RESET;
            getline(cin, task);
            todo.addTask(task);
            break;
        }
        case 2:
        {
            int index;
            cout << YELLOW << "Enter task number to remove: " << RESET;
            cin >> index;
            todo.removeTask(index - 1);
            break;
        }
        case 3:
            todo.listTasks();
            break;
        case 4:
        {
            int index;
            cout << YELLOW << "Enter task number to toggle status: " << RESET;
            cin >> index;
            todo.toggleTaskStatus(index - 1);
            break;
        }
        case 5:
            cout << GREEN << DOOR << " Exiting program. Goodbye!" << RESET << "\n";
            break;
        default:
            cout << RED << WARNING << " Invalid choice. Try again." << RESET << "\n";
        }
    } while (choice != 5);

    return 0;
}