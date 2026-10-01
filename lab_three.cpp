#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Введите количество телефонов: ";
    cin >> n;
    cin.ignore();

    vector<string> phones(n);
    cout << "Введите телефоны (каждый с новой строки):" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, phones[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (phones[j] < phones[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            string temp = phones[i];
            phones[i] = phones[minIndex];
            phones[minIndex] = temp;
        }
    }

    cout << "Отсортированный список телефонов:" << endl;
    for (auto& p : phones) {
        cout << p << endl;
    }

    return 0;
}
