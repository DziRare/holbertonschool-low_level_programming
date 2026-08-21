#ifndef _FILE_IO_H_
#define _FILE_IO_H_

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

int append_text_to_file(const char *filename, char *text_content);

void close_fd(int fd);

#endif /* _FILE_IO_H_ */

