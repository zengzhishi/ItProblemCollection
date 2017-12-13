//猫狗队列
/*JAVA 代码
public class Pet {  
    private String type;  
    public Pet(String type){  
        this.type = type;  
    }  
    public String getPetType(){  
        return this.type;  
    }  
}  
public class Dog extends Pet {  
  
    public Dog() {  
        super("dog");  
    }  
  
}  
public class Cat extends Pet {  
  
    public Cat(String type) {  
        super("cat");  
  
    }  
  
}  
*/
//实现一种猫狗队列的结构，要求如下：
//1 用户可以调用add方法将cat类或者dog类的实例放入队列中；
//2 用户可以调用pollAll方法，将队列中所有的实例按照队列的先后顺序依次弹出；
//3 用户可以调用pollDog方法，将队列中dog类的实例按照队列的先后顺序依次弹出；
//4 用户可以调用pollCat方法，将队列中cat类的实例按照队列的先后顺序依次弹出；
//5 用户可以调用isEmpty方法，检查队列中是否还有dog和cat的实例；
//6 用户可以调用isDogEmpty方法，检查队列中是否还有do的实例；
//7 用户可以调用isCatEmpty方法，检查队列中是否还有cat的实例。

#include <iostream>
#include <queue>

using namespace std;

class Pet {  
private: 
    string type;  

public:
    Pet(string pet_type){  
        type = pet_type;  
    }  

    string getPetType(){  
        return type;  
    }  

//   virtual string say() {};
}; 

class Dog: public Pet {
//private:
//    string color;
public:
    Dog(string type): Pet(type){};
//   Dog(string type, string color): Pet(type) {
//      this->color = color;
//   };

//    virtual string say() {
//        return "I am " + Pet::getPetType() + ".";
//    }
};

class Cat: public Pet {
public:
    Cat(string type): Pet(type){};
};

class PetEnterTime {
private:
    Pet *pet;
    long time;

public:
    PetEnterTime(Cat &cat, long time) {
        this->pet = &cat;
        this->time = time;
    }
    
    PetEnterTime(Dog &dog, long time) {
        this->pet = &dog;
        this->time = time;
    }

    Pet* getPet() {
        return pet;
    }

    long getTime() {
        return time;
    }

    string getPetType() {
        return pet->getPetType(); 
    }
};

class PetQueue {
private:
    queue<PetEnterTime> cat_queue;
    queue<PetEnterTime> dog_queue;
    long count;

public:
    PetQueue() {
        count = 0;
    }

    void add(Cat &cat) {
        PetEnterTime petTime(cat, count++);
        cat_queue.push(petTime);
    }

    void add(Dog &dog) {
        PetEnterTime petTime(dog, count++);
        dog_queue.push(petTime);
    }

    Pet* pollAll() {
        Pet *pet;
        if (cat_queue.empty() && cat_queue.empty()) {
            throw "Queue is empty!";
        } else if (cat_queue.empty()) {
            pet = dog_queue.front().getPet();
            dog_queue.pop();
            return pet;
        } else if (dog_queue.empty()) {
            pet = cat_queue.front().getPet();
            cat_queue.pop();
            return pet;
        } else {
            if (dog_queue.front().getTime() < cat_queue.front().getTime()) {
                pet = dog_queue.front().getPet();
                dog_queue.pop();
                return pet;
            } else {
                pet = cat_queue.front().getPet();
                cat_queue.pop();
                return pet;
            }
        }
    }

    Pet* pollDog() {
        if (!dog_queue.empty()) {
                Pet *pet = dog_queue.front().getPet();
                dog_queue.pop();
                return pet;
        } else {
            throw "Dog queue is empty!";
        }
    }

    Pet* pollCat() {
        if (!cat_queue.empty()) {
                Pet *pet = cat_queue.front().getPet();
                cat_queue.pop();
                return pet;
        } else {
            throw "Cat queue is empty!";
        }
    }

    bool isEmpty() {
        return cat_queue.empty() && dog_queue.empty();
    }

    bool isDogQueueEmpty() {
        return dog_queue.empty();
    }

    bool isCatQueueEmpty() {
        return cat_queue.empty();
    }
};

int main () {
    Dog dog1("dog1");
    Dog dog2("dog2");
    Cat cat1("cat1");
    Cat cat2("cat2");
    Cat cat3("cat3");


    PetEnterTime *pa = new PetEnterTime(dog1, 1);
    PetQueue *pq = new PetQueue();
    pq->add(dog1);
    pq->add(cat1);
    pq->add(dog2);
    pq->add(cat3);
    pq->add(cat2);

    while (!pq->isEmpty()) {
        Pet *pet = pq->pollAll();
        cout << pet->getPetType() << endl;
    }
    return 0;
}