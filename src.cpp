#include <string>
#include <iostream>

using namespace std;

class Piece{
	public:
		string get_name(){ return name; };
	private:
		string name{"king"};
};

class Square{
	public:
		Square( Square* pr = nullptr, Square* nxt = nullptr ):
			prev{ pr }, next{ nxt }{};

		//Piece* get_occupying_piece() { return p; };
		Square* get_next() const { return next; };
		Square* get_prev() const { return prev; };
		Piece* pce {nullptr};
	private:
		Square* prev;
		Square* next;
};

int main(){
	// create linked list
	Square* sq = new Square();
	Piece* p = new Piece();

	sq->pce = p;
	cout << sq->pce->get_name();
	// check dest tile is free
	// check source is free
	// move pointer of dest to piece
	// move pointer of source to piece
	return 0;
}
