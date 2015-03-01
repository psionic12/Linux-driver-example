#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	char mem[0x100];
	fd = open("/dev/char_device_example",O_RDWR);
	read(fd, mem, 0x10);
	printf("%s\n", mem);
	return 0;
}