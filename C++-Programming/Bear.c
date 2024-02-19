#pragma once
// #pragma once // A non-standard but widely supported preprocessor directive 
             // designed to cause the current source file to be included 
             // only once in a single compilation
/*
BEAR
Your Basic Bear. Its abstraction is that it has a weight property that
can be get and set. The bear also responds to the Meanness() message
that tells the client how mad the bear is currently.
*/

class Bear {

protected:
    float weight = 0;  // We could make this private: and so make Mommabear 

    float aggressiveness = 0;

    int BearType = 0; // 0=Polar, 1=Grizzly, 2=Black, 3=Mom Bear
    float TotalAggressiveness = 0;

    int CubCnt = 0;
    
    Bear* Cub0;
    Bear* Cub1;

public:
    Bear(float aWeight);            // Constructor

    void SetBearType(int aBearType);

    float GetWeight(void);          // accessors 
    void SetWeight(float aWeight);  // Weight

    void SetAggressiveness(void);

    void AddCub(Bear *aCub);

    void PrintSelf(void);

};


class Polar : public Bear {
public:
    Polar(float aWeight) : Bear(aWeight) {
        this->BearType = 0;
        this->SetAggressiveness();
    };
};


class Grizzly : public Bear {
public:
    Grizzly(float aWeight) : Bear(aWeight) {
        this->BearType = 1;
        this->SetAggressiveness();
    };
};

class Black : public Bear {
public:
    Black(float aWeight) : Bear(aWeight) {
        this->BearType = 2;
        this->SetAggressiveness();
    };
};


class Black_Momma : public Bear {
public:
    Black_Momma(float aWeight) : Bear(aWeight) {
        this->BearType = 3;
        this->SetAggressiveness();
    };
};


#include <stdio.h> 
#include <stdlib.h> 
#include "NewBear.h"


// Fill in here
/*** Constructor ***/
Bear::Bear(float aWeight) {	
	this->SetWeight(aWeight);
}

/*** Accessors ***/
void Bear::SetWeight(float aWeight) {
	weight = aWeight;
}

float Bear::GetWeight(void) {
	return(weight);
}

void Bear::SetBearType(int aBearType) {
	BearType = aBearType;
}

/*** Aggressiveness ***/
void Bear::SetAggressiveness() {
	if (BearType == 0)
		aggressiveness = weight * 1;

	else if (BearType == 1)
		aggressiveness = weight * 0.9;

	else if (BearType == 2)
		aggressiveness = weight * 0.7;

	else if (BearType == 3)
		aggressiveness = weight * 0.7 * 2;
		
		if (CubCnt == 0)
			TotalAggressiveness = aggressiveness;
		else if(CubCnt == 1)
			TotalAggressiveness = aggressiveness + Cub0->aggressiveness;
		else if(CubCnt == 2)
			TotalAggressiveness = aggressiveness + Cub0->aggressiveness + Cub1->aggressiveness;
}

void Bear::AddCub(Bear* aCub) {
	if (this->CubCnt == 0)
	{
		this->Cub0 = aCub;
		CubCnt++;
	}
	else if (this->CubCnt == 1)
	{
		this->Cub1 = aCub;
		CubCnt++;
	}
	this->SetAggressiveness();
}

void Bear::PrintSelf(void) {
	if (this->BearType == 0)
		printf("I am Polar bear, Weight=%f, Aggressiveness=%f\n", this->weight, this->aggressiveness);

	else if (this->BearType == 1)
		printf("I am Grizzly bear, Weight=%f, Aggressiveness=%f\n", this->weight, this->aggressiveness);

	else if (this->BearType == 2)
		printf("I am Black bear, Weight=%f, Aggressiveness=%f\n", this->weight, this->aggressiveness);

	else if (this->BearType == 3)
		printf("I am Black Mommabear with %d cub(s), Weight=%f, Aggressiveness=%f, Total Aggressiveness=%f\n", CubCnt, weight, aggressiveness, TotalAggressiveness);

}
