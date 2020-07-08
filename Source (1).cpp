#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

using namespace std;

struct mech {
	float speed;
	float weight;
	float width;
	float length;
	float height;
	void printData() {
		cout << "Speed: " << speed << " ||| Weight: " << weight << " ||| Width: " << width << " ||| Length: " << length << " ||| Height: " << height << endl;
	}
};

class Creator {
	protected:
		static int id;
		string fullname;
		unsigned int YOB;
		vector<string> creations;
	public:
		Creator() {}
		Creator(string _fullname, unsigned int _YOB, string _arr) : fullname(_fullname), YOB(_YOB) {
			id++;
			string arr[15];
			int j = 0;
			stringstream SS(_arr);
			string buff;
			while (getline(SS, buff, '#')) {
				arr[j] = buff;
				j++;
			}
			for (int i = 0; i < j; i++) {
				this->creations.push_back(arr[i]);
			}
		}
		void printCreatData() {
			cout << "ID - " << id << endl;
			cout << "Fullname - " << fullname << endl;
			cout << "Year of birth - " << YOB << endl;
			cout << "Creations: ";
			for (auto const& val:creations) {
				cout << "   " << val;
			}
			cout << endl;
		}
		~Creator() { id--; }
};

int Creator::id = 0;

class Planes : public Creator {
	protected:
		static int id;
		string name;
		string code;
		vector<string> owner;
		string purpose;
		mech mech_res;
	public:
		Planes() {};
		Planes(string _name, string _code, string _purpose, mech *_res, string _owner, string _fullname, unsigned int _YOB, string _arr) : name(_name), code(_code), purpose(_purpose), mech_res(*_res) {
			string arr[15];
			int j = 0;
			stringstream SS(_owner);
			string buff;
			while (getline(SS, buff, '#')) {
				arr[j] = buff;
				j++;
			}
			for (int i = 0; i < j; i++) {
				this->owner.push_back(arr[i]);
			}
			id++;
			//cout << "ajiljinu? Medeej ajillana kkk";
			this->fullname = _fullname;
			this->YOB = _YOB;
			stringstream SD(_arr);
			while (getline(SD, buff, '#')) {
				arr[j] = buff;
				j++;
			}
			for (int i = 0; i < j; i++) {
				this->creations.push_back(arr[i]);
			}
		}
		void printPlaneData() {
			cout << id << endl;
			cout << fullname << endl;
			mech_res.printData();
		}
		~Planes() { id--; }
};

int Planes::id = 0;


int main() {
	mech tursh;
	tursh.height = 10.2;
	tursh.length = 20;
	tursh.speed = 10;
	tursh.weight = 12;
	tursh.width = 5.5;
	
	//Creator *creator = new Creator("Mikhael Sergeevich", 1943, "Mig-11#Mig-43#Mig-23");
	Planes *plane = new Planes("Mig", "Mig-34", "Military", &tursh, "MigCompany", "Mikhael Sergeevich", 1943, "Mig-11#Mig-43#Mig-23");

	//creator->printCreatData();
	plane->printPlaneData();

	//delete(creator);
	delete(plane);
	system("PAUSE");
	return 0;
}
