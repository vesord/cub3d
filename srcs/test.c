#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	create_bmp(int *bits);

int	main()
{
	int *my_bmp;

	my_bmp = (int*)malloc(sizeof(int) * 100);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			my_bmp[10 * i + j] = 255;
		}
	}
	create_bmp(my_bmp);
	free(my_bmp);
	return (0);
}

void	create_bmp(int *bits)
{
	int fd;

	fd = open("bmp.bmp", O_CREAT | O_RDWR);
	// ---BITMAP FILE HEADER---
	write(fd, "BM", 2);			// TYPE OF ENDIAN, "MB" for big-end
	int size = 40 + 14 + 4 * 100;
	write(fd, &size, 4);				// SIZE OF ALL FILE
	int reserved = 0;
	write(fd, &reserved, 4);			// RESERVED
	int	offset = 54;
	write(fd, &offset, 4);			// OFFSET TO COLOR BITS

	// ---BITMAP INFO---
	int bminfo_size = 40;
	write(fd, &bminfo_size, 4);		// SIZE BMPv3
	int width = 10;
	int height = 10;
	write(fd, &width, 4);			// WIDTH
	write(fd, &height, 4);			// HEIGHT
	short planes = 1;
	write(fd, &planes, 2);			// ALWAYS 1 FOR BMP
	short btp = 32;
	write(fd, &btp, 2);				// BITS PER PIXEL
	int	comression = 0;
	write(fd, &comression, 4);		// ??? 0
	int	img_size = width * height;
	write(fd, &img_size, 4);			// IMAGE SIZE
	int	ppm = 1000;
	write(fd, &ppm, 4);				// ??? X PIXELS PER METER
	write(fd, &ppm, 4);				// ??? Y PIXELS PER METER
	int color = 0;
	write(fd, &color, 4);			// ??? COLOR TABLE
	write(fd, &color, 4);			// ??? COLOR TABLE SIZE
	write(fd, bits, 400);			// COLOR BITS
	close(fd);
}
