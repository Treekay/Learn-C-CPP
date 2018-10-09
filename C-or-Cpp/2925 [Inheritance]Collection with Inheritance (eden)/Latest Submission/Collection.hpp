 #ifndef _COLLECTION_H
#define _COLLECTION_H

class Collection {
public:
	typedef int E;
	Collection(){}
	virtual ~Collection() {}
	virtual void add(E e) = 0;
	virtual void clear(void) = 0;
	virtual bool contain(E e) = 0;
	virtual bool isEmpty(void)= 0;
	virtual void remove(E e) = 0;
	virtual int size(void) = 0;
    void qsort(E *arr, E left, E right) {
        if (left >= right) {
            return;
        }
        E i = left;
        E j = right;
        E key = arr[left];
        while(i < j) {
            while (key <= arr[j] && i < j) {
                j--;
            }
            arr[i] = arr[j];
            while (key >= arr[i] && i < j) {
                i++;
            }
            arr[j] = arr[i];
        }
        arr[i] = key;
        qsort(arr, left, i - 1);
        qsort(arr, i + 1, right);
    }  
};

#endif