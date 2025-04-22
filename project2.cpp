#include <iostream>
#include <string>
using namespace std;

// creating a Date class to store the birth dates of patients in a proper format
class Date
{
private:
    int day;
    int month;
    int year;

public:
    // DEFAULT contructor
    Date()
    {
        day = 0;
        month = 0;
        year = 0000;
    }

    // constructor
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    // Setters
    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    // Getters
    int getDay()
    {
        return this->day;
    }

    int getMonth()
    {
        return this->month;
    }

    int getYear()
    {
        return this->year;
    }

    void display()
    {
        cout << day << "/" << month << "/" << year;
    }
};

// creating a patientRecord class to store all the patients information
class PatientRecord
{
private:
    string ID;
    string firstName;
    string lastName;
    Date DoB;
    string gender;

    // used to store if patient is an emergency case or not. If yes, record will be added in linked list and emergncy queue
    int condition;

public:
    // empty DEFAULT constructor
    PatientRecord()
    {
    }

    // constructor
    PatientRecord(string ID, string firstName, string lastName, Date DoB, string gender, int condition)
    {
        this->ID = ID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->DoB = DoB;
        this->gender = gender;
        this->condition = condition;
    }

    // Setters
    void setID(string ID)
    {
        this->ID = ID;
    }

    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }

    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }

    void setDoB(Date DoB)
    {
        this->DoB = DoB;
    }

    void setGender(string gender)
    {
        this->gender = gender;
    }
    void setCondition(int condition)
    {
        this->condition = condition;
    }

    // Getters
    string getID()
    {
        return this->ID;
    }

    string getFirstName()
    {
        return this->firstName;
    }

    string getLastName()
    {
        return this->lastName;
    }

    Date getDoB()
    {
        return this->DoB;
    }

    string getGender()
    {
        return this->gender;
    }
    int getCondition() const
    {
        return this->condition;
    }

    // Display function
    void display()
    {
        cout << "ID: " << this->ID << ", Name: " << this->firstName << " " << this->lastName << ", Date of Birth: ";
        this->DoB.display();
        cout << ", Gender: " << this->gender;
        cout << ", Condition: " << this->condition << endl;
    }
};

// Node class to be used in linked list, queses and stack
struct PNode
{
    PatientRecord data;
    PNode *next;

    PNode(PatientRecord data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    PNode *head;

    LinkedList()
    {
        head = nullptr;
    }

    // insert at begining of the Patient records
    void addPatientRecord(PatientRecord newData)
    {
        PNode *newNode = new PNode(newData);
        newNode->next = head;
        head = newNode;
        cout << "Patient record added successfully!" << endl;
    }

    bool isEmpty()
    {
        return head == nullptr; // Checks if the list is empty
    }
    // delete at the middle if the record is found
    void deletePatientRecord(string key)
    {
        if (head == nullptr)
        {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        // If the head node itself needs to be deleted
        if (head->data.getID() == key)
        {
            PNode *temp = head;
            head = head->next;
            delete temp;
            cout << "Patient record deleted successfully!" << endl;
            return;
        }

        // For other nodes
        PNode *current = head;
        while (current->next != nullptr && current->next->data.getID() != key)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            cout << "Patient record not found." << endl;
            return;
        }

        // Found the node, delete it
        PNode *temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Patient record deleted successfully!" << endl;
    }

    // diaplying all the added patient records
    void printList()
    {
        PNode *current = head;
        if (current == nullptr)
        {
            cout << "No patient records found." << endl;
        }
        else
        {
            while (current != nullptr)
            {
                current->data.display();
                cout << endl;
                current = current->next;
            }
        }
    }

    // to edit any changes in patients record eg. last name changed OR incorrect DoB was entered
    void editPatientRecord(int choice, string key)
    {
        PNode *current = head;

        while (current != nullptr && current->data.getID() != key)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Record not found." << endl;
        }
        else
        {
            // choosing what needs to be edited
            if (choice == 1)
            {
                string newID;
                cout << "Current National ID: " << current->data.getID() << endl;
                cout << "Enter new National ID: ";
                cin >> newID;
                current->data.setID(newID);
                cout << "National ID updated successfully!" << endl;
            }
            else if (choice == 2)
            {
                string newFirst;
                cout << "Current First Name: " << current->data.getFirstName() << endl;
                cout << "Enter new First Name: ";
                cin >> newFirst;
                current->data.setFirstName(newFirst);
                cout << "First Name updated successfully!" << endl;
            }
            else if (choice == 3)
            {
                string newLast;
                cout << "Current Last Name: " << current->data.getLastName() << endl;
                cout << "Enter new Last Name: ";
                cin >> newLast;
                current->data.setLastName(newLast);
                cout << "Last Name updated successfully!" << endl;
            }
            else if (choice == 4)
            {
                int day, month, year;
                cout << "Current Date of Birth: ";
                current->data.getDoB().display();
                cout << endl;

                cout << "Enter new Day: ";
                cin >> day;
                cout << "Enter new Month: ";
                cin >> month;
                cout << "Enter new Year: ";
                cin >> year;

                Date newDob(day, month, year);
                current->data.setDoB(newDob);
                cout << "Date of Birth updated successfully!" << endl;
            }
            else if (choice == 5)
            {
                string newGender;
                cout << "Current gender: " << current->data.getGender() << endl;
                cout << "Enter new gender: ";
                cin >> newGender;
                current->data.setGender(newGender);
                cout << "Gender updated successfully!" << endl;
            }
            else
            {
                cout << "Invalid choice entered" << endl;
            }
            // can not edit condition manually. It is automaticlly chnaged from 1 to 0 when a patient is removed form the emergncy queue
        }
    }
};

class EmergencyQueue
{
private:
    PNode *front;
    PNode *rear;

    // constructor
public:
    EmergencyQueue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(PatientRecord patient)
    {
        PNode *temp = new PNode(patient);
        if (rear == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        cout << "Patient added to Emergency Queue" << endl;
    }
    PatientRecord dequeue()
    {
        if (isEmpty())
        {
            cout << "No patients in the Emergency Queue." << endl;
            return PatientRecord();
        }

        PNode *temp = front;
        PatientRecord removedPatient = temp->data;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        return removedPatient;
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "No emergency patient records found." << endl;
            return;
        }

        PNode *current = front;
        cout << "Emergency Queue:" << endl;
        while (current != nullptr)
        {
            current->data.display();
            current = current->next;
        }
    }
};

class TreatmentStack
{
private:
    PNode *top;

public:
    // constructor
    TreatmentStack()
    {
        top = nullptr;
    }

    void push(PatientRecord patient)
    {
        PNode *node = new PNode(patient);
        node->next = top;
        top = node;
        cout << "Record pushed to stack." << endl;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "No record to undo" << endl;
            return;
        }

        PNode *temp = top;
        cout << "Undoing treatment for: ";
        temp->data.display();
        cout << endl;
        top = top->next;
        delete temp;
    }
    void DisplayStack()
    {
        if (top == nullptr)
        {
            cout << "No records to display" << endl;
            return;
        }
        PNode *current = top;
        cout << "Treatment Records: " << endl;
        while (current != nullptr)
        {
            current->data.display();
            current = current->next;
        }
    }
};

// Priority Queue Class
class PriorityQueue
{
private:
    PNode *head;

public:
    PriorityQueue()
    {
        head = nullptr;
    }

    void enqueue(PatientRecord patient)
    {
        PNode *node = new PNode(patient);
        if (head == nullptr || patient.getCondition() < head->data.getCondition())
        {
            node->next = head;
            head = node;
        }
        else
        {
            PNode *current = head;
            while (current->next != nullptr && current->next->data.getCondition() <= patient.getCondition())
            {
                current = current->next;
            }
            node->next = current->next;
            current->next = node;
        }
        cout << "Patient added to Priority Queue." << endl;
    }

    void dequeue()
    {
        if (head == nullptr)
        {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        PNode *temp = head;
        head = head->next;
        cout << "Critical patient treated: ";
        temp->data.display();
        cout << endl;
        delete temp;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "No critical patients in queue." << endl;
            return;
        }

        PNode *current = head;
        cout << "Critical Patient Priority Queue:" << endl;
        while (current != nullptr)
        {
            current->data.display();
            cout << "Priority: " << current->data.getCondition() << endl
                 << endl;
            current = current->next;
        }
    }
};

void displayMenu()
{
    cout << endl;
    cout << "Please choose one of the following options" << endl;
    cout << "1 - Add a Patient Record" << endl;
    cout << "2 - Edit a Patient Record" << endl;
    cout << "3 - Delete a Patient Record" << endl;
    cout << "4 - Display all Patient Records" << endl;
    cout << "5 - Remove patient record from emergency room queue" << endl;
    cout << "6 - View Emergency Queue" << endl;
    cout << "7 - Treat a Patient (Push to Stack)" << endl;
    cout << "8 - Undo Last Treatment (Pop from Stack)" << endl;
    cout << "9 - View Treatment History (Display Stack)" << endl;
    cout << "0 - Exit" << endl;
    cout << endl;
}

int main()
{
    LinkedList Patients;
    cout << "--------Welcome to the Hospital Patient Management System--------" << endl;
    int choice;
    EmergencyQueue emergencyQueue;
    TreatmentStack treatmentStack;
    PriorityQueue priorityQueue;
    do
    {
        displayMenu();
        cout << "Enter your choice here: ";
        cin >> choice;

        if (choice == 1)
        {
            int option;
            cout << "Is this an emergency case? (press 1 for yes and 0 for no): " << endl;
            cin >> option;
            string ID;
            string firstName;
            string lastName;
            int day;
            int month;
            int year;
            string gender;

            cout << "Patient ID: ";
            cin >> ID;
            cout << "Patient First Name: ";
            cin >> firstName;
            cout << "Patient Last Name: ";
            cin >> lastName;
            cout << "Patient Gender: ";
            cin >> gender;
            cout << "Patient Date of Birth (dd mm yyyy): ";
            cin >> day >> month >> year;

            PatientRecord newPatient(ID, firstName, lastName, Date(day, month, year), gender, option);
            Patients.addPatientRecord(newPatient);
            if (option == 1)
            {
                emergencyQueue.enqueue(newPatient);
            }
        }
        else if (choice == 2)
        {
            int option;
            string PID;
            cout << "Enter Patient Id: ";
            cin >> PID;
            cout << "Please choose which field to edit" << endl;
            cout << "   1 - Edit National ID" << endl;
            cout << "   2 - Edit First Name" << endl;
            cout << "   3 - Edit Last Name" << endl;
            cout << "   4 - Edit Date of Birth" << endl;
            cout << "   5 - Edit Gender" << endl;
            cout << "   6 - Edit emergency status" << endl;
            cin >> option;
            Patients.editPatientRecord(option, PID);
        }
        else if (choice == 3)
        {
            string PID;
            cout << "Enter the Patient National ID you want to delete: ";
            cin >> PID;
            Patients.deletePatientRecord(PID);
        }
        else if (choice == 4)
        {

            cout << "----- List of all Patients -----" << endl;
            Patients.printList();
        }

        else if (choice == 5)
        {
            PatientRecord treatedPatient = emergencyQueue.dequeue();
            treatedPatient.setCondition(0);
        }

        else if (choice == 6)
        {
            cout << "----- List of Emergency Patients -----" << endl;
            emergencyQueue.displayQueue();
        }

        else if (choice == 7) // Push a patient to treatment stack

        {
            string PID;
            cout << "Enter Patient ID to treat: ";
            cin >> PID;

            PNode *current = Patients.head;
            bool found = false;

            while (current != nullptr)
            {
                if (current->data.getID() == PID)
                {
                    treatmentStack.push(current->data);
                    found = true;
                    break;
                }
                current = current->next;
            }

            if (!found)
            {
                cout << "Patient ID not found. Cannot push to treatment stack." << endl;
            }
        }

        else if (choice == 8) // Undo last treatment
        {

            treatmentStack.pop();
        }

        else if (choice == 9) // Display treatment stack
        {

            treatmentStack.DisplayStack();
        }
        else if (choice == 0)
        {
            cout << "You have exited the service." << endl
                 << "Thank you!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
    return 0;
}
