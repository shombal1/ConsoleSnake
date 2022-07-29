
#include <iostream>
#include <vector>
#include <list>
#include <conio.h>

using namespace std;

#pragma warning(disable : 4996)

struct Point
{
    int y;
    int x;
};

void RandomSpawn(vector<vector<int>>& map)
{
    int y; y = rand() % map.size();
    int x;
    while (true)
    {


        y = rand() % map.size();
        x = rand() % map[0].size();

        if (!(map[y][x] == 1) && !(map[y][x] == 2))
        {
            map[y][x] = 2;
            break;
        }
    }

}



void Umove(vector<vector<int>>& map, list<int*>& snake, bool& cont, Point& Head, int RetX = 0, int RetY = 0)
{
    auto END = snake.end();
    END--;
    auto ben = snake.begin();
    ben++;
    if (map[Head.y][Head.x] == 1)
    {
        if (*(ben) == &map[Head.y][Head.x])
        {
            Head.x = Head.x + RetX;
            Head.y = Head.y + RetY;
        }
        else
        {
            cont = false;
        }
    }
    else
    {
        snake.insert(snake.begin(), &map[Head.y][Head.x]);
        **END = 0;
        if (map[Head.y][Head.x] == 2)
        {
            RandomSpawn(map);

        }
        else
        {
            snake.pop_back();
        }

        **snake.begin() = 1;
    }

}


void WriteMap(vector<vector<int>> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] == 0)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << map[i][j];
            }

        }
        std::cout << "\n";
    }
}

int main()
{
    int SizeMapY = 10;
    int SizeMapX = 30;
    vector<vector<int>> map(SizeMapY, vector<int>(SizeMapX, 0));
    list<int*> python;
    Point Head;
    Head.y = SizeMapY / 2;
    Head.x = SizeMapX / 2;

    python.push_back(&map[SizeMapY / 2][SizeMapX / 2]);
    python.push_back(&map[SizeMapY / 2 + 1][SizeMapX / 2]);
    python.push_back(&map[SizeMapY / 2 + 2][SizeMapX / 2]);
    for (int i = 0; i < SizeMapX; i++)
    {
        map[0][i] = 1;
    }
    for (int i = 0; i < SizeMapX; i++)
    {
        map[SizeMapY - 1][i] = 1;
    }
    for (int i = 1; i < SizeMapY - 1; i++)
    {
        map[i][0] = 1;
    }
    for (int i = 1; i < SizeMapY - 1; i++)
    {
        map[i][SizeMapX - 1] = 1;
    }
    for (auto a = python.begin(); !(a == python.end()); a++)
    {
        **a = 1;

    }


    RandomSpawn(map);
    RandomSpawn(map);

    WriteMap(map);


    bool cont = true;
    while (cont)
    {
        bool test = true;
        while (test)
        {
            char o;
            o = getch();
            switch (o)
            {
            case 'w':
                Head.y--;
                Umove(map, python, cont, Head, 0, 1);
                test = false;
                break;
            case 's':
                Head.y++;
                Umove(map, python, cont, Head, 0, -1);
                test = false;
                break;
            case 'a':
                Head.x--;
                Umove(map, python, cont, Head, 1);
                test = false;
                break;
            case 'd':
                Head.x++;
                Umove(map, python, cont, Head, -1);
                test = false;
                break;
            default:
                break;
            }
        }

        std::system("CLS");
        WriteMap(map);



    }
    std::system("CLS");
    std::cout << "Game Over\n";
    int y;
    std::cin >> y;


}
