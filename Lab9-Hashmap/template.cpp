#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template <class Name, class Value>
class VectorMap {
	private:
	vector<Name> name_vector;
	vector <Value> value_vector;
	
	public:
	void printit() {
		for(int i = 0; i < name_vector.size(); i++) {
			cout << "name["<<i<<"]"<<name_vector[i]<<endl;
			cout << "value["<<i<<"]"<<value_vector[i]<<endl;
		}
	}
	Value operator[](Name opname) {
		return at(opname);
	}
	Value at(Name name) {
		for(int i = 0; i < name_vector.size(); i++) {
			if(name_vector[i]==name) {
				return value_vector[i];
			}
		}
		return NULL;
	}
	void set(Name myName, Value myValue) {
		name_vector.push_back(myName);
		value_vector.push_back(myValue);
	}
};
int main()
{
	
	VectorMap <string, string>foo;
	foo.printit();
	foo.set("Hello","goodbye");
	foo.printit();
	foo.set("Seeya","Later");
	cout << "value for Hello "<<foo.at("Hello")<<endl;
	cout << "value for Seeya "<<foo.at("Seeya")<<endl;
	cout << foo.operator[]("Hello")<<endl;
	cout << foo["Hello"]<<endl;
}