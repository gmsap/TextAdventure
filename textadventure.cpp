#include <iostream>
#include <fstream>
#include <string>

using namespace std;  

class character
{
public:
	string name = "";
	int health = 100;
};

class item
{
public:
	int health = 10;
};

class weapon : public item
{
public:
	int damage = 1;
};

character loadCharacter(string n) //input from a file
{
	character c;
	bool found = false;
	string line = "";

	ifstream file("saves.txt");
	
	if(file.is_open())
	{
		while(getline(file,line))
		{
			if(line == n)
			{
				c.name = n;
			}
		}
		file.close();
	}

	return c;
}

void saveCharacter(character c)
{
	//output to a file
	ofstream file;
	file.open ("saves.txt", fstream::app);
	file << c.name << endl;
	file.close();
}

int main()
{
	bool running = true;
	string input = "";
	character player;

	cout << endl << "Enter 'new' for a new character, or 'load' to load an existing character." << endl;
	getline(cin, input);
	if(input == "load") {
		cout << endl << "Enter the character's name." << endl;
		getline(cin,input);
		player = loadCharacter(input);
	} else {

	}

	cout << endl << "Loading... Enter 'help' at any point for a list of commands." << endl;

	while (running)
	{
		cout << endl << "Enter an action." << endl;
		getline(cin, input);
		if(input == "name") {
			cout << endl << "Enter your character's name." << endl;
			getline(cin, input);
			player.name = input;
		} else if(input == "stats") {
			cout << endl << player.name << endl;
		} else if(input == "save") {
			saveCharacter(player);
		} else if(input == "exit") {
			running = false;
			cout << endl << "Shutting down." << endl;
		} else {
			cout << endl << "Unknown command." << endl;
		}
	}

	return 0;
}