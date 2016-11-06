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
	string filepath = "C:/Users/David/Documents/My games/oblivion/RendererInfo.txt";
	my_input_file.open(filepath);


	if (my_input_file.is_open())
	{
		cout << "opened\n";
		my_output_file.open("C:/Users/David/Documents/My games/oblivion/output_file.txt", ofstream::trunc);
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
	
	StartProgram("C:/Program Files (x86)/Steam/steamapps/common/FINAL FANTASY XIV - A Realm Reborn/boot/ffxivboot.exe");
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
