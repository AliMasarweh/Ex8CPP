
class IllegalCharException {
private:
	 char _char;

public:
	IllegalCharException(const char invalidChar) {
		_char = invalidChar;
	}

	const char theChar() const {
		return this->_char;
	}
};
