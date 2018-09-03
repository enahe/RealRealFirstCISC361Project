/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Tommy
 *
 * Created on September 2, 2018, 12:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "mp3header.h"

void addMp3 (char * newArtistName, char * newSongTitle, char * newSongDate, int newRunTime, mp3Node** headReference) {
    
    struct mp3Node* newMp3 = (struct mp3Node*) malloc(sizeof( struct mp3Node));
    
    struct mp3Node* lastMp3 = *headReference;
    
    newMp3->artistName = newArtistName;
    newMp3->songTitle = newSongTitle;
    newMp3->songDate = newSongDate;
    newMp3->runTime = newRunTime;
    
    newMp3->next = NULL;
    
    if (*headReference == NULL) {
        newMp3->prev = NULL;
        *headReference = newMp3;
        return;
    }
    else {
        while (lastMp3->next != NULL) {
            lastMp3 = lastMp3->next;
        }
        lastMp3->next = newMp3;
        newMp3-> prev = lastMp3;
        return;
    }
}

void printForward(struct mp3Node * headReference) {
    printf("Starting from the top \n");
    while (headReference != NULL) {
        printf(" Artist Name: %s, Song Name: %s, Date Of Release: %s, Running Time: %d \n ", headReference->artistName, headReference->songTitle, headReference->songDate, headReference->runTime);
        headReference = headReference->next;
    }
}

void printBackwards(struct mp3Node * headReference) {
    struct mp3Node* lastMp3;
    printf("Take it back now ya'll \n");
    while (headReference != NULL) {
        lastMp3 = headReference;
        headReference = headReference->next;
    }
    while (lastMp3 != NULL) {
         printf(" Artist Name: %s, Song Name: %s, Date Of Release: %s, Running Time: %d \n ", lastMp3->artistName, lastMp3->songTitle, lastMp3->songDate, lastMp3->runTime);
         lastMp3 = lastMp3->prev;
    }    
}

int main(int argc, char** argv) {
     struct mp3Node* headNode = NULL;
     addMp3("test", "testTitle","testDate", 12, &headNode);
     addMp3("test2", "testTitle2","testDate2", 14, &headNode);
     printForward(headNode);
     printBackwards(headNode);
}

