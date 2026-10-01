#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(0, 100);

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
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = a[i];
            a[i] = a[maxIndex];
            a[maxIndex] = temp;
        }
    }

    cout << "Отсортированный массив по убыванию:" << endl;
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
