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

#define BUFFERSIZE 128

void addMp3 (char * newArtistName, char * newSongTitle, char * newSongDate, int newRunTime, mp3Node** headReference) {
    printf("Adding New Mp3 Node \n");
    struct mp3Node* newMp3 = (struct mp3Node*) malloc(sizeof( struct mp3Node));
    
    struct mp3Node* lastMp3 = *headReference;
    newMp3->artistName = malloc(strlen(newArtistName)+1);
    newMp3->songTitle = malloc(strlen(newSongTitle)+1);
    newMp3->songDate = malloc(strlen(newSongDate)+1);
    strcpy(newMp3->artistName, newArtistName);
    strcpy(newMp3->songTitle, newSongTitle);
    strcpy(newMp3->songDate, newSongDate);
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
        printf("Mp3 Added! \n");
        return;
    }
}

void deleteMp3(char * removeArtistName, struct mp3Node ** headReference) {
 printf("Deletion \n");

struct mp3Node * nextMp3;
struct mp3Node * currentMp3Node  = *headReference;
while (currentMp3Node != NULL)  {
    if (strcmp(removeArtistName, currentMp3Node->artistName) == 0) {
        printf("equal");
        nextMp3 = currentMp3Node -> next;
        
        if (*headReference == currentMp3Node) {
            printf("setting");
            *headReference = currentMp3Node ->next;
        }
        if(currentMp3Node -> next != NULL) {
            currentMp3Node ->next->prev = currentMp3Node -> prev;
        }
        if (currentMp3Node -> prev != NULL) {
            currentMp3Node -> prev-> next = currentMp3Node -> next;
        }
        free(currentMp3Node);
        currentMp3Node = nextMp3;
    }
    else {
        currentMp3Node = currentMp3Node -> next;
    }
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
  char  buffer[BUFFERSIZE];
  char  artistNameInput[BUFFERSIZE];
  char  songTitleInput[BUFFERSIZE];
  char  songLengthInput[BUFFERSIZE];
  char  songReleaseDate[BUFFERSIZE];
  int   songLength;
  int   len;

  printf("Welcome to MP3 Doubly Linked List! \n ");
  printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
   printf("Press ctrl or command c to exit program. \n");
  while(fgets(buffer, BUFFERSIZE , stdin) != NULL) {
      buffer[strlen(buffer)-1] = '\0';
      
      if (!strcmp(buffer, "1")) {
          printf("Please enter the artist's name.\n");
          if(fgets(artistNameInput, BUFFERSIZE , stdin) != NULL) {
          //artistNameInput[strlen(artistNameInput)-1] = '\0';
          printf("Entered Name: %s \n", artistNameInput);
          }
          printf("Please enter the song title.\n");
          if(fgets(songTitleInput, BUFFERSIZE , stdin) != NULL) {
          //songTitleInput[strlen(songTitleInput)-1] = '\0';
          printf("Entered Title: %s \n", songTitleInput);
          }
           printf("Please enter the date the song was released\n");
          if(fgets(songReleaseDate, BUFFERSIZE , stdin) != NULL) {
          //songReleaseDate[strlen(songReleaseDate)-1] = '\0';
          printf("Entered Title: %s \n", songReleaseDate);
          }

          printf("Please enter the song length in minutes.\n");
          if(fgets(songLengthInput, BUFFERSIZE , stdin) != NULL) {
          songLengthInput[strlen(songLengthInput)-1] = '\0';
          songLength = atoi(songLengthInput);
          printf("Entered Run Time: %d \n", songLength);
          }
          addMp3(artistNameInput, songTitleInput, songReleaseDate, songLength, &headNode);
           printf("Welcome to MP3 Doubly Linked List! \n ");
           printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
           printf("Press ctrl or command c to exit program. \n");
      }
      else if (!strcmp(buffer, "2")) {
          printf("Please enter the name of the artist you wish to delete. \n");
          if(fgets(artistNameInput, BUFFERSIZE, stdin) != NULL) {
          printf("Entered Name: %s \n", artistNameInput);
          }
          deleteMp3(artistNameInput, &headNode);
          printf("Welcome to MP3 Doubly Linked List! \n ");
          printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
          printf("Press ctrl or command c to exit program. \n");
      }
      else if (!strcmp(buffer, "3")) {
          printForward(headNode);
          printf("Welcome to MP3 Doubly Linked List! \n ");
          printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
          printf("Press ctrl or command c to exit program. \n");
      }
      else if (!strcmp(buffer, "4")) {
          printBackwards(headNode);
          printf("Welcome to MP3 Doubly Linked List! \n ");
          printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
          printf("Press ctrl or command c to exit program. \n");
      }
  }
  /*{
    len = (int) strlen(buffer);
    printf("length [%d] of string %s", len, buffer); // notice length!
    buffer[len - 1] = '\0';                 // why minus 1 ???
    mp3 = (mp3_t *) malloc(sizeof(mp3_t));
    mp3->name = (char *) malloc(len);
    strcpy(mp3->name, buffer);
    printf("Name is [%s]...\n", mp3->name);
  }
  free(mp3->name);   // line free 1
  free(mp3);         // line free 2
  return 0;
}
   */ 
    /*
     struct mp3Node* headNode = NULL;
     addMp3("test", "testTitle","testDate", 12, &headNode);
     addMp3("test2", "testTitle2","testDate2", 14, &headNode);
     addMp3("test", "testTitle","testDate", 12, &headNode);
     deleteMp3("test2", &headNode);
     printForward(headNode);
     printBackwards(headNode);
     * */
}

