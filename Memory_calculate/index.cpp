#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class Template
template <class T>
class Student
{
private:
    int id;
    T name;

public:
    // Constructor
    Student(int id, T name)
    {
        this->id = id;
        this->name = name;
    }

    // Getter Functions
    int getId()
    {
        return id;
    }

    T getName()
    {
        return name;
    }

    // Display Function
    void display()
    {
        cout << "Student ID   : " << id << endl;
        cout << "Student Name : " << name << endl;
        cout << "------------------------" << endl;
    }
};

int main()
{
    vector<Student<string>> students;

    int choice;

    do
    {
        cout << "\n===== Student Management System =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            int id;
            string name;

            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Student Name: ";
            getline(cin, name);

            students.push_back(Student<string>(id, name));

            cout << "Student Added Successfully!" << endl;

            break;
        }

        case 2:
        {
            if (students.empty())
            {
                cout << "No Students Found!" << endl;
            }
            else
            {
                cout << "\nStudent List\n";
                cout << "======================" << endl;

                for (auto student : students)
                {
                    student.display();
                }
            }

            break;
        }

        case 3:
        {
            int id;
            bool found = false;

            cout << "Enter Student ID to Remove: ";
            cin >> id;

            for (auto it = students.begin(); it != students.end(); it++)
            {
                if (it->getId() == id)
                {
                    students.erase(it);
                    found = true;
                    cout << "Student Removed Successfully!" << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student Not Found!" << endl;
            }

            break;
        }

        case 4:
        {
            int id;
            bool found = false;

            cout << "Enter Student ID to Search: ";
            cin >> id;

            for (auto student : students)
            {
                if (student.getId() == id)
                {
                    cout << "\nStudent Found\n";
                    student.display();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student Not Found!" << endl;
            }

            break;
        }

        case 5:
        {
            cout << "Thank You!" << endl;
            break;
        }

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}