#pragma once
#include <string>
#include <iostream>
using namespace std;

class Widget
{
private:
	string nombre;
	int cantidad;
	double costo;

public:
	Widget(string nombre, int cantidad, double costo);
	Widget(string nombre, int cantidad);
	Widget();
	~Widget();

	Widget & operator = (const Widget & e);

	bool operator ==(const Widget & e)const;
	bool operator !=(const Widget & e)const;

	bool isEmpty()const;
	void cambiarNombre(string nombre);
	void cambiarCantidad(int cantidad);
	void cambiarCosto(double costo);
	
	string obtenerNombre()const;
	int obtenerCantidad()const;
	double obtenerCosto()const;

	void pedirInfo();
	void displayWidget();

	void clear();

	friend ostream & operator << (ostream & out, const Widget & e);
	friend istream & operator >> (istream & in, Widget & e);
};

