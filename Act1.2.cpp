// Saul Sanchez Rangel
// Actividad 1.2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// despliega un vector de enteros
void despVector(vector<int> &vec)
{
    for(vector<int>::iterator i=vec.begin(); i<vec.end(); i++)
        cout << ' ' << *i;
    cout << endl;
}

// intercambia dos posiciones dentro de un vector
void swap(vector<int> &vec, int i, int j)
{
    int aux = vec[i];
    vec[i] = vec[j];
    vec[j] = aux;
}

// sort de intercambio
// Complejidad: O(n^2) ... Mejor caso: O(n^2)
void ordenaIntercambio(vector<int> &vec)
{
    int comparaciones = 0;
    int n = vec.size();
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            comparaciones++;
            if (vec[i] > vec[j]){
                swap(vec, i, j);
            }
        }
    }
    cout << comparaciones << " ";
}

// sort de burbuja
// Complejidad: O(n^2) ... Mejor caso: O(n)
void ordenaBurbuja(vector<int> &vec)
{
    int comparaciones = 0;
    int n = vec.size();
    bool ordenado = false;
    for (int i=0; i<n-1 && !ordenado; i++) {
        ordenado = true;
        for (int j=0; j<n-1-i; j++) {
            comparaciones++;
            if (vec[j] > vec[j+1]) {
                swap(vec, j, j+1);
                ordenado = false;
            }
        }
    }
    cout << comparaciones << " ";
}

void merge(vector<int> &vec, int inicio, int mitad, int fin)
{
    int tam = fin - inicio + 1;
    vector<int> aux(tam); // vector auxiliar con size elementos

    int p1 = inicio, p2 = mitad + 1;
    for (int i=0; i<tam; i++) {
        if(p1 > mitad) {
            aux[i] = vec[p2];
            p2++;
        }
        else if(p2 > fin) {
            aux[i] = vec[p1];
            p1++;
        }
        else if(vec[p1] < vec[p2]) {
            aux[i] = vec[p1];
            p1++;
        }
        else {
            aux[i] = vec[p2];
            p2++;
        }
    }
    for (int i=0; i<tam; i++)
        vec[i+inicio] = aux[i];
}

// mergeSort
// Complejidad: O() ... Mejor caso: O()
void mergeSort(vector<int> &vec, int inicio, int fin, int &comparaciones)
{
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        int comp1 = 0, comp2 = 0;
        mergeSort(vec, inicio, mitad, comp1);
        mergeSort(vec, mitad+1, fin, comp2);
        merge(vec, inicio, mitad, fin);
        comparaciones += comp1 + comp2 + (fin - inicio + 1);
    }
}

void ordenaMerge(vector<int> &vec)
{
    int comparaciones = 0;
    mergeSort(vec, 0, vec.size()-1, comparaciones);
    cout << comparaciones << endl; 
}

void busqBinaria(vector<int> &vec, int valor) {
    int a = 0;
    int b = vec.size() - 1;
    int m;
    int comparaciones = 0;
    while (a <= b) {
        comparaciones++;
        m = (a + b) / 2;
        if (vec[m] == valor) {
            cout << m << " " << comparaciones << endl;
            return;
        }
        else if (vec[m] < valor) {
            a = m + 1;
        }
        else {
            b = m - 1;
        }
    }
    cout << -1 << " " << comparaciones << endl;
}

//busqueda secuencial
void busqSecuencial(vector<int> &vec, int valor) {
    int i = 0;
    int comparaciones = 0;
    while (i < vec.size()) {
        comparaciones++;
        if (vec[i] == valor) {
            
            cout << i << " " << comparaciones << " ";
            return;
        }
        i++;
    }
    cout << -1 << " " << comparaciones << " ";
}

int main() {
    int n, m, valor;
    
    //cantidad de valores en el vector
    cin >> n;
    vector<int> desordenado(n);
    //llenar vector
    for (int i=0; i<n; i++) {
        cin >> desordenado[i];
    }
    vector<int> vec(desordenado);
    //ordenar vector
    ordenaIntercambio(vec);
    vec = desordenado;
    ordenaBurbuja(vec);
    vec = desordenado;
    ordenaMerge(vec);
    //cantidad de valores a buscar
    cin >> m;
    //buscar valores
    for (int i=0; i<m; i++) {
        cin >> valor;
        busqSecuencial(desordenado, valor);
        busqBinaria(vec, valor);
    }
    



}