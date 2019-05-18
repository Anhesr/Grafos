#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

namespace ed
{

	template <class G_Nodo, class G_Lado>
	class Grafo
	{
	private:

		G_Lado **_lados;

		G_Nodo *_nodos;

	public:

		// constructores
		Grafo(){
			_lados=NULL;
			_nodos=NULL;
		}

		Grafo(const int &n){
			_nodos=malloc(n*sizeof(int));
		}
		Grafo(const Grafo &g){
			_lados=g._lados;
			_nodos=g._nodos;
		}

		// destructor
		~Grafo(){
			_lados=NULL;
			_nodos=NULL;
		}

		// funciones
		
		void borrarGrafo() {	// cabecera indicada para que compile
			free(_lados);
			free(_nodos);
		}

		Grafo &operator=(const Grafo &g){
			this->_lados=g._lados;
			this->_nodos=g._nodos;
			return *this;
		}

		bool cargarGrafo(){
			std::string nfn;
			std::cout<<"Introduzca el nombre del fichero de nodos"<<std::endl;
			cin>>nfn;
			vector<string> f;
			char cadena[200];

			ifstream fe(nfn.c_str());

			while((fe.getline(cadena,200))!= NULL){
				f.push_back(cadena);
			}
			fe.close();

			Grafo gaux(f.size());
			*this=gaux;


			char * nfr;
			std::cout<<"Introduzca el nombre del fichero de relaciones"<<std::endl;
			cin>>nfr;
			vector<string> fr;
			char * cadena2;
			FILE * fer;
			fer= fopen(nfr,"r");

			while((getdelim(&cadena2,200," ", fer))!= -1){
				fr.push_back(cadena2);
			}
			fclose(fer);

			return true;
		}

	};
}

#endif
