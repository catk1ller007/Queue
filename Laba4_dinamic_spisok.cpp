#include <iostream>

#include "Queueshka.h"

using namespace std;

int main()
{
    Queue a;

    a.Add_Q(1);
    a.Add_Q(2);
    a.Add_Q(3);
    a.Add_Q(4);
    a.Add_Q(5);

    Queue b(a);

    Queue c;

    cout << b.front() << endl;
    cout << b.front() << endl;

    c = b;

    cout << "c: " << c.front() << endl;

    cout << b.front() << endl;
    cout << b.front() << endl;
    cout << b.front() << endl;
}