// main.cpp
#include <iostream>

#include <set>
#include <map>
#include <unordered_set>

#include <vector>
#include <string>
#include <random>

//

void DemoBase() {
	std::vector<int> initialData;
	initialData.reserve(10);
	//=================================================================
	std::random_device rd; // источник истинно случайных чисел - берет энтропию из физических свойств системы, например опрашивает датчики напряжения системы
	std::mt19937 provider(rd()); // источник псевдослучайных чисел - начальное значение задано случайно - mt19937 алгоритм псевдослучайных чисел
	std::uniform_int_distribution<int> distributor(10, 99); // класс доставщик чисел, причесывает числа до нужного нам диапазона ///(100, 900) - диапазн граничных чисел
	//=================================================================

	for (int i = initialData.size(); i < initialData.capacity(); ++i) {
		initialData.push_back(distributor(provider));
	}

	//=================================================================
	// задача найти все уникальные элементы
	//std::vector<int> uniqueData;
	std::set<int> uniqueData; // позволяет быстро находить элемент за время log() и вставлять его

	for (auto& element : initialData) {
		/*bool flag {true};
		for (auto& uElement : uniqueData) {
			if (element == uElement) {
				flag = false;
				break;
			}
		}
		if (flag) {
			uniqueData.push_back(element);
		}*/
		uniqueData.insert(element);
	}

	// ==========================================================
	std::cout << "Atall elements: " << initialData.size() << '\n';
	for (auto& i : initialData) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	std::cout << "Unique elements: " << uniqueData.size() << '\n';
	for (auto& i : uniqueData) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	{

	};
}

class A{
public:
	/*bool operator <(const A& other)const {
		return true;
	}*/
};

// перенесение оператора типа в пространство имен std,
// например, чтобы в классе не определять метод оператора < (меньше)
namespace std {

	template<>
	struct less<A> {
		bool operator()(const A& a, const A& b)const {
			return bool();
		}
	};
	// перегрузка свойства типа по признаку сравниваемости
	// таким образом мы можем научить работать с нашим типом
	// стандартную библиотеку языка нагружая функционал класса 
	// наследуемыми элементами
}

struct MyStruct {
	std::string id;
	std::string name;
	std::string patrinomyc;
	std::string surename;
};

int main() {


	//DemoBase();
	std::set<A> badTest;
	badTest.insert(A());

	// A z;
	// badTest.contains(z);  // появилась данная функция с С++ 20 в 20м стандарте // выбирается в свойствах проекта

	std::map<std::string, MyStruct> dictionary;

	std::vector<MyStruct> data{
		{"q123r15","jack","vitalievich","london"},
		{"q123r11","jon","","eddisson"},
		{"q122r15","ad","ivanovich","frolov"},
		{"q123q15","ivan","vitalievich","enstien"},
		{"q123r15","jack","vitalievich","frolov"},
		{"q123t55","patric","vitalievich","pitt"},	
	};

	// map при вставке проверяет только ключи, и если такой ключ есть, то данные не будут вставлены
	for (int i = 0; i < data.size(); ++i) {
		if (!dictionary.contains(data[i].id)) {
			dictionary.insert({ data[i].id,data[i] }); // (std::pair<std::string,MyStuct> {data[0].id,data[0]}) - компилятор делает так

		}
		else {
			std::cout << "didn't insert data:\n" << data[i].id << '\n' << data[i].name << '\n' <<
				data[i].patrinomyc << '\n' << data[i].surename << '\n' << "\nthis data alredy has:\n" <<
				dictionary[data[i].id].id << '\n' << dictionary[data[i].id].name << '\n' <<
				dictionary[data[i].id].patrinomyc << '\n' << dictionary[data[i].id].surename << '\n';
			// квадратными скобками коллекции map не пользуются
		}

	}


	return 0;
}