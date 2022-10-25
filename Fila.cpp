#include <iostream>
#include <cstdlib>


class listas{
	public:
		
	 int *vetor; //variaveis
	 
	 int *alocar_vetor(int tam) //função
	 {
	 	return vetor = (int*) malloc(tam * sizeof(int));
	 }
	 
	 void att_val(int *vetor, int tam)
	 {
	 	for(int i = 0; i < tam; ++i)
	 	{
	 		vetor[i] = 0;
		}
	 }
	 
	 void mostrar_lista(int *vetor, int tam)
	 {
	 	for (int i = 0; i < tam; ++i)
	 	{
	 		std::cout << vetor[i] << " ";
		 }
		 
		 std::cout << "\n";
	 }
};

class pilha{
	public:
		
		void fila_adicionar(int *vetor, int frente, int *tras, int valor)
		{
			if (*tras == frente - 1)
			{
				std::cout << "Fila esta cheia!\n";
				return;
			}else{
			*tras += 1
			vetor[*tras] = valor;
			return;
			}
		}
		
		void fila_remover(int *vetor, int frente, int *tras)
		{
			if (*tras < 0)
			{
				std::cout << "Fila esta vazia!\n";
				return;
			}else{
			vetor[*tras]	
				
			}
				
		
		}
		
		void invert(int *vetor, int inicio, int fim)
		{
			int aux;
			
			if(inicio < fim)
			{
			
			aux = vetor[inicio];
			vetor[inicio] = vetor[fim];
			vetor[fim] = aux;
			
			invert(vetor, inicio + 1, fim -1);
			}
			
		}
		
};

int main()
{
	listas estruturas; //classe lista
	
	pilha funct;
	
	int frente = 5;
	int tras = 0;
	
	int *fila; // vetor
	
	fila = estruturas.alocar_vetor(5);
	
	estruturas.att_val(fila, 5);
		
	funct.fila_adicionar(fila, frente, &tras, 5);
	funct.fila_adicionar(fila, &topo, 2, 5);
	funct.fila_adicionar(fila, &topo, 3, 5);
	funct.fila_adicionar(fila, &topo, 4, 5);
	funct.fila_adicionar(fila, &topo, 5, 5);
		
	estruturas.mostrar_lista(fila, 5);
	
	funct.fila_remover(fila, &topo, 5);
	funct.fila_remover(fila, &topo, 5);
	funct.fila_remover(fila, &topo, 5);
	estruturas.mostrar_lista(fila, 5);
	
	
	

	return 0;	
}
