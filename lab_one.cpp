#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(2, 103);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = dist(gen);
    }

    cout << "Исходный массив:" << endl;
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }

    cout << "Отсортированный массив по возрастанию:" << endl;
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
