#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <memory>
#include "base.h"
using namespace std;

template< typename T, typename Alloc = std::allocator<T> >
class myVector : public Base {
    public:
        // Constructor
        myVector(){
            _size = 0;
            _capacity = 1;
            _data = Alloc().allocate(_capacity);
        }
        myVector(const std::size_t & size, const T & val,
                 Alloc a = Alloc()){
            _size = _capacity = size;
            _data = a.allocate(_capacity);
            for (int index = 0; index < size; index++){
                a.construct(_data + index, val);
            }
        }
        template<typename InputIterator>
        myVector(InputIterator begin, InputIterator end,
                 Alloc a = Alloc()){
            _size = _capacity = end - begin;
            _data = a.allocate(_capacity);
            int index = 0;
            for (InputIterator iter = begin; iter != end; iter++, index++){
                a.construct(_data + index, *iter);
            }
        }
        myVector(const myVector & other){
            _size = other._size;
            _capacity = other._capacity;
            _data = Alloc().allocate(_capacity);
            for (int index = 0; index < other._size; index++){
                Alloc().construct(_data + index, other._data[index]);
            }
        }
        ~myVector(){
            for (std::size_t index = 0; index < _size; index++){
                Alloc().destroy(_data + index);
            }
            if (_capacity > 0){
                Alloc().deallocate(_data, _capacity);
            }
        }
         // Copy Operator
        myVector & operator=(const myVector & other){
            if (&other != this) {
                clear();
                if (_capacity > 0){
                    Alloc().deallocate(_data, _capacity);
                }
                _size = other._size;
                _capacity = other._capacity;
                _data = Alloc().allocate(_capacity);
                for (int index = 0; index < _size; index++){
                    Alloc().construct(_data + index, other._data[index]);
                }
            }
            return *this;
        }
         // Iterator
        typedef T * iterator;
        typedef const T * const_iterator;

        inline iterator begin(){
            return _data;
        }
        inline const_iterator begin() const{
            return _data;
        }
        inline iterator end(){
            return _data + _size;
        }
        inline const_iterator end() const{
            return _data + _size;
        }
         // Capacity
        inline std::size_t size(){
            return _size;
        }
        void resize(const std::size_t & newSize){
            if (_size == newSize) return;
            if (_size > newSize) {
                for (int index = newSize; index < _size; index++) {
                    Alloc().destroy(_data + index);
                }
            }
            else if (_size < newSize) {
                while (_capacity < newSize){
                    reserve(_capacity*2);
                }
                for (int index = _size; index < newSize; index++) {
                    Alloc().construct(_data + index, T());
                }
            }
            _size = newSize;
        }
        void resize(const std::size_t & newSize, const T & val){
            if (_size == newSize) return;
            else if (_size > newSize) {
                for (int index = newSize; index < _size; index++) {
                    Alloc().destroy(_data + index);
                }
            }
            else if (_size < newSize) {
                while (_capacity < newSize){
                    reserve(_capacity*2);
                }
                for (int index = _size; index < newSize; index++) {
                    Alloc().construct(_data + index, val);
                }
            }
            _size = newSize;
        }
        inline std::size_t capacity() const{
            return _capacity;
        }
        inline bool empty() const{
            return _size == 0;
        }
        void reserve(const std::size_t & newCapacity){
            if (_capacity >= newCapacity) return;
            else if (_capacity < newCapacity) {
                iterator newaddress = Alloc().allocate(newCapacity);
                for (int index = 0; index < _size; index++) {
                    Alloc().construct(newaddress + index, _data[index]);
                    Alloc().destroy(_data + index);
                }
                Alloc().deallocate(_data, _capacity);
                _capacity = newCapacity;
                _data = newaddress;
            }
        }
         // Element Access
        inline T & operator[](const std::size_t & index){
            return _data[index];
        }
        inline const T & operator[](const std::size_t & index) const{
            return _data[index];
        }
        inline T & front(){
            return _data[0];
        }
        inline const T & front() const{
            return _data[0];
        }   
        inline T & back(){
            return _data[_size - 1];
        }
        inline const T & back() const{
            return _data[_size - 1];
        }
        inline T * data(){
            return _data;
        }
        inline const T * data() const{
            return _data;
        }
         // Modifiers
        template<typename InputIterator>
        void assign(InputIterator begin, InputIterator end){
            int newSize(0);
            for (InputIterator iter = begin; iter != end; iter++) {
                newSize++;
            }
            while (_capacity < newSize){
                reserve(_capacity*2);
            }
            for (int index = 0; index < _size; index++) {
                Alloc().destroy(_data + index);
            }
            InputIterator iter = begin;
            for (int index = 0; index < newSize; index++, iter++){
                Alloc().construct(_data + index, *iter);
            }
            _size = newSize;
        }
        void assign(const std::size_t & newSize, const T & val){
            while(_capacity < newSize){
                reserve(_capacity*2);
            }
            for (int index = 0; index < _size; index++) {
                Alloc().destroy(_data + index);
            }
            for (int index = 0; index < newSize; index++) {
                Alloc().construct(_data + index, val);
            }
            _size = newSize;
        }
        void push_back(const T & val){
            while (_size >= _capacity){
                reserve(_capacity*2);
            }
            Alloc().construct(_data + _size, val);
            _size++;
        }
        void pop_back(){
            Alloc().destroy(_data + _size - 1);
            _size--;
        }
        void clear(){
            for (std::size_t index = 0; index < _size; index++){
                Alloc().destroy(_data + index);
            }
            _size = 0;
        }
     private:
        T * _data;
        std::size_t _size, _capacity;
};

#endif