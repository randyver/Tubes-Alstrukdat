#include <stdio.h>

#include "kicauan.h"
#include "../database/database.h"
#include "../ADT/Wordmachine.h"
#include "../ADT/DynamicList.h"
#include "../assets/Tweet.h"
#include "../assets/User.h"

void kicauan() {
    if (current_user == -1) {
        printf("\nAnda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    DynamicList visible_tweets;
    create_dynamic_list(&visible_tweets, 1);

    for (int i = 0; i < users[current_user].tweets.length; ++i) {
        insert_last_dynamic_list(&visible_tweets, users[current_user].tweets.list[i]);
    }

    for (int i = 0; i < total_user; ++i) {
        if (i == current_user) continue;
        if (friends.matrix[i][current_user]) {
            for (int j = 0; j < users[i].tweets.length; ++j) {
                insert_last_dynamic_list(&visible_tweets, users[i].tweets.list[j]);
            }
        }
    }

    // for (int i = 0; i < total_user; ++i) {
    //     if (!users[i].is_public) continue;
    //     for (int j = 0; j < users[i].tweets.length; ++j) {
    //         insert_last_dynamic_list(&visible_tweets, users[i].tweets.list[j]);
    //     }
    // }

    // for (int i = 0; i < total_user; ++i) {
    //     if (current_user != i && !friends.matrix[current_user][i]) continue;
    //     if (users[i].is_public) continue;
    //     for (int j = 0; j < users[i].tweets.length; ++j) {
    //         insert_last_dynamic_list(&visible_tweets, users[i].tweets.list[j]);
    //     }
    // }

    sort_descending_dynamic_list(&visible_tweets);    

    for (int i = 0; i < visible_tweets.length; ++i) {
        print_tweet(&tweets[visible_tweets.list[i]], 0);
        printf("\n\n");
    }


}