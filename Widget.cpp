#include "Widget.h"

Widget::Widget(string nombre, int cantidad, double costo)
{
	this->nombre = nombre;
	this->cantidad = cantidad;
	this->costo=costo;
}

Widget::Widget(string nombre, int cantidad)
{
	this->nombre = nombre;
	this->costo = 0.0;
	this->cantidad = cantidad;
}

Widget::Widget()
{
	this->cantidad = 0;
	this->costo = 0;
	this->nombre = "";
}

Widget::~Widget(){}

Widget & Widget::operator = (const Widget & e)
{
	this->nombre = e.nombre;
	this->cantidad = e.cantidad;
	this->costo = e.costo;
	return(*this);
}

void Widget::clear()
{
	this->cantidad = 0;
	this->costo = 0.0;
	this->nombre = "";
}

bool Widget::isEmpty()const
{
	return(this->nombre == "" && this->cantidad == 0);
}

bool Widget::operator==(const Widget & e)const
{
	return(this->nombre == e.nombre);
}

bool Widget::operator!=(const Widget & e)const
{
	return(this->nombre != e.nombre);
}

void Widget::cambiarNombre(string nombre)
{
	this->nombre = nombre;
}

void Widget::cambiarCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void Widget::cambiarCosto(double costo)
{
	this->costo = costo;
}

string Widget::obtenerNombre()const
{
	return(this->nombre);
}

int Widget::obtenerCantidad()const
{
	return(this->cantidad);
}

double Widget::obtenerCosto()const
{
	return(this->costo);
}

ostream & operator << (ostream & out, const Widget & e)
{
	out << e.nombre;
	out << e.costo;
	out << e.cantidad;

	return(out);
}

istream & operator >> (istream & in, Widget & e)
{
	cout << "Nombre: ";
	in >> e.nombre;
	cout << "Costo: ";
	in >> e.costo;
	cout << "Cantidad: ";
	in >> e.cantidad;

	return(in);
}

void Widget::pedirInfo()
{
	cout << "Nombre: ";
	cin >> this->nombre;
	cout << "Costo: ";
	cin >> this->costo;
	cout << "Cantidad: ";
	cin >> this->cantidad;
}

void Widget::displayWidget()
{
	cout << this->obtenerNombre()<<" "
		<< this->obtenerCantidad()<<" "
		<< this->obtenerCosto();
	cout << endl;
}