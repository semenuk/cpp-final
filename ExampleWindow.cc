/*
 * ExampleWindow.cc
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#include <cmath>

static constexpr double Pi = acos(-1.);

#include "ExampleWindow.h"

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height)
{
	_angle = 0.;
	_eye_level = 0.;
}

static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };
static const float s_material_yellow[4]  { 1.f, 1.f, 0.f, 1.f };

void ExampleWindow::setup()
{
	// Включает тест глубины
	glEnable(GL_DEPTH_TEST);
	// Разрешаем освещение и включаем нулевую лампу
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	// Задает значения очистки цветом буфера цвета
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	// Устанавливает перспективу
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void ExampleWindow::render()
{
	// Очистка экрана
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Cчитывает текущую матрицу
	glLoadIdentity();
	// Устанавливает точку наблюдения, камеру
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);

	// Поворот сцены, регулируется параметром _angle
	glRotated(_angle, 0., 0., 1.);


	// Начинает рисовать прямоугольники
	glBegin(GL_QUADS);

	// Задается нормаль
	glNormal3d(  1.,  0.,  0.);
	// Устанавливает свойства материала
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_red);
	// Задает координаты первой точки прямоугольника
	glVertex3d(  1., -1.,  1.);
	// Задает координаты второй точки прямоугольника
	glVertex3d(  1.,  1.,  1.);
	// Задает координаты третьей точки прямоугольника
	glVertex3d(  1.,  1., -1.);
	// Задает координаты четвертой точки прямоугольника
	glVertex3d(  1., -1., -1.);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_magenta);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
	glVertex3d( -1.,  1.,  1.);
	glVertex3d(  1.,  1.,  1.);
	glVertex3d(  1., -1.,  1.);
	glVertex3d( -1., -1.,  1.);

	glNormal3d(  0.,  0., -1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
	glVertex3d(  1.,  1., -1.);
	glVertex3d( -1.,  1., -1.);
	glVertex3d( -1., -1., -1.);
	glVertex3d(  1., -1., -1.);

	// Заканчивает рисовать прямоугольники
	glEnd();
}

void ExampleWindow::handle_logic()
{
	// Вращает изображение по горизонтали
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

	// Вращает изображение по вертикали
	_eye_level = sin(_angle / 180. * Pi);
}
