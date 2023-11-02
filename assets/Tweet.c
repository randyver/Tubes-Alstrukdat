#include "Tweet.h"
#include "../database/database.h"
#include <stdlib.h>
#include "../ADT/Wordmachine.h"
#include "../ADT/Datetime.h"

Tweet new_tweet(char *text, int tweet_id, int author_id) {
    Tweet tweet;

    tweet.id = tweet_id;
    tweet.text = text;
    tweet.likes = 0;
    tweet.author_id = author_id;
    tweet.datetime = current_time();

    return tweet;
}

void set_tweet_text_from_id(int id, char *text) {
    free(tweets[id].text);
    size_t length;
    my_strlen(text, &length);
    tweets[id].text = malloc((length + 1) * sizeof(char));
    my_strcpy(tweets[id].text, text);
}

void set_tweet_datetime_from_id(int id, char *datetime) {
    free(tweets[id].datetime);
    size_t length;
    my_strlen(datetime, &length);
    tweets[id].datetime = malloc((length + 1) * sizeof(char));
    my_strcpy(tweets[id].datetime, datetime);
}

void set_tweet_text(Tweet *t, char *text) {
    free(t->text);
    size_t length;
    my_strlen(text, &length);
    t->text = malloc((length + 1) * sizeof(char));
    my_strcpy(t->text, text);
}

void set_tweet_datetime(Tweet *t, char *datetime) {
    free(t->datetime);
    size_t length;
    my_strlen(datetime, &length);
    t->datetime = malloc((length + 1) * sizeof(char));
    my_strcpy(t->datetime, datetime);
}

void print_tweet(Tweet *t, int spaces) {
    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("ID: %d\n", t->id);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Text: %s\n", t->text);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Likes: %d\n", t->likes);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Author: %s\n", users[t->author_id].name);

    for (int i = 0; i < spaces; ++i) printf("\t");
    printf("Datetime: %s\n", t->datetime);
    // printf("ID: %d\n"
    //     "Text: %s\n"
    //     "Likes: %d\n"
    //     "Author: %s\n"
    //     "Datetime: %s\n",
        
    //     t->id,
    //     t->text,
    //     t->likes,
    //     users[t->author_id].name,
    //     t->datetime);
}