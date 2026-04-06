#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

// ===================================================================================
// Selection Sort Implementation in C++
// Number of data used: 15
// Data used: 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24
// ===================================================================================

std::vector<int> data_awal = {12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24};

// ===================================================================================

void print_vector(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

void cetak_header(const std::string& nama) {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "  " << nama << "\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "  Data awal : ";
    print_vector(data_awal);
    std::cout << "\n" << std::string(50, '-') << "\n";
}

// ===================================================================================
// Selection Sort = find the smallest element
// and swap it with the element at the current position
// Complexity: O(n^2)
// ===================================================================================

void selection_sort(std::vector<int> arr) {
    cetak_header("SELECTION SORT");
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int idx_min = i;                        // Assume element at i is minimum
        for (int j = i + 1; j < n; ++j) {      // Find smallest element in remaining array
            if (arr[j] < arr[idx_min]) {
                idx_min = j;                    // Update new minimum position
            }
        }
        std::swap(arr[i], arr[idx_min]);        // Swap to position i
        std::cout << "  Iterasi " << std::setw(2) << (i + 1)
                  << " (pilih min=" << std::setw(2) << arr[i]
                  << " -> posisi " << i << "): ";
        print_vector(arr);
        std::cout << "\n";
    }

    std::cout << "\n  [OK] Hasil Selection Sort : ";
    print_vector(arr);
    std::cout << "\n";
}

// ===================================================================================
// Running Selection Sort
// ===================================================================================

int main() {
    std::cout << "\n" << std::string(110, '-') << "\n";
    std::cout << "IMPLEMENTASI SELECTION SORT\n";
    std::cout << "Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24\n";
    std::cout << std::string(55, '=') << "\n";

    selection_sort(data_awal);

    std::vector<int> sorted_data = data_awal;
    std::sort(sorted_data.begin(), sorted_data.end());

    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "HASIL AKHIR\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "  Data awal   : ";
    print_vector(data_awal);
    std::cout << "\n  Hasil sort  : ";
    print_vector(sorted_data);
    std::cout << "\n" << std::string(50, '=') << "\n";

    return 0;
}