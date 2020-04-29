#undef debug

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;
int PrintBST(list<int>& printList);
int PrintBST(list<string>& printList);

template<typename T>
class BSTNode {

public:
	// Constructors, etc.
	BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
	BSTNode(BSTNode&); // copy constructor
    ~BSTNode(); // destructor
	BSTNode& operator= (BSTNode&); // copy assignment operator

	// ***** Your group will define/implement the insert function
	// ***** at about line 89 below...
	void insert(const T& data);

	// Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
	BSTNode<T>* getRight() const { return _right; }
	T& getData() const { return _data; }
	void setData(const T& data) { _data = data; }

	// Display functions used by operator<<.
	// ***** Your group will define/implement the pre & post display functions
	// ***** at about lines 114 & 127 below...
	void inOrderDisplay(ostream&) const;
	void preOrderDisplay(ostream&) const;
	void postOrderDisplay(ostream&) const;

	// List member function
	void listify(list<T>&) const;

	// The insertion operator below uses in-order display.
	// ***** Change the implementation of this insertion operator
	// ***** in order to switch to pre- or post-order display
	friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
		{ b.inOrderDisplay(out); return out; }

private:
	T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;

	// private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
	void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
	cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
	delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy assignment operator: ";
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
	return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
#ifdef debug
	cout << "BSTNode<T>::insert called with data == " << data << endl;
#endif

	if (data < _data) {
		if (getLeft() !=nullptr){
			_left->insert(data);
		}
		else{
			addLeft(data);
		}
	}
	if (data > _data) {
		if (getRight() !=nullptr){
			_right->insert(data);
		}
		else{
			addRight(data);
		}
	}
}


template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
 if (_left != nullptr) {
	    _left->inOrderDisplay(out);
	    out << ", ";
	}
	out << _data;
	if (_right != nullptr) {
	    out << ", ";
	    _right->inOrderDisplay(out);
	}
}


/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
	#ifdef debug
	cout << "BSTNode<T>::preOrderDisplay called\n";
	#endif

	out << _data;
	if (_left != nullptr){
		out << ", ";
		_left->preOrderDisplay(out);
	}
	if (_right != nullptr){
		out << ", ";
		_right->preOrderDisplay(out);
	}
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
	#ifdef debug
	cout << "BSTNode<T>::postOrderDisplay called\n";
	#endif

	if (_left != nullptr){
		_left->postOrderDisplay(out);
		out << ", ";
	}
	if (_right != nullptr){
		_right->postOrderDisplay(out);
		out << ", ";
	}
	out << _data;
}

template<typename T>
void BSTNode<T>::listify(list<T>& tempList) const {
	//using values to list in order if left--push--if right
	// preorder = push--if left--if right
	// postorder = if left--if right--push
 	if (_left != nullptr){
		_left->listify(tempList);
	}
	tempList.push_back(_data);
	if (_right != nullptr){
		_right->listify(tempList);
	}

}


int main(void) {
	BSTNode<int> iroot(100);
	iroot.insert(10);
	iroot.insert(20);
	iroot.insert(200);
	iroot.insert(300);
	cout << "iroot == " << iroot << endl;

	BSTNode<string> sroot("Sunday");
	sroot.insert("Monday");
	sroot.insert("Tuesday");
	sroot.insert("Wednesday");
	sroot.insert("Thursday");
	sroot.insert("Friday");
	sroot.insert("Saturday");
	cout << "sroot == " << sroot << endl << endl;

	cout << "Creating irootList via iroot.listify" << endl;
	list<int>irootList;
	iroot.listify(irootList);
	PrintBST(irootList);
	cout << endl;

	cout << "Creating srootList via sroot.listify" << endl;
	list<string>srootList;
	sroot.listify(srootList);
	PrintBST(srootList);
	cout << endl;
	
	BSTNode<int> iroot4(1000);
	iroot4.insert(2000);
	iroot4.insert(3000);
	iroot4.insert(4000);
	iroot4.insert(5000);
	cout << "iroot4 == " << iroot4 << endl;
	cout << "Creating iroot4List via iroot4.listify" << endl;
	list<int>iroot4List;
	iroot4.listify(iroot4List);

	//creating map
	map<string, list<int>> mi;
	mi.emplace("iroot4List", iroot4List);
	mi.emplace("irootList", irootList);

	//Printing map
	cout << "Contents of map<string, list<int>> mi (using ranged for loops): " << endl;
	for (auto& printMap: mi){
		cout << printMap.first <<": ";
			for (int& i : printMap.second){
				cout << i << " ";
			}
		cout << endl;
	}
	cout << "mi[irootList] == " ;
	for (auto mit = mi["irootList"].begin(); mit != mi["irootList"].end(); ++mit){
		cout << " " << *mit;
	}
	cout << endl;
	cout << "mi[iroot4List] == " ;
	for (auto mit = mi["iroot4List"].begin(); mit != mi["iroot4List"].end(); ++mit){
		cout << " " << *mit;
	}




#ifdef debug
	BSTNode<int> iroot2(iroot); // use copy constructor
	cout << "\nAfter copy constructor:\n";
	cout << "iroot2 == " << iroot2 << endl;

	BSTNode<int> iroot3;
	iroot3 = iroot2; // use copy assignment operator
	cout << "\nAfter copy assignment operator:\n";
	cout << "iroot3 == " << iroot3 << endl << endl;
#endif

	return 0;
}

int PrintBST(list<int>& printList){
	// listing elements with forward iterator
	cout << "irootList (forward iterator) == ";
	for (auto it = printList.begin(); it != printList.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//listing elements with reverse iterator
	cout << "irootList (reverse iterator) == ";
	for (auto rit = printList.rbegin(); rit != printList.rend(); rit++){
		cout << *rit << " ";
	}
	cout << endl;

	//listing elements with range for loop
	cout << "irootList (ranged for loop) == ";
	for (int& i : printList ){
		cout << i << " ";
	}
	cout << endl;
}

int PrintBST(list<string>& printList){
	// listing elements with forward iterator
	cout << "srootList (forward iterator) == ";
	for (auto it = printList.begin(); it != printList.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//listing elements with reverse iterator
	cout << "srootList (reverse iterator) == ";
	for (auto rit = printList.rbegin(); rit != printList.rend(); rit++){
		cout << *rit << " ";
	}
	cout << endl;

	//listing elements with range for loop
	cout << "srootList (ranged for loop) == ";
	for (const string& i : printList){
		cout << i << " ";
	}
	cout << endl;
}

