 
#include "player.hpp"
#include "judge.hpp"
#include <iostream>
using namespace std;
 Player::Player(){
 }
 void Player::init(std::string name, Role role){
   Player::m_name = name;
   Player::m_role = role;
 }
 Player::~Player(){}

 Player::Role Player::role() const{
   return m_role;
 }
 void Player::answer() const{
   if (m_role == Villager) cout << Player::m_name<<": I am the villager!!"<< endl;
   else if (m_role == Werewolf) cout << Player::m_name << ": Shh... I am a Werewolf."<< endl;
   else if (m_role == Seer) cout << Player::m_name << ": Shh... I am a Seer."<< endl;
   else if (m_role == Witch) cout << Player::m_name <<": Shh... I am a Witch."<< endl;
   else if (m_role == Hunter) cout << Player::m_name <<": Shh... I am a Hunter."<< endl;
 }
 void Player::pretend() const{
   cout << m_name <<": I am the villager!!"<< endl;
 }