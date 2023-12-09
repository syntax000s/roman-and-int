#include<iostream>
#include<map>

std::map<int, char> int_roman;
std::map<char, int> roman_int;

int roman_TOint(std::map< char, int> mp,std::string str )
{
	int result = 0, buf = mp[str[0]];
	for (int i = 0; i < str.size(); i++) {
		if(buf >= mp[str[i]])
		{ 
			result += mp[str[i]];
		}
		else
		{
			result = (result - buf * 2) + mp[str[i]];

		}
		buf = mp[str[i]];
	}


	return result;
}
std::string int_TOroman(std::map<int, char> mp, int number)
{
	std::string result = "";
	std::map<int, char>::iterator it;

	it = mp.begin();
	for (int i = 0; i < mp.size()-1; i++) { it++; }

	bool sequence = false;
	for (int i=0; number > 0;i++) {
		if(number<it->first)
		{

			if (i == 1) { sequence = 1; }
			else { sequence = 0; }

			it--,i=0;
			continue;
		}
		else
		{
			number = number - it->first;
			result = result + it->second;
			if (i == 4 && (it->first <= 100))
			{
				if(!sequence){ i++; }
				
				while (i)
				{
					result.pop_back();
					i--;
				}
				result = result + it->second;
				if(!sequence){ it++; }
				it++;
				result = result + it->second;

			}
			
		}
	}



	return result;
}
void interfeis()
{
	int chois=1;

	while (chois) {
		std::cout << "\nenter action\n1-roman to int\n2-int to roman\n0-exit\n";
		std::cin >> chois;
		if(chois==1)
		{
			std::cout << "enter roman number: ";
			std::string str;
			std::cin >> str;
			std::cout << roman_TOint(roman_int, str) << '\n';
			continue;
		}
		if(chois==2)
		{
			int num;
			std::cout << "enter int number: ";
			std::cin >> num;
			std::cout << int_TOroman(int_roman, num);
			continue;
		}
		std::cout << "no correct input, again\n";
	}
}
int main()
{
	int_roman[1] = 'I';
	int_roman[5] = 'V';
	int_roman[10] = 'X';
	int_roman[50] = 'L';
	int_roman[100] = 'C';
	int_roman[500] = 'D';
	int_roman[1000] = 'M';
	roman_int['I'] = 1;
	roman_int['V'] = 5;
	roman_int['X'] = 10;
	roman_int['L'] = 50;
	roman_int['C'] = 100;
	roman_int['D'] = 500;
	roman_int['M'] = 1000;
	
	interfeis();
	

	return 0;
}
