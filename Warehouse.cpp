#include "Warehouse.h"
#include "Widget.h"
#include <iostream>
#include <string>
#include <fstream>
#include "ArrayBag.h"
using namespace std;

WareHouse::WareHouse(){}

WareHouse::~WareHouse(){}

void WareHouse::processDeliveries()
{
	ifstream file;
	file.open("deliveries.txt");

	if (!file.is_open())
	{
		cout << "El documento ya esta abierto.\n";
		cout << "Cierralo y vuelvelo a intentar.\n";
	}

	while (!file.eof())
	{
		int n;
		double c;
		string v;
		file >> v;
		file >> n;
		file >> c;
		Widget d(v, n, c);
		this->onHand.push(d);
	}

	file.close();

	if (!getCurrentOrder().isEmpty() || !this->toBeFilled.isEmpty())
		this->fillOrders();
}

void WareHouse::processOrders()
{
	ifstream file;
	file.open("orders.txt");

	if (!file.is_open())
	{
		cout << "El documento ya esta abierto.\n";
		cout << "Cierralo y vuelvelo a intentar.\n";
	}

	while (!file.eof())
	{
		int n;
		string v;
		file >> v;
		file >> n;
		Widget o(v, n);
		this->toBeFilled.push(o);
	}
	file.close();

	if (!this->onHand.isEmpty())
		this->fillOrders();
	cout << endl;
}

void WareHouse::displayCurrentOrder()
{
	if (!this->widget.isEmpty())
	{
		
		cout << endl;
		cout << "Orden actual: ";
		cout << this->widget.obtenerNombre() << " "
			<< this->widget.obtenerCantidad();
		cout << endl << endl;
	}
	else
		cout << "\nTodas las ordenes han sido completadas\n\n";
}

void WareHouse::manageWareHouse()
{
	int select;
	do
	{
		cout << "1. Manejar almacen\n";
		cout << "2. Mostrar orden actual\n";
		cout << "3. Salida.\n";
		cout << "Seleccione la opcion: ";
		cin >> select;
		switch (select)
		{
		case 1:	cout << endl;
				this->Inventory();
				cout << endl;
				break;
		case 2: displayCurrentOrder();
				break;
		case 3: cout << "\nGracias por usar el programa\n\n";
				break;
		default:cout << "\nSeleccion equivocada.\n\n";
				break;
		}
	} while (select != 3);
}

ArrayBag<Widget> WareHouse::getWidgetsUsed()const
{
	return(this->widgetsUsed);
}

void WareHouse::orderComplete()
{
	cout << "\nOrden completada y su costo total: ";
	cout << getCurrentOrder().obtenerNombre() << " " 
		<< getCurrentOrder().obtenerCantidad() << " " 
		<< this->costOrder << endl;
	
	if (!getWidgetsUsed().isEmpty())
	{
		cout << "Widgets usados para completar la orden: ";
		for (int i = 0; i < getWidgetsUsed().getCurrentSize(); i++)
			cout << getWidgetsUsed().getEntry(i).obtenerNombre() << " "
			<< getWidgetsUsed().getEntry(i).obtenerCantidad() << " "
			<< getWidgetsUsed().getEntry(i).obtenerCosto() <<" | ";
	}
	cout << endl;
	this->widgetsUsed.clear();
	this->widget.clear();
	this->toBeFilled.pop();
	this->numOrder = 0;
	this->costOrder = 0.0;
	
}

Widget WareHouse::getCurrentOrder()const
{
	return(this->widget);
}

void WareHouse::Inventory()
{
	this->processDeliveries();
	this->processOrders();


	if (!getCurrentOrder().isEmpty())
	{
		cout << "Orden para " << getCurrentOrder().obtenerNombre() 
			<< " de cantidad " << getCurrentOrder().obtenerCantidad() 
			<< " no pudo ser llenada.\n";

		this->widget = this->toBeFilled.peek();

		cout << "Widgets restantes: ";
		for (int i = 0; i < this->widgetsUsed.getCurrentSize(); i++)
			cout << getWidgetsUsed().getEntry(i).obtenerNombre() << " "
			<< getWidgetsUsed().getEntry(i).obtenerCantidad() << " "
			<< getWidgetsUsed().getEntry(i).obtenerCosto()<<" | ";
		cout << endl;
	}
}

void WareHouse::fillOrders()
{
	while (!this->toBeFilled.isEmpty() && !this->onHand.isEmpty())
	{
		if (getCurrentOrder().isEmpty())
		{
			this->widget = this->toBeFilled.peek();
			this->numOrder = getCurrentOrder().obtenerCantidad();
		}

		while (this->numOrder != 0 && !this->onHand.isEmpty())
		{
			Widget fromStack = this->onHand.peek();
			int numOnHand = fromStack.obtenerCantidad();
			this->onHand.pop();
			
			if (numOnHand > this->numOrder)
			{
				Widget forOrder(fromStack.obtenerNombre(), this->numOrder, fromStack.obtenerCosto());
				this->costOrder += this->numOrder*(fromStack.obtenerCosto()*1.5);
				this->widgetsUsed.add(forOrder);
				fromStack.cambiarCantidad(numOnHand - this->numOrder);
				this->onHand.push(fromStack);
				this->orderComplete();
			}
			else if (numOnHand == this->numOrder)
			{
				this->costOrder += numOnHand*(fromStack.obtenerCosto()*1.5);
				this->widgetsUsed.add(fromStack);
				this->orderComplete();
			}
			else
			{
				this->costOrder += numOnHand*(fromStack.obtenerCosto()*1.5);
				this->widgetsUsed.add(fromStack);
				this->numOrder -= numOnHand;
			}
		}
	} 
}