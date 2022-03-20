#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct NodeStudent
{
    int id;
    int marks;
    struct NodeStudent *next;
};

struct NodeStudent *head = NULL;
struct NodeStudent *tail = NULL;

int isEmpty()
{
    if (!head && !tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insertAtEnd(int marks, int id)
{
    if (head == NULL && tail == NULL)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head->next = current;
        tail = current;
    }
    else
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
}

void printList()
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
    }
    else
    {
        struct NodeStudent *p = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        p = head;
        while (p != NULL)
        {
            cout << "ID: " << p->id << " Marks: " << p->marks << endl;
            p = p->next;
        }
    }
}

void insertAtStart(int marks, int id)
{
    if (head == NULL && tail == NULL)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = head;
        head = current;
    }
    else
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = head;
        head = current;
    }
}

void inserAfterValue(int idAfter, int marks, int id)
{
    int checkFound = 0;
    struct NodeStudent *p = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
    p = head;
    while (p != NULL)
    {
        if (p->id == idAfter)
        {
            struct NodeStudent *addNode = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
            addNode->marks = marks;
            addNode->id = id;
            addNode->next = p->next;
            p->next = addNode;
            checkFound = 1;
            break;
        }
        p = p->next;
    }
    if (!checkFound)
    {
        cout << "Can't found the given id" << endl;
    }
}

void inserBeforeValue(int idBefore, int marks, int id)
{
    int checkValue = 0;
    struct NodeStudent *pHead = head;
    struct NodeStudent *pHeadNext = head->next;
    if (pHead->id == idBefore)
    {
        struct NodeStudent *addNode = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        addNode->marks = marks;
        addNode->id = id;
        addNode->next = pHead;
        checkValue = 1;
        head = addNode;
    }
    else
    {
        while (pHeadNext != NULL)
        {
            if (pHeadNext->id == idBefore)
            {
                struct NodeStudent *addNode = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
                addNode->marks = marks;
                addNode->id = id;
                pHead->next = addNode;
                addNode->next = pHeadNext;
                checkValue = 1;
                break;
            }
            pHeadNext = pHeadNext->next;
            pHead = pHead->next;
        }

        if (checkValue == 0)
        {
            cout << "Can't find the id, try with correct id " << idBefore << endl;
        }
    }
}

void pop_back()
{
    int checkValue = 0;
    struct NodeStudent *pHead = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
    struct NodeStudent *pHeadNext = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));

    if (isEmpty())
    {
        cout << "Can't pop, no element in list" << endl;
    }
    else
    {
        pHead = head;
        pHeadNext = pHead->next;
        if (head == tail)
        {
            free(head);
            free(tail);
            head = NULL;
            tail = NULL;
        }
        else
        {
            while (pHeadNext->next != NULL)
            {
                pHead = pHead->next;
                pHeadNext = pHeadNext->next;
            }
            pHead->next = NULL;
            tail = pHead;
            free(pHeadNext);
            pHeadNext = NULL;
        }
    }
}

void pop_front()
{

    if (head == NULL && tail == NULL)
    {
        cout << "Can't pop from empty linked list" << endl;
    }
    else
    {
        struct NodeStudent *ptr = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        ptr = head->next;
        free(head);
        head = ptr;
    }
}

void deleteID(int idToDelete)
{
    if (isEmpty())
    {
        cout << "Can't delete from an empty list" << endl;
    }
    else
    {
        struct NodeStudent *pHead = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        struct NodeStudent *pHeadNext = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        pHead = head;
        pHeadNext = head->next;
        if (pHead->id == idToDelete)
        {
            struct NodeStudent *ptrDel = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
            ptrDel = pHeadNext;
            free(head);
            head = NULL;
            head = ptrDel;
        }
        else
        {
            int found = 0;
            while (pHeadNext != NULL)
            {
                // cout<<pHeadNext->id<<endl;
                if (pHeadNext->id == idToDelete && !pHeadNext->next)
                {
                    free(tail);
                    tail = NULL;
                    pHead->next = NULL;
                    tail = pHead;
                }
                else if (pHeadNext->id == idToDelete)
                {
                    pHead->next = pHeadNext->next;
                    free(pHeadNext);
                    pHeadNext = NULL;
                    // head = pHead;
                    found = 1;
                    break;
                }
                pHead = pHead->next;
                pHeadNext = pHeadNext->next;
            }

            if (!found)
            {
                cout << "Provide a valid id to delete" << endl;
            }
        }
    }
}

void deleteAfter(int idAfterToDeleteAfter)
{
    struct NodeStudent *p;
    p = head;
    int found = 0;
    if (tail->id == idAfterToDeleteAfter)
    {
        cout << "Can't delete after the last number" << endl;
    }
    else
    {
        while (p->next != NULL)
        {
            if (p->id == idAfterToDeleteAfter)
            {
                if (p->next == tail)
                {
                    tail = p;
                }
                found = 1;
                p->next = (p->next)->next;
                break;
            }
            p = p->next;
        }
        if (!found)
        {
            cout << "Can't find the provided number" << endl;
        }
    }
}

void deleteBefore(int idToDeleteBefore)
{
    struct NodeStudent *pPrevious = head;
    struct NodeStudent *p = pPrevious->next;
    int found = 0;
    if (idToDeleteBefore == head->id)
    {
        cout << "Can't delete before the head." << endl;
    }
    else
    {
        if (p->id == idToDeleteBefore)
        {
            // cout<<"HEllo"<<endl;
            head = p;
            // cout<<"Hello 1"<<endl;
            free(pPrevious);
            // cout<<"Hello 2"<<endl;
            pPrevious = NULL;
            // cout<<"Hello 3"<<endl;
        }
        else
        {
            while (p != NULL)
            {
                if (p->next->id == idToDeleteBefore)
                {
                    pPrevious->next = p->next;
                    found = 1;
                    break;
                }
                p = p->next;
                pPrevious = pPrevious->next;
            }
            if (!found)
            {
                cout << "Can't find the number to delete" << endl;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // insertAtEnd(101, 52);
    // insertAtStart(99, 7);
    // inserAfterValue(7, 200, 50);
    // insertAtEnd(900, 90);
    // deleteBefore(50);
    // cout<<"S";

    while (1)
    {
        int choiceMain;
        cout << "1. Insertion\n2. Deletion\n3. Print\n4. Exit\n";
        cin >> choiceMain;
        if (choiceMain == 1)
        {
            int choiceInsert;
            cout << "1. Insert at the end\n2. Insert at the start\n3. Insert after the value\n4. Insert before the value\n";
            cin >> choiceInsert;
            if (choiceInsert == 1)
            {
                int marks, id;
                cout << "Enter marks\n";
                cin >> marks;
                cout << "Enter id\n";
                cin >> id;
                insertAtEnd(marks, id);
            }
            else if (choiceInsert == 2)
            {
                int marks, id;
                cout << "Enter marks\n";
                cin >> marks;
                cout << "Enter id\n";
                cin >> id;
                insertAtStart(marks, id);
            }
            else if (choiceInsert == 3)
            {
                int marks, id, idBefore;
                cout << "Enter after id\n";
                cin >> idBefore;
                cout << "Enter marks\n";
                cin >> marks;
                cout << "Enter id\n";
                cin >> id;
                inserAfterValue(idBefore, marks, id);
            }
            else if (choiceInsert == 4)
            {
                int marks, id, idBefore;
                cout << "Enter before id\n";
                cin >> idBefore;
                cout << "Enter marks\n";
                cin >> marks;
                cout << "Enter id\n";
                cin >> id;
                inserBeforeValue(idBefore, marks, id);
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
        else if (choiceMain == 2)
        {
            int choiceDelete;
            cout << "1. Delete at the end\n2. Delete at the start\n3. Delete after the value\n4. Delete before the value\n5. Delete value\n";
            cin >> choiceDelete;
            if (choiceDelete == 1)
            {
                pop_back();
            }
            else if (choiceDelete == 2)
            {
                pop_front();
            }
            else if (choiceDelete == 3)
            {
                int valAfter;
                cout << "Delete after\n";
                cin >> valAfter;
                deleteAfter(valAfter);
            }
            else if (choiceDelete == 4)
            {
                int valBefore;
                cout << "Delete Before\n";
                cin >> valBefore;
                deleteBefore(valBefore);
            }
            else if (choiceDelete == 5)
            {
                int val;
                cout << "Delete value\n";
                cin >> val;
                deleteID(val);
            }
            else
            {
                cout << "Invalid id\n";
            }
        }
        else if (choiceMain == 3)
        {
            printList();
        }
        else if (choiceMain == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid method";
        }
    }

    return 0;
}