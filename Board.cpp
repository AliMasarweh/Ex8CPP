#include "Board.h"


Board::Board() {
	this->sizeOfBoard = 4;
	this->board = new Status*[this->sizeOfBoard];
	int i;
	for (i = 0; i < this->sizeOfBoard; i++)
		this->board[i] = new Status[this->sizeOfBoard];
}

Board::Board(int size) {
	this->sizeOfBoard = size;
	this->board = new Status*[this->sizeOfBoard];
	int i;
	for (i = 0; i < this->sizeOfBoard; i++)
		this->board[i] = new Status[this->sizeOfBoard];
}

Board::Board(const Board& newBoard) {
	this->sizeOfBoard = newBoard.sizeOfBoard;
	this->board = new Status*[this->sizeOfBoard];
	int i, j;
	for (i = 0; i < this->sizeOfBoard; i++) {
		this->board[i] = new Status[this->sizeOfBoard];
		for (j = 0; j < this->sizeOfBoard; j++)
			this->board[i][j] = newBoard.board[i][j];
	}
}

Board::~Board() {
	int i;
	for (i = 0; i< this->sizeOfBoard; i++)
		delete[] board[i];
	delete[] board;
}

Board& Board::operator=(const Board& newBoard) {
	this->~Board();
	this->sizeOfBoard = newBoard.sizeOfBoard;
	board = new Status*[this->sizeOfBoard];
	int i, j;
	for (i = 0; i < this->sizeOfBoard; i++) {
		board[i] = new Status[this->sizeOfBoard];
		for (j = 0; j < this->sizeOfBoard; j++)
			this->board[i][j] = newBoard.board[i][j];
	}
	return *this;
}

Board& Board::operator= (const char newStatus) {
	Status status(newStatus);
	int i, j;
	for (i = 0; i < this->sizeOfBoard; i++)
		for (j = 0; j < this->sizeOfBoard; j++)
			this->board[i][j] = status;
	return *this;
}

Status& Board::operator[] (Coordination const &Coordination) const {
	if (Coordination.getXCoordination() < this->sizeOfBoard && Coordination.getXCoordination() >= 0 &&
		Coordination.getYCoordination() < this->sizeOfBoard && Coordination.getYCoordination() >= 0)
		return board[Coordination.getXCoordination()][Coordination.getYCoordination()];
	throw IllegalCoordinateException(Coordination);//Invalied Coordination
}

ostream& operator<< (ostream& os, const Board& inserteBoard) {
	int i, j;
	for (i = 0; i < inserteBoard.sizeOfBoard; i++) {
		for (j = 0; j < inserteBoard.sizeOfBoard; j++)
			os << inserteBoard.board[i][j];
		os << endl;
	}
	return os;
}
/*Insert a string or a file represting a board*/
istream& operator>> (istream &is, Board &board) {
	string line;
	is >> line;
	int size = line.length();
	Board temp(size);
	int i;
	for (i = 0; i<size; i++) temp[{0, i}] = line[i];
	int num = 1;
	while (num < size && is >> line) {
		i = 0;
		for (i = 0; i<size; i++) temp[{num, i}] = line[i];
		num++;
	}
	board = temp;
	return is;
}

unsigned int Board::size() const {
	return this->sizeOfBoard;
}
int Board::BoardSize() const {
	return this->sizeOfBoard;
}

/*This method draws a portable pixmap (ppm) image of the current board (including the assinged X & O)*/
string Board::draw(int pixels) {
	Board board{ sizeOfBoard };
	board = *this;
	int width = pixels, height = pixels;
	string fileName = "TicTacToe.ppm";
	int fileIndx = 0;
	while (exists(fileName)) {
		fileName = "TicTacToe_" + to_string(sizeOfBoard) + "_" + to_string(fileIndx) + ".ppm";
		fileIndx++;
	}//Checking if a file exists with the same name ,if so, we give it a new name
	ofstream output(fileName, ios::app | ios::binary);
	output << "P6" << endl << width << " " << height << endl << 255 << endl;

	RedGreenBlue *image = new RedGreenBlue[width*height];
	int blackSeparator = (width / sizeOfBoard);

	for (int i = 0; i<width; i++) {  // row
		for (int j = 0; j<height; j++) { // column
			//if (i % blackSeparator == 0 || j % blackSeparator == 0) {
			//	image[(width*i) + j].red = 0;
			//	image[(width*i) + j].green = 0;
			//	image[(width*i) + j].blue = 0;
			//}
			//else{
				image[(width*i) + j].red = 255;
				image[(width*i) + j].green = 255;
				image[(width*i) + j].blue = 255;
			//}
		}
	}

	for (int i = 0; i<sizeOfBoard; i++) {//Diving the board by it's size
		for (int j = 0; j<height; j++) {
			image[(i*blackSeparator*width) + j].red = 0;
			image[(i*blackSeparator*width) + j].green = 0;
			image[(i*blackSeparator*width) + j].blue = 0;
			image[(width*j) + i*blackSeparator].red = 0;
			image[(width*j) + i*blackSeparator].green = 0;
			image[(width*j) + i*blackSeparator].blue = 0;
		}
	}

	for (int raw = 0; raw<sizeOfBoard; raw++) {//O and X signs
		for (int column = 0; column<sizeOfBoard; column++) {
			int topOfSquare, bottomOfSquare, leftOfSquare, rightOfSquare;
			topOfSquare = column*(width / sizeOfBoard);
			bottomOfSquare = (column + 1)*(width / sizeOfBoard);
			leftOfSquare = raw*(width / sizeOfBoard);
			rightOfSquare = (raw + 1)*(width / sizeOfBoard);

			if (board[{raw, column}] == 'O') {// Draws an O in the current square
				int xCoordinationCenter = (rightOfSquare - leftOfSquare) / 2;
				int yCoordinationCenter = (bottomOfSquare - topOfSquare) / 2;
				int rad = xCoordinationCenter;
				for (int i = 0; i < rightOfSquare - leftOfSquare; i++) {
					int j = sqrt((rad*rad) - (i - xCoordinationCenter)*(i - xCoordinationCenter)) + yCoordinationCenter;
					image[width*(leftOfSquare + j) + topOfSquare + i].green = 255;
					image[width*(leftOfSquare + j) + topOfSquare + i].blue = 0;
					image[width*(leftOfSquare + j) + topOfSquare + i].red = 0;
					image[width*(rightOfSquare - j) + bottomOfSquare - i].green = 255;
					image[width*(rightOfSquare - j) + bottomOfSquare - i].blue = 0;
					image[width*(rightOfSquare - j) + bottomOfSquare - i].red = 0;
				}
			}
			else if (board[{raw, column}] == 'X') { // Draws an X in the current square
				for (int t = 0; t<rightOfSquare - leftOfSquare; t++) {
					image[width*(t + leftOfSquare) + topOfSquare + t].green = 0;
					image[width*(t + leftOfSquare) + topOfSquare + t].red = 0;
					image[width*(t + leftOfSquare) + topOfSquare + t].blue = 255;
					image[width*(t + leftOfSquare) + bottomOfSquare - t].blue = 255;
					image[width*(t + leftOfSquare) + bottomOfSquare - t].green = 0;
					image[width*(t + leftOfSquare) + bottomOfSquare - t].red = 0;
				}
			}
		}
	}
	/*
	*image processing
	*/
	output.write(reinterpret_cast <char*>(image), 3 * pixels*pixels);
	/*
	 * Sapce emptying
	 */
	output.close();
	delete[] image;
	return fileName;
}

bool Board::exists(const std::string& name) {
	ifstream f(name.c_str());
	return f.good();
}
