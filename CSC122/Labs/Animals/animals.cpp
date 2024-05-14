#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Base Class Life
class Life
{
protected:
	//protected members
	short health;
	short birthRate;
	short foodWorth;
	short age;
public :

	//accessors
	inline short getHealth(void)
	{
		return health;
	}
	inline short getBirthRate(void)
	{
		return birthRate;
	}
	inline short getFoodWorth(void)
	{
		return foodWorth;
	}
	inline short getAge(void)
	{
		return age;
	}

	//mutators
	inline bool setHealth(short newHealth)
	{
		bool okay = false;
		if (newHealth >= 0)
		{
			health = newHealth;
			okay = true;
		}
		return okay;
	}
	inline bool setBirthRate(short newBirthRate)
	{
		bool okay = false;
		if (newBirthRate >= 0)
		{
			birthRate = newBirthRate;
			okay = true;
		}
		return okay;
	}
	inline bool setFoodWorth(short newFoodWorth)
	{
		bool okay = false;
		if (newFoodWorth >= 0)
		{
			foodWorth = newFoodWorth;
			okay = true;
		}
		return okay;
	}
	inline bool setAge(short newAge)
	{
		bool okay = false;
		if (newAge >= 0)
		{
			age = newAge;
			okay = true;
		}
		return okay;
	}

	//default constructor
	Life()
		: health(10), birthRate(5), foodWorth(8), age(0)
	{
	}
	//copy constructor
	Life(const Life & obj)
		: health(obj.health), birthRate(obj.birthRate),
		foodWorth(obj.foodWorth), age(obj.age)
	{
		health = obj.health;
		birthRate = obj.birthRate;
		foodWorth = obj.foodWorth;
		age = obj.age;
	}

	//constructors
	Life(short newHealth, short newBirthRate, short newFoodWorth, short newAge)
		: health(newHealth), birthRate(newBirthRate), foodWorth(newFoodWorth),
		age(newAge)
	{
		setHealth(newHealth);
		setBirthRate(newBirthRate);
		setFoodWorth(newFoodWorth);
		setAge(newAge);
	}
	//methods

};

//Class Plant derived from base class Life
class Plant : public Life
{
protected:
	//protected members
	string plantName;
public:
	
	//accessors
	string getName(void)
	{
		return plantName;
	}

	//mutators
	bool setName(string newName)
	{
		bool okay = true;
		plantName = newName;
		return okay;
	}

	//default constructor
	Plant()
		:plantName("")
	{
	}

	//copy constructor
	Plant(const Plant& obj)
		: Life(obj.health, obj.birthRate, obj.foodWorth, obj.age), 
		  plantName(obj.plantName)
	{
		health = obj.health;
		birthRate = obj.birthRate;
		foodWorth = obj.foodWorth;
		age = obj.age;
		plantName = obj.plantName;
	}
	//constructor
	Plant(short newHealth, short newBirthRate, short newFoodWorth, 
		  short newAge, string newName)
		: Life(newHealth,newBirthRate,newFoodWorth, newAge), 
		plantName(newName)
	{
		setHealth(newHealth);
		setBirthRate(newBirthRate);
		setFoodWorth(newFoodWorth);
		setAge(newAge);
		setName(newName);
	}
};

//Class Animal derived from base class Life
class Animal : public Life
{
protected:
	short hunger;
	short speed;
public:
	
	//accessor
	inline short getHunger(void)
	{
		return hunger;
	}
	inline short getSpeed(void)
	{
		return speed;
	}

	//mutators
	inline bool setHunger(short newHunger)
	{
		bool okay = false;
		if (newHunger >= 0)
		{
			hunger = newHunger;
			okay = true;
		}
		return okay;
	}
	inline bool setSpeed(short newSpeed)
	{
		bool okay = false;
		if (newSpeed >= 0)
		{
			hunger = newSpeed;
			okay = true;
		}
		return okay;
	}
	//default constructor
	Animal()
		: hunger(5), speed(6)
	{
	}
	//copy constructoy
	Animal(const Animal& obj)
		:Life(obj.health, obj.birthRate, obj.foodWorth, obj.age), 
		 hunger(obj.hunger), speed(obj.speed)
	{
		health = obj.health;
		birthRate = obj.birthRate;
		foodWorth = obj.foodWorth;
		age = obj.age;
		hunger = obj.hunger;
		speed = obj.speed;
	}
	//constructors
	Animal(short newHealth, short newBirthRate, short newFoodWorth, short newAge,
		   short newHunger, short newSpeed)
		:Life(newHealth, newBirthRate, newFoodWorth, newAge), 
		 hunger(newHunger), speed(newSpeed)
	{
		setHealth(newHealth);
		setBirthRate(newBirthRate);
		setFoodWorth(newFoodWorth);
		setAge(newAge);
		setHunger(newHunger);
		setSpeed(newSpeed);
	}
	
};
//Class Prey derived from parent class Animal
class Prey : public Animal
{
protected:
	short evade;
	string preyName;
public:

	//accessor
	short getEvade(void)
	{
		return evade;
	}

	string getPreyName(void)
	{
		return preyName;
	}

	//mutators
	inline bool setEvade(short newEvade)
	{
		bool okay = false;
		if (newEvade >= 0)
		{
			evade = newEvade;
			okay = true;
		}
		return okay;
	}
	inline bool setPreyName(string newName)
	{
		bool okay = true;
		preyName = newName;
		return okay;
    }

	//constructors
	Prey()
		: evade(5), preyName("")
	{

	}
	//copy constructor
	Prey(const Prey& obj)
		: Animal(obj.health, obj.birthRate, obj.foodWorth, obj.age,
			obj.hunger, obj.speed), evade(obj.evade), preyName(obj.preyName)
	{
		health = obj.health;
		birthRate = obj.birthRate;
		foodWorth = obj.foodWorth;
		age = obj.age;
		hunger = obj.hunger;
		speed = obj.speed;
		evade = obj.evade;
		preyName = obj.preyName;
	}
	Prey(short newHealth, short newBirthRate, short newFoodWorth, short newAge,
		short newHunger, short newSpeed, short newEvade, string newPreyName)
		:Animal(newHealth, newBirthRate, newFoodWorth, newAge,
			   newHunger, newSpeed), evade(newEvade), preyName(newPreyName)
	{
		setHealth(newHealth);
		setBirthRate(newBirthRate);
		setFoodWorth(newFoodWorth);
		setAge(newAge);
		setHunger(newHunger);
		setSpeed(newSpeed);
		setEvade(newEvade);
		setPreyName(newPreyName);
	}
	
};
//Class Pred derived from parent class Animal
class Pred : public Animal
{
protected:
	short attack;
	string predName;
public:

	//accessor
	short getAttack(void)
	{
		return attack;
	}

	string getPredName(void)
	{
		return predName;
	}

	//mutators
	inline bool setAttack(short newAttack)
	{
		bool okay = false;
		if (newAttack >= 0)
		{
			attack = newAttack;
			okay = true;
		}
		return okay;
	}
	inline bool setPredName(string newName)
	{
		bool okay = true;
		predName = newName;
		return okay;
	}

	//constructors
	Pred()
		: attack(5), predName("")
	{

	}
	//copy constructor
	Pred(const Pred & obj)
		: Animal(obj.health, obj.birthRate, obj.foodWorth, obj.age,
			obj.hunger, obj.speed), attack(obj.attack), predName(obj.predName)
	{
		health = obj.health;
		birthRate = obj.birthRate;
		foodWorth = obj.foodWorth;
		age = obj.age;
		hunger = obj.hunger;
		speed = obj.speed;
		attack = obj.attack;
		predName = obj.predName;
	}
	//constructor
	Pred(short newHealth, short newBirthRate, short newFoodWorth, short newAge,
		short newHunger, short newSpeed, short newAttack, string newPredName)
		:Animal(newHealth, newBirthRate, newFoodWorth, newAge, newHunger,
			newSpeed), attack(newAttack), predName(newPredName)
	{
		setHealth(newHealth);
		setBirthRate(newBirthRate);
		setFoodWorth(newFoodWorth);
		setAge(newAge);
		setHunger(newHunger);
		setSpeed(newSpeed);
		setAttack(newAttack);
		setPredName(newPredName);
	}
};

//function prototypes
vector<Plant> makePlant(string name, short size, short health,
	short birthRate, short foodWorth, short age);
vector<Prey> makePrey(string name, short size, short health, short birthRate,
	short foodWorth, short age, short hunger, short speed, short evade);
vector<Pred> makePred(string name, short size, short health, short birthRate,
	short foodWorth, short age, short hunger, short speed, short attack);
void printPlant(vector<Plant> vec);
void printPrey(vector<Prey> vec);
void printPred(vector<Pred> vec);
void plantDies(vector<Plant> & vec);
void preyDies(vector<Prey> & vec);
void predDies(vector<Pred> & vec);



//Main Function
int main(void)
{
	//decalring variables
	vector<Pred> wolf;
	vector<Prey> bunny;
	vector<Plant> grass;
	
	//constructiong objects into vectors
	grass = makePlant("Grass", 15, 10, 15, 5, 0);
	bunny = makePrey("Bunny", 10, 10, 14, 10, 0, 10, 20, 10);
	wolf = makePred("Wolf", 5, 15, 5, 10, 0, 10, 15, 10);

	//displaying all objects stats
	printPlant(grass);
	printPrey(bunny);
	printPred(wolf);

	//displaying the number of each type of objects
	cout << "Grasss Alive: " << grass.size() << endl;
	cout << "Bunnys Alive: " << bunny.size() << endl;
	cout << "Wolves Alive: " << wolf.size() << endl;

	//killing a wolf by setting the health to 0
	wolf[2].setHealth(0);	
	cout << "A Wolf just died!\n";
	//updating count
	predDies(wolf);
	cout << "Grasss Alive: " << grass.size() << endl;
	cout << "Bunnys Alive: " << bunny.size() << endl;
	cout << "Wolves Alive: " << wolf.size() << endl;
	

	return 0;
}

//function definitions
vector<Plant> makePlant(string name, short size, short health, 
	short birthRate, short foodWorth, short age)
{
	vector<Plant> plants;
	Plant plant(health, birthRate, foodWorth, age, name);

	for (vector<Plant>::size_type i = 0; static_cast<short>(i) < size; i++)
	{
		plants.push_back(plant);

	}
	return plants;
}

vector<Prey> makePrey(string name, short size, short health, short birthRate, 
	short foodWorth, short age, short hunger, short speed, short evade)
{
	vector<Prey> preys;
	Prey prey(health, birthRate, foodWorth, age, hunger, speed, evade, name);

	for (vector<Prey>::size_type i = 0; static_cast<short>(i) < size; i++)
	{
		preys.push_back(prey);

	}
	return preys;
}

vector<Pred> makePred(string name, short size, short health, short birthRate,
	short foodWorth, short age, short hunger, short speed, short attack)
{
	vector<Pred> preds;
	Pred pred(health, birthRate, foodWorth, age, hunger, speed, attack, name);

	for (vector<Prey>::size_type i = 0; static_cast<short>(i) < size; i++)
	{
		preds.push_back(pred);

	}
	return preds;
}

void printPlant(vector<Plant> vec)
{
	for (vector<Plant>::size_type i = 0; i < vec.size(); i++)
	{
		cout << "Health: " << vec[i].getHealth() << "\nBirth Rate: "
			<< vec[i].getBirthRate() << "\nFood Worth: " 
			<< vec[i].getFoodWorth() << "\nAge: "
			<< vec[i].getAge() << "\nName: " 
			<< vec[i].getName() << i+1 << endl;
	}

	cout << "Created " << vec.size() << " plants!\n";
}

void printPrey(vector<Prey> vec)
{
	for (vector<Prey>::size_type i = 0; i < vec.size(); i++)
	{
		cout << "Health: " << vec[i].getHealth() << "\nBirth Rate: "
			<< vec[i].getBirthRate() << "\nFood Worth: "
			<< vec[i].getFoodWorth() << "\nAge: "
			<< vec[i].getAge() << "\nHunger: "
			<< vec[i].getHunger() << "\nSpeed: "
			<< vec[i].getSpeed() << "\nEvade: " 
			<< vec[i].getEvade() << "\nName: "
			<< vec[i].getPreyName() << i + 1 << endl;
	}

	cout << "Created " << vec.size() << " prey!\n";
}

void printPred(vector<Pred> vec)
{
	for (vector<Pred>::size_type i = 0; i < vec.size(); i++)
	{
		cout << "Health: " << vec[i].getHealth() << "\nBirth Rate: "
			<< vec[i].getBirthRate() << "\nFood Worth: "
			<< vec[i].getFoodWorth() << "\nAge: "
			<< vec[i].getAge() << "\nHunger: "
			<< vec[i].getHunger() << "\nSpeed: "
			<< vec[i].getSpeed() << "\nAttack: "
			<< vec[i].getAttack() << "\nName: " 
			<< vec[i].getPredName() << i + 1 << endl;
	}

	cout << "Created " << vec.size() << " Preds!\n";
}

void plantDies(vector<Plant> & vec)
{

	for (vector<Plant>::size_type i = 0; i < vec.size(); i++)
	{
		if (vec[i].getHealth() == 0)
		{
			vec.erase(vec.begin() + i);
			i--;
		}

	}
}
void preyDies(vector<Prey> & vec)
{

	for (vector<Prey>::size_type i = 0; i < vec.size(); i++)
	{
		if (vec[i].getHealth() == 0)
		{
			vec.erase(vec.begin() + i);
			i--;
		}

	}
}

void predDies(vector<Pred> & vec)
{
	for (vector<Pred>::size_type i = 0; i < vec.size(); i++)
	{
		if (vec[i].getHealth() == 0)
		{
			vec.erase(vec.begin() + i);
			i--;
		}
	}
}
