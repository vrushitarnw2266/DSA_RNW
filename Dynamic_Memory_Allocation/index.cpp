#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Linked List Class
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    // Append at End
    void append(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Insert at Beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "Linked List : ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Search
    void search(int key)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Element Found.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Element Not Found.\n";
    }

    // Delete Node
    void deleteNode(int key)
    {
        if (head == NULL)
        {
            cout << "List is Empty.\n";
            return;
        }

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;

            cout << "Node Deleted.\n";
            return;
        }

        Node *current = head;

        while (current->next != NULL && current->next->data != key)
        {
            current = current->next;
        }

        if (current->next == NULL)
        {
            cout << "Element Not Found.\n";
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;

        delete temp;

        cout << "Node Deleted.\n";
    }

    // Reverse Linked List
    void reverse()
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;

        cout << "Linked List Reversed.\n";
    }
};

int main()
{
    LinkedList list;

    int choice, value;

    do
    {
        cout << "\n====== Linked List Menu ======\n";
        cout << "1. Append Node\n";
        cout << "2. Insert At Beginning\n";
        cout << "3. Display\n";
        cout << "4. Search Element\n";
        cout << "5. Delete Node\n";
        cout << "6. Reverse Linked List\n";
        cout << "7. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Value : ";
            cin >> value;
            list.append(value);
            break;

        case 2:
            cout << "Enter Value : ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 3:
            list.display();
            break;

        case 4:
            cout << "Enter Value to Search : ";
            cin >> value;
            list.search(value);
            break;

        case 5:
            cout << "Enter Value to Delete : ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 6:
            list.reverse();
            break;

        case 7:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}