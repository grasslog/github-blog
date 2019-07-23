#include <vector>

class Observer
{
public: 
    virtual ~Observer();
    virtual void update() = 0;

    void observer(Observable* s)
    {
        s->register_(this);
        subject_->unregister(this);
    }

    Observable* subject_;
};

class Observable
{
public:
    void register_(Observer* x);
    void unregister(Observer* x);

    void notifyObservers() 
    {
        for(Observer* x : observers_)
        {
            x->update();
        }
    }

private:
    std::vector<Observer*> observers_;
};