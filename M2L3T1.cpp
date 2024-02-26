#include <iostream>
#include <string>

class IntArray {
    int* p;
    unsigned int size;
public:
    IntArray(int inp_size) {
        size = inp_size;
        p = new int[size];
    }
    ~IntArray() {delete[] p;}
    int& operator[](unsigned int idx);
    void setElements();
    void printElements();
    unsigned int getSize() const;
    bool isPrice(int price);
    unsigned int findIndex(int element);
private:
    void Resize(unsigned int required_index);
};

int& IntArray::operator[](unsigned int idx) {
    if(idx >= size) Resize(idx);
    return p[idx];
}

void IntArray::Resize(unsigned int required_index) {
    unsigned int new_size = size;
    while(new_size <= required_index) new_size *= 2;
    int *new_array = new int[new_size];
    for(unsigned int i = 0; i < size; i++) new_array[i] = p[i];
    delete[] p;
    p = new_array;
    size = new_size;
}

void IntArray::setElements() {
    for(unsigned int i = 0; i < size; i++) std::cin >> p[i];
}

void IntArray::printElements() {
    for(unsigned int i = 0; i < size-1; i++) std::cout << p[i] << " ";
    std::cout << p[size-1] << std::endl;
}

unsigned int IntArray::getSize() const {
    return size;
}

bool IntArray::isPrice(int price) {
    bool res = false;
    int l = 0;
    int r = size;

    if (r == 0 || price < p[0] || price > p[r-1]) {
        res = false;
        return res;
    }

    while(l<=r) {
        int mid = (l+r)/2;
        if (price == p[mid]) {
            res = true;
            break;
        }
        else {
            if (price < p[mid]) r = mid - 1;
            else l = mid + 1;
        }
    }

    return res;
}

unsigned int IntArray::findIndex(int element) {
    (void)element;

    int left = 0;
    int right = size - 1;
    unsigned int index = 99;
    if (element < p[left]) return left;
    if (element > p[right]) return right + 1;
    
    while ((element > p[left]) && (element < p[right])) {
        if (p[left] == p[right]) break;
        index = left + (right - left)*(element - p[left])/(p[right] - p[left]);
        // std::cout << "index: " << index << std::endl;
        if (p[index]>element) right = index - 1;
        else if (p[index] < element) left = index + 1;
        else return index;
    }
    if (p[left] == element) return left;
        else if (p[left] > element) return index + 1;
    if (p[right] == element) return right;

    return index;
}


int main() {
    int n;
    std::cin >> n;
    IntArray arr(n);
    arr.setElements();
    //arr.printElements();

    int element;
    std::cin >> element;
    std::cout << arr.findIndex(element) << std::endl;
    return 0;
}