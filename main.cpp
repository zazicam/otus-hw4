#include "print.hpp"

/**
 *	\brief Тестирование функции вывода в main
 *	\param argc int
 *	\param argv char**
 *	\return int
 *	\details 
 *	Вызов шаблонной функции печати ip адреса представленного
 *	в различных форматах (char, short, int, long)
 */
int main (int argc, char **argv) {
	(void)argc;
	(void)argv;
	print_ip(char(-1));
	print_ip(short(0));
	print_ip(int(2130706433));
	print_ip((long long)(8875824491850138409));

	return 0;
}
