#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

class Process {
public:
    string name;
    int PID;
    string SessionName;
    int SessionNumber;
    int MemoryUsage;

    // Constructor to initialize process details
    Process(string name, int PID, string SessionName, int SessionNumber, int MemoryUsage)
            : name(name), PID(PID), SessionName(SessionName), SessionNumber(SessionNumber), MemoryUsage(MemoryUsage) {}

    // Function to display process details
    void display() const {
        cout << setw(26) << left << name << setw(8) << right << PID << " " << setw(17) << left << SessionName
             << setw(11) << right << SessionNumber << setw(11) << right << MemoryUsage << " K\n";
    }
};

class ProcessList {
public:
    vector<Process> processes;

    // Function to fill the process list from the operating system
    void fillFromOS() {
        // Run the tasklist command on Windows to get the list of running processes
        FILE* pipe = _popen("tasklist /fo csv /nh", "r");
        // pipe is a object from type file from cstdlib
        //_popen function It opens a pipe to a command
        // "tasklist -> to open it "/fo csv -> format as CSV (Comma-Separated Values) name ,pid ,...
        //"/nh -> skip header line  (elly fo2) // "r" -> read


        // Check if the pipe is successfully opened
        if (!pipe) {
            cout << "Error: Unable to run tasklist command.\n";
            return;
        }

        char buffer[256];//temp array to store the line

        // Read each line of the output from the tasklist command tobuffer array
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            // slice the CSV line using (string tokenize) using \ , as deli
            char* name = strtok(buffer, "\",");
            int pid = atoi(strtok(nullptr, "\",")); //take start from the prev
            char* sessionName = strtok(nullptr, "\",");
            int sessionNumber = atoi(strtok(nullptr, "\","));
            int memoryUsage = atoi(strtok(nullptr, "\","));


            // Create a Process object and add it to the list
            processes.emplace_back(name, pid, sessionName, sessionNumber, memoryUsage);
        }

        // Close the pipe
        _pclose(pipe);
    }

    // Function to display the list of processes as it is in cmd

    void displayProcesses() {
        // Display the header
        cout << "Image Name                PID      Session Name     Session#    Mem Usage\n";
        cout << "========================= ======== ================ =========== ============\n";

        // Display the processes
        for (const Process& process : processes) {
            process.display();
        }
    }
    // Function to display the list of processes sorted by a specified key
    void displaySorted(const string& key) {
cout << "-------------------------------------------------------------------------\n";
        if (key == "name") {
            sort(processes.begin(), processes.end(),[](const Process& a, const Process& b){return a.name<b.name;});
            cout << "sorted by Name : \n ";
        }
        else if (key == "pid") {
            sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {return a.PID < b.PID;});
            cout << "sorted by PID : \n ";

        }
        else if (key == "memory") {
            sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {return a.MemoryUsage < b.MemoryUsage;});
            cout << "sorted by memory usage : \n ";

        }

        // Display the sorted processes
        displayProcesses();

    }
};

int main() {
    ProcessList taskManager;
    taskManager.fillFromOS();
    taskManager.displayProcesses();
    taskManager.displaySorted("name");
    taskManager.displaySorted("pid");
    taskManager.displaySorted("memory");

    return 0;
}
