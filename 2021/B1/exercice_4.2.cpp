#include <vector> // Inclusion de la bibliothèque vector
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    // Exercice 4.2
    vector<int> v1(10, 6);

    for (int i = 0; i < v1.size(); i++) {
        cout << "Element n°" << i << ": " << v1[i] << endl;
    }

    for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++) {
        cout << "Element : " << *it << endl;
    }

    for (int const &value : v1) {
        cout << "Element : " << value << endl;
    }


    return 0;
}
