#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Event {
protected:
    string title, date, location;

public:
    Event(string title, string date, string location) 
        : title(title), date(date), location(location) {}

    virtual void display() const {
        cout << "Event: " << title << "\nDate: " << date << "\nLocation: " << location << endl;
    }

    virtual ~Event() {}
};

class Workshop : public Event {
    string speaker;

public:
    Workshop(string title, string date, string location, string speaker)
        : Event(title, date, location), speaker(speaker) {}

    void display() const override {
        cout << "[Workshop] ";
        Event::display();
        cout << "Speaker: " << speaker << endl;
    }
};

class Conference : public Event {
    int numberOfDays;

public:
    Conference(string title, string date, string location, int numberOfDays)
        : Event(title, date, location), numberOfDays(numberOfDays) {}

    void display() const override {
        cout << "[Conference] ";
        Event::display();
        cout << "Duration: " << numberOfDays << " days" << endl;
    }
};

class Meetup : public Event {
    string topic;

public:
    Meetup(string title, string date, string location, string topic)
        : Event(title, date, location), topic(topic) {}

    void display() const override {
        cout << "[Meetup] ";
        Event::display();
        cout << "Topic: " << topic << endl;
    }
};

int main() {
    vector<Event*> events;
    
    events.push_back(new Workshop("C++ Best Practices", "2023-10-05", "New York", "Jane Doe"));
    events.push_back(new Conference("Tech Innovations 2023", "2023-11-15", "San Francisco", 3));
    events.push_back(new Meetup("Local Startups", "2023-09-20", "Los Angeles", "Emerging Technologies"));

    for (Event* event : events) {
        event->display();
        cout << endl;
    }

    // Clean up dynamically allocated memory
    for (Event* event : events) {
        delete event;
    }
    events.clear();

    return 0;
}