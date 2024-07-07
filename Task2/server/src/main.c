#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "my_fifo"

int main() {
  if (mkfifo(FIFO_NAME, 0644) == -1) {
    perror("mkfifo");
    exit(EXIT_FAILURE);
  }

  int fifo_fd = open(FIFO_NAME, O_WRONLY);
  if (fifo_fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  const char* message = "Hi!";
  if (write(fifo_fd, message, 3) == -1) {
    perror("write");
    close(fifo_fd);
    exit(EXIT_FAILURE);
  }

  close(fifo_fd);
  return 0;
}
