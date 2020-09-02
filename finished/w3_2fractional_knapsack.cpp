#include <iostream>
#include <iomanip>

struct Item {
    double weight;
    double value;
    double value_by_weight;
    Item * next;
};

class Priority_Items {
    private:
        Item * head;
    public:
        Priority_Items() {head = nullptr;}
        void push(double weight, double value) {
            //create new item
            Item * tmp = new Item;
            tmp->weight = weight;
            tmp->value = value;
            tmp->value_by_weight = value/weight;
            tmp->next = nullptr;
            //nothing in list
            if (head == nullptr) {
                head = tmp;
            }//if the list has one or more items, let's find where to place it
            else {//first, does it go before the head?
                if (tmp->value_by_weight > head->value_by_weight) {
                    tmp->next = head;
                    head = tmp;
                }
                else {//no? then where does it go?
                    //create a traversal node
                    Item * traversal = head;
                    //find position
                    while (traversal->next != nullptr && traversal->next->value_by_weight > tmp->value_by_weight)
                        traversal = traversal->next;
                    //place it
                    tmp->next = traversal->next;
                    traversal->next = tmp;
                }
            }
        }
        //pop top item and return it
        Item pop() {
            Item * tmp = head;
            head = head->next;
            Item ret = *tmp;
            delete tmp;

            return ret;
        }
        bool isEmpty() {
            return head == nullptr;
        }
        void print() {
            Item * tmp = head;
            int i = 1;
            while (tmp->next != nullptr) {
                std::cout << i++ << ": weight: " << tmp->weight << "\tvalue: " << tmp->value  << "\tv/w: " << tmp->value_by_weight << std::endl;
                tmp = tmp->next;
            }
            std::cout << i << ": weight: " << tmp->weight << " \tvalue: " << tmp->value << " \tv/w: " << tmp->value_by_weight << std::endl;
        }

};

double get_optimal_value(int capacity, Priority_Items items) {
    double value = 0.0;
    int carry = 0;

    //fill until full or no more items to place
    while (carry < capacity && !items.isEmpty()) {
        Item new_item = items.pop();

        //check if we can fit the whole item
        if (new_item.weight + carry <= capacity) {
            value += new_item.value;
            carry += new_item.weight;
        }//or only add a fraction
        else {
            //what fraction?
            double fraction = new_item.weight/(capacity - carry);
            //add it
            value += new_item.value/fraction;
            carry = capacity;
        }
    }
    return value;
}

int main() {
    int n;
    double capacity;
    std::cin >> n >> capacity;
    Priority_Items cache;
    double w;
    double v;
    for (int i = 0; i<n;i++) {
        std::cin >> v >> w;
        cache.push(w,v);
    }

    double optimal_value = get_optimal_value(capacity, cache);

    std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
    return 0;
}
