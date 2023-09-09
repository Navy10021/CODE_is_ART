#include "oop.h"
#include <iostream>

// Bird Class Definitions
Bird::Bird(double wingspan) : wingspan_(wingspan) {}

Bird::~Bird() = default;

double Bird::GetWingspan() const {
    return wingspan_;
}

void Bird::SetWingspan(double wingspan) {
    wingspan_ = wingspan;
}

// Eagle Class Definitions
Eagle::Eagle(double wingspan) : Bird(wingspan) {
    speedFactor_ = 1.5;
}

double Eagle::Speed() const {
    return wingspan_ * speedFactor_;
}

void Eagle::PrintSelf() const {
    std::cout << "I am an Eagle, Wingspan = " << wingspan_ << ", Speed = " << Speed() << '\n';
}

// Falcon Class Definitions
Falcon::Falcon(double wingspan) : Bird(wingspan) {
    speedFactor_ = 1.2;
}

double Falcon::Speed() const {
    return wingspan_ * speedFactor_;
}

void Falcon::PrintSelf() const {
    std::cout << "I am a Falcon, Wingspan = " << wingspan_ << ", Speed = " << Speed() << '\n';
}

// Sparrow Class Definitions
Sparrow::Sparrow(double wingspan) : Bird(wingspan) {
    speedFactor_ = 1.0;
}

double Sparrow::Speed() const {
    return wingspan_ * speedFactor_;
}

void Sparrow::PrintSelf() const {
    std::cout << "I am a Sparrow, Wingspan = " << wingspan_ << ", Speed = " << Speed() << '\n';
}

// BirdNest Class Definitions
BirdNest::BirdNest() = default;

BirdNest::BirdNest(const BirdNest& other) {
    for (Bird* bird : other.birds_) {
        if (dynamic_cast<Eagle*>(bird)) {
            birds_.push_back(new Eagle(*dynamic_cast<Eagle*>(bird)));
        } else if (dynamic_cast<Falcon*>(bird)) {
            birds_.push_back(new Falcon(*dynamic_cast<Falcon*>(bird)));
        } else if (dynamic_cast<Sparrow*>(bird)) {
            birds_.push_back(new Sparrow(*dynamic_cast<Sparrow*>(bird)));
        }
    }
}
BirdNest::~BirdNest() {
    for (Bird* bird : birds_) {
        delete bird;
    }
}

void BirdNest::AddBird(Bird* aBird) {
    if (birds_.size() < 3) {
        birds_.push_back(aBird);
    } else {
        std::cout << "The nest is full, cannot add more birds.\n";
    }
}

double BirdNest::TotalSpeed() const {
    double totalSpeed = 0.0;
    for (const Bird* bird : birds_) {
        totalSpeed += bird->Speed();
    }
    return totalSpeed;
}

void BirdNest::PrintSelf() const {
    double totalWingspan = 0.0;
    for (const Bird* bird : birds_) {
        totalWingspan += bird->GetWingspan();
    }
    
    std::cout << "This nest has " << birds_.size() << " bird(s), Total Wingspan = " << totalWingspan << ", Total Speed = " << TotalSpeed() << '\n';
}
