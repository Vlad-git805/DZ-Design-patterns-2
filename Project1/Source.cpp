#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Messages
{
private:
	static Messages* messages;
	Messages() {}
	Messages(const Messages&) = delete;
	Messages& operator=(Messages&) = delete;

public:

	static Messages* GetInstance()
	{
		if (messages == nullptr)
			messages = new  Messages();
		return messages;
	}

	void Write_to_file(string msg)
	{
		ofstream fout;
		fout.open("file.txt", ios::app);
		fout << msg << endl;
		fout.close();
	}

	void Reading_from_file()
	{
		string str;
		ifstream fin;
		fin.open("file.txt");
		while (getline(fin, str))
		{
			cout << str << endl;
		}
		fin.close();
	}
};

Messages* Messages::messages = nullptr;

int main()
{
	Messages::GetInstance()->Write_to_file("lolkek");

	Messages::GetInstance()->Reading_from_file();
	system("pause");
	return 0;
}