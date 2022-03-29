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
//struct NodeStudent *node = head;

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

struct NodeStudent* getMid()
{
    struct NodeStudent *slow_ptr = head;
    struct NodeStudent *fast_ptr = head;
    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        //cout << "The middle element is [" << slow_ptr->id << "]" << endl;
    }
    return slow_ptr;

}

struct NodeStudent* reverseFromMid(struct NodeStudent* mid){
    if (mid->next == NULL || mid == NULL){
        return mid;
    }
    else {
        struct NodeStudent* newHead = reverseFromMid(mid->next);
        mid->next->next = mid;
        mid->next = NULL;
        return newHead;
    }
}

int checkPalindrome(struct NodeStudent* midReversed){
    struct NodeStudent* p = head;
    struct NodeStudent* q = midReversed;
    int check = 0;
    while (q){
        // cout<<"Here 2";
        // cout<<p->id<<endl;
        // cout<<q->id<<endl;
        // cout<<midReversed->id<<endl;
        if (p->id != q->id){
            cout<<p->id<<endl;
            cout<<q->id<<endl;
            // cout<<"Here 3";
            check++;
            break;
        }
        else{
        p = p->next;
        q = q->next;
        }
    }
    if (check == 0){
        // cout<<"Here 6";   
        return 1;
    }
    else{
        // cout<<"Here 7";
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    insertAtEnd(10, 1);
    insertAtEnd(20, 2);
    insertAtEnd(30, 3);
    insertAtEnd(30, 3);
    insertAtEnd(20, 2);
    insertAtEnd(10, 1);
    struct NodeStudent* headForPalindrome = getMid();
    struct NodeStudent* secondHead = reverseFromMid(headForPalindrome);
    //cout<<"w";
    // cout<<head->id<<head->next->id;
    cout<<checkPalindrome(secondHead);
    // cout<<head->id<<head->next->id;
    //cout<<"S";
    return 0;
}