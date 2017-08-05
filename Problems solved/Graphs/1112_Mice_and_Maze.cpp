#include <iostream>
#include<cctype>
#include<ctype.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<fstream>
#include<map>
#include<set>
#include<queue>
#include<stdio.h>
#include<cstring>
#include<sstream>
#include<locale>
#include<utility>
#include<list>
using namespace std;

#ifdef _DEBUG

   #include <fstream>

   istream * in.txt;
   ostream * out;
#endif

#define Y second
#define X first
#define MP make_pair
#define SZ size()
#define PB push_back
#define VI vector<int>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CUBE(a) ((a)*(a)*(a))
#define SQ(a) ((a)*(a))
#define FOR(i,N) for(int i = 0 ; i < N ; ++i)

typedef unsigned int UI ;
typedef pair<UI,pair< UI,UI > > ppUI;

typedef int V;          // tipo de costes
typedef pair<V,int> P;  // par de (coste,nodo)
typedef set<P> S;       // conjunto de pares

int N;                  // numero de nodos
vector<P> A[10001];     // listas adyacencia (coste,nodo)

// int prec[201]; // predecesores (nodes from s to t)
// another way to obtain a path (above all, if there is
// more than one, consists in.txt using BFS from the target
// and add to the queue those nodes that lead to the
// minimum cost in.txt the preceeding node)

V dijkstra(int s, int t) {
    S m;                          // cola de prioridad
    vector<V> z(N, 1000000000);   // distancias iniciales
    z[s] = 0;                     // distancia a s es 0
    m.insert(MP(0, s));           // insertar (0,s) en m
    while(m.SZ > 0){
        P p = *m.begin();   // p=(coste,nodo) con menor coste
        m.erase(m.begin()); // elimina este par de m
        if (p.Y == t) return p.X; // cuando nodo es t, acaba
        // para cada nodo adjacente al nodo p.Y
        for(int i = 0; i < (int)A[p.Y].SZ; i++){
            // q = (coste hasta nodo adjacente, nodo adjacente)
            P q(p.X + A[p.Y][i].X, A[p.Y][i].Y);
            // si q.X es la menor distancia hasta q.Y
            if (q.X < z[q.Y]) {
                m.erase(MP(z[q.Y], q.Y)); // borrar anterior
                m.insert(q);              // insertar q
                z[q.Y] = q.X;             // actualizar distancia
				// prec[q.Y] = p.Y;       // actualizar predecesores
            }
        }
    }
    return -1;
}

int main()
{
    #ifdef _DEBUG

     in.txt  = new ifstream("entrada.txt");
     out = new ofstream("salida.txt");
     cin.rdbuf(in.txt->rdbuf());
     cout.rdbuf(out->rdbuf());
    #endif

    int cases;
    cin>>cases;
    while(cases--){
        UI cells, exit_cell, end_time,conexions;
        cin>>cells>>exit_cell>>end_time>>conexions;
        exit_cell--;

        N = cells;
        UI c1,c2,cost;
        while(conexions--){
            cin>>c1>>c2>>cost;
            c1--;
            c2--;
            A[c1].PB(MP(cost,c2));
        }
        int mices_solved = 0;
        FOR(i,cells){
            if(dijkstra(i,exit_cell) <= end_time){
                mices_solved++;
            }
        }

        cout<<mices_solved<<endl;
        if(cases)
            cout<<endl;
        FOR(i,cells){
            A[i] = vector<P>();
        }
    //TODO ERASE DIJKSTRA CONTENT
    }

}
