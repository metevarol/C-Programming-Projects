#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define MAX_PIPE_CMDS 20

pid_t child_pids[MAX_PIPE_CMDS];
int num_pipe_cmds = 0;

void terminate_child_processes() {
    for (int i = 0; i < num_pipe_cmds; i++) {
        kill(child_pids[i], SIGTERM);
    }
}

int main() {
    char input[256]; // assuming input string is at most 256 characters
    char *pipe_cmds[MAX_PIPE_CMDS];

    // Register the signal handler for terminating child processes on exit
    atexit(terminate_child_processes);

    while (1) {
        // Get the input string from the user
        printf("Enter a string with pipe-separated commands (up to %d):\n", MAX_PIPE_CMDS);
        fgets(input, sizeof(input), stdin);

        if (input[0] == ':' && input[1] == 'q') {
            exit(0);
        }

        // Tokenize the input string by the pipe character
        char *token = strtok(input, "|");
        while (token != NULL && num_pipe_cmds < MAX_PIPE_CMDS) {
            pipe_cmds[num_pipe_cmds++] = token;
            if (token[0] == ' ') {
                memmove(token, token + 1, strlen(token));
            }
            token = strtok(NULL, "|");
        }

        // Set up pipes and execute commands
        int fds[2];
        int fd_in = 0;

        for (int i = 0; i < num_pipe_cmds; i++) {
            pipe(fds);

            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                // Child process
                if (i < num_pipe_cmds - 1) {
                    dup2(fds[1], STDOUT_FILENO); // Redirect stdout to write end of the pipe
                }
                close(fds[0]); // Close the read end of the pipe, not needed in child

                if (fd_in != 0) {
                    dup2(fd_in, STDIN_FILENO); // Redirect stdin to read end of previous pipe
                }

                execl("/bin/sh", "sh", "-c", pipe_cmds[i], NULL);
                perror("execl");
                exit(1);
            } else {
                // Parent process
                close(fds[1]); // Close write end of the current pipe, no longer needed
                fd_in = fds[0]; // Set fd_in for the next iteration to the read end of the current pipe
                child_pids[i] = pid; // Store the child process ID
            }
        }

        // Wait for child processes to complete
        for (int i = 0; i < num_pipe_cmds; i++) {
            int status;
            waitpid(child_pids[i], &status, 0);
        }

        // Log the pids and corresponding commands
        time_t current_time = time(NULL);
        char log_file[64];
        snprintf(log_file, sizeof(log_file), "log_%ld.txt", current_time);

        FILE *fp = fopen(log_file, "a");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }

        for(int i = 0; i < num_pipe_cmds; i++) {
        fprintf(fp, "PID: %d, Command: %s\n", child_pids[i], pipe_cmds[i]);
            }
        fclose(fp);

            // Reset the number of pipe commands for the next iteration
    num_pipe_cmds = 0;
}

return 0;

}
