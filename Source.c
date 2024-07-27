GNU nano 6.2                                                                                       trial.c                                                                                                
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_BIDDERS 4
#define BIDDING_PERIOD 10
#define NUM_ITEMS 3

struct Item {
    int itemid;
    char itemname[10];
    float highestbid;
    pthread_mutex_t mutex;
};

struct Item items[NUM_ITEMS];

void* bidder_routine(void* arg) {
    int bidderID =*((int*)arg);
    for(int i = 0; i < BIDDING_PERIOD; i++) {
        int itemIndex = rand() % NUM_ITEMS;
        float bid = (float)(rand() % 100 + 1);
        pthread_mutex_lock(&items[itemIndex].mutex);
        if(bid > items[itemIndex].highestbid) {
            items[itemIndex].highestbid = bid;
            printf("Bidder %d placed a bid of %.2f on item %d : %s\n", bidderID, bid, items[itemIndex].itemid, items[itemIndex].itemname);
        }
        pthread_mutex_unlock(&items[itemIndex].mutex);
        sleep(1);   
    }
    return NULL;
}

int main() {
    pthread_t bidders[NUM_BIDDERS];
    srand(time(NULL));

    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i].itemid = i + 1;
        printf("Enter name for Item %d:\n ", items[i].itemid); 
        scanf("%s", items[i].itemname); // No & needed for arrays
        items[i].highestbid = 0.0;
        pthread_mutex_init(&items[i].mutex, NULL);
    }
   int *bidderIDs[NUM_BIDDERS];
    for (int i = 0; i < NUM_BIDDERS; i++) {
        bidderIDs[i] = (int*)malloc(sizeof(int));
        *bidderIDs[i] = i + 1; // Set the bidder ID
    }

    for (int i = 0; i < NUM_BIDDERS; i++) {
        if (pthread_create(&bidders[i], NULL, bidder_routine, *(void*)i+1) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < NUM_BIDDERS; i++) {
        if (pthread_join(bidders[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
        free(bidderIDs[i]);
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Highest bid for Item %d (%s): %.2f\n", items[i].itemid, items[i].itemname, items[i].highestbid);
        pthread_mutex_destroy(&items[i].mutex);
    }

return 0;
}