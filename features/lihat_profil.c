#include <stdio.h>
#include <stdlib.h>
#include "lihat_profil.h"

#include "../ADT/boolean.h"
#include "../ADT/Wordmachine.h"

#include "../assets/User.h"
#include "../database/database.h"

void lihat_profil(char *name) {
    if (current_user == -1){
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    int id_user = search_id_by_name(name);
    if (id_user == -1) {
        printf("Tidak ada profil dengan nama tersebut!\n");
    } else {
        if (current_user != id_user && !users[id_user].is_public && !friends.matrix[current_user][id_user]) {
            printf("Sayangnya akun %s diprivat:( Ikuti dulu yuk biar bisa lihat profil %s!\n", users[id_user].name, users[id_user].name);
        } else {
            printf("| Nama: %s\n", users[id_user].name);
            printf("| Bio Akun: %s\n", users[id_user].bio);
            printf("| No HP: %s\n", users[id_user].phone);
            printf("| Weton: %s\n", users[id_user].weton);
            printf("Foto profil akun %s\n", users[id_user].name);
            print_profile_picture(&users[id_user]);
        }
    }
}
