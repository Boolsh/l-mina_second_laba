#include <iostream>
#include "BinTree.h"
#include <fstream>
#include <string>


bool process_numbers(BinTree* tree, std::istream& input = std::cin) {
    int number;
    bool res = 0;
    while (input >> number) {
        tree->add(number);
        res = true;
    }
    return res;
}
int menu()
{
    int res;
    std::cout << "Выберите вариант ввода данных\n1.Ввести числа вручную\n2.Считать с файла" << std::endl;
    std::cin >> res;
    return res;
}

int main()
{
    setlocale(LC_ALL, "RU");
	BinTree* tr = new BinTree();
    int choice = menu();
    if (choice == 1)
    {
        std::cout << "Введите числа (для завершения введите нечисловое значение):" << std::endl;
        if (process_numbers(tr))
        {
            tr->print();

            std::cout << "Количество листьев в дереве:" << std::endl;
            std::cout << std::endl << tr->count_leafs();
        }
        else
        {
            std::cout << "Пустое дерево" << std::endl;
        }
    }
    else
    {
        std::cout << "Введите называние файла:" << std::endl;
        std::string file_name;
        std::cin >> file_name;
        file_name += ".txt";
        std::ifstream file(file_name);
        if (!file.is_open())
            std::cout << "Файла не существует" << std::endl;
        else
            if (process_numbers(tr, file))
            {
                tr->print();

                std::cout << "Количество листьев в дереве:" << std::endl;
                std::cout << std::endl << tr->count_leafs();
            }
            else
            {
                std::cout << "Пустое дерево" << std::endl;
            }

    }
	

}