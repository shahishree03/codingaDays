#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PAGES 100
#define MAX_FRAMES 7

// Function to display the contents of the page frames in rows
void display_frames(int frames[], int num_frames) {
     int num_columns = (num_frames + num_frames - 1) / num_frames;
    for (int i = 0; i < num_columns; i++) {
        for (int j = i; j < num_frames; j += num_columns) {
            if (frames[j] == -1) {
                printf("[ ]\t");
            } else {
                printf("[%d]\t", frames[j]);
            }
           
        }
        printf("\n");
        
    }
}


// Function to check if a page exists in frames
bool page_exists(int frames[], int num_frames, int page) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// FIFO (First-In-First-Out) page replacement algorithm
int fifo(int pages[], int num_pages, int num_frames) {
    int page_faults = 0;
    int frame_index = 0;
    int frames[MAX_FRAMES];

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];

        if (!page_exists(frames, num_frames, page)) {
            frames[frame_index] = page;
            frame_index = (frame_index + 1) % num_frames;
            page_faults++;
        }

        display_frames(frames, num_frames);
    }

    return page_faults;
}

// LRU (Least Recently Used) page replacement algorithm
int lru(int pages[], int num_pages, int num_frames) {
    int page_faults = 0;
    int frames[MAX_FRAMES];
    int used_count[MAX_FRAMES] = {0};

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];

        if (!page_exists(frames, num_frames, page)) {
            int min_used = used_count[0];
            int min_index = 0;

            for (int j = 1; j < num_frames; j++) {
                if (used_count[j] < min_used) {
                    min_used = used_count[j];
                    min_index = j;
                }
            }

            frames[min_index] = page;
            page_faults++;
        }

        for (int j = 0; j < num_frames; j++) {
            if (frames[j] != -1) {
                used_count[j]++;
            }
        }

        used_count[page_exists(frames, num_frames, page)] = 0;
        display_frames(frames, num_frames);
    }

    return page_faults;
}

// OPT (Optimal) page replacement algorithm
int opt(int pages[], int num_pages, int num_frames) {
    int page_faults = 0;
    int frames[MAX_FRAMES];

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        int page = pages[i];

        if (!page_exists(frames, num_frames, page)) {
            int replace_index = -1;

            for (int j = 0; j < num_frames; j++) {
                int future_page_index = -1;

                for (int k = i + 1; k < num_pages; k++) {
                    if (pages[k] == frames[j]) {
                        future_page_index = k;
                        break;
                    }
                }

                if (future_page_index == -1) {
                    replace_index = j;
                    break;
                }

                if (replace_index == -1 || future_page_index > i) {
                    replace_index = j;
                }
            }

            frames[replace_index] = page;
            page_faults++;
        }

        display_frames(frames, num_frames);
    }

    return page_faults;
}

int main() {
    int pages[MAX_PAGES];
    int num_frames;
    int num_pages;
    int page_faults;
    int choice;

    srand(time(NULL));

    printf("Enter the number of page references (1-100): ");
    scanf("%d", &num_pages);

    if (num_pages < 1 || num_pages > MAX_PAGES) {
        printf("Number of pages is out of range.\n");
        return 1;
    }

    printf("Page Reference String: ");
    for (int i = 0; i < num_pages; i++) {
        pages[i] = rand() % 10; // Pages range from 0 to 9
        printf("%d ", pages[i]);
    }
    printf("\n");

    printf("Enter the number of page frames (1-7): ");
    scanf("%d", &num_frames);

    if (num_frames < 1 || num_frames > MAX_FRAMES) {
        printf("Number of frames is out of range.\n");
        return 1;
    }

    while (1) {
        printf("\nSelect Page Replacement Algorithm:\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. Optimal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("FIFO Algorithm:\n");
                page_faults = fifo(pages, num_pages, num_frames);
                printf("Total Page Faults: %d\n\n", page_faults);
                break;
            case 2:
                printf("LRU Algorithm:\n");
                page_faults = lru(pages, num_pages, num_frames);
                printf("Total Page Faults: %d\n\n", page_faults);
                break;
            case 3:
                printf("Optimal Algorithm:\n");
                page_faults = opt(pages, num_pages, num_frames);
                printf("Total Page Faults: %d\n\n", page_faults);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
