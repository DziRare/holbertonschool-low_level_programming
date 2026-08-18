#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Name of file to read from
 * @letters: Number of letters to be read
 *
 * Return: Number of letters written
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file;
	int letters_read;
	int letters_written;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}
	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters + 1);
	if (buffer == NULL)
	{
		return (0);
	}

	letters_read = read(file, buffer, letters);
	if (letters_read == -1)
	{
		return (0);
	}
	else if (letters_read > 0)
	{
		letters = letters_read;
	}

	letters_written = write(STDOUT_FILENO, buffer, letters);
	if (letters_written == -1)
	{
		return (0);
	}
	free(buffer);
	close(file);

	return (letters_written);
}
