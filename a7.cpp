// Abdalla Kharoub
// 665282497


#include <iostream>
#include <string>
#include "a7.h"
using namespace std;

class employee {

protected:

    string name, level, mentor;

    employee* next;

public:

    // parameterized constructor
    employee(string name, string level) {

        this->name = name;

        this->level = level;

        this->mentor = "";

        this->next = nullptr;

    }

    void hire(employee* newEmp) {

        // checking if list is empty
        if (next == nullptr) {

            // if so them add new employee to the start
            next = newEmp;

        } 
        
        // otherwise list is not empty
        else {

            // since list is not empty
            // creat a temp pointer and make it
            // point to what next is pointing to
            employee* temp = next;

            // traverse through the list untill
            // we reach the end
            while (temp->next != nullptr) {

                // update to next node
                temp = temp->next;
            }

            // we reached the end
            // so add newEmp to the end of list
            temp->next = newEmp;

        }
    }
    

    // function to promote or demote an employee by changing their level
    void promoteDemote(string empName, string newLevel) {

        // create temp pointer and make it point
        // to what next is pointing to
        employee* temp = next;

        // traversing through the list as long as
        // temp is not null and that we have not found the name
        while (temp != nullptr && temp->name != empName) {

            temp = temp->next;
        }

        // loop exited thus we found name
        // make sure that temp is not null
        if (temp != nullptr) {

            // promote or demote employee
            temp->level = newLevel;

        } 
        
        // otherwise employee is not found
        else {

            cout << "Employee not found!" << endl;

        }
    }

    // function to look up the level of an employee
    void findLevel(string empName) {

        employee* temp = next;

        // searching for employee by name
        while (temp != nullptr && temp->name != empName) {

            temp = temp->next;

        }

        // makiing sure that temp is not null
        if (temp != nullptr) {

            // display the level of the employee
            cout << "The level of " << empName << " is: " << temp->level << endl;

        } 
        
        // otherwise we have not found employee
        else {

            cout << "Employee not found!" << endl;
        }
    }

    // function to dismiss an employee
    void dismiss(string empName) {

        // checking if next is null
        // if it is then list is empty
        if (next == nullptr) {

            cout << "No employees to dismiss." << endl;

            return;

        }

        employee* temp = next;

        // checking if the first employee is the one to 
        // be dismissed
        if (temp -> name == empName) {

            // declaring pointer delNode and making it point
            // to the current node
            employee* delNode = temp;

            // letting the next pointer point to
            // the next node in the list
            next = temp->next;

            // deleting node
            delete delNode;

            cout << empName << " has been dismissed" << endl;

            // no need to continue
            return;

        }

        // searching for employee by name
        while (temp->next != nullptr && temp->next->name != empName) {

            temp = temp->next;
        }

        // checking if we have reached the 
        // end of the list
        if (temp->next != nullptr) {

            // declaring pointer delNode and making it point
            // to the next node in the list
            employee* delNode = temp->next;

            // making temp next point to the
            // next next node by passing node 
            // to be deleted
            temp->next = delNode->next;

            // deleting node
            delete delNode;

            cout << empName << " has been dismissed" << endl;

        } 
       
        // otherwise we have reached the end of the list
        // and employee was not found
        else {

            cout << "Employee not found :(" << endl;

        }
    }

    // function to assign a mentor to an employee
    void assignMentor(string empName, string mentorName) {


        // create temp pointer and make
        // it point to what next is pointing to
        employee* temp = next;

        // searching for employee by name
        while (temp != nullptr && temp->name != empName) {

            temp = temp->next;

        }

        // checking if we have reached the end of
        //  the list
        if (temp != nullptr) {

            // if we have not reached the end
            // then assign mentor
            temp->mentor = mentorName;

        } 
        
        // otherwise we have reached the end of 
        // the list and the employee was not found
        else {

            cout << "Employee not found :(" << endl;

        }
    }

    // function to lookup an employee's mentor
    void lookupMentor(string empName) {

        employee* temp = next;

        // searching list for employee name
        while (temp != nullptr && temp->name != empName) {

            temp = temp->next;

        }

        // checking if we have not reached the
        // end of the list
        if (temp != nullptr) {

            // checking if there is no mentor
            if (temp->mentor == "") {

                cout << empName << " has no mentor." << endl;

            } 
          
            // if there is a mentor print
            else {

                cout << "The mentor of " << empName << " is: " << temp->mentor << endl;

            }
        } 
      
        // we have reached the end of the list
        else {

            cout << "Employee not found :(" << endl;

        }
    }

    //  function to terminate mentor-mentee relationship
    void terminateMentor(string empName) {

        employee* temp = next;

         while (temp != nullptr && temp->name != empName) {

            temp = temp->next;

        }

        // if we have not reached the end of 
        // the list then set mentor to empty
        if (temp != nullptr) {

            temp->mentor = "";  

            cout << "Mentor-mentee relationship for " << empName << " has been terminated." << endl;

        } 
    
        // otherwise, we have reached end of 
        // list and employee was not found
        else {

            cout << "Employee not found!" << endl;

            }
        }


    // function to display all employees and their mentors
    void displayAll() {

        employee* temp = next;

        // if temp is null then list
        // is empty 
        if (temp == nullptr) {

            cout << "No employees found" << endl;

        } 
        
        // otherwise 
        else {

            // while temp is not null
            while (temp != nullptr) {

                // check if mentor is empty
                if (temp->mentor == "") {

                    cout << temp->name << " is mentored by None" << endl;

                } 
                
                // since mentor is not empty
                // print the metor
                else {

                    cout << temp->name << " is mentored by " << temp->mentor << endl;

                }

                // updating temp to next node
                temp = temp->next;

            }
        }
    }

    // function to display all employees at a specific level
    void displayByLevel(string level) {

        employee* temp = next;

        // boolean varibale to check
        bool found = false;

        // while temp is not null
        while (temp != nullptr) {

            // check if level matches
            if (temp->level == level) {

                // if level matches display employee at the level
                cout << temp->name << " is at level: " << temp->level << endl;

                // set found to true
                found = true;

            }

            // updating temp to next node
            temp = temp->next;
        }

        // if found is still false
        // then there are no employees
        // found at that level
        if (!found) {

            cout << "No employees found at level: " << level << endl;

        }
    }
};

class Manager : public employee {

public:

    Manager(string name, string level) : employee(name, level) {}

    // function to hire an employee
    void hireEmployee(employee* newEmp) {

        hire(newEmp);

    }

    // function to assign mentor to an employee
    void assignMentorToEmployee(string empName, string mentorName) {

        assignMentor(empName, mentorName);

    }

    // function to display all employees and their mentors
    void displayEmployees() {

        displayAll();

    }

    // function to display employees at a specific level
    void displayEmployeesAtLevel(string level) {

        displayByLevel(level);

    }
};

// function to check user input
void check(int option, Manager &manager) {

    string name, level, mentor;

    if (option == 1) {

        cout << "Enter employee name: ";

        cin >> name;

        cout << "Enter employee level: ";

        cin >> level;

        employee* newEmp = new employee(name, level);

        manager.hireEmployee(newEmp);

    } 
    
    else if (option == 2) {

        cout << "Enter employee name: ";
        
        cin >> name;

        cout << "Enter new level: ";

        cin >> level;

        manager.promoteDemote(name, level);

    } 
    
    else if (option == 3) {

        cout << "Enter employee name to dismiss: ";

        cin >> name;

        manager.dismiss(name);

    } 
    
    else if (option == 4) {

        cout << "Enter employee name to find level: ";

        cin >> name;

        manager.findLevel(name);

    } 
    
    else if (option == 5) {

        cout << "Enter level to display employees at: ";

        cin >> level;

        manager.displayEmployeesAtLevel(level);

    } 
    
    else if (option == 6) {

        cout << "Enter mentee name: ";

        cin >> name;

        cout << "Enter mentor name: ";

        cin >> mentor;

        manager.assignMentorToEmployee(name, mentor);

    }
    
    else if (option == 7) {

        cout << "Enter employee name to terminate mentor-mentee pair: ";

        cin >> name;

        manager.terminateMentor(name);
    }
    
    else if (option == 8) {

        cout << "Enter employee name to lookup mentor: ";

        cin >> name;

        manager.lookupMentor(name);

    } 
    
    else if (option == 9) {

        manager.displayEmployees();

    } 
    
    else {

        cout << "Invalid option!" << endl;

    }
}

// Function to get user option
void getOption() {

    int option = 0;

    Manager manager("","");

    while (option != 10) {

        cout << endl;

        cout << "Choose an option:" << endl;

        cout << "1. Hire an employee" << endl;

        cout << "2. Promote/Demote an employee" << endl;

        cout << "3. Dismiss an employee" << endl;

        cout << "4. Lookup an employee's level" << endl;

        cout << "5. Display all employees at a specific level" << endl;

        cout << "6. Assign mentor to an employee" << endl;

        cout << "7. terminate a mentor/mentee pair" << endl;

        cout << "8. Lookup mentoring info for an employee" << endl;

        cout << "9. Display all current mentoring pairs" << endl;
        
        cout << "10. Exit" << endl;

        cin >> option;

        if (option != 10) {

            check(option, manager);

        }
    }

    if (option == 10) {

        cout << "Exiting program!" << endl;
    }

}

