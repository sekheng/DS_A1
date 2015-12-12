#ifndef VEC2D_H
#define VEC2D_H

/******************************************************************************/
/*!
\file       Vec2D.h
\author  Lee Sek Heng
\par        email: 150629Z@mymail.nyp.edu.sg
\brief
Srtuct to define a 2D Vector
*/
/******************************************************************************/

/******************************************************************************/
/*!
        Struct Vec2D:
\brief  Defines a 2D Vector and it's method
*/
/******************************************************************************/
struct Vec2D
{
	double x, y;

	Vec2D(double coordX, double coordY);
};

#endif