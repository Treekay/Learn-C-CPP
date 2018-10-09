 #include "Bulider.hpp"
#include <iostream>
using namespace std;

Bulider* Bulider::_instance;
Bulider* Bulider::getInstance(){
	if (_instance == NULL) _instance = new Bulider;
  	return _instance;
}
void Bulider::destroyInstance(){
 	delete _instance;
 	_instance = NULL;
}

// check the token's validity in current nesting structure
// if valid, record it in _tokens, if not, set _error true
void Bulider::handleOneToken(Token token){
  	if (token.type == "DATA") {
  		token.depth = _stack.size();
  		_tokens.push_back(token);
  	}
  	else if (token.type == "OPEN_TAG") {
  		token.depth = _stack.size();
  		_tokens.push_back(token);
  		_stack.push(token);
  	}
  	else if (token.type == "CLOSE_TAG") {
  		if (_stack.size() == 0) _error = true;
  		else if (_stack.top().content != token.content) _error = true;
  		else _stack.pop();
  	}
}
void Bulider::display(){
	if (_error == false && _stack.empty()){
	  	for (int index = 0 ; index < _tokens.size(); index++){
	  		if (_tokens[index].content.length() != 0){
		  		for (int ter = 0; ter < _tokens[index].depth; ter++) cout << "  ";
		  		cout << _tokens[index].content;
		  		if (_tokens[index].type == "OPEN_TAG" ) cout << ':';
		  		cout << endl;
		  	}
	  	}
	}
	else  cout << "INVALID INPUT" << endl;
}