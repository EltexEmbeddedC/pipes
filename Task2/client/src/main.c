#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 10

int main() {
  int fifo_fd = open(FIFO_NAME, O_RDONLY);
  if (fifo_fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  if (read(fifo_fd, buffer, BUFFER_SIZE) == -1) {
    perror("read");
    close(fifo_fd);
    exit(EXIT_FAILURE);
  }

  printf("Read from FIFO: %s\n", buffer);

  close(fifo_fd);

  if (unlink(FIFO_NAME) == -1) {
    perror("unlink");
    exit(EXIT_FAILURE);
  }

  return 0;
}
