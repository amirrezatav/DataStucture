#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
enum Direction
{
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW,
	None
};
struct Driver
{
	int X;
	int Y;
	Direction direction;
	Driver(int i, int j) : X(i), Y(j), direction(Direction::N) {}
	void NextDircetion()
	{
		if(direction != Direction::None)
			direction = (Direction)((int)direction+1);
	}
};
class Maze
{
public:
	int MapRowSize;
	int MapColumnSize;
	int DestinationX;
	int DestinationY;
	int** MazeMap;
	bool** visited;
	int startX;
	int StartY;
	Maze(int** map, int MapRowSize, int MapColumnSize, int DestinationX, int DestinationY, int startX, int StartY)
		:MapRowSize(MapRowSize), MapColumnSize(MapColumnSize),DestinationX(DestinationX), DestinationY(DestinationY),startX(startX), StartY(StartY)
	{
		MazeMap = new int*[MapRowSize];
		visited = new bool*[MapRowSize];
		for (size_t i = 0; i < MapRowSize; i++)
		{
			MazeMap[i] = new int[MapColumnSize];
			visited[i] = new bool[MapColumnSize];
			for (size_t j = 0; j < MapColumnSize; j++)
			{
				MazeMap[i][j] = map[i][j];
				visited[i][j] = false;
			}
		}
	}
	inline bool isSafe(int x , int y)
	{
		return (x >= 0 && x <= MapColumnSize && y >= 0 && y <= MapRowSize && MazeMap[x][y] == 0 && !visited[x][y]);
	}
	bool isReachable()
	{

		stack<Driver> s;

		Driver temp(startX, StartY);
		s.push(temp);

		while (!s.empty()) {

			temp = s.top();
			Direction currentDirection = temp.direction;
			int currentX = temp.X;
			int currentY = temp.Y;
			temp.NextDircetion();
			s.pop();
			s.push(temp);

			// If we reach the Food coordinates
			// return true
			if (currentX == DestinationX && currentY == DestinationY) {
				return true;
			}

			switch (currentDirection)
			{
			case N:
				if (isSafe(currentX - 1, currentY)) {
					Driver temp1(currentX - 1, currentY);
					visited[currentX-1][currentY] = true;
					s.push(temp1);
				}
				break;
			case NE:
				if (isSafe(currentX - 1, currentY+1)) {
					Driver temp1(currentX - 1, currentY + 1);
					visited[currentX - 1][currentY + 1] = true;
					s.push(temp1);
				}
				break;
			case E:
				if (isSafe(currentX , currentY + 1)) {
					Driver temp1(currentX , currentY + 1);
					visited[currentX][currentY + 1] = true;
					s.push(temp1);
				}
				break;
			case SE:
				if (isSafe(currentX+1, currentY + 1)) {
					Driver temp1(currentX+1, currentY + 1);
					visited[currentX+1][currentY + 1] = true;
					s.push(temp1);
				}
				break;
			case S:
				if (isSafe(currentX + 1, currentY)) {
					Driver temp1(currentX + 1, currentY);
					visited[currentX + 1][currentY] = true;
					s.push(temp1);
				}
				break;
			case SW:
				if (isSafe(currentX + 1, currentY - 1)) {
					Driver temp1(currentX + 1, currentY - 1);
					visited[currentX + 1][currentY - 1] = true;
					s.push(temp1);
				}
				break;
			case W:
				if (isSafe(currentX , currentY - 1)) {
					Driver temp1(currentX , currentY - 1);
					visited[currentX ][currentY - 1] = true;
					s.push(temp1);
				}
				break;
			case NW:
				if (isSafe(currentX - 1, currentY - 1)) {
					Driver temp1(currentX - 1, currentY - 1);
					visited[currentX - 1][currentY - 1] = true;
					s.push(temp1);
				}
				break;
			case None:
				// If none of the direction can take the rat to the Food, retract back
				// to the path where the rat came from.
				visited[currentX][currentY] = true;
				s.pop();
				break;
			default:
				throw exception();
				break;
			}
		}
	
		// If the stack is empty and
		// no path is found return false.
		return false;
	}
};
int main()
{
	// Maze matrix
	int mazemap[4][5] = {
		{ 0, 1, 0, 0, 1 },
		{ 0, 0, 0, 1, 0 },
		{ 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0 }
	};
	int **MazeMap = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		MazeMap[i] = new int[5];
		for (size_t j = 0; j < 5; j++)
			MazeMap[i][j] = mazemap[i][j];
	}

	Maze maze(MazeMap, 4, 5, 3, 4, 0, 0);

	if (maze.isReachable()) 
		cout << "Path Found!" << '\n';
	else
		cout << "No Path Found!" << '\n';

	return 0;
}
