#include <stdio.h>
#define MAX_SHELF_WEIGHT 500.0

typedef struct {
    int pallet_id;
    float weight_kg;
    float temp_celsius;
} PalletItem;

typedef struct {
    int shelf_id;
    int is_cold_storage;
    float current_weight_kg;
} WarehouseShelf;

int kiem_tra_an_toan_nhap_kho(WarehouseShelf shelf, PalletItem item) {
    if (shelf.is_cold_storage == 1) {
        if (item.temp_celsius < -18.0 || item.temp_celsius > 5.0) {
            printf("[LOI KHO LANH] Nhiet do %.1f C khong dat chuan!\n",
                   item.temp_celsius);
            return 0;
        }
    }

    if (shelf.current_weight_kg + item.weight_kg > MAX_SHELF_WEIGHT) {
        printf("[LOI QUA TAI] Tong khoi luong %.1f kg vuot 500 kg!\n",
               shelf.current_weight_kg + item.weight_kg);
        return 0;
    }

    return 1;
}

int main() {
    WarehouseShelf ke_lanh_101 = {101, 1, 400.0};
    PalletItem pallet_moi = {5001, 150.0, 12.0};

    printf("=== KIEM TRA AN TOAN NHAP KHO ===\n");
    printf("Ke %d: %.1f kg\n",
           ke_lanh_101.shelf_id, ke_lanh_101.current_weight_kg);
    printf("Pallet %d: %.1f kg, nhiet do %.1f C\n",
           pallet_moi.pallet_id,
           pallet_moi.weight_kg,
           pallet_moi.temp_celsius);

    if (kiem_tra_an_toan_nhap_kho(ke_lanh_101, pallet_moi)) {
        printf("KET QUA: DUYET NHAP KHO!\n");
    } else {
        printf("KET QUA: TU CHOI NHAP KHO!\n");
    }

    return 0;
}
// Loi 1: Dung && sai, phai dung || de kiem tra ngoai khoang -18 den 5 do C.
// Loi 2: Chi kiem tra khoi luong kien hang, phai kiem tra ca tong khoi luong tren ke.
