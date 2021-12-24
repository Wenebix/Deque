#include <iostream>
#include "Deque.h"
using namespace std;

int main()
{
    cout << "tests for deque consisting of int (Size(), PushBack(), PushFront(), PopBack(), Output)" << endl;
    Deque<int> deque_1;
    deque_1.PushBack(5);
    deque_1.PushFront(4);
    deque_1.PushBack(3);

    cout << deque_1.Size() << endl;
    deque_1.PrintInNormalOreder(cout);
    deque_1.PrintInReversedOreder(cout);

    deque_1.PopBack();
    deque_1.PrintInNormalOreder(cout);
    deque_1.PrintInReversedOreder(cout);

    cout << "tests for deque consisting of const char*(Size(), PushBack(), PushFront(), PopFront(), Output)" << endl;
    Deque<const char*> deque_2;
    deque_2.PushBack("abab");
    deque_2.PushFront("bac");
    deque_2.PushBack("doda");

    cout << deque_2.Size() << endl;
    deque_2.PrintInNormalOreder(cout);
    deque_2.PrintInReversedOreder(cout);

    deque_2.PopFront();
    deque_2.PrintInNormalOreder(cout);
    deque_2.PrintInReversedOreder(cout);

    cout << "tests for deque consisting of int (copy-constructor)" << endl;
    Deque<int> deque_3(deque_1);

    deque_3.PushBack(5);
    deque_3.PushFront(4);
    deque_3.PushBack(3);

    cout << deque_3.Size() << endl;
    deque_3.PrintInNormalOreder(cout);
    deque_3.PrintInReversedOreder(cout);

    deque_3.PopFront();
    deque_3.PrintInNormalOreder(cout);
    deque_3.PrintInReversedOreder(cout);

    cout << "tests for deque consisting of int (Clear)" << endl;
    deque_1.Clear();
    deque_1.PrintInNormalOreder(cout);
    deque_1.PrintInReversedOreder(cout);
    deque_3.PrintInNormalOreder(cout);
    deque_3.PrintInReversedOreder(cout);

    cout << "tests for deque consisting of int (operator =)" << endl;
    deque_3 = deque_1;
    deque_1.PrintInNormalOreder(cout);
    deque_1.PrintInReversedOreder(cout);
    deque_3.PrintInNormalOreder(cout);
    deque_3.PrintInReversedOreder(cout);

    return 0;
}

