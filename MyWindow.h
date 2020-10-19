/*
 * ExampleWindow.h
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

// Объявление класса MyWindow как потомка Window
class MyWindow: public Window
{
public:
	static constexpr int DEFAULT_WIDTH = 800;
	static constexpr int DEFAULT_HEIGHT = 600;

protected:
	double _angle; // Угол поворота модели
	double _eye_level; // Высота уровня глаз
	double _heightHome = 1.; // Высота дома
	double _widthHome = 1.; // Ширина дома
	double _lengthHome = 1.; // Длина дома

public:

	// Конструктор класса ExampleWindow
	MyWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);

	// Деструктор класса ExampleWindow
	virtual ~MyWindow() = default;

	// Метод начальной настройки окна
	virtual void setup() override;

	// Метод отрисовки окна
	virtual void render() override;

	// Метод обработки логики
	virtual void handle_logic() override;

	// Метод обработки нажатий клавиш
	virtual void handle_keys(const Uint8 * keys) override;
};




#endif /* MYWINDOW_H_ */
