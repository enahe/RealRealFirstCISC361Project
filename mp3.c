
/* 
 * File:   mp3.c
 * Author: Eric Nahe
 *
 * Created on September 2, 2018, 12:58 PM
 * Updated on September 6, 2018, 3:06 PM
 * 
 * This program allows a user to add, delete, and print entries in a doubly linked 
 * list of MP3's. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mp3header.h"

#define BUFFERSIZE 128

void addMp3 (char * newArtistName, char * newSongTitle, char * newSongDate, int newRunTime, mp3Node** headReference) {
    printf("Adding New MP3 Node \n");
    ///allocate memory for our new Mp3Node
    struct mp3Node* newMp3 = (struct mp3Node*) malloc(sizeof( struct mp3Node));
    
    struct mp3Node* lastMp3 = *headReference;
    //allocate space in memory for the 3 char *'s 
    newMp3->artistName = malloc(strlen(newArtistName)+1);
    newMp3->songTitle = malloc(strlen(newSongTitle)+1);
    newMp3->songDate = malloc(strlen(newSongDate)+1);
    //copy the strings into their assigned locations 
    strcpy(newMp3->artistName, newArtistName);
    strcpy(newMp3->songTitle, newSongTitle);
    strcpy(newMp3->songDate, newSongDate);
    //assign the int for run time directly into its location,
    //since its an int we don't need to worry about malocing it. 
    newMp3->runTime = newRunTime;
    
    //since this is added at the end of the list, we can assign its next node 
    //to null. 
    newMp3->next = NULL;
    
    //check to see if this is the first node in the list
    if (*headReference == NULL) {
        newMp3->prev = NULL;
        *headReference = newMp3;
        return;
    }
    else {
        //now traverse the list until you reach the end, and make the last node the
        //prev of our newly added node
        while (lastMp3->next != NULL) {
            lastMp3 = lastMp3->next;
        }
        lastMp3->next = newMp3;
        newMp3-> prev = lastMp3;
        printf("MP3 Added! \n");
        return;
    }
}

void deleteMp3(char * removeArtistName, struct mp3Node ** headReference) {
 printf("Deleting MP3\n");
//initialize 2 nodes
struct mp3Node * nextMp3;
struct mp3Node * currentMp3Node  = *headReference;

//start traversing the list
while (currentMp3Node != NULL)  {
    //if the artistName of the current node matches the remove artist node, then remove it from the list
    if (strcmp(removeArtistName, currentMp3Node->artistName) == 0) {
        printf("equal");
        nextMp3 = currentMp3Node -> next;
        //if the headReference is the current node, advance it so you can still traverse the list
        if (*headReference == currentMp3Node) {
            printf("setting");
            
            *headReference = currentMp3Node ->next;
        }
        //assign the current Mp3's next node to the next node in the list
        if(currentMp3Node -> next != NULL) {
            currentMp3Node ->next->prev = currentMp3Node -> prev;
        }
        //assign the current Mp3's previous node to the next node in the lsit
        if (currentMp3Node -> prev != NULL) {
            currentMp3Node -> prev-> next = currentMp3Node -> next;
        }
        
        //free all of the data for the structs we initialized for the node, and free the node itself. 
        free(currentMp3Node->artistName);
        free(currentMp3Node->songTitle);
        free(currentMp3Node->songDate);
        free(currentMp3Node);
        //make the current node the next one
        currentMp3Node = nextMp3;
    }
    else {
        currentMp3Node = currentMp3Node -> next;
    }
}
}

void printForward(struct mp3Node * headReference) {
    printf("Printing Forward\n");
    //traverse the list, front to back, printing along the way
    while (headReference != NULL) {
        printf(" Artist Name: %s, Song Name: %s, Date Of Release: %s, Running Time: %d \n ", headReference->artistName, headReference->songTitle, headReference->songDate, headReference->runTime);
        headReference = headReference->next;
    }
}

void printBackwards(struct mp3Node * headReference) {
    struct mp3Node* lastMp3 = headReference;
    printf("Printing Backwards\n");
    //first traverse the list forwards
    while (headReference != NULL) {
        lastMp3 = headReference;
        headReference = headReference->next;
    }
    //then go backwards and print
    while (lastMp3 != NULL) {
         printf(" Artist Name: %s, Song Name: %s, Date Of Release: %s, Running Time: %d \n ", lastMp3->artistName, lastMp3->songTitle, lastMp3->songDate, lastMp3->runTime);
         lastMp3 = lastMp3->prev;
    }    
}

void deleteAll(struct mp3Node ** headReference) {
    printf("Deleting All MP3's\n");

struct mp3Node * nextMp3;
struct mp3Node * currentMp3Node  = *headReference;

//go through and delete all the remaining nodes in the list.
while (currentMp3Node != NULL)  {
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
        free(currentMp3Node->artistName);
        free(currentMp3Node->songTitle);
        free(currentMp3Node->songDate);
        free(currentMp3Node);
        currentMp3Node = nextMp3;
}
}

int main(int argc, char** argv) {
  //initializing initial node and the strings for the buffer and inputs provided by the user
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
  printf("Press 5 to exit program.\n");
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
           printf("Press 5 to exit program.\n");
      }
      else if (!strcmp(buffer, "2")) {
          printf("Please enter the name of the artist you wish to delete. \n");
          if(fgets(artistNameInput, BUFFERSIZE, stdin) != NULL) {
          printf("Entered Name: %s \n", artistNameInput);
          }
          deleteMp3(artistNameInput, &headNode);
          printf("Welcome to MP3 Doubly Linked List! \n ");
          printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
          printf("Press 5 to exit program.\n");
      }
      else if (!strcmp(buffer, "3")) {
          printForward(headNode);
          printf("Welcome to MP3 Doubly Linked List! \n ");
          printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
          printf("Press 5 to exit program.\n");
      }
      else if (!strcmp(buffer, "4")) {
          printBackwards(headNode);
          printf("Welcome to MP3 Doubly Linked List! \n ");
          printf("Please press 1 to add a new Mp3 to your list, 2 to delete an Mp3 from your list, 3 to print the list forwards, and 4 to print the list backwards \n");
          printf("Press 5 to exit program.\n");
      }
      else if (!strcmp(buffer, "5")) {
          deleteAll(&headNode);
          exit(0);
      }
  }
}

