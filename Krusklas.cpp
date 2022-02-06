/* Kruskals Algo - Min Cost Spanning Tree */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define V 7 
#define E 9 

vector<vector<int>> edge 
{
    {1,1,2,6,2,5,7,5,3},        // Vertice 1 - 0th row
    {6,2,3,5,7,7,4,4,4},        // Vertice 2 - 1st row 
    {5,25,12,20,10,18,14,16,8} // cost of edge between Vertice 1 and Vertice 2 - 2nd row
};

vector<int> Included(V+2,0) ;

vector<int> Set(V+1,-1) ;

vector<vector<int>> Solution(3,vector<int> (V+2)) ;

class setOperations 
{
  private :
  
    int cycle = 0 ;
    
  public :
  
    int findRoot(int u) 
    {
        int x = u ;
        while (Set[x] > 0) 
        {
            x = Set[x] ;
        }
        if (u < Set.size() && u > 0) { return x; }
        return INT_MAX ;
    }
    
    int performUnion(int u, int v) 
    {
        if (findRoot(u) == findRoot(v)) 
        {
            cycle++ ;
            return 0;
        }
        else
        {
            if ( abs(Set[findRoot(u)]) >= abs(Set[findRoot(v)]) ) 
            {
                Set[findRoot(u)] += Set[findRoot(v)] ;
                Set[findRoot(v)] = findRoot(u) ;
            }else
            {
                Set[findRoot(v)] += Set[findRoot(u)] ;
                Set[findRoot(u)] = findRoot(v) ;
            }
            return 1 ;
        }
        
    }
    
    ~setOperations() {
        cout<<"\n\nCycles Found : "<<cycle;
    }
    
};

int main() {
    
    setOperations S ;
    
    int i = 0 , j , k , n = V , e = E , min , u , v , c , cost = 0; 
    while (i < n-1) 
    {
        min = INT_MAX ;
        
        for (j = 0 ; j < e ; j++) {
            if (Included[j]==0 && edge[2][j] < min) 
            {
                min = edge[2][j] ;
                k = j ;
                u = edge[0][j] ;
                v = edge[1][j] ;
                c = edge[2][j] ;
            }
        }
        
        if (S.performUnion(u,v)) 
        {
            Solution[0][i] = u ;
            Solution[1][i] = v ;
            Solution[2][i] = c ;
            i++ ;
        }
        
        Included[k] = 1 ;
        
    }
    
    for (i = 0 ; i < Solution.size() ; i++) 
    {
        Solution[i].resize(V-1) ;
        for (j = 0 ; j < Solution[0].size() ; j++) 
        {
            cout<<Solution[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    for (i = 0 ; i < V-1 ; i++) 
    {
        cost += Solution[2][i] ;
    }
    
    cout<<"\nMinimun Cost of Edges : "<<cost<<endl;
    
    return 0 ;
}
