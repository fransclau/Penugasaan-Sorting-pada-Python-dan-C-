# ===================================================================================
# Implementasi Selection Sort dalam Python
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
# Selection Sort = mencari elemen paling kecil
# dan menukar dengan elemen di posisi saat ini
# Kompleksitas : O(n²)
# ===================================================================================
 
def selection_sort(arr):
    cetak_header("SELECTION SORT")
    n = len(arr)
 
    for i in range(n - 1):
        idx_min = i                        # Asumsikan elemen ke-i adalah minimum
        for j in range(i + 1, n):         # Cari elemen terkecil di sisa array
            if arr[j] < arr[idx_min]:
                idx_min = j               # Update posisi minimum baru
        arr[i], arr[idx_min] = arr[idx_min], arr[i]   # Tukar ke posisi i
        print(f"  Iterasi {i+1:2d} (pilih min={arr[i]:2d} → posisi {i}): {arr}")
 
    print(f"\n  ✅ Hasil Selection Sort : {arr}")
 
# ===================================================================================
# Running Selection Sort
# ===================================================================================
if __name__ == "__main__":
    print("\n" + "--" * 55)
    print("IMPLEMENTASI SELECTION SORT")
    print("Data : 12, 74, 75, 90, 56, 23, 31, 4, 57, 48, 53, 24, 86, 11, 24")
    print("=" * 55)
 
    selection_sort(data_awal[:])
 
    print("\n" + "=" * 50)
    print("HASIL AKHIR")
    print("=" * 50)
    print(f"  Data awal   : {data_awal}")
    print(f"  Hasil sort  : {sorted(data_awal)}")
    print("=" * 50)