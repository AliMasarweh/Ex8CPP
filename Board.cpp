#include "Board.h"
#include <vector>
#include <fstream>
#include <math.h>

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

unsigned int Board::size() const{
	return this->sizeOfBoard;
}
int Board::BoardSize() const {
	return this->sizeOfBoard;
}


string Board::draw(int pixels) {
		string fileName = "myimage.ppm";
		int i = 1;
		while (exists(fileName)) {
			fileName = "myimage" + std::to_string(i) + ".ppm";
			i++;
		}
		Board board{ this->sizeOfBoard };
		board = *this;
		int length = pixels, width = pixels;
		ofstream output(fileName, ios::app | ios::binary);
		output << "P6" << endl << length << " " << width << endl << 255 << endl;
		//vector<RedGreenBlue> *image;
		//image = new vector<RedGreenBlue>();
		RedGreenBlue image[length*length];
        
    for(int j=0; j<length;j++){  // row
       for(int i=0; i<length;i++){ // column
/*
*giving all three the number 255 gives us a white board pic
*/
           image[(length*j)+i].red =255;
           image[(length*j)+i].green = 255;
           image[(length*j)+i].blue =255; 
         }
       }

/*
* creat lines
*/
	for(int i=0;i<size;i++){//create rows
	    int wid=i*(length/size);
            for(int j=0;j<length;j++){
/*
*giving only the blue one 255 and others 
* give them zero makes our TicTacToe board rows a blue rows
*/
          	image[(wid*length)+j].red =0;
          	image[(wid*length)+j].green =0;
                image[(wid*length)+j].blue =255;
		}
	}
	for(int i=0;i<size;i++){//create col
		int len =i*(length/size);
		for(int j=0;j<length;j++){
/*
*giving only the blue one 255 and others 
* give them zero makes our TicTacToe board col a blue col
*/
		    image[(length*j)+len].red =0;
		    image[(length*j)+len].green =0;
		    image[(length*j)+len].blue =255;
		}
	}
	for(int i=0;i<size;++i){//O and X signs
		for(int j=0;j<size;j++){
                    int len, to_len, wid, to_wid;
	            len =j*(length/size);
		    to_len =(j+1)*(length/size);
		    wid =i*(length/size);
		    to_wid =(i+1)*(length/size);
            
            if(board[{i,j}] =='O'){//draw O
	           int len_dist =(to_len-len)/2;
                   int wid_dist =(to_wid-wid)/2;
                   int rad = len_dist;
		   for(int i=0;i<to_wid-wid;i++){
		       int j=sqrt((rad*rad)-(i-len_dist)*(i-len_dist))+wid_dist;
/*
*sign O will be black cuz all green red and blue = 0
*/

/* the idea here is to draw the two sides of sing O at the same time
*  something like this :
*                        --
*                     --    --
*                   --        --
*                     --    --
*                        --
*two sides at the same time (left and right) :-)
*/
                       image[length*(wid+j)+len+i].green =0;
          	       image[length*(wid+j)+len+i].blue =0;
                       image[length*(wid+j)+len+i].red =0;
               	       image[length*(to_wid-j)+len+i].green =0;
          	       image[length*(to_wid-j)+len+i].blue =0;
                       image[length*(to_wid-j)+len+i].red =0;
		 }
	     }
/*
*giving all green red and blue zero ,makes our X sign color black
*/
/* 
* same method used in drawing O 
*/
		else if(board[{i,j}] =='X'){ // draw X
		       for(int t=0;t<to_wid-wid;t++){
                           image[length*(t+wid)+len+t].green =0;
                           image[length*(t+wid)+len+t].red =0;
	                   image[length*(t+wid)+len+t].blue =0;
                           image[length*(t+wid)+to_len-t].blue =0;
                           image[length*(t+wid)+to_len-t].green =0;
                           image[length*(t+wid)+to_len-t].red =0;
			}
	   	    } 
		}
	    }

		/*
		*image processing
		*/
		output.write(reinterpret_cast <char*>(&image), 3 * pixels*pixels);
		output.close();
		return fileName;
	}

bool Board::exists(const std::string& name) {
	ifstream f(name.c_str());
    	return f.good();
}
