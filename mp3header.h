/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mp3header.h
 * Author: Tommy
 *
 * Created on September 3, 2018, 1:59 PM
 */

#ifndef MP3HEADER_H
#define MP3HEADER_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
//
/*
 mp3Node: a doubly linked list node containing an artistName in string,
 * a song title in string, a song date in sting, and the runtime of the song as an int. It also has pointers to the next and previous songs 
 * in the MP3 list. 
 */
typedef struct mp3Node {
    char * artistName;
    char * songTitle;
    char * songDate;
    int runTime;
    struct mp3Node * next;
    struct mp3Node * prev; 
} mp3Node;

/* addMp3: Takes in 3 strings from the user (newArtistName, newSongTitle, newSongDate) and an int from the user (newRunTime), along with the address of
 * the head node in the doubly linked list and adds a new mp3 node to the back of the list.
 */
void addMp3 (char * newArtistName, char * newSongTitle, char * newSongDate, int newRunTime, struct mp3Node** headReference);

/* deleteMp3: Takes in a string from the user (removeArtistName) and the address of the head node of the doubly linked list
 * and deletes all mp3's from the list that have that artists name attached to it.
 */
void deleteMp3 (char * removeArtistName, struct mp3Node** headReference);

/*  printForward: Takes in the address of the head node in the doubly linked list and prints out the data in each node of the linked list 
 *  from the first entry to the last one.
 */

void printForward (struct mp3Node* headReference);

/*  printBackward: Takes in the address of the head node in the doubly linked list and prints out the data in each node of the linked list 
 *  from the last entry to the first one.
 */

void printBackward (struct mp3Node* headReference);

/* deleteAll: Takes in the address of the head node of the linked list and deletes all of its nodes before exiting program.
 */
void deleteAll(struct mp3Node** headReference);
#endif /* MP3HEADER_H */

