#include "shell.h"
#include <fcntl.h>

#define CP_BUF_SIZE 4096

int cp_command(char **argv) {
    int src_fd, dest_fd;
    ssize_t bytes_read;
    char buffer[CP_BUF_SIZE];
    
    src_fd = open(argv[1], O_RDONLY);
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while ((bytes_read = read(src_fd, buffer, CP_BUF_SIZE)) > 0) {
        ssize_t bytes_written = 0;
        
        while (bytes_written < bytes_read) {
            ssize_t result = write(dest_fd, buffer + bytes_written, bytes_read - bytes_written);
            bytes_written += result;
        }
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}
