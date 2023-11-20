#include <stdio.h>
#include <stdlib.h>
void display_frames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        printf("| ");
        if (frames[i] == -1) {
            printf("   ");
        } else {
            printf("%2d ", frames[i]);
        }
        printf("|\n");
    }
    for (int i = 0; i < n; i++) {
        printf("----");
    }
    printf("\n");
}

void fcfs(int* arr, int n, int frames)
{
   int page_faults = 0;
    int frame_index = 0;
    int frame[frames];

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = arr[i];
        int page_found = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            frame[frame_index] = page;
            frame_index = (frame_index + 1) % frames;
            page_faults++;
        }

        display_frames(frame, frames);
    }

    printf("Page Faults: %d\n", page_faults);
}

void lru(int* arr,int n, int frames)
{
int page_faults = 0;
    int frame[frames];

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = arr[i];
        int page_found = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            // Find the least recently used page
            int lru_index = i;
            for (int j = 0; j < frames; j++) {
                for (int k = i - 1; k >= 0; k--) {
                    if (frame[j] == arr[k]) {
                        if (k < lru_index) {
                            lru_index = k;
                            frame[j] = page;
                            page_faults++;
                        }
                        break;
                    }
                }
            }

            if (!page_found) {
                frame[i % frames] = page;
                page_faults++;
            }
        }

        display_frames(frame, frames);
    }

    printf("Page Faults: %d\n", page_faults);
}
void opt(int* arr, int n, int frames)
{
int page_faults = 0;
    int frame[frames];

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int page = arr[i];
        int page_found = 0;

        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            int replace_index = -1;

            for (int j = 0; j < frames; j++) {
                int future_page_index = -1;

                for (int k = i + 1; k < n; k++) {
                    if (arr[k] == frame[j]) {
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

            frame[replace_index] = page;
            page_faults++;
        }

        display_frames(frame, frames);
    }

    printf("Page Faults: %d\n", page_faults);
}

int main()
{
    int n, nframes,i,arr[20];
    printf("enter numner of eleemnts for your arr ");
    scanf("%d",&n);
    printf("\nEnter number of frames: ");
    scanf("%d",&nframes);
    printf("\nenter elements referencs.......\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nFCFS\n");
    fcfs(arr,n,nframes);
    printf("\nLRU\n");
    lru(arr,n,nframes);
    printf("\nOPT\n");
    opt(arr,n,nframes);
}