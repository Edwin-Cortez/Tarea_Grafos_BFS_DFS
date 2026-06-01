package ejercicio_grafos;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class MainJava {

    public static class GrafoJava {
        private final Map<Integer, List<Integer>> listaAdyacencia;

        public GrafoJava() {
            this.listaAdyacencia = new HashMap<>();
        }

        public void agregarNodo(int nodo) {
            listaAdyacencia.putIfAbsent(nodo, new ArrayList<>());
        }

        public void agregarArista(int u, int v) {
            agregarNodo(u);
            agregarNodo(v);
            listaAdyacencia.get(u).add(v);
            listaAdyacencia.get(v).add(u);
            // Ordenar para cumplir la regla del vecino menor alfabético/numérico
            Collections.sort(listaAdyacencia.get(u));
            Collections.sort(listaAdyacencia.get(v));
        }

        public void imprimirListaAdyacencia() {
            for (Map.Entry<Integer, List<Integer>> entrada : listaAdyacencia.entrySet()) {
                System.out.println("Nodo " + entrada.getKey() + ": " + entrada.getValue());
            }
        }

        public void ejecutarBFS(int inicio) {
            System.out.print("BFS: ");
            Map<Integer, Boolean> visitados = new HashMap<>();
            Queue<Integer> cola = new LinkedList<>();

            visitados.put(inicio, true);
            cola.add(inicio);

            while (!cola.isEmpty()) {
                int actual = cola.poll();
                System.out.print(actual + " ");

                for (int vecino : listaAdyacencia.getOrDefault(actual, new ArrayList<>())) {
                    if (!visitados.getOrDefault(vecino, false)) {
                        visitados.put(vecino, true);
                        cola.add(vecino);
                    }
                }
            }
            System.out.println();
        }

        public void ejecutarDFS(int inicio) {
            System.out.print("DFS: ");
            Map<Integer, Boolean> visitados = new HashMap<>();
            dfsRecursivo(inicio, visitados);
            System.out.println();
        }

        private void dfsRecursivo(int nodo, Map<Integer, Boolean> visitados) {
            visitados.put(nodo, true);
            System.out.print(nodo + " ");

            for (int vecino : listaAdyacencia.getOrDefault(nodo, new ArrayList<>())) {
                if (!visitados.getOrDefault(vecino, false)) {
                    dfsRecursivo(vecino, visitados);
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=== EJECUCION GRAFO: EJERCICIO 16 (JAVA COLLECTIONS) ===\n");

        GrafoJava g = new GrafoJava();
        g.agregarArista(1, 2);
        g.agregarArista(1, 3);
        g.agregarArista(2, 4);
        g.agregarArista(2, 5);
        g.agregarArista(3, 6);
        g.agregarArista(5, 7);
        g.agregarArista(6, 7);
        g.agregarArista(7, 8);
        g.agregarArista(8, 9);

        System.out.println("--- LISTA DE ADYACENCIA ---");
        g.imprimirListaAdyacencia();
        System.out.println();

        g.ejecutarBFS(1);
        g.ejecutarDFS(1);
    }
}