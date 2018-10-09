  #include "Parser.hpp"

Parser* Parser::_instance;
Parser* Parser::getInstance(){
	if (_instance == NULL)_instance = new Parser;
	return _instance;
}
void  Parser::destroyInstance(){
	delete _instance;
	_instance = NULL;
}
void Parser::consumeOneChar(char ch){
	_state->handleOneChar(_instance , ch);
	if (ch == '<'){
		DataState::destroyInstance();
     	setState(TagNameState::getInstance());
	}
	else if (ch == '>'){
		TagNameState::destroyInstance();
        setState(DataState::getInstance());
	}
}