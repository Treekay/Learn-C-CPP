 #include "Bitset.h"
#include <iostream>
#include <climits>
using namespace std;
bitset::bitset(){
	for (int index = 0; index < N; index++) {
		a[index] = 0;
	}
}
void bitset::set(int pos){
	int byte;
	byte = pos / 32;
	int bit;
	bit = pos % 32;
	a[byte] |= 1 << bit ;
}
void bitset::reset(int pos){
	int byte;
	byte = pos / 32;
	int bit;
	bit = pos % 32;
	a[byte] &= (~ (1 << bit));
}
int bitset::count() const{
	int num;
	num = 0;
	int index;
	for (index = 0; index < max_length; index++) {
		if (test(index)) num++;
	}
	return num;
}
bool bitset::test(int pos) const{
	int byte;
	byte = pos / 32;
	int bit;
	bit = pos % 32;
	if ((a[byte] & (1 << bit )) == (1 << bit )) return true;
	else return false;
}
bool bitset::any() const{
	int index;
	for (index = 0; index < N; index++) {
		if ( a[index] != 0) return true;
	}
	return false;
}
bool bitset::none() const{
	int index;
	for (index = 0; index < max_length; index++) {
		if ( a[index] != 0) return false;
	}
	return true;
}
bool bitset::all() const{
	int index;
	for (index = 0; index < max_length; index++) {
		if (!test(index)) return false;
	}
	return true;
}
bitset& bitset::operator&= (const bitset& b){
	int index;
	for (index = 0; index < N; index++) {
		a[index] &= b.a[index];
	}
	return *this;
}
bitset& bitset::operator|= (const bitset& b){
	int index;
	for (index = 0; index < N; index++) {
		a[index] |= b.a[index];
	}
	return *this;
}
bitset& bitset::operator^= (const bitset& b){
	int index;
	for (index = 0; index < N; index++) {
		a[index] ^= b.a[index];
	}
	return *this;
}
bitset& bitset::operator= (const bitset& b){
	int index;
	for (index = 0; index < N; index++) {
		a[index] = b.a[index];
	}
	return *this;
}
bitset& bitset::operator <<= (int pos){
	int index;
	for (index = max_length-1; index > 1; index--) {
		if (test(index-2)) set(index);
		else reset(index);
	}
	reset(index--);
	reset(index);
	return *this;
}
bitset& bitset::operator >>= (int pos){
	int index;
	for (index = 0; index < max_length-2; index++) {
		if (test(index+2)) set(index);
		else reset(index);
	}
	set(index++);
	set(index);
	return *this;
}
bitset bitset::operator~() const{
	int index;
	bitset c = bitset();
	for (index = 0; index < N; index++) {
		c.a[index] = ~a[index] ;
	}
	return c;
}
bitset bitset::operator&(const bitset& b) const{
	bitset c = bitset();
	int index;
	for (index = 0; index < N; index++) {
		c.a[index] = a[index] & b.a[index];
	}
	return c;
}
bitset bitset::operator|(const bitset& b) const{
	bitset c = bitset();
	int index;
	for (index = 0; index < N; index++) {
		c.a[index] = a[index] | b.a[index];
	}
	return c;
}
bitset bitset::operator^(const bitset& b) const{
	bitset c = bitset();
	int index;
	for (index = 0; index < N; index++) {
		c.a[index] = a[index] ^ b.a[index];
	}
	return c;
}
bitset bitset::operator<<(int pos) const{
	bitset c = bitset();
	int index;
	for (index = max_length-1; index > 1; index--) {
		if (test(index-2)) c.set(index);
		else c.reset(index);
	}
	c.reset(index--);
	c.reset(index);
	return c;
}
bitset bitset::operator>>(int pos) const{
	bitset c = bitset();
	int index;
	for (index = 0; index < max_length-2; index++) {
		if (test(index+2)) c.set(index);
		else c.reset(index);
	}
	c.set(index++);
	c.set(index);
	return c;
}
bool bitset::operator== (const bitset& b) const{
	int index;
	for (index = 0;index < N; index++) {
		if (a[index] != b.a[index]) return false;
	}
	return true;
}
bool bitset::operator!= (const bitset& b) const{
	int index;
	int check;
	check = 0;
	for (index = 0;index < N; index++) {
		if (a[index] != b.a[index]) check = 1;
	}
	if (check == 0) return false;
	else return true;
}
bool bitset::operator[] (int pos) const{
 	return test(pos);
}