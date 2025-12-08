#include <bits/stdc++.h>

using namespace std;

int main()
{
    struct Node
    {
        int x, y, z;
    };

    vector<Node> nodes;
    int x, y, z;
    char sepatator;

    while (cin >> x >> sepatator >> y >> sepatator >> z)
    {
        Node node;

        node.x = x;
        node.y = y;
        node.z = z;

        nodes.push_back(node);
    }

    struct Edge
    {
        int source, destination;

        unsigned long long distance;

        bool operator<(const Edge &other) const
        {
            if (distance != other.distance)
            {
                return distance < other.distance;
            }

            if (source != other.source)
            {
                return source < other.source;
            }

            return destination < other.destination;
        }

        bool operator>(const Edge &other) const
        {
            if (distance != other.distance)
            {
                return distance > other.distance;
            }

            if (source != other.source)
            {
                return source > other.source;
            }

            return destination > other.destination;
        }
    };

    priority_queue<Edge, vector<Edge>, greater<Edge>> distances;

    int n = nodes.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Edge edge;

            edge.source = i;
            edge.destination = j;
            edge.distance = 1ull * (nodes[i].x - nodes[j].x) * (nodes[i].x - nodes[j].x) + 1ull * (nodes[i].y - nodes[j].y) * (nodes[i].y - nodes[j].y) + 1ull * (nodes[i].z - nodes[j].z) * (nodes[i].z - nodes[j].z);

            distances.push(edge);
        }
    }

    auto setComp = [](const set<int> &a, const set<int> &b)
    {
        int la = a.size(), lb = b.size();

        if (la != lb)
        {
            return la > lb;
        }

        return *a.begin() < *b.begin();
    };

    set<set<int>, decltype(setComp)> trees(setComp);
    vector<bool> inATree(n);
    
    long long rez;

    while (!distances.empty())
    {
        int source = distances.top().source;
        int destination = distances.top().destination;

        distances.pop();

        if (!inATree[source] && !inATree[destination])
        {
            trees.insert({source, destination});
            inATree[source] = inATree[destination] = true;
            rez = nodes[source].x * nodes[destination].x;
        }
        else if (inATree[source] && !inATree[destination])
        {
            for (auto it = trees.begin(); it != trees.end(); it++)
            {
                if (it->find(source) != it->end())
                {
                    auto mySet = *it;
                    trees.erase(it);
                    mySet.insert(destination);
                    trees.insert(mySet);
                    inATree[destination] = true;
                    rez = nodes[source].x * nodes[destination].x;
                    break;
                }
            }
        }
        else if (!inATree[source] && inATree[destination])
        {
            for (auto it = trees.begin(); it != trees.end(); it++)
            {
                if (it->find(destination) != it->end())
                {
                    auto mySet = *it;
                    trees.erase(it);
                    mySet.insert(source);
                    trees.insert(mySet);
                    inATree[source] = true;
                    rez = nodes[source].x * nodes[destination].x;
                    break;
                }
            }
        }
        else
        {
            for (auto it1 = trees.begin(); it1 != trees.end();)
            {
                if (it1->find(source) != it1->end() && it1->find(destination) != it1->end())
                {
                    break;
                }
                else if (it1->find(source) != it1->end())
                {
                    auto aux = *it1;
                    for (auto it2 = next(it1); it2 != trees.end(); it2++)
                    {
                        if (it2->find(destination) != it2->end())
                        {
                            for (auto it3 : *it2)
                            {
                                aux.insert(it3);
                            }

                            trees.erase(it2);
                            break;
                        }
                    }

                    it1 = trees.erase(it1);

                    trees.insert(aux);
                    rez = nodes[source].x * nodes[destination].x;
                }
                else if (it1->find(destination) != it1->end())
                {
                    auto aux = *it1;
                    for (auto it2 = next(it1); it2 != trees.end(); it2++)
                    {
                        if (it2->find(source) != it2->end())
                        {
                            for (auto it3 : *it2)
                            {
                                aux.insert(it3);
                            }

                            trees.erase(it2);
                            break;
                        }
                    }

                    it1 = trees.erase(it1);

                    trees.insert(aux);
                    rez = nodes[source].x * nodes[destination].x;
                }
                else
                {
                    it1++;
                }
            }
        }
    }

    cout << rez;
    return 0;
}
