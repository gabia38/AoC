#include <bits/stdc++.h>

using namespace std;

struct Pipe
{
    char shape;
    int pozi, pozj, distance;
};

void advance(vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe, const int &l);
void addNorth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe);
void addEast(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe, const int &l);
void addSouth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe);
void addWest(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe);

int main()
{
    vector<string> map;
    string line;

    int pozi, pozj;
    while (getline(cin, line))
    {
        if (line.find('S') != string::npos)
        {
            pozi = map.size();
            pozj = line.find('S');
        }

        map.push_back(line);
    }

    int l = map[0].size();
    queue<Pipe> pipes;

    if (0 < pozi && (map[pozi - 1][pozj] == '|' || map[pozi - 1][pozj] == '7' || map[pozi - 1][pozj] == 'F'))
    {
        Pipe pipe;

        pipe.shape = map[pozi - 1][pozj];
        pipe.pozi = pozi - 1;
        pipe.pozj = pozj;
        pipe.distance = 1;

        pipes.push(pipe);
    }
    if (pozj < l - 1 && (map[pozi][pozj + 1] == '-' || map[pozi][pozj + 1] == 'J' || map[pozi][pozj + 1] == '7'))
    {
        Pipe pipe;

        pipe.shape = map[pozi][pozj + 1];
        pipe.pozi = pozi;
        pipe.pozj = pozj + 1;
        pipe.distance = 1;

        pipes.push(pipe);
    }
    if (pozi < map.size() - 1 && (map[pozi + 1][pozj] == '|' || map[pozi + 1][pozj] == 'L' || map[pozi + 1][pozj] == 'J'))
    {
        Pipe pipe;

        pipe.shape = map[pozi + 1][pozj];
        pipe.pozi = pozi + 1;
        pipe.pozj = pozj;
        pipe.distance = 1;

        pipes.push(pipe);
    }
    if (0 < pozj && (map[pozi][pozj - 1] == '-' || map[pozi][pozj - 1] == 'F' || map[pozi][pozj - 1] == 'L'))
    {
        Pipe pipe;

        pipe.shape = map[pozi][pozj - 1];
        pipe.pozi = pozi;
        pipe.pozj = pozj - 1;
        pipe.distance = 1;

        pipes.push(pipe);
    }

    map[pozi][pozj] = '.';

    int maxi = 0;
    while (!pipes.empty())
    {
        Pipe pipe = pipes.front();

        pipes.pop();

        advance(map, pipes, pipe, l);

        maxi = max(maxi, pipe.distance);
    }

    cout << maxi;
    return 0;
}

void advance(vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe, const int &l)
{
    switch (pipe.shape)
    {
    case '|':
    {
        addNorth(map, pipes, pipe);
        addSouth(map, pipes, pipe);
        break;
    }
    case '-':
    {
        addEast(map, pipes, pipe, l);
        addWest(map, pipes, pipe);
        break;
    }
    case 'L':
    {
        addNorth(map, pipes, pipe);
        addEast(map, pipes, pipe, l);
        break;
    }
    case 'J':
    {
        addNorth(map, pipes, pipe);
        addWest(map, pipes, pipe);
        break;
    }
    case '7':
    {
        addSouth(map, pipes, pipe);
        addWest(map, pipes, pipe);
        break;
    }
    case 'F':
    {
        addSouth(map, pipes, pipe);
        addEast(map, pipes, pipe, l);
        break;
    }
    }

    map[pipe.pozi][pipe.pozj] = '.';
}

void addNorth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe)
{
    if (0 < pipe.pozi && (map[pipe.pozi - 1][pipe.pozj] == '|' || map[pipe.pozi - 1][pipe.pozj] == '7' || map[pipe.pozi - 1][pipe.pozj] == 'F'))
    {
        Pipe newPipe;

        newPipe.shape = map[pipe.pozi - 1][pipe.pozj];
        newPipe.pozi = pipe.pozi - 1;
        newPipe.pozj = pipe.pozj;
        newPipe.distance = pipe.distance + 1;

        pipes.push(newPipe);
    }
}

void addEast(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe, const int &l)
{
    if (pipe.pozj < l - 1 && (map[pipe.pozi][pipe.pozj + 1] == '-' || map[pipe.pozi][pipe.pozj + 1] == 'J' || map[pipe.pozi][pipe.pozj + 1] == '7'))
    {
        Pipe newPipe;

        newPipe.shape = map[pipe.pozi][pipe.pozj + 1];
        newPipe.pozi = pipe.pozi;
        newPipe.pozj = pipe.pozj + 1;
        newPipe.distance = pipe.distance + 1;

        pipes.push(newPipe);
    }
}

void addSouth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe)
{
    if (pipe.pozi < map.size() - 1 && (map[pipe.pozi + 1][pipe.pozj] == '|' || map[pipe.pozi + 1][pipe.pozj] == 'L' || map[pipe.pozi + 1][pipe.pozj] == 'J'))
    {
        Pipe newPipe;

        newPipe.shape = map[pipe.pozi + 1][pipe.pozj];
        newPipe.pozi = pipe.pozi + 1;
        newPipe.pozj = pipe.pozj;
        newPipe.distance = pipe.distance + 1;

        pipes.push(newPipe);
    }
}

void addWest(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe)
{
    if (0 < pipe.pozj && (map[pipe.pozi][pipe.pozj - 1] == '-' || map[pipe.pozi][pipe.pozj - 1] == 'F' || map[pipe.pozi][pipe.pozj - 1] == 'L'))
    {
        Pipe newPipe;

        newPipe.shape = map[pipe.pozi][pipe.pozj - 1];
        newPipe.pozi = pipe.pozi;
        newPipe.pozj = pipe.pozj - 1;
        newPipe.distance = pipe.distance + 1;

        pipes.push(newPipe);
    }
}
