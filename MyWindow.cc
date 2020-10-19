/*
 * MyWindow.cc
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#include <cmath>
#include <iostream>

static constexpr double Pi = acos(-1.);

#include "MyWindow.h"

MyWindow::MyWindow(int width, int height)
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

void MyWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
			5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);

	glRotated(_angle, 0., 0., 1.);

	double height = _heightHome;
	double width = _widthHome;
	double length = _lengthHome;

	glBegin(GL_QUADS);

	glNormal3d(  1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
	glVertex3d(  length, -width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  length,  width, -height);
	glVertex3d(  length, -width, -height);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
	glVertex3d( -length,  width,  height);
	glVertex3d( -length, -width,  height);
	glVertex3d( -length, -width, -height);
	glVertex3d( -length,  width, -height);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
	glVertex3d( -length,  width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  length,  width, -height);
	glVertex3d( -length,  width, -height);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_blue);
	glVertex3d(  length, -width,  height);
	glVertex3d( -length, -width,  height);
	glVertex3d( -length, -width, -height);
	glVertex3d(  length, -width, -height);

	glNormal3d(  0.,  0.,  1.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_yellow);
	glVertex3d( -length,  width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  length, -width,  height);
	glVertex3d( -length, -width,  height);

	// Крыша
	glNormal3d(  1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d(  length, -width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  0.,      width,  height + 1.);
	glVertex3d(  0.,     -width,  height + 1.);

	glNormal3d( -1.,  0.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d( -length,  width,  height);
	glVertex3d( -length, -width,  height);
	glVertex3d(  0.,     -width,  height + 1.);
	glVertex3d(  0.,      width,  height + 1.);

	glEnd();

	glBegin(GL_TRIANGLES);

	glNormal3d(  0.,  1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d( -length,  width,  height);
	glVertex3d(  length,  width,  height);
	glVertex3d(  0.,      width,  height + 1.);

	glNormal3d(  0., -1.,  0.);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
	glVertex3d(  length, -width,  height);
	glVertex3d( -length, -width,  height);
	glVertex3d(  0.,     -width,  height + 1.);

	glEnd();
}

void MyWindow::handle_logic()
{
}

void MyWindow::handle_keys(const Uint8 * keys)
{

	if (keys[SDL_SCANCODE_W]) {
		_heightHome += 0.001;
	}

	if (keys[SDL_SCANCODE_S]) {
		_heightHome -= 0.001;
	}

	if (keys[SDL_SCANCODE_Q]) {
		_widthHome += 0.001;
	}

	if (keys[SDL_SCANCODE_A]) {
		_widthHome -= 0.001;
	}

	if (keys[SDL_SCANCODE_E]) {
		_lengthHome += 0.001;
	}

	if (keys[SDL_SCANCODE_D]) {
		_lengthHome -= 0.001;
	}

	if (_lengthHome <= 1.)
		_lengthHome = 1.;

	if (_widthHome <= 1.)
		_widthHome = 1.;

	if (_heightHome <= 1.)
		_heightHome = 1.;

	if (keys[SDL_SCANCODE_RIGHT]) {
		_angle += 0.05;
	}

	if (keys[SDL_SCANCODE_LEFT]) {
		_angle -= 0.05;
	}


	if (_angle >= 360.)
		_angle -= 360.;
}
