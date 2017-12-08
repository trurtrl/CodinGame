#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

struct Node
{
    int index;
    bool gate = false;
    bool visited = false;
    Node* pred;
    vector<Node*> adj;
    Node(int index)
    : index{index}
    {};
};

class Graph
{
public:
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    vector<Node*> nodes;
    
    Graph()
    {
        cin >> N >> L >> E; cin.ignore();
        for (int i=0; i<N; ++i)
        {
            nodes.push_back(new Node(i));
        };
    }   
    ~Graph()
    {
        for (int n=0; n<N; ++n)
        {
            delete nodes[n];
        };
    }
    
    void setEdges()
    {
        for (int i = 0; i < L; i++) 
        {
            int N1; // N1 and N2 defines a link between these nodes
            int N2;
            cin >> N1 >> N2; cin.ignore();
            nodes[N1]->adj.push_back(nodes[N2]);
            nodes[N2]->adj.push_back(nodes[N1]);
        };
    }
    
    void setGates()
    {
        for (int i = 0; i < E; i++) 
        {
            int EI; // the index of a gateway node
            cin >> EI; cin.ignore();
            nodes[EI]->gate = true;
        };        
    }
    
    void nextStep()
    {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        
        severLink(findGate(SI));
       
    }

private:
    Node* findGate(int agent)
    {
        for (Node* pN: nodes) 
        {
            pN->visited = false;
            pN->pred = nullptr;
        };
        list<Node*> line;        
        line.push_back(nodes[agent]);
        while(!line.empty())
        {
            Node* pNode = line.front();
            pNode->visited = true;

            for(Node* pAdj: pNode->adj)
            {        
                if (pAdj->gate)
                {
                    if (pNode->index == agent)
                    {
                        pAdj->pred = pNode;
                        return pAdj;
                    }
                    else 
                    {
                        return pNode;
                    };
                } 
                else if (!pAdj->visited)
                {

                    pAdj->pred = pNode;
                    line.push_back(pAdj);
                };
            };
            line.pop_front();
        };
    }


    void severLink(Node* pNode)
    {
        int first = pNode->index;

        int second = pNode->pred->index;
        cout << first << " " << second << endl;
    };
};


int main()
{
    Graph net = Graph();
    net.setEdges();
    net.setGates();
    
    while(1)
    {
        net.nextStep();
    };

}
