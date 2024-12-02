#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 100

int main()
{
	int fd, i;
	char buffer[BUFFER_SIZE];
	//opening the fifo for writing
	fd=open(FIFO_NAME, O_WRONLY);
	if(fd==-1)
	{
		perror("error in opening the FIFO for writing\n");
		exit(0);
	}
	//writing the message to the fifo
	for(int i=0;i<5;i++)
	{
		snprintf(buffer, BUFFER_SIZE, "message %d from the writer\n",i+1);
		write(fd, buffer, strlen(buffer)+1); //+1 for null
	}
	printf("message %d written\n",i+1);
	close(fd);
}
