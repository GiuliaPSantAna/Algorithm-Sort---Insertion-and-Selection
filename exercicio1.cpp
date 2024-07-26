#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <chrono>

using namespace std;

class AlgoritmoSort{  //Algoritmos utilizados para ordenar o array
public:

    static void insertionSort(vector<int>& array){  //Implementação do algoritmo Insertion Sort
        int a;
        a = array.size();
        for (int i = 1; i < a; i++) {
            int c;
            c = arr[i];
            int j = i - 1;
            while (j >= 0 && array[j] > c){
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = c;
        }
    }

    static void selectionSort(vector<int>& array){  //Implementação do algoritmo Selection Sort
        int a;
        a = array.size();
        for (int i = 0; i < a - 1; i++){
            int min_idx;
            min_idx = i;
            for (int j = i + 1; j < a; j++)
                if (array[j] < array[min_idx])
                    min_idx = j;
            swap(array[min_idx], array[i]);
        }
    }
};

void printarArray(const vector<int>& array){  //Função usada para printar o vetor
    for (int numero : array)
        cout << numero << " ";
    cout << endl;
}

int main(int numc, char* numv[]){ 

    if (numc < 2) {  //Verifica se o nome do arquivo está correto
        cerr << "Use: " << numv[0] << " nome_arquivo\n";
        return 1;
    }

    ifstream file(numv[1]);  //Abre o arquivo
    if (!file.is_open()){
        cerr << "Não foi possível abrir o arquivo" << numv[1] << endl;
        return 1;
    }

    vector<int> original;  //Faz a leitura do arquivo
    string line;

    while (getline(file, line)){
        istringstream iss(line);
        int numero;

        while (iss >> numero){  //Faz a inserção dos números no vetor
            original.push_back(numero);
        }
    }

file.close();  //Fecha o arquivo

while(1){  //Utilizado para que o usuário escolha qual algoritmo de ordenação deseja 
    int opcao;

        cout << "\n\n Menu:\n\n";
        cout << "\t 1 - Insertion Sort\n";
        cout << "\t 2 - Selection Sort\n";
        cout << "\t 3 - Cancelar\n\n";
        cout << "Opcao escolhida: ";
        cin >> opcao;

        if (opcao == 3){
            cout << "Saindo do programa\n";
            break;
        }

vector<int> vcopia = voriginal;  //Copia para outro vetor
            
        if (opcao == 1){ //Utilizado para ordenar o array usando Insertion Sort

                auto inicio = chrono::steady_clock::now();  //Calcula o tempo utilizado na execução
                AlgoritmoSort::insertionSort(vcopia);
                auto parada = chrono::steady_clock::now();
                auto duracao = chrono::duration_cast<chrono::milliseconds>(parada - inicio);
                cout << "\nInsertion Sort:\n";
                printarArray(vcopia);
                cout << "\nTempo utilizado para execução: " << duracao.count() << " milisegundos\n";
        }
        
        if (opcao == 2){  //Utilizado para ordenar o array usando Selection Sort
            
                auto inicio = chrono::steady_clock::now();  //Calcula o tempo utilizado na execução
                AlgoritmoSort::selectionSort(vcopia);
                auto parada = chrono::steady_clock::now();
                auto duracao = chrono::duration_cast<chrono::milliseconds>(parada - inicio);
                cout << "\nSelection Sort:\n";
                printarArray(vcopia);
                cout << "\nTempo utilizado para execução: " << duracao.count() << " milisegundos\n";
        }

        if (opcao != 1 && opcao != 2){
                cout << "\nOpcao inexistente\n";
            }

        }
        
    }
    return 0;
  }
