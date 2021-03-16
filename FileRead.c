// a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z

/*
        lseek(fd,offset,Position)
Parameters :
1 : File descriptor
2 : Offset (Positive / negative)
3 :     SEEK_SET    -> From staring positioon of file
         SEEK_CUR   -> From current position of file
         SEEK_END   -> From the ened of file

 */

//  Accept file name and position from user and read the 10 bytes of data from that position.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void FileRead(char *name, int possition)
{
	int fd = 0;
	int iRet = 0;
	char mug[10] = {'\0'};
	
	fd = open(name,O_RDONLY);
	
	if(fd == -1)
	{
		printf("Unable to open the file \n");
		return;
	}
	
	iRet = lseek(fd, possition, SEEK_SET);
	printf("return value of lseek : %d \n", iRet);    //same like possition
	
	iRet = read(fd,mug,10);
	printf("Data from the file is :\n");
	
	printf("return value of read : %d\n", iRet);        //how much bytes are read
	write(1,mug,iRet);
	
	printf("\n");
	
	close(fd);
	
}

int main()
{
  char name[20];
  int iValue = 0;
  
  printf("enter the file name \n");
  scanf("%s",name);
  
  printf("Enter the possition \n");
  scanf("%d",&iValue);
  
  FileRead(name,iValue);

return 0;
}

/*

enter the file name
Data.txt
Enter the possition
11
return value of lseek : 11
Data from the file is :
return value of read : 10
nikita rau

*/