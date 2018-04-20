#include <iostream>
#include <vector>
using namespace std;
template <class Name, class Value>
class VectorMap {
  private:
	vector<Name> name_vector;
	vector <Value> value_vector;
	
  public:
	Value &operator[](Name opname) {
		return at(opname);
	}
	Value &at(Name name) {
	    // O(n)
		for(int i = 0; i < name_vector.size(); i++) {
			if(name_vector[i]==name) {
				return value_vector[i];
			}
		}
		// If it doesnt exist, create it.
		name_vector.push_back(name);
		Value emptyval;
		value_vector.push_back(emptyval);
		return value_vector.back();
	}
};