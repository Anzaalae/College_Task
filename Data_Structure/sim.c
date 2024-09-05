#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Page { // this is for struct for Page in frame
    int location;     // location is address in memory
    int r;            // r is referenced bit
    int m;            // m is modified bit
} page;               // i will use struct Page to page

void nru(int frameSize) { // this function is about NRU
    FILE *list = fopen("./access.list", "r"); // for reading access.list file

    int access= 0; // variable for count access
    int read= 0;   // variable for count read
    int write= 0;  // variable for count write
    int hits= 0;   // variable for count page hit
    int faults= 0; // variable for count page fault

    page frame[frameSize]; // page array for frame Queue
    int frameIndex = 0;    // variable for size about present frame
    
    int location;          // varible about physical memory address
    char* action;          // this will contain 'read' or 'write' memory access 
    char buffer[100]= {0}; // this is for save access.list file's access line
    
    int found = 0;         // this is for check if given memory access is already in frame

    while (fgets(buffer, sizeof(buffer), list) != NULL) { // read line by line at access.list
        buffer[strlen(buffer)- 1]= '\0';                // remove end of line message

        location= atoi(strtok(buffer, " "));            // address accessing physical memory
        action= strtok(NULL, " ");                      // access type, this include 'read' or 'write'

        for (int i= 0; i< frameIndex; i++) {           // loop for check if accessing memory is already in frame
            if(frame[i].location == location) {        // case about accessing memory addressing is in frame
                frame[i].r= 1;                         // modify referenced bit that checking index
                if (action[0] == 'w') frame[i].m= 1;   // modify modified bit when access again with write

                page temp= frame[i];                   // for compare frame, initialize temporary frame 
                
                for (int j= i; j< frameIndex- 1; j++) frame[j]= frame[j + 1]; // move front 1 index after founded frame
                
                frame[frameIndex - 1]= temp; // input at last index in frame array

                action[0]=='r' ? read++ : write++; // count access action read or write
                access++;                          // count access
                hits++;                            // find same frame in array means hit

                found= 1;                          // change found condition

                break;                             // end for searching frame
            } // end if conditional statement
        } // end for loop

        if (!found) { // if we can't find in frame we need to add frame now accessing
            page temp;                            // temporary page for compare and sorting array
            temp.location= location;              // initialize temporary frame's memory location that now accessing
            temp.r= 0;                            // initialize temporary frame's r bit to 0
            action[0]=='w' ? temp.m=1 : temp.m=0; // if write access, initialize temporary frame's m bit to 1

            if (frameIndex < frameSize) {                               // if now frame size is not over given frame size
                frame[frameIndex++] = temp;                             // input modified last index in array
            } else {                                                    // if now frame size is full
                int class_found= 0;                                     // check for input class
                for (int k= 0; k< 4; k++) {                             // check for each class
                    for (int i= 0; i< frameIndex; i++) {                // loop for find input class and index
                        if (frame[i].r == (k&2) >> 1 && frame[i].m == (k&1)) { // check bit operation for each class    
                            for (int j= i; j< frameIndex- 1; j++) frame[j]= frame[j + 1]; // move front 1 index after founded frame
                            
                            frame[frameIndex- 1]= temp;                // input frame

                            class_found= 1;                            // modify to check find class
                            break;                                     // out loop because we input frame
                        } // end if conditional statement
                    } // end for loop
                    if (class_found) break;                            // out loop because we input frame
                } // end for loop
            } // end if conditional statement

            action[0]== 'r' ? read++ : write++;  // count access action read or write
            access++;                            // count access
            faults++;                            // failed find same frame in array means fault
        } // end if conditional statement
        found= 0; // modify found state before read next access.list line
    } // end while loop

    printf("Total number of access: %d\n", access); // print now access count
    printf("Total number of read: %d\n", read);     // print now read access count
    printf("Total number of write: %d\n", write);   // print now write access count
    printf("Number of page hits: %d\n", hits);      // print now hits count
    printf("Number of page faults:  %d\n", faults); // print now page fault count
    printf("Page fault rate: %d/%d = %f%%\n", faults, access, (double)faults/access*100); // print now fault rate

    fclose(list);                   // close access.list files
} // end nru function

void fifo(int frameSize) { // this function is about NRU
    FILE *list= fopen("./access.list", "r");

    int access= 0; // variable for count access
    int read= 0;   // variable for count read
    int write= 0;  // variable for count write
    int hits= 0;   // variable for count page hit
    int faults= 0; // variable for count page fault
    
    int *frame= (int *)malloc(sizeof(int)* frameSize); // this is circular Queue frame
    int front= 0;                                      // Queue front index
    int back= 0;                                       // Queue back index
    int count= 0;                                      // count for now frame size
    int found= 0;                                      // for check frame same with now searching

    int location;          // varible about physical memory address
    char* action;          // this will contain 'read' or 'write' memory access 
    char buffer[100]= {0}; // this is for save access.list file's access line

    while(fgets(buffer, sizeof(buffer), list)!= NULL) { // read line by line at access.list
        buffer[strlen(buffer)- 1]= '\0';                // remove end of line message

        location= atoi(strtok(buffer, " "));            // address accessing physical memory
        action= strtok(NULL, " ");                      // access type, this include 'read' or 'write'

        for(int i= front; i< front+ count; i++) {       // loop for check if already Queue has frame now accessing
            if(frame[i % frameSize] == location) {      // if find same memory frame
                found= 1;                               // check for knowing that found same memory address
                
                action[0]=='r' ? read++ : write++;      // count access action read or write
                access++;                               // count access
                hits++;                                 // find same frame in array means hit

                break;                                  // out loop because we find same memory address
            }
        }

        if(!found) {                                    // if we failed to find same memory access
            if(count< frameSize) {                      // if now frame size not exceed given frame size
                frame[back]= location;                  // input frame at Queue's back index
                back= (back+ 1) % frameSize;            // resize back index reference
                count++;                                // count now frame size
            } else {                                    // if now frame size id full now
                front= (front+ 1) % frameSize;          // move 1 front index reference 
                frame[back]= location;                  // input frame at Queue's back index
                back= (back+ 1) % frameSize;            // resize back index reference
            } // end if conditional statement

            action[0]== 'r' ? read++ : write++;  // count access action read or write
            access++;                            // count access
            faults++;                            // failed find same frame in array means fault
        } // end if conditional statement

        found= 0;                                // modify found state before read next access.list line
    } // end while loop

    printf("Total number of access: %d\n", access); // print now access count
    printf("Total number of read: %d\n", read);     // print now read access count
    printf("Total number of write: %d\n", write);   // print now write access count
    printf("Number of page hits: %d\n", hits);      // print now hits count
    printf("Number of page faults:  %d\n", faults); // print now page fault count
    printf("Page fault rate: %d/%d = %f%%\n", faults, access, (double)faults/access*100); // print now fault rate
    
    free(frame);                    // free dynamic memory allocation
    fclose(list);                   // close access.list files
} // end fifo function

int main(int args, char* argv[]) {  // main function
    char *vm= argv[1];              // variable for 'fifo' or 'nru'
    int frameSize= atoi(argv[2]);   // variable for frame size 

    if(strcmp(vm, "fifo")== 0) fifo(frameSize);     // if user input 'fifo', execute fifo funciton
    else if(strcmp(vm, "nru")== 0) nru(frameSize);  // else if user input 'nru', execute nru function
    
    return 0; // end main function
} // end main function