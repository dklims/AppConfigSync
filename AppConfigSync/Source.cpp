#include <fstream>

#include <iostream>
#include <string>

#include <Windows.h>



using namespace std;


void StartProgram(string filename);
int main()

{
	//define / open files
	ifstream my_input_file; 
	ofstream my_output_file;
	char filepath[150];//"C:/Users/David/Documents/My games/oblivion/RendererInfo.txt";
	cout << "enter a directory to copy: ";
	cin.getline(filepath,sizeof(filepath));
	cout << endl;
	
	cout << "enter a destination directory: ";
	char destinationPath[150];
	cin.getline(destinationPath, sizeof(destinationPath));
	cout << endl;

	my_input_file.open(filepath);


	if (my_input_file.is_open())
	{
		cout << "opened\n";
		my_output_file.open(destinationPath, ofstream::trunc);
		char c;
		my_input_file.get(c);
		while (my_input_file)
		{
			my_output_file.put(c);
			my_input_file.get(c);
		}

		my_input_file.close();
		my_output_file.close();


	}
	else
	{
		cout << "FAIL\n";
	}
	char programToStart[150];
	cout << "enter a program to start: ";
	cin.getline(programToStart,sizeof(programToStart));
	
	StartProgram(programToStart);
	//StartProgram("C:/Users/David/AppData/Roaming/Spotify/Spotify.exe");
	//system("copy C:\\Users\\David\\Desktop\\folder_to copy\\' 'C:\\Users\\David\\Desktop\\end\\'");
	//system("copy C:\\Users\\David\\Google Drive\\Saves\\ffxivConfig\\FINAL FANTASY XIV - A Realm Reborn\\ C:\\Users\\David\\Desktop\\end\\");


	cin.get();
	return 0;
}

void StartProgram(string filename)
{
	ShellExecuteA(NULL, "open", filename.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
