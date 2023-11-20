#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024 // 1KB memory hole

typedef struct {
    int id;
    int size;
    int allocated;
} Process;

void initialize(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].allocated = 0;
    }
}

void display_memory(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        if (processes[i].allocated) {
            printf("P%d (%dKB) ", processes[i].id, processes[i].size);
        } else {
            printf("[ ] (%dKB) ", processes[i].size);
        }
    }
    printf("\n");
}

int first_fit(Process processes[], int n) {
    int wasted_memory = 0;
    for (int i = 0; i < n; i++) {
        if (!processes[i].allocated) {
            for (int j = 0; j < n; j++) {
                if (!processes[j].allocated && processes[j].size >= processes[i].size) {
                    processes[j].allocated = 1;
                    wasted_memory += processes[j].size - processes[i].size;
                    break;
                }
            }
        }
    }
    return wasted_memory;
}

int best_fit(Process processes[], int n) {
    int wasted_memory = 0;
    for (int i = 0; i < n; i++) {
        if (!processes[i].allocated) {
            int best_fit_index = -1;
            int min_fragmentation = MEMORY_SIZE + 1;
            for (int j = 0; j < n; j++) {
                if (!processes[j].allocated && processes[j].size >= processes[i].size) {
                    int fragmentation = processes[j].size - processes[i].size;
                    if (fragmentation < min_fragmentation) {
                        best_fit_index = j;
                        min_fragmentation = fragmentation;
                    }
                }
            }
            if (best_fit_index != -1) {
                processes[best_fit_index].allocated = 1;
                wasted_memory += min_fragmentation;
            }
        }
    }
    return wasted_memory;
}

int worst_fit(Process processes[], int n) {
    int wasted_memory = 0;
    for (int i = 0; i < n; i++) {
        if (!processes[i].allocated) {
            int worst_fit_index = -1;
            int max_fragmentation = -1;
            for (int j = 0; j < n; j++) {
                if (!processes[j].allocated && processes[j].size >= processes[i].size) {
                    int fragmentation = processes[j].size - processes[i].size;
                    if (fragmentation > max_fragmentation) {
                        worst_fit_index = j;
                        max_fragmentation = fragmentation;
                    }
                }
            }
            if (worst_fit_index != -1) {
                processes[worst_fit_index].allocated = 1;
                wasted_memory += max_fragmentation;
            }
        }
    }
    return wasted_memory;
}

int main() {
    Process processes[] = {
        {1, 200, 0},
        {2, 300, 0},
        {3, 150, 0},
        {4, 400, 0},
        {5, 100, 0},
        {6, 50, 0},
        {7, 250, 0}
    };
    int num_processes = sizeof(processes) / sizeof(Process);

    initialize(processes, num_processes);

    printf("First Fit:\n");
    int wasted_memory_first_fit = first_fit(processes, num_processes);
    display_memory(processes, num_processes);
    printf("Total wasted memory (External Fragmentation + Internal Fragmentation): %d KB\n\n", wasted_memory_first_fit);

    initialize(processes, num_processes); // Reset allocation
    printf("Best Fit:\n");
    int wasted_memory_best_fit = best_fit(processes, num_processes);
    display_memory(processes, num_processes);
    printf("Total wasted memory (External Fragmentation + Internal Fragmentation): %d KB\n\n", wasted_memory_best_fit);

    initialize(processes, num_processes); // Reset allocation
    printf("Worst Fit:\n");
    int wasted_memory_worst_fit = worst_fit(processes, num_processes);
    display_memory(processes, num_processes);
    printf("Total wasted memory (External Fragmentation + Internal Fragmentation): %d KB\n\n", wasted_memory_worst_fit);

    return 0;
}
