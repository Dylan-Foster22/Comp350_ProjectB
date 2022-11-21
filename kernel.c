//void printChar(char);
void readSector(char*, int);
void printString(char*);
//void readString(char*);
void handleInterrupt21(int AX, int BX, int CX, int DX);

main()
{

//	ah=0xe
//	al='Z'
//	printChar('Z');
	//assume intterupt 21 is printChar
//	interrupt(0x21,100,'W',0,0);

	char buffer[512];
	readSector(buffer,30);
//	char line[80];


//	printString("Enter a line   ");
//	readString(line);
//	printString(line);
	printString(buffer);

	printString("Hello World       ");

	makeInterrupt21();
	interrupt(0x21,0,0,0,0);

	while(1){}
}

void printString(char* c)
{
	int r = 0;
	for(r = 0; c[r] != 0;r++)
	{
	interrupt(0x10,0xe*256+c[r],0,0,0);
	}
}

void readSector(char* buffer, int sector)
{
int AH = 2;
int AL = 1;
int AX = AH*256+AL;
	interrupt(0x13,AX, buffer, sector+1, 0x80);
}

//void readString(char* line)
//{

//index = 0;

//while(1)
//{
//achar = interrupt(0x16,

//printChar(achar);
//line[index] == achar;
//index = index+1;
//if user pressed enter, break OR if achar is enter, break
//}
//print a 0xa, put 0xa into line[index++];
//put a 0 into line[index];
//}

void printChar(char c)
{
	interrupt(0x10,0xe*100+c,0,0,0);
}

void handleInterrupt21(int AX, int BX, int CX, int DX)
{
	if (AX==0)
	{
		printString("Hello World Again \n");
	}
}
