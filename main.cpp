// Simple Program to Change Window Titles
// By: MottZilla

#include <windows.h>
#include <stdio.h>

char UserString[256];
DWORD ProcessId = 0;
POINT mousepos;

void FindAndChangeWindowTitle()
{		
	HWND hWnd;

	printf("Enter Current Window Title:");
	gets(UserString);
	
	hWnd = FindWindow(NULL, UserString);
	GetWindowThreadProcessId(hWnd, &ProcessId);

	if(UserString[0] == 0)	// If No Title Given by User.
	{	hWnd = NULL;ProcessId = 0;	}
	
    if(ProcessId == 0)
    {
    	printf("Couldn't find Window. Title must match exactly.\nWould you like to use mouse position to find window instead?\n Hover your mouse over the Window Title you want to change, type Y, and then hit ENTER.\n Y/N?\n");
    	gets(UserString);
    	if(UserString[0] == 'Y' || UserString[0] == 'y')
    	{
    		GetCursorPos(&mousepos);
    		hWnd = WindowFromPoint(mousepos);
    		GetWindowThreadProcessId(hWnd, &ProcessId);
    		GetWindowText(hWnd,UserString,256);
		}
		else
		{
			return;
		}
	}

	printf("Process ID:%d\n",ProcessId);
	printf("Current Title: %s\n",UserString);
	printf("Enter New Window Title:");
	gets(UserString);	
	SetWindowText(hWnd, UserString);
}

int main()
{	
	FindAndChangeWindowTitle();	
	return 0;
}
