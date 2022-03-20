#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Marks
{
    string subject;
    int numbers;
    Marks* next;
};

struct Student{
    string name;
    Student* next;
    Marks* marks;
};

Student* headStudent = NULL;
Student* tailStudent = NULL;

void insertStudents(string n){
    if (!headStudent && !tailStudent)
    {
        Student* c = new Student();
        c->name = n;
        c->next = NULL;
        c->marks = NULL;
        headStudent = c;
        tailStudent = c;
    }
    else if (headStudent == tailStudent)
    {   
        Student* c = new Student();
        c->name = n;
        c->next = NULL;
        c->marks = NULL;
        tailStudent->next = c;
        tailStudent = c;
    }
    else{
        Student* c = new Student();
        c->name = n;
        c->next = NULL;
        c->marks = NULL;
        tailStudent->next = c;
        tailStudent = c;
    }
}

void insertMarks(string nameFind, string subjectName, int subjectMarks){
    Student* p = headStudent;
    // while (p)
    // {
    //     if (p->name == nameFind)
    //     {
    //         Marks* m = new Marks();
    //         m->numbers = subjectMarks;
    //         m->subject = subjectName;
    //         m->next = NULL;
    //         marksStorage.push_back(m);
    //         names.push_back(p->name);
    //         break;                                                                                                                                   
    //     }
    //     p = p->next;
    // }

    while (p)
    {
        if (p->name == nameFind)
        {
            break;
        }
        p = p->next;
    }
    if (p->marks == NULL)
    {
        Marks* m = new Marks();
        m->numbers = subjectMarks;
        m->subject = subjectName;
        m->next = NULL;
        p->marks = m;
    }
    else{
        Marks* q = new Marks();
        q->numbers = subjectMarks;
        q->subject = subjectName;
        q->next = p->marks;
        p->marks = q;
    }
}

void checkDis(string nameFind){
    Student* p = headStudent;
    while (p->name != nameFind && p != NULL)
    {
        p = p->next;
    }
    if (p)
    {
        cout<<"Student's name: "<<p->name<<endl;
        Marks* m = p->marks;
        if (m)
        {
            while (m)
            {
                cout<<m->subject<<" "<<m->numbers<<endl;
                m = m->next;
            }
        }
        else if (!m) {
            cout<<"No record found"<<endl;
        }
    }
    
}

void display()
{
    if (headStudent)
    {
        Student* p = headStudent;
        while (p)
        {
            cout<<p->name<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    insertStudents("Haider");   
    insertStudents("ABC");   
    insertStudents("Ahmad");
    insertStudents("XYZ");   
    // display();
    insertMarks("Ahmad","DSA",4);
    insertMarks("Ahmad","PF",3);
    insertMarks("Ahmad","XYZ",2);
    insertMarks("Haider","ABC1",4);
    insertMarks("Haider","ABC2",4);
    insertMarks("Haider","ABC3",4);

    checkDis("Ahmad");
    checkDis("Haider");
    return 0;
}