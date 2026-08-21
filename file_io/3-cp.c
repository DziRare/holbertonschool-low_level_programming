#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void close_fd(int fd);
void open_files(char *file_from, char *file_to, int *fd_from, int *fd_to);
void copy_content(int fd_from, int fd_to, char *file_to);

/**
 * close_fd - closes a file descriptor and checks for errors
 * @fd: the file descriptor to close
 *
 * Return: void
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_files - opens the source and destination files
 * @file_from: name of the file to read from
 * @file_to: name of the file to write to
 * @fd_from: pointer to store the source file descriptor
 * @fd_to: pointer to store the destination file descriptor
 *
 * Return: void
 */
void open_files(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
}

/**
 * copy_content - copies content from one file descriptor to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_to: name of the destination file (for error messages)
 *
 * Return: void
 */
void copy_content(int fd_from, int fd_to, char *file_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		bytes_read = read(fd_from, buffer, BUFFER_SIZE);
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_to);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv[1], argv[2], &fd_from, &fd_to);
	copy_content(fd_from, fd_to, argv[2]);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
