#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <ostream>
#include "produccion.h"
#include "ventas.h"
#include "warehouse.h"

void menu() {
    SalesReport reporte;
    int cant_bau, option;
    do
    {
        std::cout << "Welcome!" << std::endl;
        std::cout << "1. Aluminum production." << std::endl;
        std::cout << "2. View the warehouse." << std::endl;
        std::cout << "3. Generate sales report." << std::endl;
        std::cout << "4. Purchase bauxite." << std::endl;
        std::cout << "5. Exit." << std::endl;
        std::cout << "Please enter a choice: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "Please enter the amount of bauxite you wish to use (max 100): ";
            std::cin >> cant_bau;
            if (cant_bau > 0 && cant_bau <= 100)
            {
                preparing(cant_bau);
            }
            else
            {
                std::cout << "Invalid number! (max 100 or min 1)" << std::endl;
            }
            break;

        case 2:
        // Muestra la cantidad de aluminio que esta disponible
            std::cout << "amount of aluminum in storage ";
            std::cout << warehouse_alu() << std::endl;
            break;

        case 3:
            reporte.generarReporte();
            break;

        case 4:
        {
            PurchaseOrder pedido;
            std::cout << "Enter client name: ";
            std::cin >> pedido.cliente;
            std::cout << "Enter quantity of bauxite: ";
            std::cin >> pedido.cantidad_bauxita;
            pedido.fecha = "2023-10-01"; // Replace with real date handling
            reporte.agregarPedido(pedido);
            std::cout << "Purchase order added." << std::endl;
            break;
        }

        default:
            std::cout << "Error: opción no válida" << std::endl;
        }

    } while (option != 5);
}

#endif // MENU_H
