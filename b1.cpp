#include<iostream>
#include<vector>
using namespace std;

struct mech{
	float speed;
	float weight;
	float width;
	float length;
	float height;
};
class planes {
	public:
		int id;
		char *name;
		char *code;
		vector<string> owner;
		char *purpose;
		mech mech_res;
		planes(10, "ner1", "code",){
			
		}
		
};
class creator: public planes{
	public:
		char *fullname;
		unsigned int YOB;
		vector<string> creations;
		
};
int main(){
	
	return 0;
}