string Board::draw(int num) {
	Board board{ sizeOfBoard };
	board = *this;
	//string fileName ="TicTacToe.ppm";
	int length = num, width = num;
	string fileName = "TicTacToe_" + to_string(sizeOfBoard) + ".ppm";// this way we can make all type of dif board with dif image names
	ofstream output(fileName, ios::app | ios::binary);
	output << "P6" << endl << length << " " << width << endl << 255 << endl;

	RedGreenBlue *image= new RedGreenBlue[length*length];

	for (int j = 0; j<length; j++) {  // row
		for (int i = 0; i<length; i++) { // column
										 /*
										 *giving all three the number 255 gives us a white board pic
										 */
			image[(length*j) + i].red = 255;
			image[(length*j) + i].green = 255;
			image[(length*j) + i].blue = 255;
		}
	}

	/*
	* creat lines
	*/
	for (int i = 0; i<sizeOfBoard; i++) {//create rows
		int wid = i*(length / sizeOfBoard);
		for (int j = 0; j<length; j++) {
			/*
			*giving only the blue one 255 and others
			* give them zero makes our TicTacToe board rows a blue rows
			*/
			image[(wid*length) + j].red = 0;
			image[(wid*length) + j].green = 0;
			image[(wid*length) + j].blue = 255;
		}
	}
	for (int i = 0; i<sizeOfBoard; i++) {//create col
		int len = i*(length / sizeOfBoard);
		for (int j = 0; j<length; j++) {
			/*
			*giving only the blue one 255 and others
			* give them zero makes our TicTacToe board col a blue col
			*/
			image[(length*j) + len].red = 0;
			image[(length*j) + len].green = 0;
			image[(length*j) + len].blue = 255;
		}
	}
	for (int i = 0; i<sizeOfBoard; ++i) {//O and X signs
		for (int j = 0; j<sizeOfBoard; j++) {
			int len, to_len, wid, to_wid;
			len = j*(length / sizeOfBoard);
			to_len = (j + 1)*(length / sizeOfBoard);
			wid = i*(length / sizeOfBoard);
			to_wid = (i + 1)*(length / sizeOfBoard);

			if (board[{i, j}] == 'O') {//draw O
				int len_dist = (to_len - len) / 2;
				int wid_dist = (to_wid - wid) / 2;
				int rad = len_dist;
				for (int i = 0; i<to_wid - wid; i++) {
					int j = sqrt((rad*rad) - (i - len_dist)*(i - len_dist)) + wid_dist;
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
					image[length*(wid + j) + len + i].green = 0;
					image[length*(wid + j) + len + i].blue = 0;
					image[length*(wid + j) + len + i].red = 0;
					image[length*(to_wid - j) + len + i].green = 0;
					image[length*(to_wid - j) + len + i].blue = 0;
					image[length*(to_wid - j) + len + i].red = 0;
				}
			}
			/*
			*giving all green red and blue zero ,makes our X sign color black
			*/
			/*
			* same method used in drawing O
			*/
			else if (board[{i, j}] == 'X') { // draw X
				for (int t = 0; t<to_wid - wid; t++) {
					image[length*(t + wid) + len + t].green = 0;
					image[length*(t + wid) + len + t].red = 0;
					image[length*(t + wid) + len + t].blue = 0;
					image[length*(t + wid) + to_len - t].blue = 0;
					image[length*(t + wid) + to_len - t].green = 0;
					image[length*(t + wid) + to_len - t].red = 0;
				}
			}
		}
	}
	
	if ((num == 1) || (num == 2) || (num == 3) || (num == 4) || (num == 5) || (num == 6)
		|| (num == 7) || (num == 8) || (num == 9) || (num == 10) || (num == 11) || (num == 12)
		|| (num == 13) || (num == 14) || (num == 15) || (num == 16) || (num == 17) || (num == 18)
		|| (num == 19) || (num == 20)) {

		int length = num, width = num;
		string fileName = "TicTacToe_" + to_string(sizeOfBoard) + ".ppm";// this way we can make all type of dif board with dif image names
		ofstream output(fileName, ios::app | ios::binary);
		output << "P6" << endl << length << " " << width << endl << 255 << endl;

		RedGreenBlue *image = new RedGreenBlue[length*length];

		for (int j = 0; j<length; j++) {  // row
			for (int i = 0; i<length; i++) { // column
											 /*
											 *giving all three the number 255 gives us a white board pic
											 */
				image[(length*j) + i].red = 255;
				image[(length*j) + i].green = 255;
				image[(length*j) + i].blue = 255;
			}
		}

		/*
		* creat lines
		*/
		for (int i = 0; i<sizeOfBoard; i++) {//create rows
			int wid = i*(length / sizeOfBoard);
			for (int j = 0; j<length; j++) {
				/*
				*giving only the blue one 255 and others
				* give them zero makes our TicTacToe board rows a blue rows
				*/
				image[(wid*length) + j].red = 0;
				image[(wid*length) + j].green = 0;
				image[(wid*length) + j].blue = 255;
			}
		}
		for (int i = 0; i<sizeOfBoard; i++) {//create col
			int len = i*(length / sizeOfBoard);
			for (int j = 0; j<length; j++) {
				/*
				*giving only the blue one 255 and others
				* give them zero makes our TicTacToe board col a blue col
				*/
				image[(length*j) + len].red = 0;
				image[(length*j) + len].green = 0;
				image[(length*j) + len].blue = 255;
			}
		}
		for (int i = 0; i<sizeOfBoard; ++i) {//O and X signs
			for (int j = 0; j<sizeOfBoard; j++) {
				int len, to_len, wid, to_wid;
				len = j*(length / sizeOfBoard);
				to_len = (j + 1)*(length / sizeOfBoard);
				wid = i*(length / sizeOfBoard);
				to_wid = (i + 1)*(length / sizeOfBoard);

				if (board[{i, j}] == 'O') {//draw O
					int len_dist = (to_len - len) / 2;
					int wid_dist = (to_wid - wid) / 2;
					int rad = len_dist;
					for (int i = 0; i<to_wid - wid; i++) {
						int j = sqrt((rad*rad) - (i - len_dist)*(i - len_dist)) + wid_dist;
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
						image[length*(wid + j) + len + i].green = 0;
						image[length*(wid + j) + len + i].blue = 0;
						image[length*(wid + j) + len + i].red = 0;
						image[length*(to_wid - j) + len + i].green = 0;
						image[length*(to_wid - j) + len + i].blue = 0;
						image[length*(to_wid - j) + len + i].red = 0;
					}
				}
				/*
				*giving all green red and blue zero ,makes our X sign color black
				*/
				/*
				* same method used in drawing O
				*/
				else if (board[{i, j}] == 'X') { // draw X
					for (int t = 0; t<to_wid - wid; t++) {
						image[length*(t + wid) + len + t].green = 0;
						image[length*(t + wid) + len + t].red = 0;
						image[length*(t + wid) + len + t].blue = 0;
						image[length*(t + wid) + to_len - t].blue = 0;
						image[length*(t + wid) + to_len - t].green = 0;
						image[length*(t + wid) + to_len - t].red = 0;
					}
				}
			}
		}
	}

	/*
	*image processing
	*/
	output.write(reinterpret_cast <char*>(&image), 3 * num*num);
	output.close();
	return fileName;
}
