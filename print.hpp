#pragma once

#include <iostream>
#include <vector>
#include <list>

/** 
 *	\brief Спецификация шаблонной функции печати IP-адреса, представленного в целочисленном формате
 *	\param ip T
 *	\return void
 *	\details Если тип параметра шаблона один из (char, short, int, long, long long), то шаблон 
 *	инстанцируется с соответствующим типом аргумента, иначе ошибка компиляции и работает механизм SFINAE.
 *	Функция последовательно берет младшие байты целого числа, кладет в список и затем выводит в обратном
 *	порядке.
 */
template <typename T>
	typename std::enable_if<
	std::is_same<typename std::remove_reference<T>::type,char>::value ||
	std::is_same<typename std::remove_reference<T>::type,short>::value ||
	std::is_same<typename std::remove_reference<T>::type,int>::value ||
	std::is_same<typename std::remove_reference<T>::type,long>::value ||
	std::is_same<typename std::remove_reference<T>::type,long long>::value
	,void>::type
print_ip(T ip) {

	unsigned long long us=ip; 

	std::list<int> l; 
	
	for (long unsigned int i = 0; i < sizeof(ip); i++) {
		int my_ip=us&255;
		l.push_front(my_ip);
		us>>=8;
	}
	for (auto it = l.cbegin(); it != l.cend(); ++it) {
		if (it == l.cbegin()) {
			std::cout<<(*it);
		} else {
			std::cout<<"."<<(*it);
		}
	}

	std::cout<<std::endl;
}

/** \brief Спецификация шаблонной функции печать IP-адреса, представленного в виде строки
 * 	\param ip T
 *	\return void
 */
template <typename T>
	typename std::enable_if<
	std::is_same<typename std::remove_reference<T>::type,std::string>::value
	,void>::type
print_ip(T ip) {
	std::cout<<ip.c_str()<<std::endl;
}

/** \brief Спецификация шаблонной функции печать IP-адреса, представленного в виде контейнера (vector, list)
 *	\param ip T
 *	\return void
 */
template <typename T>
	typename std::enable_if<
	std::is_same<typename std::remove_reference<T>::type,std::vector<int>>::value ||
	std::is_same<typename std::remove_reference<T>::type,std::list<int>>::value
	,void>::type
print_ip(T ip) {
	for (auto it = ip.cbegin(); it != ip.cend(); it++) {
		if (it!=ip.cbegin())
			std::cout<<".";
		std::cout<<(*it);
	}
	std::cout<<std::endl;
}

