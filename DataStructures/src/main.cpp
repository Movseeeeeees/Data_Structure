#include <iostream>
#include "vector.h"
#include "list.h"
#include "deque.h"
#include <vector> // Include vector header

using namespace std;

void check_list()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    cout << "List size: " << list.get_size() << endl;
    list.print();

    list.pop_back();
    list.print();

    list.pop_front();
    list.print();

    list.reverse();
    list.print();

    list.insert(2, 10);
    list.print();

    list.erase(2);
    list.print();

    List list2;
    list2.push_front(6);
    list2.push_front(7);
    list2.Merge(list);
    cout << "List2 after merge: ";
    list2.print();

    List list3;
    list3.push_back(1);
    list3.push_back(4);

    list2.Splice(list2.begin(), list3);
    cout << "List2 after splice: ";
    list2.print();

    list2.reverse();
    list2.print();
}

void check_deque()
{
    Deque deque;

    deque.push_back(18); 
    
    for (int i = 0; i < 12; ++i) {
        deque.push_back(i);
    }
    for (int i = 0; i < 5; ++i) {
        deque.push_front(i);
    }
    cout << "Deque after push_front: ";
    deque.print();

    cout << "Size of deque: " << deque.size() << endl;

    for (int i = 0; i < 12; ++i) {
        deque.push_back(i);
    }
    cout << "Deque after push_back: ";
    deque.print();
    cout << "Size of deque: " << deque.size() << endl;
    
    deque.pop_back();
    deque.pop_back();

    cout << "Deque after pop_back: ";
    deque.print();
    
    deque.pop_front();
    deque.pop_front();
    cout << "Deque after pop_front: ";
    deque.print();
    cout << "Size of deque: " << deque.size() << endl;

    cout <<deque[2]<<endl;
    cout <<deque[7]<<endl;

    deque.printViaIterator(); 
}

void BubbleSort(std::vector<int>& vec)
{
    for(int i=0;i < vec.size()-1;i++)
    {
        for(int j=0;j < vec.size()- 1 - i;j++)
        {
            if(vec[j] > vec[j+1])
            {
                std::swap(vec[j], vec[j+1]);
            }
        }
    }
}

void insertionSort(Vector& vec)
{
    for (int i = 1; i <vec.size(); i++)
    {
        int key = vec[i];
        int j = i - 1;
        while( j>=0 && vec[j] > key)//shift
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> leftPart(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightPart(vec.begin() + mid + 1, vec.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            vec[k++] = leftPart[i++];
        } else {
            vec[k++] = rightPart[j++];
        }
    }

    while (i < leftPart.size()) {
        vec[k++] = leftPart[i++];
    }

    while (j < rightPart.size()) {
        vec[k++] = rightPart[j++];
    }
}

void mergeSort(std::vector<int>& vec, int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

int main() {
    std::vector<int> vec={5,2,9,1,5,6};

    
    std::cout<<"Original vector: ";
    for (const auto& v : vec) 
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    BubbleSort(vec);

    std::cout<<"Sorted vector using Bubble Sort: ";
    for (const auto& v : vec) 
    {
        std::cout << v << " ";
    }

    Vector vector = {5, 2, 9, 1, 5, 6};
    std::cout << "\nOriginal Vector: ";
    vector.print();
    insertionSort(vector);  
    std::cout << "Sorted Vector using Insertion Sort: ";
    vector.print(); 

    std::vector<int> vec2 = {9, 4, 7, 1, 3, 8, 2};

    std::cout << "Original vector: ";
    for (int num : vec2)
        std::cout << num << " ";
    std::cout << std::endl;

    mergeSort(vec2, 0, vec2.size() - 1);

    std::cout << "Sorted vector using Merge Sort: ";
    for (int num : vec2)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}