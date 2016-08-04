#include "Warehouse.h"
#include <iostream>
using namespace std;

int main()
{
	WareHouse w;
	w.manageWareHouse();
}
/*
1. Manejar almacen
2. Mostrar orden actual
3. Salida.
Seleccione la opcion: 1


Orden completada y su costo total: vendor4 65 3300
Widgets usados para completar la orden: vendor4 50 35 | vendor3 15 30 |

Orden completada y su costo total: vendor3 30 1312.5
Widgets usados para completar la orden: vendor3 25 30 | vendor2 5 25 |

Orden completada y su costo total: vendor2 20 750
Widgets usados para completar la orden: vendor2 20 25 |

Orden para vendor1 de cantidad 30 no pudo ser llenada.
Widgets restantes: vendor2 5 25 | vendor1 20 20 |

1. Manejar almacen
2. Mostrar orden actual
3. Salida.
Seleccione la opcion: 2

Orden actual: vendor1 30

1. Manejar almacen
2. Mostrar orden actual
3. Salida.
Seleccione la opcion: 1


Orden completada y su costo total: vendor1 30 1050
Widgets usados para completar la orden: vendor2 5 25 | vendor1 20 20 | vendor4 5
35 |

Orden completada y su costo total: vendor4 65 3262.5
Widgets usados para completar la orden: vendor4 45 35 | vendor3 20 30 |

Orden completada y su costo total: vendor3 30 1275
Widgets usados para completar la orden: vendor3 20 30 | vendor2 10 25 |

Orden completada y su costo total: vendor2 20 750
Widgets usados para completar la orden: vendor2 20 25 |

Orden para vendor1 de cantidad 30 no pudo ser llenada.
Widgets restantes: vendor1 20 20 |

1. Manejar almacen
2. Mostrar orden actual
3. Salida.
Seleccione la opcion: 3

Gracias por usar el programa

Press any key to continue . . .
*/