/**
 * Учебная прога. Ожидает ввода трёх строк,
 * кладёт их в массив строк и выводит этот массив.
 **/

#include <stdio.h>
#include <malloc.h>
#define LINESLIMIT 3  // лимит на количество вводимых строк
#define BYTESCOUNT sizeof(getchar())  // узнаём, сколько байт на символ

int gline(int *line);  // набор строки line, возвращает её длину
void copyline(int *from, int *to, int charscount);  // копирование массива строки
char* delimiter(char c, int count);  // строка разделителя: (символ, количество)

int gline(int *line) {
	int linelength = 0;
	while((line[linelength] = getchar()) != EOF && line[linelength] != '\n') {
		linelength++;
	}
	return linelength;
}
void copyline(int *from, int *to, int charscount) {
	for(int i = 0; i < charscount; i++) {
		to[i] = from[i];
	}
}
char* delimiter(char c, int count) {
	char* d = (char*)malloc(count * BYTESCOUNT);
	for(int i = 0; i < count; i++) {
		d[i] = c;
	}
	return d;
}
int main(void) {
	int i, y;                    // счётчики
	int *line;                   // указатель на массив набираемой строки
	int *lines[LINESLIMIT];      // указатель на массив указателей на массивы строк
	int linelength[LINESLIMIT];  // указатель на массив длин строк
	for(i = 0; i < LINESLIMIT; i++) {
		linelength[i] = gline(line);  // читаем строку
		lines[i] = (int*)malloc(linelength[i] * BYTESCOUNT);  // выделаяем память
		copyline(line, lines[i], linelength[i]);  // копируем строку в массив строк
	}
	printf("%s\n", delimiter('-', 80));  // создаём и выводим разделитель
	for(i = 0; i < LINESLIMIT; i++) {  //  выводим созданный массив строк
		for(y = 0; y < linelength[i]; y++) {
			printf("%c", lines[i][y]);
		}
		printf("\n");
	}
	return 0;
}
