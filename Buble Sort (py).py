# ===================================================================================
# Implementasi Bubble Sort dalam Python
# Jumlah data yang digunakan:  15
# Data yang digunakan : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24
# ===================================================================================
 
data_awal = [12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24]
 
# ===================================================================================
 
def cetak_header(nama):
    print("\n" + "=" * 50)
    print(f"  {nama}")
    print("=" * 50)
    print(f"  Data awal : {data_awal}")
    print("-" * 50)
 
# ===================================================================================
# Bubble Sort = membandingkan dua elemen bersebelahan dan menukarnya jika urutannya salah
# Kompleksitas : O(n²)
# ===================================================================================
 
def bubble_sort(arr):
    cetak_header("Bubble Sort")
    n = len(arr)
    iterasi = 1
 
    for i in range(n - 1):
        ada_tukar = False                  # apakah ada pertukaran
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:        # Jika elemen kiri > kanan → tukar
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                ada_tukar = True
        print(f"  Iterasi {iterasi:2d} (pass {i+1}): {arr}")
        iterasi += 1
        if not ada_tukar:                  # Jika tidak ada tukar → sudah terurut, stop
            break
 
    print(f"\n  ✅ Hasil Bubble Sort    : {arr}")
 
# ===================================================================================
# Running Bubble Sort
# ===================================================================================
if __name__ == "__main__":
    print("\n" + "--" * 30)
    print("IMPLEMENTASI BUBBLE SORT")
    print("Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24")
    print("=" * 55)
 
    bubble_sort(data_awal[:])
 
    print("\n" + "=" * 50)
    print("HASIL AKHIR")
    print("=" * 50)
    print(f"  Data awal   : {data_awal}")
    print(f"  Hasil sort  : {sorted(data_awal)}")
    print("=" * 50) 