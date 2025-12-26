#include <bits/stdc++.h>

using namespace std;

struct Pipe
{
    char shape;
    int pozi, pozj;
};

void advance(vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe, const int &l);
void addNorth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe);
void addEast(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe, const int &l);
void addSouth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe);
void addWest(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe);
void buildOut(vector<string> &map, const int &l);
void addPipe(vector<string> &map, queue<Pipe> &outside, int pozi, int pozj);
int inside(const vector<string> &original, const vector<string> &map, const int &i, int j, const int &l);

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

    Pipe pipe;

    pipe.pozi = pozi;
    pipe.pozj = pozj;

    bool north = true, south = true, west = true, east = true;

    if (0 < pozi && (map[pozi - 1][pozj] == '-' || map[pozi - 1][pozj] == '.'))
    {
        north = false;
    }
    if (pozj < l - 1 && (map[pozi][pozj + 1] == '|' || map[pozi][pozj + 1] == '.'))
    {
        east = false;
    }
    if (pozi < map.size() - 1 && (map[pozi + 1][pozj] == '-' || map[pozi + 1][pozj] == '.'))
    {
        south = false;
    }
    if (0 < pozj && (map[pozi][pozj - 1] == '|' || map[pozi][pozj - 1] == '.'))
    {
        west = false;
    }

    if (north)
    {
        if (south)
        {
            pipe.shape = '|';
        }
        else if (east)
        {
            pipe.shape = 'L';
        }
        else
        {
            pipe.shape = 'J';
        }
    }
    else if (south)
    {
        if (west)
        {
            pipe.shape = '7';
        }
        else
        {
            pipe.shape = 'F';
        }
    }
    else
    {
        pipe.shape = '-';
    }

    pipes.push(pipe);

    vector<string> original = map;

    while (!pipes.empty())
    {
        Pipe pipe = pipes.front();

        pipes.pop();

        advance(map, pipes, pipe, l);
    }

    buildOut(map, l);

    int rez = 0;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < l; j++)
        {
            rez += map[i][j] != 'O' && map[i][j] != 'W' ? inside(original, map, i, j, l) : 0;
        }
    }

    cout << rez;
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

    map[pipe.pozi][pipe.pozj] = 'W';
}

void addNorth(const vector<string> &map, queue<Pipe> &pipes, const Pipe &pipe)
{
    if (0 < pipe.pozi && (map[pipe.pozi - 1][pipe.pozj] == '|' || map[pipe.pozi - 1][pipe.pozj] == '7' || map[pipe.pozi - 1][pipe.pozj] == 'F'))
    {
        Pipe newPipe;

        newPipe.shape = map[pipe.pozi - 1][pipe.pozj];
        newPipe.pozi = pipe.pozi - 1;
        newPipe.pozj = pipe.pozj;

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

        pipes.push(newPipe);
    }
}

void buildOut(vector<string> &map, const int &l)
{
    queue<Pipe> outside;

    for (int j = 0; j < l; j++)
    {
        if (map[0][j] != 'W')
        {
            addPipe(map, outside, 0, j);
        }
        if (map[map.size() - 1][j] != 'W')
        {
            addPipe(map, outside, map.size() - 1, j);
        }
    }
    for (int i = 1; i < map.size() - 1; i++)
    {
        if (map[i][0] != 'W')
        {
            addPipe(map, outside, i, 0);
        }
        if (map[i][l - 1] != 'W')
        {
            addPipe(map, outside, i, l - 1);
        }
    }

    while (!outside.empty())
    {
        Pipe pipe = outside.front();

        outside.pop();

        if (0 < pipe.pozi && map[pipe.pozi - 1][pipe.pozj] != 'W' && map[pipe.pozi - 1][pipe.pozj] != 'O')
        {
            addPipe(map, outside, pipe.pozi - 1, pipe.pozj);
        }
        if (pipe.pozj < l - 1 && map[pipe.pozi][pipe.pozj + 1] != 'W' && map[pipe.pozi][pipe.pozj + 1] != 'O')
        {
            addPipe(map, outside, pipe.pozi, pipe.pozj + 1);
        }
        if (pipe.pozi < map.size() - 1 && map[pipe.pozi + 1][pipe.pozj] != 'W' && map[pipe.pozi + 1][pipe.pozj] != 'O')
        {
            addPipe(map, outside, pipe.pozi + 1, pipe.pozj);
        }
        if (0 < pipe.pozj && map[pipe.pozi][pipe.pozj - 1] != 'W' && map[pipe.pozi][pipe.pozj - 1] != 'O')
        {
            addPipe(map, outside, pipe.pozi, pipe.pozj - 1);
        }
    }
}

void addPipe(vector<string> &map, queue<Pipe> &outside, int pozi, int pozj)
{
    Pipe pipe;

    pipe.shape = map[pozi][pozj];
    pipe.pozi = pozi;
    pipe.pozj = pozj;

    outside.push(pipe);

    map[pipe.pozi][pipe.pozj] = 'O';
}

int inside(const vector<string> &original, const vector<string> &map, const int &i, int j, const int &l)
{
    int crossing = 0;

    char last = '|';
    for (; j < l; j++)
    {
        if (map[i][j] == 'W')
        {
            switch (original[i][j])
            {
            case '|':
            {
                crossing++;
                last = '|';
                break;
            }
            case 'F':
            {
                last = 'F';
                break;
            }
            case '7':
            {
                if (last == 'L')
                {
                    crossing++;
                }
                last = '7';
                break;
            }
            case 'L':
            {
                last = 'L';
                break;
            }
            case 'J':
            {
                if (last == 'F')
                {
                    crossing++;
                }
                last = 'J';
                break;
            }
            }
        }
    }

    return crossing % 2;
}
