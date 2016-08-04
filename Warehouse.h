#pragma once
#include "LinkedStack.h"
#include "Node.h"
#include "StackInterface.h"
#include "Widget.h"
#include "ArrayBag.h"


class WareHouse
{
private:
	LinkedStack<Widget> toBeFilled;
	LinkedStack<Widget> onHand;
	ArrayBag<Widget> widgetsUsed;
	int numOrder;
	Widget widget;
	double costOrder;
	int numDelivery;

public:
	WareHouse();
	~WareHouse();
	void displayCurrentOrder();
	void processDeliveries();
	void processOrders();
	void fillOrders();
	void manageWareHouse();
	ArrayBag<Widget> getWidgetsUsed()const;
	Widget getCurrentOrder()const;
	void orderComplete();
	void Inventory();
};