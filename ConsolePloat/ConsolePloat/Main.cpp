#include <iostream>
#include <conio.h>
#include <cmath>

#define WIDTH 80 //Ширина окна в пикселях
#define HEIGHT 25 // Высота окна в пикселях


// Функция
double function(double x) {
	double y = sin(x);
	return y;
}

int main() {
	double start = -10, end = 5; // Координаты начала и конца отрезка графика
	double yMin = -5, yMax = 2; //
	double step = (end - start) / WIDTH; // Шаг аргумента
	double h = yMax - yMin; // Высота графика

	int curXpos = HEIGHT*(yMax / h); //Координати Х оси со смещением в окне
	int curYpos = WIDTH*(start / (end - start) + 1); //Координати У оси со смещением в окне
	char matrix[HEIGHT][WIDTH];  //Инициализация матрицы

	//Заполнения матрицы
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == curXpos) {
				matrix[curXpos][j] = '-'; // Х ось
			}

			else if (j == curYpos) {
				matrix[i][curYpos] = '|'; // У ось
			}
			else {
				matrix[i][j] = 0; 
			}
		}
	}

	/*
	*	Считаем значения функций и заносим их в матрицу, при этом 
	*	проведя маштабирования под наше окно 80 на 25
	*/
	for (double curPos = start; curPos < end; curPos += step) { 
		double value = function(curPos); //значение функции
		int y = HEIGHT*(yMax/h) - roundf((value)* HEIGHT / h); // координата У в окне
		int x = roundf((WIDTH * (curPos - start) / (end - start))); // координата Х в окне

		if (y >= 0 && y < 25) {
			matrix[y][x] = '+'; // заносим, в координатах (Х, У) есть точка
		}
	}

	//Выводим матрицу в окно
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			char c = matrix[i][j];
			putchar(c);
		}
	}

	//Ждем нажатия клавиши и выходим
	_getch();
	return 0;
}
