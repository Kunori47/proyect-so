#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Sale {
    int cantidad_lingotes;
    std::string fecha;
    double precio_total;
};

struct PurchaseOrder {
    int cantidad_bauxita;
    std::string cliente;
    std::string fecha;
};

class SalesReport {
private:
    std::vector<Sale> ventas;
    std::vector<PurchaseOrder> pedidos;
public:
    void agregarVenta(int cantidad, const std::string& fecha, double precio) {
        ventas.emplace_back(Sale{cantidad, fecha, precio});
    }

    void agregarPedido(const PurchaseOrder& pedido) {
        pedidos.emplace_back(pedido);
    }

    void generarReporte() {
        std::ofstream archivo("facturacion.txt");

        std::cout << "Reporte de Ventas:\n";
        archivo << "Reporte de Ventas:\n";
        for(const auto& venta : ventas){
            std::cout << "Cantidad: " << venta.cantidad_lingotes 
                      << ", Fecha: " << venta.fecha 
                      << ", Precio Total: $" << venta.precio_total << std::endl;
            archivo   << "Cantidad: " << venta.cantidad_lingotes 
                      << ", Fecha: " << venta.fecha 
                      << ", Precio Total: $" << venta.precio_total << std::endl;
        }
        std::cout << "\nPedidos de Compra:\n";
        archivo << "\nPedidos de Compra:\n";
        for(const auto& pedido : pedidos){
            std::cout << "Cliente: " << pedido.cliente 
                      << ", Cantidad: " << pedido.cantidad_bauxita 
                      << ", Fecha: " << pedido.fecha << std::endl;
            archivo   << "Cliente: " << pedido.cliente 
                      << ", Cantidad: " << pedido.cantidad_bauxita 
                      << ", Fecha: " << pedido.fecha << std::endl;
        }
        // Cerrar el archivo 
        archivo.close(); 
        std::cout << "Datos escritos en el archivo exitosamente." << std::endl;
    }
};