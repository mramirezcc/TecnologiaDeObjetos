import java.util.Scanner;

public class main {
    private static char[][] tablero = new char[3][3];
    private static StackArray<String> historial = new StackArray<>(9); // máximo 9 jugadas

    public static void main(String[] args){
        inicializarTablero();
        Scanner sc = new Scanner(System.in);
        char    jugadorActual  = 'X';
        boolean juegoTerminado = false;

        while (!juegoTerminado) {
            mostrarTablero();
            System.out.println("Turno del jugador " + jugadorActual);
            System.out.println("(fila y columna--> 0 2) o 'u' para atras:");

            String entrada = sc.nextLine().trim();

            // Opción para deshacer
            if (entrada.equalsIgnoreCase("u")) {
                boolean deshizo = deshacerMovimiento();
                if (deshizo) {
                    //cambiar jugador porque se deshizo el movimiento
                    jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
                }
                continue;// saltar al siguiente ciclo
            }

            // Registrar movimiento
            boolean registrado = registrarMovimiento(entrada, jugadorActual);
            if (!registrado) continue;// si no se registra pide otra entrada

            // Verificar si gana
            if (verificarGanador(jugadorActual)) {
                mostrarTablero();
                System.out.println("Gana jugador " + jugadorActual + ". Congratulation");
                juegoTerminado = true;
            } else if (tableroLleno()) {
                mostrarTablero();
                System.out.println("Empate");
                juegoTerminado = true;
            } else {
                //cambiar jugador
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            }
        }
    }

    // registra un movimiento dado el input "fila col"
    private static boolean registrarMovimiento(String entrada, char jugadorActual) {
        String[] partes = entrada.split("\\s+");
        if (partes.length < 2) {
            System.out.println("Entrada inválida");
            return false;
        }
        int fila = Integer.parseInt(partes[0]);
        int col = Integer.parseInt(partes[1]);

        if (fila < 0 || fila > 2 || col < 0 || col > 2){// verificar rango
            System.out.println("Fuera de rango (0-1-2).");
            return false;
        }

        if (tablero[fila][col] != ' ') {
            System.out.println("Posicion ocupada.");
            return false;
        }

        tablero[fila][col] = jugadorActual;
        historial.push(fila + "," + col);
        return true;
    }

    // deshace movimiento
    private static boolean deshacerMovimiento() {
        try {
            String movimiento = historial.pop(); // saca el último movimiento
            String[] partes = movimiento.split(",");
            int fila = Integer.parseInt(partes[0]);
            int col = Integer.parseInt(partes[1]);
            tablero[fila][col] = ' ';
            System.out.println("Se deshizo el movimiento en (" + fila + "," + col + ")");
            return true;
        } catch (Exception e) {
            System.out.println("Sin movimientos para deshacer");
            return false;
        }
    }

    //verifica si el jugador ha jugado
    private static boolean verificarGanador(char jugador) {
        for (int i = 0; i < 3; i++) {
            if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) return true;
            if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) return true;
        }
        if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) return true;
        if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) return true;
        return false;
    }

    private static void inicializarTablero() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tablero[i][j] = ' ';
    }

    private static void mostrarTablero() {
        System.out.println("\n  0   1   2");
        for (int i = 0; i < 3; i++) {
            System.out.print(i + " ");
            for (int j = 0; j < 3; j++) {
                System.out.print(tablero[i][j]);
                if (j < 2) System.out.print(" | ");
            }
            System.out.println();
            if (i < 2) System.out.println(" ---+---+---");
        }
        System.out.println();
    }

    private static boolean tableroLleno() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (tablero[i][j] == ' ') return false;
        return true;
    }
}
