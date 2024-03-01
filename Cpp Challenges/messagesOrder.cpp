#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

class Message {
public: 
    Message() {}
    static int staticOrder;
    int order=staticOrder;
    const string& get_text() const {
        return message;
    }
    void set_text(const string& text){
        message = text;
        staticOrder++;
    }
    friend bool operator<(const Message& message1,const Message& message2){
    
        if (message1.order > message2.order)
            return false;
        
        return true;     
    }
private:
    string message;     
};
int Message::staticOrder=0;


class MessageFactory{
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message temp;
        temp.set_text(text);
        return temp;
    }
      
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
