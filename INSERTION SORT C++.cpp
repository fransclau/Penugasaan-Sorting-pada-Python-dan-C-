#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

vector<int> data_awal = {12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24};

void print_vector(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]";
}

void cetak_header(const string& nama) {
    cout << "\n" << string(50, '=') << "\n";
    cout << "  " << nama << "\n";
    cout << string(50, '=') << "\n";
    cout << "  Data awal : ";
    print_vector(data_awal);
    cout << "\n" << string(50, '-') << "\n";
}

void insertion_sort(vector<int> arr) {
    cetak_header("INSERTION SORT");
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int kunci = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;

        cout << "  Iterasi " << setw(2) << i
             << " (sisip " << setw(2) << kunci << "): ";
        print_vector(arr);
        cout << "\n";
    }

    cout << "\n  Result of Insertion Sort : ";
    print_vector(arr);
    cout << "\n";
}

int main() {
    cout << "\n" << string(110, '-') << "\n";
    cout << "INSERTION SORT IMPLEMENTATION\n";
    cout << "Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24\n";
    cout << string(55, '=') << "\n";

    insertion_sort(data_awal);

    vector<int> sorted_data = data_awal;
    sort(sorted_data.begin(), sorted_data.end());

    cout << "\n" << string(50, '=') << "\n";
    cout << "FINAL RESULT\n";
    cout << string(50, '=') << "\n";
    cout << "  Initial data  : ";
    print_vector(data_awal);
    cout << "\n";
    cout << "  Sorted result : ";
    print_vector(sorted_data);
    cout << "\n" << string(50, '=') << "\n";

    return 0;
}