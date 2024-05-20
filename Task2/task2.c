/*
Задание 2. Инверсия старших

На вход программе подается беззнаковое 32-битное целое число N. Требуется
изменить значения всех битов старшего байта числа на противоположные и
вывести полученное таким образом число.

Данные на входе:
Беззнаковое 32-битное целое число N
Данные на выходе:
Одно целое число.
Пример №1
Данные на входе:
1
Данные на выходе:
4278190081
Пример №2
Данные на входе:
4278190081
Данные на выходе:
1
 */
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	const uint32_t LENGHT_BYTE = 8;
	const uint32_t LENGHT_UINT32 = 32;
	const uint32_t LENGHT_UINT32_MINUS_BYTE = LENGHT_UINT32 - LENGHT_BYTE;

	int N = 0;

	printf("Enter an unsigned 32-bit integer N: ");
	scanf("%" PRIu32, &N);

	// смешаем вправо на дельту U32 - U8, инвертируем ее и возвращаем обратно
	//  далее логическое или числа с нулями вместо старшего байта для объединения результата
	N = ((~(N >> LENGHT_UINT32_MINUS_BYTE)) << LENGHT_UINT32_MINUS_BYTE) | ((N << LENGHT_BYTE) >> LENGHT_BYTE);
	printf("Inversion of all the bits of highest byte is equal: %" PRIu32, N);

	return 0;
}
