#include <iostream>
#include "Vector.h"

using namespace std;

int compare_ints(int x, int y) {
    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    return 0;
    // return -1, x < y
    // return 1, x > y
    // return 0, x == y
}

int main() {
    Vector<int> v;

    // index, element
    v.insert(0, 1);
    v.insert(1, 2);
    v.insert(2, 3);
    v.insert(3, 4);
    v.insert(1, 5);

    v.print();

    Vector<int> w = v;//aici e copy constructor
    Vector<int> z = v;//aici e copy constructor


    v.remove(0);
    w.sort(compare_ints);
    z.sort();
    printf("%d\n", w[0]);
    printf("%d\n", w[1]);

    v.print();
    w.print();
    z.print();
    return 0;
}
