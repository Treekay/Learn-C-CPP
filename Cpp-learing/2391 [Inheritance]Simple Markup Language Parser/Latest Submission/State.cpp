#include "State.hpp"
#include "Parser.hpp"
#include <string>

State* DataState::_instance;
State* TagNameState::_instance;
State* DataState::getInstance(){
    if (_instance == NULL) _instance = new DataState;
  	return _instance;
}
void DataState::destroyInstance(){
  	delete _instance;
    _instance = NULL;
}
void DataState::handleOneChar(Parser* parser, char ch){
    if (ch != '>' && ch != '<') _cache += ch;
    else if (ch == '<') {
      emit(parser->getBulider());
    }
}
void DataState::emit(Bulider* dest){
    Token poi;
    poi.type = "DATA";
    int front = 0;
    for (int index = 0; index < _cache.length(); index++){
      if (_cache[index] != ' ' && _cache[index] != '\n') {
        front = index;
        break;
      }
    }
    int back = 0;
    for (int index = _cache.length()-1; index >= 0; index--){
      if (_cache[index] != ' '  && _cache[index] != '\n') {
        back = index;
        break;
      }
    }
    if (front < back){
      for (int index = front; index <= back; index++){
        poi.content += _cache[index];
      }
      dest->handleOneToken(poi);
    }
}



State* TagNameState::getInstance(){
    if (_instance == NULL) _instance = new TagNameState;
  	return _instance;
}
void TagNameState::destroyInstance(){
  	delete _instance;
  	_instance = NULL;
}

void TagNameState::handleOneChar(Parser* parser, char ch){
  	if (ch != '>' && ch != '<') _cache += ch;
    else if (ch == '>') {
        emit(parser->getBulider());
    }
}
void TagNameState::emit(Bulider* dest){
  	Token poi;
    if (_cache[0] == '/') {
      if (_cache.length() != 1){
          poi.type = "CLOSE_TAG";
          for (int index = 1; index < _cache.length(); index++){
              poi.content += _cache[index];
          }
          dest->handleOneToken(poi);
      }
    }
    else  {
      if (_cache.length() != 0){
          poi.type = "OPEN_TAG";
          poi.content += _cache;
          dest->handleOneToken(poi);
        }
    }
}