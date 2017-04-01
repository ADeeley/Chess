#include <string>
#include <iostream>

using namespace std;

class Piece{
	public:
		Piece( string nm ):
			name{ nm }{};
		string get_name(){ return name; };
	private:
		string name{};
};

class Square{
	public:
		Square( char nm ):
			name{ nm } {};

		//Piece* get_occupying_piece() { return p; };
		Piece* occupier {nullptr};
		char get_name() { return name; };
		Square* prev { nullptr };
		Square* next { nullptr };
	private:
		const char name;
};

class Board{
	public:
		Board();
		Square* find_square( string name );
		void move_piece( string source, string destination );
		Square* get_squarelist(){ return squarelist; };
	private:

		Square* squarelist;
};

Board::Board(){
	// Generates the linked list for board
	string names = "abcdefghi";
	for ( char c : names )
	{
		if ( c == 'a' ) // declare the list initially
		{
			Square* squarelist = new Square( c );
			continue;
		}
		squarelist->next = new Square( c );
		squarelist->next->prev = squarelist;
		squarelist = squarelist->next;

	}
}

Square* Board::find_square( string name ){
	// finds the square object with called name and returns a pointer to tie object.
	Square* sq = squarelist;
	//find the first object in the linked list
	while( sq -> prev )
	{
		sq = sq->prev;
	}
	/// to finish	
}

void test_board_constructor( Board b ){

	Square* brd = b.get_squarelist();
	while ( brd->prev )
	{
		cout << brd->get_name();
		brd = brd->prev;
	}
}

int main(){
	Board b = Board();
	test_board_constructor( b );
	// create linked list
	/*Square* sq = new Square();
	sq.next = new Square();
	sq.prev= new Square();
	sq->occupier = new Piece( "Pawn" );
	cout << sq->occupier->get_name() << '\n';
	sq->next->occupier = new Piece( "King" );
	cout << sq->next->occupier->get_name() << '\n';
	*/
	// check dest tile is free
	// check source is free
	// move pointer of dest to piece
	// move pointer of source to piece
	return 0;
}
