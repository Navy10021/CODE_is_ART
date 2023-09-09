# include <stdio.h>
# include <stdlib.h>

class Bear{
    public:
        Bear(float aWeight);    // Constructor

        void SetWeight(float aWeight);  // accessors
        float GetWeight(void);
        virtual float Aggressiveness(void);  // 가상함수, 동적바인딩
        virtual void PrintSelf() = 0;        // 가상함수, 동적바인딩
    
    protected:
        float weight;
};

class Polar : public Bear{
    public:
        Polar(float aWeight) : Bear(aWeight) {};    // Constructor
        void PrintSelf();
};

class Grizzly : public Bear{
    public:
        Grizzly(float aWeight) : Bear(aWeight) {};  // Constructor

        float Aggressiveness(void);
        void PrintSelf();  
};

class Black : public Bear{
    public:
        Black(float aWeight) : Bear(aWeight) {};    // Constructor

        virtual float Aggressiveness(void);
        void PrintSelf();       
};

class Black_Momma : public Black{
    public:
        Black_Momma(float aWeight) : Black(aWeight){
            int nCub = 0;
            cub1 = NULL;
            cub2 = NULL;
        };       // Constructor

        void AddCub(Black* aCub);   // Black bear를 받는 함수
        float Aggressiveness(void);
        float TotalAggressiveness(void);
        void PrintSelf();

    protected:
        Black *cub1;
        Black *cub2;
        int nCub;
};


/*---- Bear -----*/
// Constructor
Bear::Bear(float aWeight){
    weight = aWeight;
}
// accessors
void Bear::SetWeight(float aWeight){
    weight = aWeight;
}

float Bear::GetWeight(void){
    return weight;
}

float Bear::Aggressiveness(void){
    return weight;
}

/*---- Polar -----*/
void Polar::PrintSelf(){
    // Bear의 Weight와 Agressiveness*1 을 그대로 사용
    printf("I am Polar bear, Weith = %f, Aggressiveness = %f\n", weight, Aggressiveness());
}

/*---- Grizzly -----*/
float Grizzly::Aggressiveness(void){
    return (Bear::Aggressiveness() * 0.9);
}

void Grizzly::PrintSelf(){
    // Bear의 Weight와 Agressiveness*1 을 그대로 사용
    printf("I am Grizzly bear, Weith = %f, Aggressiveness = %f\n", weight, Aggressiveness());
}

/*---- BLACK -----*/
float Black::Aggressiveness(void){
    return (Bear::Aggressiveness() * 0.7);
}

void Black::PrintSelf(){
    printf("I am Black bear, Weith = %f, Aggressiveness = %f\n", weight, Aggressiveness());
}

/*---- BLACK Momma-----*/
void Black_Momma::AddCub(Black *aCub){
    if (nCub == 0)
        cub1 = aCub;
    else
        cub2 = aCub;
    nCub++;   
}

float Black_Momma::Aggressiveness(void){
    if (nCub == 0){
        return Black::Aggressiveness();
    }
    else{
        return Black::Aggressiveness() * 2;
    }
}

float Black_Momma::TotalAggressiveness(void){
    float cubA1 = 0;
    float cubA2 = 0;

    if (nCub == 0){
        cubA1 = 0;
        cubA2 = 0;
    }

    else if (nCub == 1){
        cubA1 = cub1->Aggressiveness();
        cubA2 = 0;
    }

    else{
        cubA1 = cub1->Aggressiveness();
        cubA2 = cub2->Aggressiveness();
    }
    return (Aggressiveness() + cubA1 + cubA2);
}

void Black_Momma::PrintSelf(){
    printf("I am Black Momma bear with %d cub(s), Weith = %f, Aggressiveness = %f, Total Aggressiveness = %f\n", nCub, weight, Aggressiveness(), TotalAggressiveness());
}


int main(){
    Bear* B1 = new Polar(450);
    Bear* B2 = new Grizzly(300);
    Black_Momma* B3 = new Black_Momma(100);

    Black* cub1 = new Black(50);
    Black* cub2 = new Black(25);

    B3->AddCub(cub1);
    B3->AddCub(cub2);

    B1->PrintSelf();
    B2->PrintSelf();
    B3->PrintSelf();

    /*
    delete B1;
    delete B2;
    delete B3;
    delete cub1;
    delete cub2;

    return EXIT_SUCCESS;*/
}
