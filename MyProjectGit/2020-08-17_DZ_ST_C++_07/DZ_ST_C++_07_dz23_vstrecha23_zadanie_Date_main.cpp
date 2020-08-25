﻿// DZ_ST_C++_07_dz23_vstrecha23_zadanie_Date_main.cpp
//
// задание из файла DZ_ST_C++_03.pdf
// Встреча №10
// Тема: Перегрузка операторов глобальными функциями,
//       дружественные функции, дружественная перегрузка,
//       перегрузка ввода - вывода
// Задание.
/*
Создайте класс с именем Date для хранения даты
(или используйте ранее созданный).
В классе должна быть функция-член, которая увеличивает день на 1.
Напишите соответствующие конструкторы и функции-члены.
В классе должны быть перегружены операции:
++, -- ,!=, ==, >, <, >>, <<, =, +=, -=, ().
Используйте обычную и дружественную перегрузку.
*/

#include <iostream>
#include <clocale>
#include "DZ_ST_C++_07_dz23_vstrecha23_zadanie_Date.h"
using namespace spaceDate;



// ГЛАВНАЯ ФУНКЦИЯ
int main() {
	setlocale(LC_ALL, "ru");

	// создание объекта конструктором по умолчанию
	std::cout << " Создадим объект Дата Конструктором по умолчанию:  ";
	Date date1;
	std::cout << "Дата == " << date1 << std::endl;
	std::cout << std::endl;

	// вывод номера объекта перегруженным оператором ()
	std::cout << " Выведем оператором () номер объекта-даты: " << date1() << std::endl;
	std::cout << std::endl;

	// создание объекта конструктором с параметрами
	std::cout << " Создадим объект Дата Конструктором с параметрами: ";
	Date date2(29, 02, 2000);
	std::cout << "Дата " << date2() << " == " << date2 << std::endl;
	std::cout << std::endl;

	// создание объекта конструктором копирования
	std::cout << " Создадим объект Дата Конструктором копирования копированием Даты " << date2() << " >>>" << std::endl;
	Date date3(date2);
	std::cout << " Дата " << date3() << " == " << date3 << std::endl;
	std::cout << std::endl;

	// присвоение значений объекту перегруженным оператором =
	std::cout << " Присвоим объекту Дата " << date1() << " значение объекта Дата" << date2() << ": ";
	date1 = date2;
	std::cout << "Дата " << date1() << " == " << date1 << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором ++C
	std::cout << " Изменим значение объекта Дата " << date1() << " == " << date1 << " оператором ++С >>> " << std::endl;
	std::cout << " Дата " << date1() << " == " << ++date1 << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором --C
	std::cout << " Изменим значение объекта Дата " << date1() << " == " << date1 << " оператором --С >>> " << std::endl;
	std::cout << " Дата " << date1() << " == " << --date1 << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором C++
	std::cout << " Изменим значение объекта Дата " << date1() << " == " << date1 << " оператором С++ >>> " << std::endl;
	std::cout << " Возвращенное значение: Дата " << date1() << " == " << date1++ << std::endl;
	std::cout << " Измененное значение  : Дата " << date1() << " == " << date1 << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором C--
	std::cout << " Изменим значение объекта Дата " << date1() << " == " << date1 << " оператором С-- >>> " << std::endl;
	std::cout << " Возвращенное значение: Дата " << date1() << " == " << date1-- << std::endl;
	std::cout << " Измененное значение  : Дата " << date1() << " == " << date1 << std::endl;
	std::cout << std::endl;

	int value{ 0 };

	// изменение значения объекта перегруженным оператором +=
	value = 20;
	std::cout
		<< " Изменим значение объекта Дата " << date1() << " == " << date1
		<< " оператором += на " << value << " >>> " << std::endl;
	std::cout << " Дата " << date1() << " == " << (date1 += value) << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором +=
	value = -5;
	std::cout
		<< " Изменим значение объекта Дата " << date1() << " == " << date1
		<< " оператором += на " << value << " >>> " << std::endl;
	std::cout << " Дата " << date1() << " == " << (date1 += value) << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором -=
	value = 10;
	std::cout
		<< " Изменим значение объекта Дата " << date1() << " == " << date1
		<< " оператором -= на " << value << " >>> " << std::endl;
	std::cout << " Дата " << date1() << " == " << (date1 -= value) << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором -=
	value = -20;
	std::cout
		<< " Изменим значение объекта Дата " << date1() << " == " << date1
		<< " оператором -= на " << value << " >>> " << std::endl;
	std::cout << " Дата " << date1() << " == " << (date1 -= value) << std::endl;
	std::cout << std::endl;

	// сравним объекты на равенство
	std::cout
		<< " Сравним объекты на равенство >>> \n"
		<< " Дата " << date1() << " == " << date1
		<< (date1 == date2 ? "" : " не")
		<< " равна Дате " << date2() << " == " << date2
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на равенство
	std::cout
		<< " Сравним объекты на равенство >>> \n"
		<< " Дата " << date3() << " == " << date3
		<< (date3 == date2 ? "" : " не")
		<< " равна Дате " << date2() << " == " << date2
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на неравенство
	std::cout
		<< " Сравним объекты на неравенство >>> \n"
		<< " Дата " << date1() << " == " << date1
		<< (date1 != date2 ? " не" : "")
		<< " равна Дате " << date2() << " == " << date2
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на неравенство
	std::cout
		<< " Сравним объекты на неравенство >>> \n"
		<< " Дата " << date3() << " == " << date3
		<< (date3 != date2 ? " не" : "")
		<< " равна Дате " << date2() << " == " << date2
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на больше
	std::cout
		<< " Сравним объекты на больше >>> \n"
		<< " Дата " << date1() << " == " << date1
		<< (date1 > date2 ? "" : " не")
		<< " больше Даты " << date2() << " == " << date2
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на больше
	std::cout
		<< " Сравним объекты на больше >>> \n"
		<< " Дата " << date3() << " == " << date3
		<< (date3 > date2 ? "" : " не")
		<< " больше Даты " << date2() << " == " << date2
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на меньше
	std::cout
		<< " Сравним объекты на меньше >>> \n"
		<< " Дата " << date2() << " == " << date2
		<< (date2 < date1 ? "" : " не")
		<< " меньше Даты " << date1() << " == " << date1
		<< std::endl;
	std::cout << std::endl;

	// сравним объекты на меньше
	std::cout
		<< " Сравним объекты на меньше >>> \n"
		<< " Дата " << date2() << " == " << date2
		<< (date2 < date3 ? "" : " не")
		<< " меньше Даты " << date3() << " == " << date3
		<< std::endl;
	std::cout << std::endl;


	// присвоение значения объекту ручным вводом из консоли
//	std::cout << " Введите через пробел параметры Даты " << date1() << " : день месяц год > ";
//	std::cin >> date1;
//	std::cout << " Дата " << date1() << " == " << date1 << std::endl;
//	std::cout << std::endl;


	// создание объекта конструктором с параметрами
	std::cout << " Создадим объект Дата-test: ";
	Test test(29, 02, 2000);
	std::cout << "Дата-test" << " == " << test << std::endl;
	std::cout << std::endl;

	// изменение значения объекта перегруженным оператором ++C
	std::cout << " Изменим значение объекта Дата-test == " << test << " оператором ++С >>> " << std::endl;
	std::cout << " Дата-test == " << ++test << std::endl;
	std::cout << std::endl;

	return 0;
}



