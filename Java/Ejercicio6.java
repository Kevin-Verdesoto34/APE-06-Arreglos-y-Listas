import java.util.ArrayList;
import java.util.Scanner;

public class Ejercicio6 {
    
    // Clase interna para representar un Producto
    static class Producto {
        String nombre;
        int cantidad;
        double precio;
        
        Producto(String nombre, int cantidad, double precio) {
            this.nombre = nombre;
            this.cantidad = cantidad;
            this.precio = precio;
        }
        
        double calcularTotal() {
            return cantidad * precio;
        }
        
        public String toString() {
            return nombre + " | Cantidad: " + cantidad + " | Precio: $" + precio + " | Total: $" + String.format("%.2f", calcularTotal());
        }
    }
    
    static ArrayList<Producto> inventario = new ArrayList<>();
    static Scanner scanner = new Scanner(System.in);
    
    public static void main(String[] args) {
        int opcion;
        
        // Agregar algunos productos de ejemplo
        inventario.add(new Producto("Laptop", 5, 899.99));
        inventario.add(new Producto("Mouse", 20, 29.99));
        inventario.add(new Producto("Teclado", 15, 79.99));
        inventario.add(new Producto("Monitor", 8, 299.99));
        
        do {
            mostrarMenu();
            System.out.print("Selecciona una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine();
            
            switch (opcion) {
                case 1:
                    agregarProducto();
                    break;
                case 2:
                    verInventario();
                    break;
                case 3:
                    actualizarCantidad();
                    break;
                case 4:
                    actualizarPrecio();
                    break;
                case 5:
                    buscarProducto();
                    break;
                case 6:
                    eliminarProducto();
                    break;
                case 7:
                    mostrarResumen();
                    break;
                case 8:
                    System.out.println("\n¡Hasta luego!");
                    break;
                default:
                    System.out.println("\n❌ Opción inválida.\n");
            }
        } while (opcion != 8);
        
        scanner.close();
    }
    
    static void mostrarMenu() {
        System.out.println("\n========== SISTEMA DE INVENTARIO ==========");
        System.out.println("1. Agregar producto");
        System.out.println("2. Ver inventario");
        System.out.println("3. Actualizar cantidad");
        System.out.println("4. Actualizar precio");
        System.out.println("5. Buscar producto");
        System.out.println("6. Eliminar producto");
        System.out.println("7. Ver resumen del inventario");
        System.out.println("8. SALIR");
        System.out.println("==========================================");
    }
    
    // Agregar un nuevo producto
    static void agregarProducto() {
        System.out.print("\nIngresa el nombre del producto: ");
        String nombre = scanner.nextLine();
        
        System.out.print("Ingresa la cantidad: ");
        int cantidad = scanner.nextInt();
        
        System.out.print("Ingresa el precio unitario: $");
        double precio = scanner.nextDouble();
        scanner.nextLine();
        
        if (cantidad > 0 && precio > 0) {
            inventario.add(new Producto(nombre, cantidad, precio));
            System.out.println("✓ Producto '" + nombre + "' agregado al inventario.");
        } else {
            System.out.println("❌ La cantidad y el precio deben ser mayores a 0.");
        }
    }
    
    // Ver todo el inventario
    static void verInventario() {
        if (inventario.isEmpty()) {
            System.out.println("\n⚠️  El inventario está vacío.");
            return;
        }
        
        System.out.println("\n========== INVENTARIO ==========");
        for (int i = 0; i < inventario.size(); i++) {
            System.out.println((i + 1) + ". " + inventario.get(i));
        }
        System.out.println("Total de productos diferentes: " + inventario.size());
    }
    
    // Actualizar cantidad de un producto
    static void actualizarCantidad() {
        if (inventario.isEmpty()) {
            System.out.println("\n⚠️  El inventario está vacío.");
            return;
        }
        
        verInventario();
        System.out.print("\nIngresa el número del producto: ");
        int indice = scanner.nextInt();
        scanner.nextLine();
        
        if (indice > 0 && indice <= inventario.size()) {
            Producto prod = inventario.get(indice - 1);
            System.out.print("Ingresa la nueva cantidad: ");
            int nuevaCantidad = scanner.nextInt();
            scanner.nextLine();
            
            if (nuevaCantidad >= 0) {
                int cantidadAnterior = prod.cantidad;
                prod.cantidad = nuevaCantidad;
                System.out.println("✓ Cantidad actualizada: " + cantidadAnterior + " → " + nuevaCantidad);
            } else {
                System.out.println("❌ La cantidad no puede ser negativa.");
            }
        } else {
            System.out.println("❌ Número de producto inválido.");
        }
    }
    
    // Actualizar precio de un producto
    static void actualizarPrecio() {
        if (inventario.isEmpty()) {
            System.out.println("\n⚠️  El inventario está vacío.");
            return;
        }
        
        verInventario();
        System.out.print("\nIngresa el número del producto: ");
        int indice = scanner.nextInt();
        
        if (indice > 0 && indice <= inventario.size()) {
            Producto prod = inventario.get(indice - 1);
            System.out.print("Ingresa el nuevo precio: $");
            double nuevoPrecio = scanner.nextDouble();
            scanner.nextLine();
            
            if (nuevoPrecio > 0) {
                double precioAnterior = prod.precio;
                prod.precio = nuevoPrecio;
                System.out.printf("✓ Precio actualizado: $%.2f → $%.2f\n", precioAnterior, nuevoPrecio);
            } else {
                System.out.println("❌ El precio debe ser mayor a 0.");
            }
        } else {
            System.out.println("❌ Número de producto inválido.");
        }
    }
    
    // Buscar un producto por nombre
    static void buscarProducto() {
        if (inventario.isEmpty()) {
            System.out.println("\n⚠️  El inventario está vacío.");
            return;
        }
        
        System.out.print("\nIngresa el nombre a buscar: ");
        String nombre = scanner.nextLine();
        
        System.out.println("\n========== RESULTADOS DE BÚSQUEDA ==========");
        boolean encontrado = false;
        for (Producto prod : inventario) {
            if (prod.nombre.toLowerCase().contains(nombre.toLowerCase())) {
                System.out.println("✓ " + prod);
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            System.out.println("❌ No se encontraron productos con ese nombre.");
        }
    }
    
    // Eliminar un producto
    static void eliminarProducto() {
        if (inventario.isEmpty()) {
            System.out.println("\n⚠️  El inventario está vacío.");
            return;
        }
        
        verInventario();
        System.out.print("\nIngresa el número del producto a eliminar: ");
        int indice = scanner.nextInt();
        scanner.nextLine();
        
        if (indice > 0 && indice <= inventario.size()) {
            Producto productoEliminado = inventario.remove(indice - 1);
            System.out.println("✓ Producto '" + productoEliminado.nombre + "' eliminado del inventario.");
        } else {
            System.out.println("❌ Número de producto inválido.");
        }
    }
    
    // Ver resumen del inventario
    static void mostrarResumen() {
        if (inventario.isEmpty()) {
            System.out.println("\n⚠️  El inventario está vacío.");
            return;
        }
        
        int totalItems = 0;
        double valorTotal = 0;
        double precioPromedio = 0;
        double precioMayor = inventario.get(0).precio;
        double precioMenor = inventario.get(0).precio;
        String productoMasCaro = inventario.get(0).nombre;
        String productoMasBarato = inventario.get(0).nombre;
        
        for (Producto prod : inventario) {
            totalItems += prod.cantidad;
            valorTotal += prod.calcularTotal();
            precioPromedio += prod.precio;
            
            if (prod.precio > precioMayor) {
                precioMayor = prod.precio;
                productoMasCaro = prod.nombre;
            }
            if (prod.precio < precioMenor) {
                precioMenor = prod.precio;
                productoMasBarato = prod.nombre;
            }
        }
        
        precioPromedio = precioPromedio / inventario.size();
        
        System.out.println("\n========== RESUMEN DEL INVENTARIO ==========");
        System.out.println("Cantidad total de artículos: " + totalItems);
        System.out.println("Número de productos diferentes: " + inventario.size());
        System.out.printf("Valor total del inventario: $%.2f\n", valorTotal);
        System.out.printf("Precio promedio: $%.2f\n", precioPromedio);
        System.out.printf("Producto más caro: %s ($%.2f)\n", productoMasCaro, precioMayor);
        System.out.printf("Producto más barato: %s ($%.2f)\n", productoMasBarato, precioMenor);
    }
}
