/*
* @Author: Adrián Epifanio
* @Date:   2020-03-07 08:29:24
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-03-07 08:41:26
*/

#include "../include/Framework.h"

Framework::Framework() {
}

Framework::~Framework() {
}

void Framework::divideyVenceras(Problema* p, Solucion* s){
	if (p->isCasoMinimo()){
		p->solver(s);
	}
	else{
		pair<Problema*,Problema*> subProblemas;
		pair<Solucion*,Solucion*> subSoluciones;
		subProblemas = p->descomponer();
		subSoluciones.first = s->getInstance();
		subSoluciones.second = s->getInstance();
		divideyVenceras(subProblemas.first, subSoluciones.first);  //.1
		divideyVenceras(subProblemas.second, subSoluciones.second);  //.2
		s->mezcla(subSoluciones);
	}
};

