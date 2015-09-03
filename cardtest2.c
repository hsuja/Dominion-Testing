// Jason Hsu
// hsuja@onid.oregonstate.edu
// 4/26/15
// CS362-400

// test play_smithy()

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int main(){

    struct gameState* g = malloc(sizeof(struct gameState));
    int currentPlayer = 0;
    int handPos;
    int pre_handCount;
	
    // Player 1
    g->deckCount[0] = 5;
    g->handCount[0] = 5;
    g->discardCount[0] = 5;

    g->deck[0][0] = silver;
    g->deck[0][1] = copper;
    g->deck[0][2] = estate;
    g->deck[0][3] = silver;
    g->deck[0][4] = village;

    g->hand[0][0] = copper;
    g->hand[0][1] = gold;
    g->hand[0][2] = copper;
    g->hand[0][3] = smithy;
    g->hand[0][4] = curse;

    g->discard[0][0] = smithy;
    g->discard[0][1] = province;
    g->discard[0][2] = estate;
    g->discard[0][3] = estate;
    g->discard[0][4] = copper;

    // Player 2
    g->deckCount[1] = 0;
    g->handCount[1] = 3;
    g->discardCount[1] = 5;

    g->hand[1][0] = adventurer;
    g->hand[1][1] = gold;
    g->hand[1][2] = smithy;

    g->discard[1][0] = copper;
    g->discard[1][1] = copper;
    g->discard[1][2] = estate;
    g->discard[1][3] = estate;
    g->discard[1][4] = estate;

    // Player 3
    g->deckCount[2] = 5;
    g->handCount[2] = 3;
    g->discardCount[2] = 5;

    g->deck[2][0] = smithy;
    g->deck[2][1] = village;
    g->deck[2][2] = silver;
    g->deck[2][3] = village;
    g->deck[2][4] = smithy;

    g->hand[2][0] = adventurer;
    g->hand[2][1] = gold;
    g->hand[2][2] = smithy;

    g->discard[2][0] = estate;
    g->discard[2][1] = copper;
    g->discard[2][2] = estate;
    g->discard[2][3] = estate;
    g->discard[2][4] = smithy;
   
    printf("\nTESTING play_smithy():\n\n");

    handPos = 3;
    pre_handCount = g->handCount[currentPlayer];

    play_smithy(&currentPlayer, g, &handPos);

    if(g->handCount[currentPlayer] == pre_handCount + 2){
        printf("play_smithy(): PASS - cards added to hand and smithy discarded\n");
    }else if(g->handCount[currentPlayer] == pre_handCount + 3){
        printf("play_smithy(): FAIL - cards added to hand but smithy not discarded\n");
    }else{
        printf("play_smith(): FAIL - unknown error");
    }

    handPos = 2;
    currentPlayer = 1;
    pre_handCount = g->handCount[currentPlayer];

    play_smithy(&currentPlayer, g, &handPos);

    if(g->handCount[currentPlayer] == pre_handCount + 2){
        printf("play_smithy(): PASS - cards added to hand and smithy discarded\n");
    }else if(g->handCount[currentPlayer] == pre_handCount + 3){
        printf("play_smithy(): FAIL - cards added to hand but smithy not discarded\n");
    }else{
        printf("play_smith(): FAIL - unknown error");
    }

    handPos = 2;
    currentPlayer = 2;
    pre_handCount = g->handCount[currentPlayer];

    play_smithy(&currentPlayer, g, &handPos);

    if(g->handCount[currentPlayer] == pre_handCount + 2){
        printf("play_smithy(): PASS - cards added to hand and smithy discarded\n");
    }else if(g->handCount[currentPlayer] == pre_handCount + 3){
        printf("play_smithy(): FAIL - cards added to hand but smithy not discarded\n");
    }else{
        printf("play_smith(): FAIL - unknown error");
    }

    printf("Tests complete.\n");

    free(g);

    return 0;
}







