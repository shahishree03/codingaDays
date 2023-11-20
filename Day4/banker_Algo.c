#include <stdio.h>

#define MAX_RESOURCES 10
#define MAX_PROCESSES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes, num_resources;

void input_data() {
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the maximum resources for each process:\n");
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for (j = 0; j < num_resources; j++) {
        scanf("%d", &available[j]);
    }

    printf("Enter the allocated resources to processes:\n");
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
}


void calculate_need() {
    int i, j;
    for (i = 0; i < num_processes; i++) {
        for (j = 0; j < num_resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int is_safe_state() {
    int i, j, count = 0;

    for (i = 0; i < num_processes; i++) {
        finish[i] = 0;
    }

    for (j = 0; j < num_resources; j++) {
        work[j] = available[j];
    }

    for (i = 0; i < num_processes; i++) {
        if (finish[i] == 0) {
            int can_allocate = 1;
            for (j = 0; j < num_resources; j++) {
                if (need[i][j] > work[j]) {
                    can_allocate = 0;
                    break;
                }
            }
            if (can_allocate) {
                finish[i] = 1;
                for (j = 0; j < num_resources; j++) {
                    work[j] += allocation[i][j];
                }
                i = -1; // Start over
                count++;
            }
        }
    }

    return count == num_processes;
}

int request_resources(int process, int request[]) {
    int i;

    for (i = 0; i < num_resources; i++) {
        if (request[i] > need[process][i] || request[i] > available[i]) {
            return 0; // Request cannot be granted
        }
    }

    for (i = 0; i < num_resources; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    if (is_safe_state()) {
        return 1; // Request granted
    } else {
        // Rollback changes
        for (i = 0; i < num_resources; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
            need[process][i] += request[i];
        }
        return 0; // Request denied
    }
}

void display_matrix(const char* name, int matrix[MAX_PROCESSES][MAX_RESOURCES], int rows, int cols) {
    printf("%s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void display_safe_sequence(int sequence[], int length) {
    printf("Safe sequence: ");
    for (int i = 0; i < length; i++) {
        printf("P%d", sequence[i]);
        if (i < length - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}
int main() {
    int process, request[MAX_RESOURCES];

    input_data();
    calculate_need();

    display_matrix("Maximum Matrix", maximum, num_processes, num_resources);
    display_matrix("Allocation Matrix", allocation, num_processes, num_resources);
    display_matrix("Need Matrix", need, num_processes, num_resources);


    printf("Enter the process number (0-%d) and the request for resources:\n", num_processes - 1);
    scanf("%d", &process);
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &request[i]);
    }

    if (request_resources(process, request)) {
        printf("Request granted. System is in a safe state.\n");
    } else {
        printf("Request denied. System would be in an unsafe state.\n");
    }

    if (is_safe_state()) {
        int safe_sequence[MAX_PROCESSES];
        int sequence_length = 0;
        
        for (int i = 0; i < num_processes; i++) {
            if (finish[i] == 1) {
                safe_sequence[sequence_length] = i;
                sequence_length++;
            }
        }

        display_safe_sequence(safe_sequence, sequence_length);
        printf("System is in a safe state.\n");
    } else {
        printf("System is in an unsafe state.\n");
    }

}
