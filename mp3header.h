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
 mp3Node: a doubly linked list node containing an artistName in char,
 * a song title in char, a song date in char perferably in mm-dd-yy format,
 * and the runtime of the song.
 * 
 */
typedef struct mp3Node {
    char * artistName;
    char * songTitle;
    char * songDate;
    int runTime;
    struct mp3Node * next;
    struct mp3Node * prev; 
} mp3Node;
/* addMp3: Adds a new mp3 node to the back of the list.
 */
void addMp3 (char * newArtistName, char * newSongTitle, char * newSongDate, int newRunTime, struct mp3Node** headReference);

/* deleteMp3: Deletes all entries from a specific artist from the linked list.
 */
void deleteMp3 (char * removeArtistName, struct mp3Node** headReference);

/*  printForward: does a forward traversal of the list 
 */

void printForward (struct mp3Node* headReference);

/* printBackwards: does a reverse transversal of the list
 */

void printBackward (struct mp3Node* headReference);
#endif /* MP3HEADER_H */

