#include "player.hpp"
#include "judge.hpp"
#include <iostream>
using namespace std;

Judge::Judge(){
  m_players_count = 0;
 }
Judge::~Judge(){
}

void Judge::on(const Player* player){
  m_players[m_players_count++] = player;
}
void Judge::call(Player::Role role){
  int index;
  if (role == Player::Villager) {
     cout << "Calling: Villager" << endl;
    for (index = 0; index < kMaxCountOfPlayers; index++) {
        if (m_players[index]->Player::role() == Player::Villager) m_players[index]->answer();
        else m_players[index]->pretend();
      }
     return;
   }
  else {
     if (role == Player::Werewolf) cout << "Calling: Werewolf"<<endl;
     else if (role == Player::Seer) cout << "Calling: Seer" <<endl;
     else if (role == Player::Witch) cout << "Calling: Witch"<<endl;
     else if (role == Player::Hunter) cout << "Calling: Hunter"<<endl;
     for (index = 0; index < kMaxCountOfPlayers; index++) {
        if (m_players[index]->Player::role() == role) m_players[index]->answer();
      }
   }
}