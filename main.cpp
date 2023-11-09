//Создать класс словарь по примеру с питона дав методы
//
//добавить
//
//удалить(по ключу)
//
//Перегрузить индексатор для получения значения по ключу
//
//Дать метод получения всех ключей

#include <iostream>
#include <string>

template <typename KeyType, typename ValType>

class Dictionary
{

private:
	static const int MAX_SIZE = 1000;
	KeyType keys[MAX_SIZE];
	ValType vals[MAX_SIZE];
	int size;

public:
	Dictionary()
	{
		size = 0;	
	}


	void add(const KeyType& key, const ValType& val)
	{
		if (size < MAX_SIZE)
		{
			keys[size] = key;
			vals[size] = val;
			size++;
		}
	}


	void remove(const KeyType& key) {
		for (int i = 0; i < size; i++) {
			if (keys[i] == key) {
				for (int j = i; j < size - 1; j++) {
					keys[j] = keys[j + 1];
					vals[j] = vals[j + 1];
				}
				size--;
				keys[size] = KeyType();
				vals[size] = ValType();
				return;
			}
		}
	}

	ValType& operator[](const KeyType& key)
	{
		for (int i = 0; i < size; i++)
		{
			if (keys[i] == key)
			{
				return vals[i];
			}
		}
		keys[size] = key;
		vals[size] = ValType();
		size++;
		return vals[size - 1];
	}

	void getAllKeys()
	{
		std::cout << "All keys: " << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << keys[i] << std::endl;
		}
	}
};

int main() 
{
	setlocale(LC_ALL, "");
	
	Dictionary<std::string, std::string>dictEngToRu;

	dictEngToRu.add("improve", "улучшать");
	dictEngToRu.add("understand", "понимать");
	dictEngToRu.add("give", "давать");
	dictEngToRu.add("study", "учиться");
	dictEngToRu.add("speak", "говорить");

	std::cout << "improve: " << dictEngToRu["improve"] << std::endl;
	std::cout << "understand: " << dictEngToRu["understand"] << std::endl;
	std::cout << "speak: " << dictEngToRu["speak"] << std::endl;
	std::cout << "give: " << dictEngToRu["give"] << std::endl;
	dictEngToRu.getAllKeys();
	dictEngToRu.remove("give");
	std::cout << "give: " << dictEngToRu["give"] << std::endl;

	std::cout << "give: " << dictEngToRu["give"] << std::endl;
	std::cout << "study: " << dictEngToRu["study"] << std::endl;

	dictEngToRu.getAllKeys();
	
	return 0;
}
